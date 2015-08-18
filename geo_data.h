#pragma once

#include "edge.h"
#include "io.h"
#include "location.h"
#include "part.h"
#include "point.h"
#include "polygon.h"
#include "region.h"
#include "typedef.h"

namespace troll {

#define TROLL_DEF_VAR(var_t, var) \
	var_t var;

#define TROLL_DEF_PTR(ptr_t, ptr) \
	ptr_t *ptr;

#define TROLL_DEF_ARR(arr_t, arr) \
	TROLL_DEF_VAR(count_t, arr##_count); \
	TROLL_DEF_PTR(arr_t, arr);

#define TROLL_DEF_GEO_DATA \
	TROLL_DEF_ARR(point_t, points); \
	TROLL_DEF_ARR(edge_t, edges); \
	TROLL_DEF_ARR(index_t, edge_indexes); \
	TROLL_DEF_ARR(part_t, parts); \
	TROLL_DEF_ARR(polygon_t, polygons); \
	TROLL_DEF_ARR(region_t, regions);

struct geo_data_t {
	TROLL_DEF_GEO_DATA
};

#undef TROLL_DEF_VAR
#undef TROLL_DEF_PTR
#undef TROLL_DEF_ARR

void geo_data_map(void *dat, geo_data_t* geo_data);
void geo_data_save(void *dat, geo_data_t* geo_data);

region_id_t geo_data_lookup(geo_data_t const &geo_data, location_t const &location);
void geo_data_show(geo_data_t const &geo_data, output_t &out);

}