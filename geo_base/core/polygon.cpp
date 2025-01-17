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

#include <geo_base/core/polygon.h>

namespace geo_base {

static bool check(part_t const *part, point_t const &point, ref_t const *edge_refs,
    edge_t const *edges, point_t const *points)
{
    number_t const edge_refs_number = (part + 1)->edge_refs_offset - part->edge_refs_offset;
    return part->contains(point, edge_refs_number, edge_refs, edges, points);
}

bool polygon_t::contains(point_t const &point, part_t const *parts, ref_t const *edge_refs,
    edge_t const *edges, point_t const *points) const
{
    if (!bbox.contains(point))
        return false;

    parts += parts_offset;
    part_t const *parts_end = parts + parts_number;

    // Find lower bound part, which can contains given point.
    part_t const *part = std::lower_bound(parts, parts_end, point,
        [&] (part_t const &a, point_t const &b) {
            return a.coordinate < b.x;
        }
    );

    if (part->coordinate > point.x) {
        if (part == parts)
            return false;
        --part;
    }

    if (point.x < part->coordinate || point.x > (part + 1)->coordinate)
        return false;

    if (point.x == part->coordinate)
        if (part != parts && check(part - 1, point, edge_refs, edges, points))
            return true;
        
    return check(part, point, edge_refs, edges, points);
};

bool polygon_base_t::better(polygon_base_t const &p, region_t const *regions,
    number_t regions_number) const
{
    if (square < p.square)
        return true;

    if (square == p.square) {
        region_t const *begin = regions;
        region_t const *end = regions + regions_number;

        region_t const *r1 = std::lower_bound(begin, end, region_id);
        region_t const *r2 = std::lower_bound(begin, end, p.region_id);

        if (r1 == end || r1->region_id != region_id)
            return false;

        if (r2 == end || r2->region_id != p.region_id)
            return false;

        return r1->better(*r2);
    }

    return false;
}

bool raw_polygon_t::contains(point_t const &point, ref_t const *edge_refs, edge_t const *edges,
    point_t const *points) const
{
    if (!bbox.contains(point))
        return false;

    edge_refs += edge_refs_offset;
    
    number_t intersections = 0;
    for (number_t i = 0; i < edge_refs_number; ++i) {
        edge_t const &e = edges[edge_refs[i]];

        if (e.contains(point, points))
            return true;

        point_t a = points[e.beg];
        point_t b = points[e.end];

        if (a.x > b.x)
            std::swap(a, b);

        if (a.x < point.x && b.x >= point.x && e.lower(point, points))
            ++intersections;
    }

    return intersections % 2 == 1;
}

} // namespace geo_base
