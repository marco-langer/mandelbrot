#include "MandelbrotImpl.hpp"

#include <gtest/gtest.h>


TEST(mandelbrot, mapPixel)
{
    const Size size{ 800, 600 };
    const Rectangle rectangle{ .x{ -1.0F }, .width{ 2.0F }, .height{ 1.0F } };

    EXPECT_EQ(mapPixel(0, 0, size, rectangle), std::complex<float>(-1.0F, 0.0F));
    EXPECT_EQ(mapPixel(400, 300, size, rectangle), std::complex<float>(0.0F, 0.5F));
}
