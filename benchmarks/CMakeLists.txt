find_package(benchmark CONFIG REQUIRED)

add_executable(mandelbrot-benchmark mandelbrot_benchmark.cpp)

target_link_libraries(mandelbrot-benchmark
    PRIVATE
        mandelbrot-core
        benchmark::benchmark_main
)

set_compiler_options(mandelbrot-benchmark)
