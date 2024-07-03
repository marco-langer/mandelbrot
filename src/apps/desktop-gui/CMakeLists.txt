find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(mandelbrot)

target_sources(mandelbrot
    PUBLIC
        main.cpp
        MainWindow.cpp
        MainWindow.hpp
        ParameterWidget.cpp
        ParameterWidget.hpp
)

target_link_libraries(mandelbrot
    PRIVATE
        mandelbrot-core
        Microsoft.GSL::GSL
        Qt5::Widgets
)

set_compiler_options(mandelbrot)
