#include "Write.hpp"

#include <png++/png.hpp>

#include <gsl/narrow>

#include <array>
#include <cmath>
#include <optional>


namespace {

png::rgb_pixel toColor(const Pixel& pixel)
{
    if (!pixel) {
        return png::rgb_pixel{};
    }

    static const std::array colorPalette{ png::rgb_pixel{},
                                          png::rgb_pixel{ 0, 0, 20 },
                                          png::rgb_pixel{ 0, 0, 40 },
                                          png::rgb_pixel{ 22, 16, 48 },
                                          png::rgb_pixel{ 47, 19, 69 },
                                          png::rgb_pixel{ 79, 16, 84 },
                                          png::rgb_pixel{ 110, 100, 110 },
                                          png::rgb_pixel{ 140, 140, 140 },
                                          png::rgb_pixel{ 170, 170, 170 },
                                          png::rgb_pixel{ 200, 200, 200 },
                                          png::rgb_pixel{ 233, 233, 233 },
                                          png::rgb_pixel{ 255, 255, 255 } };

    const auto index{ gsl::narrow_cast<std::size_t>(colorPalette.size() * *pixel) };
    return colorPalette[index];
}

}   // namespace


tl::expected<void, std::string>
write(const PixelBuffer& pixelBuffer, const std::filesystem::path& filePath)
{
    const std::size_t width{ pixelBuffer.width() };
    const std::size_t height{ pixelBuffer.height() };
    png::image<png::rgb_pixel> image{ gsl::narrow_cast<unsigned int>(width),
                                      gsl::narrow_cast<unsigned int>(height) };

    for (std::size_t y = 0; y < height; ++y) {
        for (std::size_t x = 0; x < width; ++x) {
            image[y][x] = toColor(pixelBuffer.at(x, y));
        }
    }

    try {
        image.write(filePath);
        return {};
    } catch (const std::exception& e) {
        return tl::make_unexpected(e.what());
    }
}
