#include "Mandelbrot.hpp"

#include <benchmark/benchmark.h>


namespace {

void benchCreateMandelbrot(benchmark::State& state)
{
    const Params params{ .size{ .width{ 1280 }, .height{ 720 } },
                         .region{ .x{ -2.5F }, .y{ -1.0F }, .width{ 3.5F }, .height{ 2.0F } },
                         .maxIterations{ 100 },
                         .threshhold{ 1000.0F } };

    for (const auto _ : state) {
        PixelBuffer pixelBuffer{ createMandelbrot(params) };
        benchmark::DoNotOptimize(pixelBuffer);
    }
}

}   // namespace


BENCHMARK(benchCreateMandelbrot)->Unit(benchmark::kMillisecond);
