#pragma once

#include "PixelBuffer.hpp"
#include "Rectangle.hpp"
#include "Size.hpp"

#include <complex>
#include <cstdint>
#include <optional>


std::complex<float>
mapPixel(std::size_t x, std::size_t y, const Size& size, const Rectangle& rectangle);


Pixel julia(std::complex<float> c, int maxIterations, float threshhold);
