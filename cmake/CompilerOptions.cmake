function(_add_warnings TargetName)
    set(GCC_WARNINGS
        -pedantic-errors
        -Wall
        -Wcast-align
        -Wdouble-promotion
        -Werror
        -Wextra
        -Wimplicit-fallthrough
        -Wnon-virtual-dtor
        -Wnull-dereference
        -Wold-style-cast
        -Woverloaded-virtual
        -Wshadow
        -Wunused

        -Wduplicated-branches
        -Wduplicated-cond
        -Wlogical-op
        -Wsuggest-override
        # -Wuseless-cast => is generated in Qt moc_ files up until Qt 6.4/6.5
    )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(WARNINGS_CXX ${GCC_WARNINGS})
    else()
        message(AUTHOR_WARNING "No compiler warnings set for CXX compiler: '${CMAKE_CXX_COMPILER_ID}'")
    endif()

    target_compile_options(${TargetName} PRIVATE ${WARNINGS_CXX})
endfunction()


function(set_compiler_options TargetName)
    target_compile_features(${TargetName} PRIVATE cxx_std_20)
    _add_warnings(${TargetName})
endfunction()
