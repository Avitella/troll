#pragma once

#include "exception.h"
#include "io.h"
#include "location.h"
#include "log.h"
#include "typedef.h"
#include "vector.h"
#include "watch.h"

#include <sstream>
#include <string>

namespace troll {

template<typename callback_t>
void geo_read_txt(input_t &in, callback_t callback)
{
	std::string curstr;
	std::stringstream strin;

	region_id_t region_id;
	count_t locations_count;
	vector_t<location_t> locations;

	count_t lines_count = 0;
	watch_t watch;

	while (std::getline(in, curstr)) {
		++lines_count;
		count_t region_line = lines_count;

		strin.clear();
		strin << curstr;

		if (!(strin >> region_id))
			throw exception_t("Can't read region_id on %u: \"%s\"", lines_count, curstr.c_str());

		if (!(strin >> locations_count))
			throw exception_t("Can't read locations count on %u: \"%s\"", lines_count, curstr.c_str());

		locations.resize(locations_count);

		for (location_t &l : locations) {
			++lines_count;
			
			if (!std::getline(in, curstr))
				throw exception_t("Wrong locations count for %ld on %u", region_id, region_line);

			strin.clear();
			strin << curstr;

			if (!(strin >> l.lon >> l.lat))
				throw exception_t("Can't read locations on %u: \"%s\"", lines_count, curstr.c_str());
		}

		callback(region_id, locations);
	}

	log_info("geo_read_txt") << "Processed lines count = " << lines_count;
	log_info("geo_read_txt") << "Generated for " << watch.total() / 60. << " minutes";
}

}
