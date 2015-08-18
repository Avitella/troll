#include "geo_base_alloc.h"
#include "unordered_map.h"
#include "vector.h"

#include <iostream>

using namespace troll;

using refs_point_t = unordered_map_t<point_t, ref_t, hash64_t, equal_t>;
using refs_edge_t = unordered_map_t<edge_t, ref_t, hash64_t, equal_t>;

enum class border_type_t {
	LEFT,
	RIGHT
};

struct border_t {
	coordinate_t coordinate;
	ref_t edge_ref;
	border_type_t type;
};

struct buffer_t {
	vector_t<point_t> points;
	vector_t<edge_t> edges;
	vector_t<border_t> borders;
};

#define TROLL_DEF_VAR(var_t, var) \
	var_t var;

#define TROLL_DEF_PTR(ptr_t, ptr) \
	// undef

#define TROLL_DEF_ARR(arr_t, arr) \
	vector_t<arr_t> arr;

struct context_t {
	TROLL_DEF_GEO_DATA

	ref_t ref_point(point_t const &p)
	{
		if (refs_point.find(p) == refs_point.end()) {
			refs_point[p] = points.size();
			points.push_back(p);
		}
		return refs_point[p];
	}

	ref_t ref_edge(edge_t const &e)
	{
		if (refs_edges.find(e) == refs_edges.end()) {
			refs_edges[e] = edges.size();
			edges.push_back(e);
		}
		return refs_edges[e];
	}

	refs_point_t refs_point;
	refs_edge_t refs_edges;
};

#undef TROLL_DEF_VAR
#undef TROLL_DEF_PTR
#undef TROLL_DEF_ARR

static void context_save(geo_base_alloc_t *alloc, context_t *context)
{
	geo_data_t *geo_data = alloc->geo_data();

#define TROLL_DEF_VAR(var_t, var) \
	do { \
		geo_data->var = context->var; \
	} while (false);

#define TROLL_DEF_PTR(ptr_t, ptr) \
	// undef

#define TROLL_DEF_ARR(arr_t, arr) \
	do { \
		geo_data->arr##_count = context->arr.size(); \
		geo_data->arr = (arr_t *) alloc->alloc(sizeof(arr_t) * context->arr.size()); \
		copy_n(context->arr.begin(), context->arr.size(), geo_data->arr); \
		context->arr.clear(); \
		context->arr.shrink_to_fit(); \
	} while (false);

	TROLL_DEF_GEO_DATA

#undef TROLL_DEF_VAR
#undef TROLL_DEF_PTR
#undef TROLL_DEF_ARR
}

// static void update_context(region_id_t region_id, vector_t<location_t> const &locations, context_t *context, buffer_t *bufer)
static void update_context(region_id_t, vector_t<location_t> const &, context_t *, buffer_t *)
{

}

static void usage()
{
	std::cerr << "geo-base-generate <geo.dat>" << std::endl;
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);

	if (argc != 2) {
		usage();
		return -1;
	}

	context_t context;
	buffer_t buffer;
	geo_base_alloc_t base(argv[1]);

	region_id_t region_id;
	count_t locations_count;
	vector_t<location_t> locations;
	
	while (std::cin >> region_id >> locations_count) {
		locations.resize(locations_count);
		for (location_t &l : locations) {
			if (!(std::cin >> l.lon >> l.lat)) {
				std::cerr << "Wrong locations count" << std::endl;
				return -1;
			}
		}
		update_context(region_id, locations, &context, &buffer);
	}

	context_save(&base, &context);

	return 0;
}
