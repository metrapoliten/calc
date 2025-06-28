cmake_minimum_required(VERSION 3.21)
project(calc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
add_link_options("-fuse-ld=lld")

find_package(Slint QUIET)
if (NOT Slint_FOUND)
    message("Slint could not be located in the CMake module search path. Downloading it from Git and building it locally")
    include(FetchContent)
    FetchContent_Declare(
            Slint
            GIT_REPOSITORY https://github.com/slint-ui/slint.git
            # `release/1` will auto-upgrade to the latest Slint >= 1.0.0 and < 2.0.0
            # `release/1.0` will auto-upgrade to the latest Slint >= 1.0.0 and < 1.1.0
            GIT_TAG release/1
            SOURCE_SUBDIR api/cpp
    )
    FetchContent_MakeAvailable(Slint)
endif (NOT Slint_FOUND)

add_executable("${PROJECT_NAME}")
add_subdirectory(src)
target_compile_options(Slint INTERFACE -Wno-shadow-field-in-constructor)
target_link_libraries(calc PRIVATE Slint::Slint)
slint_target_sources(calc ui/ui.slint)
# On Windows, copy the Slint DLL next to the application binary so that it's found.
if (WIN32)
    add_custom_command(TARGET my_application POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:my_application> $<TARGET_FILE_DIR:my_application> COMMAND_EXPAND_LISTS)
endif ()