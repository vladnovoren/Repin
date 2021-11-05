cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(Repin VERSION 1.0)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -O2")


set(GLIB_SOURCE glib/glib_clock/glib_clock.cpp
                glib/glib_color/glib_color.cpp
                glib/glib_events/glib_events.cpp
                glib/glib_primitives/glib_primitives.cpp
                glib/glib_render_target/glib_render_target.cpp
                glib/glib_render_texture/glib_render_texture.cpp
                glib/glib_render_window/glib_render_window.cpp
                glib/glib_texture/glib_texture.cpp
                glib/glib_tools/glib_tools.cpp
)

set(GUI_SOURCE gui/gui_events/gui_events.cpp
               gui/gui_view/gui_view.cpp
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
include_directories(${header_dir_list})

add_library(glib STATIC ${GLIB_SOURCE})
add_library(gui STATIC ${GUI_SOURCE})

target_link_libraries(gui PUBLIC glib)