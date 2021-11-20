cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(Repin VERSION 1.0)

# set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -O2")
set(CMAKE_CXX_FLAGS "-g -fsanitize=address -Wall -Wextra -Werror -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(GLIB_SOURCE src/glib/glib_clock/glib_clock.cpp
                src/glib/glib_color/glib_color.cpp
                src/glib/glib_events/glib_convert_events.cpp
                src/glib/glib_events/glib_events.cpp
                src/glib/glib_primitives/glib_primitives.cpp
                src/glib/glib_render_target/glib_render_target.cpp
                src/glib/glib_render_texture/glib_render_texture.cpp
                src/glib/glib_render_window/glib_render_window.cpp
                src/glib/glib_texture/glib_texture.cpp
                src/glib/glib_tools/glib_tools.cpp
)

set(GUI_SOURCE src/gui/gui_abstract_view/gui_abstract_view.cpp
               src/gui/gui_abstract_view/gui_abstract_view_functor.cpp
               src/gui/gui_abstract_view/gui_default_view_skin.cpp
               src/gui/gui_button/gui_button.cpp
               src/gui/gui_button/gui_button_skin.cpp
               src/gui/gui_event_emitter/gui_event_emitter.cpp
               src/gui/gui_skin_manager/gui_skin_manager.cpp
               src/gui/gui_view_manager/gui_view_manager.cpp
               src/gui/gui_drag_area/gui_drag_area.cpp
               src/gui/gui_drag_area/gui_drag_area_functor.cpp
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

add_executable(Repin src/app.cpp)

target_link_libraries(glib PUBLIC sfml-graphics)
target_link_libraries(gui PUBLIC glib)
target_link_libraries(Repin PUBLIC gui)
