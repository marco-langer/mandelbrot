cmake_minimum_required(VERSION 3.18)

project(mandelbrot LANGUAGES CXX)

include(cmake/CompilerOptions.cmake)

add_subdirectory(benchmarks)
add_subdirectory(cmake)
add_subdirectory(src)

include(CTest)
if (BUILD_TESTING)
    add_subdirectory(tests)
endif()
