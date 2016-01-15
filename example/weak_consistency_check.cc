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

#include <geo_base/open_street_map/weak_consistency_checker.h>
#include <geo_base/util/log.h>
#include <geo_base/util/memory.h>
#include <geo_base/util/pool_allocator.h>

using namespace geo_base;
using namespace open_street_map;

int main(int argc, char *argv[])
{
	log_setup(STDERR_FILENO, LOG_LEVEL_DEBUG);

	if (argc != 2) {
		log_error("USAGE: weak-consistency-check <planet-latest.osm.pbf>");
		return -1;
	}

	pool_allocator_t allocator(128_mb);

	file_t file;
	file.read_open(argv[0]);
	file_input_stream_t stream(file.fd());

	reader_t reader(&stream);
	weak_consistency_checker_t checker(&allocator);

	checker.parse(&reader);

	if (!checker.check()) {
		log_error("The data is not consistent!");
	} else {
		log_info("Data is consistent");
	}

	return 0;
}
