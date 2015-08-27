#include "geo_base.h"
#include "location.h"
#include "log.h"
#include "stop_watch.h"

#include <iomanip>
#include <iostream>

using namespace troll;

static input_t &operator >> (input_t &in, location_t &l)
{
	in >> l.lat;
	in.ignore();
	in >> l.lon;
	return in;
}

static int convert_to_mks(double x)
{
	return x * 1000000;
}

int main(int argc, char *argv[])
{
	std::ios_base::sync_with_stdio(false);
	std::cerr << std::fixed << std::setprecision(2);

	if (argc != 2) {
		log_error("geo-base-perf") << "geo-base-perf <geodata.dat>";
		return -1;
	}

	try {
		geo_base_t geo_base(argv[1]);

		location_t location;
		std::vector<uint32_t> checkpoints;

		while (std::cin >> location) {
			stop_watch_t sw;

			sw.checkpoint();
			geo_base.lookup(location);
			double t = sw.checkpoint();

			checkpoints.push_back(convert_to_mks(t));
		}

		sort(checkpoints.begin(), checkpoints.end());

		for (size_t l = 0, r = 0; l < checkpoints.size(); l = r) {
			r = l + 1;
			while (r < checkpoints.size() && checkpoints[r] == checkpoints[l])
				++r;

			log_info("geo-base-perf") << r * 100.0 / checkpoints.size() << "% <= " << checkpoints[l] << "µs";
		}

	} catch (std::exception const &e) {
		log_error("geo-base-perf", "EXCEPTION") << e.what();
	}

	return 0;
}