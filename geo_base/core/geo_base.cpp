// Copyright (c) 2016 Urtashev Arslan. All rights reserved.
// Contacts: <urtashev@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in all copies or
//   substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <algorithm>

#include <geo_base/core/geo_base.h>
#include <geo_base/core/geo_data/geo_data.h>

namespace geo_base {

static bool polygon_contains(polygon_t const &p, point_t const &point, geo_data_t const &geo_data)
{
    part_t const *parts = geo_data.parts();
    ref_t const *edge_refs = geo_data.edge_refs();
    edge_t const *edges = geo_data.edges();
    point_t const *points = geo_data.points();
    return p.contains(point, parts, edge_refs, edges, points);
}

template<typename answer_t>
static void update_answer(answer_t const **answer, answer_t const &polygon,
    geo_data_t const &geo_data)
{
    if (!*answer) {
        *answer = &polygon;
    } else {
        region_t const *regions = geo_data.regions();
        number_t const regions_number = geo_data.regions_number();
        if (!(*answer)->better(polygon, regions, regions_number))
            *answer = &polygon;
    }
}

static void sort_debug(geo_base_t::debug_t *debug, geo_data_t const &geo_data)
{
    region_t const *regions = geo_data.regions();
    number_t const regions_number = geo_data.regions_number();

    std::sort(debug->begin(), debug->end(), [&] (geo_id_t const &a, geo_id_t const &b) {
        region_t const *r1 = std::lower_bound(regions, regions + regions_number, a);
        region_t const *r2 = std::lower_bound(regions, regions + regions_number, b);
        return r1->better(*r2);
    });
}

geo_id_t geo_base_t::lookup(location_t const &location, debug_t *debug) const
{
    geo_data_t const &geo_data = *geo_data_proxy_->geo_data();

    if (debug)
        debug->clear();

    point_t const point(location);
    ref_t const box_ref = lookup_area_box(point);

    if (box_ref >= geo_data.boxes_number())
        return UNKNOWN_GEO_ID;

    number_t const refs_offset = geo_data.boxes()[box_ref].polygon_refs_offset;
    number_t const refs_number = geo_data.boxes()[box_ref].polygon_refs_number;

    polygon_t const *answer = nullptr;

    for (ref_t l = refs_offset, r = 0; l < refs_offset + refs_number; l = r) {
        ref_t const *refs = geo_data.polygon_refs();
        polygon_t const *p = geo_data.polygons();

        r = l + 1;

        if (polygon_contains(p[refs[l]], point, geo_data)) {
            if (p[refs[l]].type == polygon_t::TYPE_INNER) {
                // All polygons with same region_id must be skipped if polygon is inner.
                // In geo_data small inner polygons stored before big outer polygons.
                while (r < refs_offset + refs_number && p[refs[l]].region_id == p[refs[r]].region_id)
                    ++r;

            } else {
                update_answer(&answer, p[refs[l]], geo_data);

                if (debug)
                    debug->push_back(p[refs[l]].region_id);

                while (r < refs_offset + refs_number && p[refs[l]].region_id == p[refs[r]].region_id)
                    ++r;
            }
        }
    }

    if (debug)
        sort_debug(debug, geo_data);

    return answer ? answer->region_id : UNKNOWN_GEO_ID;
}

geo_id_t geo_base_t::raw_lookup(location_t const &location, debug_t *debug) const
{
    geo_data_t const &geo_data = *geo_data_proxy_->geo_data();

    if (debug)
        debug->clear();

    point_t const point(location);
    
    raw_polygon_t const *borders = geo_data.raw_polygons();
    number_t const borders_number = geo_data.raw_polygons_number();

    raw_polygon_t const *answer = nullptr;

    number_t i = 0;
    while (i < borders_number) {
        if (borders[i].contains(point, geo_data.raw_edge_refs(), geo_data.edges(), geo_data.points())) {
            if (borders[i].type == raw_polygon_t::TYPE_INNER) {
                number_t j = i + 1;
                while (j < borders_number && borders[i].region_id == borders[j].region_id)
                    ++j;

                i = j;

            } else {
                update_answer(&answer, borders[i], geo_data);

                if (debug)
                    debug->push_back(borders[i].region_id);

                number_t j = i + 1;
                while (j < borders_number && borders[i].region_id == borders[j].region_id)
                    ++j;

                i = j;
            }
        } else {
            ++i;
        }
    }

    if (debug)
        sort_debug(debug, geo_data);

    return answer ? answer->region_id : UNKNOWN_GEO_ID;
}

bool geo_base_t::each_kv(geo_id_t region_id, kv_callback_t callback) const
{
    geo_data_t const &g = *geo_data_proxy_->geo_data();

    region_t const *begin = g.regions();
    region_t const *end = begin + g.regions_number();

    region_t const *region = std::lower_bound(begin, end, region_id);

    if (region == end || region->region_id != region_id)
        return false;

    kv_t const *kvs = g.kvs() + region->kvs_offset;
    char const *blobs = g.blobs();

    for (number_t i = 0; i < region->kvs_number; ++i) {
        char const *k = blobs + kvs[i].k;
        char const *v = blobs + kvs[i].v;
        callback(k, v);
    }

    return true;
}

void geo_base_t::each_polygon(polygon_callback_t callback) const
{
    geo_data_t const &g = *geo_data_proxy_->geo_data();

    for (number_t i = 0; i < g.polygons_number(); ++i)
        callback(g.polygons()[i]);
}

void geo_base_t::each_part(polygon_t const &polygon, part_callback_t callback) const
{
    geo_data_t const &g = *geo_data_proxy_->geo_data();

    number_t const parts_offset = polygon.parts_offset;
    number_t const parts_number = polygon.parts_number;

    for (number_t i = parts_offset; i < parts_offset + parts_number; ++i) {
        part_t const &part = g.parts()[i];
        part_t const &npart = g.parts()[i + 1];
        number_t const edge_refs_number = npart.edge_refs_offset - part.edge_refs_offset;
        callback(part, edge_refs_number);
    }
}

} // namespace geo_base
