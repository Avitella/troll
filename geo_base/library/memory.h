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

#pragma once

#include <stdint.h>

namespace geo_base {

size_t constexpr MEMORY_ALIGNMENT = 16ull;

inline unsigned long long constexpr operator "" _gb (unsigned long long x)
{
    return x * (1ull << 30);
}

inline unsigned long long constexpr operator "" _mb (unsigned long long x)
{
    return x * (1ull << 20);
}

inline unsigned long long constexpr operator "" _kb (unsigned long long x)
{
    return x * (1ull << 10);
}

inline unsigned long long align_memory(unsigned long long x)
{
    if (x % MEMORY_ALIGNMENT == 0)
        return x;
    return x + MEMORY_ALIGNMENT - x % MEMORY_ALIGNMENT;
}

inline bool is_aligned_memory(void *ptr)
{
    return ((uintptr_t) ptr) % MEMORY_ALIGNMENT == 0;
}

} // namespace geo_base
