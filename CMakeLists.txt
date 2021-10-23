cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(Repin VERSION 1.0)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -O2")


set(TOOLS_SOURCE Tools/utils.cpp Tools/vector2.cpp)
add_library(Tools STATIC ${TOOLS_SOURCE})

set(GRAPHICS_SOURCE Graphics/Clock/clock.cpp
                    Graphics/Color/color.cpp
                    Graphics/Events/events.cpp
                    Graphics/Primitives/primitives.cpp
                    Graphics/RenderTarget/render_target.cpp
                    Graphics/RenderTexture/render_texture.cpp
                    Graphics/RenderWindow/render_window.cpp
                    )


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)


MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.hpp)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()


HEADER_DIRECTORIES(header_dir_list)
list(LENGTH header_dir_list header_dir_list_count)
message(STATUS "[INFO] Found ${header_dir_list_count} header directories: ${header_dir_list}.")
include_directories(${header_dir_list} Graphics/Primitives/)

add_library(Graphics STATIC ${GRAPHICS_SOURCE})

target_link_libraries(Graphics PUBLIC Tools)