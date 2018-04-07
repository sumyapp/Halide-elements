#include <cstdint>
#include "Halide.h"
#include "Element.h"

using namespace Halide;
using Halide::Element::schedule;

template<typename T>
class Label : public Halide::Generator<Label<T>> {
public:
    ImageParam src{type_of<T>(), 2, "src"};

    GeneratorParam<int32_t> width{"width", 1024};
    GeneratorParam<int32_t> height{"height", 500};

    Func build() {
        Func dst{"dst"};
        dst = Element::label_firstpass(src, width, height);

        schedule(src, {width, height});
        schedule(dst, {width, height});
        return dst;
    }
};

RegisterGenerator<Label<uint8_t>> label_u8{"label_u8"};
RegisterGenerator<Label<uint16_t>> label_u16{"label_u16"};
