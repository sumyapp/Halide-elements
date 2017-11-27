#include <iostream>
#include "Halide.h"
#include "Element.h"

using namespace Halide;
using namespace Halide::Element;

template<typename T, typename D>
class Integral : public Halide::Generator<Integral<T, D>> {
public:
    GeneratorParam<int32_t> width{"width", 1024};
    GeneratorParam<int32_t> height{"height", 768};

    ImageParam src{type_of<T>(), 2, "src"};

    Func build() {
        Func dst = integral<D>(src, width, height);

        schedule(src, {width, height});
        schedule(dst, {width, height});

        return dst;
    }
};

RegisterGenerator<Integral<uint8_t, float>> integral_u8_f32{"integral_u8_f32"};
RegisterGenerator<Integral<uint16_t, float>> integral_u16_f32{"integral_u16_f32"};
RegisterGenerator<Integral<uint32_t, float>> integral_u32_f32{"integral_u32_f32"};
RegisterGenerator<Integral<uint8_t, double>> integral_u8_f64{"integral_u8_f64"};
RegisterGenerator<Integral<uint16_t, double>> integral_u16_f64{"integral_u16_f64"};
RegisterGenerator<Integral<uint32_t, double>> integral_u32_f64{"integral_u32_f64"};