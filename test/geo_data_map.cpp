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

#include <geo_base/core/geo_base.h>
#include <geo_base/core/geo_data/debug.h>
#include <geo_base/core/geo_data/map.h>
#include <geo_base/generator/generator.h>
#include <geo_base/library/pool_allocator.h>
#include <geo_base/library/stop_watch.h>
#include <test/geo_base_test.h>

#include <utility>

using namespace geo_base;

class geo_data_map_test_t : public test_t {
};

template<typename val_t>
static bool is_equal(val_t const &a, val_t const &b)
{
    return !memcmp(&a, &b, sizeof(val_t));
}

template<typename arr_t>
static bool is_equal(arr_t const *a, arr_t const *b, number_t number)
{
    for (number_t i = 0; i < number; ++i)
        if (!is_equal(a[i], b[i]))
            return false;
    return true;
}

static bool operator == (geo_data_t const &a, geo_data_t const &b)
{
#define GEO_BASE_DEF_VAR(var_t, var) \
    if (a.var() != b.var()) \
        return false;

#define GEO_BASE_DEF_ARR(arr_t, arr) \
    if (a.arr##_number() != b.arr##_number()) \
        return false; \
    if (!is_equal(a.arr(), b.arr(), a.arr##_number())) \
        return false;

    GEO_BASE_DEF_GEO_DATA

#undef GEO_BASE_DEF_VAR
#undef GEO_BASE_DEF_ARR

    return true;
}

TEST_F(geo_data_map_test_t, simple_serialize)
{
    pool_allocator_t allocator(1_mb);

    generator::geo_data_test_t geo_data;
    geo_data.set_version(GEO_DATA_CURRENT_VERSION);

    geo_data_map_t geo_data_map1(geo_data, &allocator);
    geo_data_map_t geo_data_map2(geo_data_map1.data(), geo_data_map1.size());

    EXPECT_TRUE(geo_data_map1 == geo_data);
    EXPECT_TRUE(geo_data_map1 == geo_data_map2);
}

TEST_F(geo_data_map_test_t, check_version)
{
    pool_allocator_t allocator(1_mb);

    generator::geo_data_test_t geo_data;
    geo_data.set_version(GEO_DATA_VERSION_0);

    EXPECT_THROW(geo_data_map_t(geo_data, &allocator), exception_t);
}

TEST_F(geo_data_map_test_t, fake_data_serialize)
{
    pool_allocator_t allocator(64_mb);
    pool_allocator_t serialize_allocator(64_mb);

    generator::geo_data_test_t geo_data;
    generator::generator_t generator(generator::config_t(), &geo_data, &allocator);

    proto::region_t region;

    proto::polygon_t *polygon = region.add_polygons();
    polygon->set_polygon_id(123);

    using pair_t = std::pair<int, int>;
    using vector_t = std::vector<pair_t>;

    for (pair_t const &p : vector_t{{0, 0}, {10, 0}, {10, 0}, {10, 10}}) {
        proto::location_t *l = polygon->add_locations();
        l->set_lon(p.first);
        l->set_lat(p.second);
    }

    region.set_region_id(123);

    generator.init();
    generator.update(region);
    generator.fini();

    geo_data_map_t geo_data_map1(geo_data, &serialize_allocator);
    geo_data_map_t geo_data_map2(geo_data_map1.data(), geo_data_map1.size());

    EXPECT_TRUE(geo_data_map1 == geo_data);
    EXPECT_TRUE(geo_data_map1 == geo_data_map2);

    geo_base_t geo_base(geo_data_map2);

    EXPECT_EQ(123ull, geo_base.lookup(location_t(5, 5)));
    EXPECT_EQ(UNKNOWN_GEO_ID, geo_base.lookup(location_t(-1, -1)));
    EXPECT_EQ(UNKNOWN_GEO_ID, geo_base.lookup(location_t(0, 3)));
    EXPECT_EQ(123ull, geo_base.lookup(location_t(4, 0)));
    EXPECT_EQ(123ull, geo_base.lookup(location_t(5, 5)));

    geo_data::show(log_fd(), geo_data_map2);
}
