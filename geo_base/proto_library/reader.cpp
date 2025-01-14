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

#include <geo_base/library/log.h>
#include <geo_base/library/stop_watch.h>
#include <geo_base/proto_library/reader.h>

namespace geo_base {
namespace proto {

void reader_t::generate_index()
{
    if (!index_.empty()) {
        log_warning("Index already generated!");
        return;
    }

    log_debug("Generating proto reader index...");

    stop_watch_t stop_watch;
    stop_watch.run();

    each_with_ptr([&] (char const *ptr, proto::region_t const &region) {
        if (index_.find(region.region_id()) != index_.end())
            log_warning("Region %lu already exists in index", region.region_id());
        index_[region.region_id()] = ptr - ((char const *) mem_file_.data());
    });

    float const seconds = stop_watch.get();
    log_debug("Proto reader index generated in %.3f seconds (%.3f minutes)",
        seconds, seconds / 60.0);
}

} // namespace proto
} // namespace geo_base
