#include "Mandelbrot.hpp"

#include "MandelbrotImpl.hpp"


PixelBuffer createMandelbrot(const Params& params)
{
    const std::size_t width{ params.size.width };
    const std::size_t height{ params.size.height };

    PixelBuffer pixelBuffer{ width, height };

    for (std::size_t y = 0; y < height; ++y) {
        for (std::size_t x = 0; x < width; ++x) {
            pixelBuffer.at(x, y) = julia(
                mapPixel(x, y, params.size, params.region),
                params.maxIterations,
                params.threshhold);
        }
    }

    return pixelBuffer;
}
