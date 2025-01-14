// Copyright (c) 2015 Urtashev Arslan. All rights reserved.
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
#include <geo_base/generator/generator.h>
#include <geo_base/generator/gen_geo_data.h>
#include <geo_base/library/memory.h>
#include <geo_base/library/pool_allocator.h>
#include <geo_base/open_street_map/converter.h>
#include <test/geo_base_test.h>

#include <utility>

using namespace geo_base;

class generator_test_t : public test_t {
};

TEST_F(generator_test_t, generator_test)
{
    pool_allocator_t allocator(1_mb);

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

    geo_base_t geo_base(geo_data);

    EXPECT_EQ(123ull, geo_base.lookup(location_t(5, 5)));
    EXPECT_EQ(UNKNOWN_GEO_ID, geo_base.lookup(location_t(-1, -1)));
    EXPECT_EQ(UNKNOWN_GEO_ID, geo_base.lookup(location_t(0, 3)));
    EXPECT_EQ(123ull, geo_base.lookup(location_t(4, 0)));
    EXPECT_EQ(123ull, geo_base.lookup(location_t(5, 5)));
}

TEST_F(generator_test_t, dump)
{
    ASSERT_NO_THROW(open_street_map::run_pool_convert("test/andorra-latest.osm.pbf", "andorra-latest.pbf", 1));

    generator::config_t config;
    config.save_raw_borders = true;

    ASSERT_NO_THROW(generator::generate("andorra-latest.pbf", "andorra-latest.dat.test", config));

    mem_file_t pre;
    pre.read_open("test/andorra-latest.dat.pre");

    mem_file_t test;
    test.read_open("andorra-latest.dat.test");

    geo_data_map_t map1((char const *) pre.data(), pre.size());
    geo_data_map_t map2((char const *) test.data(), test.size());

    geo_data::show(log_fd(), map1);
    geo_data::show(log_fd(), map2);

    ASSERT_EQ(pre.size(), test.size());
    ASSERT_TRUE(geo_data::equals(map1, map2));
}

TEST_F(generator_test_t, polygon)
{
}
