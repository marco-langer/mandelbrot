#include "MandelbrotImpl.hpp"

#include <gsl/narrow>


namespace {

std::complex<float> julia(std::complex<float> z, std::complex<float> c) { return z * z + c; }

}   // namespace


std::complex<float>
mapPixel(std::size_t x, std::size_t y, const Size& size, const Rectangle& rectangle)
{
    return std::complex<float>{
        rectangle.x
            + gsl::narrow_cast<float>(x) / gsl::narrow_cast<float>(size.width) * rectangle.width,
        rectangle.y
            + gsl::narrow_cast<float>(y) / gsl::narrow_cast<float>(size.height) * rectangle.height
    };
}


Pixel julia(std::complex<float> c, int maxIterations, float threshhold)
{
    std::complex<float> z;
    int i{ 0 };
    for (i = 0; i < maxIterations; ++i) {
        z = julia(z, c);
        if (std::abs(z) > threshhold) {
            return gsl::narrow_cast<float>(i) / maxIterations;
        }
    }

    return std::nullopt;
}
