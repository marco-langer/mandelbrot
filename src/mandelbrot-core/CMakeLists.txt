find_package(Microsoft.GSL CONFIG REQUIRED)

add_library(mandelbrot-core STATIC)

target_sources(mandelbrot-core
    PUBLIC
        include/Mandelbrot.hpp
        include/PixelBuffer.hpp
        include/Rectangle.hpp
        include/Size.hpp
        src/Mandelbrot.cpp
        src/MandelbrotImpl.cpp
        src/MandelbrotImpl.hpp
)

target_include_directories(mandelbrot-core PUBLIC include)

target_link_libraries(mandelbrot-core PRIVATE Microsoft.GSL::GSL)

set_compiler_options(mandelbrot-core)
