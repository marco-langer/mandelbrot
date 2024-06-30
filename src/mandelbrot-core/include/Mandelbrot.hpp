#pragma once

#include "PixelBuffer.hpp"
#include "Rectangle.hpp"
#include "Size.hpp"


struct Params
{
    Size size{ .width{ 800 }, .height{ 600 } };
    Rectangle region{ .x{ -2.5F }, .y{ -1.0F }, .width{ 3.5F }, .height{ 2.0F } };
    int maxIterations{ 100 };
    float threshhold{ 1000.0F };
};


PixelBuffer createMandelbrot(const Params& params);
