enable_testing()
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(mandelbrot-test)

target_sources(mandelbrot-test PUBLIC mandelbrot_test.cpp)

get_target_property(MANDELBROT_SRC_DIR mandelbrot-core SOURCE_DIR)

add_library(mandelbrot-core-for-tests INTERFACE)
target_include_directories(mandelbrot-core-for-tests INTERFACE ${MANDELBROT_SRC_DIR}/src)
target_link_libraries(mandelbrot-core-for-tests INTERFACE mandelbrot-core)

target_link_libraries(mandelbrot-test
    PRIVATE
        mandelbrot-core-for-tests
        GTest::gmock_main
)

set_compiler_options(mandelbrot-test)

gtest_discover_tests(mandelbrot-test)
