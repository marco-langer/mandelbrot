find_path(PNGPP_INCLUDE_DIRS "png++/color.hpp")

add_library(pngpp INTERFACE)

target_include_directories(pngpp INTERFACE ${PNGPP_INCLUDE_DIRS})
target_link_libraries(pngpp INTERFACE png)

set_target_properties(pngpp
    PROPERTIES
        INTERFACE_SYSTEM_INCLUDE_DIRECTORIES
            $<TARGET_PROPERTY:pngpp,INTERFACE_INCLUDE_DIRECTORIES>
)
