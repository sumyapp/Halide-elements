#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <exception>

#include <Halide.h>

namespace Halide {
namespace Element {

void throw_assert(bool condition, const char *msg) 
{
    if (!condition) {
        throw std::runtime_error(msg);
    }
}

template<typename T>
struct Upper;

template<>
struct Upper<int16_t> {
    using type = int32_t;
};

template<>
struct Upper<int32_t> {
    using type = int64_t;
};

template<>
struct Upper<float> {
    using type = float;
};

template<>
struct Upper<double> {
    using type = double;
};


} //namespace Element
} //namespace Halide

