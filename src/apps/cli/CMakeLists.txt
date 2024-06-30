find_package(fmt CONFIG REQUIRED)
find_package(tl-expected CONFIG REQUIRED)

add_executable(mandelbrot-cli)

target_sources(mandelbrot-cli
    PUBLIC
        main.cpp
        Write.cpp
        Write.hpp
)

target_link_libraries(mandelbrot-cli
    PRIVATE
        mandelbrot-core
        pngpp
        fmt::fmt
        tl::expected
)

set_compiler_options(mandelbrot-cli)
