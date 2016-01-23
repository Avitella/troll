// Copyright (c) 2015, 2016 Urtashev Arslan. All rights reserved.
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

#pragma once

#include <geo_base/core/common.h>
#include <geo_base/core/geo_data/geo_data.h>
#include <geo_base/core/geo_data/loader.h>
#include <geo_base/lib/mem_file.h>

namespace geo_base {

geo_id_t const UNKNOWN_GEO_ID = static_cast<geo_id_t>(-1);

class geo_base_t {
public:
    geo_base_t()
        : geo_data_loader_()
    { }

    geo_base_t(geo_base_t &&g)
        : geo_data_loader_()
    {
        std::swap(geo_data_loader_, g.geo_data_loader_);
    }

    geo_base_t &operator = (geo_base_t &&g)
    {
        std::swap(geo_data_loader_, g.geo_data_loader_);
    }

    explicit geo_base_t(char const *path)
        : geo_data_loader_(new geo_data_map_loader_t(path))
    { }

    explicit geo_base_t(geo_data_t const &geo_data)
        : geo_data_loader_(new geo_data_wrapper_t(geo_data))
    { }

    geo_id_t lookup(location_t const &location) const;

private:
    geo_data_loader_ptr_t geo_data_loader_;

    GEO_BASE_DISALLOW_EVIL_CONSTRUCTORS(geo_base_t);
};

}
