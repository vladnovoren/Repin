cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(Repin VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)

add_compile_options(
    -O2

    -g
    -fsanitize=address

    -Werror
    -Wall
    -Wextra
    -Wpedantic
)

add_link_options(
    -fsanitize=address
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(GLIB_SOURCE src/glib/glib_clock/glib_clock.cpp
                src/glib/glib_color/glib_color.cpp
                src/glib/glib_events/glib_events.cpp
                src/glib/glib_primitives/glib_primitives.cpp
                src/glib/glib_render_target/glib_render_target.cpp
                src/glib/glib_render_texture/glib_render_texture.cpp
                src/glib/glib_render_window/glib_render_window.cpp
                src/glib/glib_texture/glib_texture.cpp
                src/glib/glib_tools/glib_tools.cpp
                src/glib/glib_text/glib_text.cpp
                src/glib/glib_font/glib_font.cpp
)

set(GUI_SOURCE src/gui/gui_abstract_widget/gui_abstract_widget.cpp
               src/gui/gui_abstract_widget/gui_abstract_widget_functor.cpp
               src/gui/gui_abstract_widget/gui_abstract_widget_skin.cpp
               src/gui/gui_button/gui_button.cpp
               src/gui/gui_button/gui_button_skin.cpp
               src/gui/gui_skin_manager/gui_skin_manager.cpp
               src/gui/gui_widget_manager/gui_widget_manager.cpp
               src/gui/gui_window/gui_title_bar/gui_title.cpp
               src/gui/gui_window/gui_title_bar/gui_title_bar.cpp
               src/gui/gui_window/gui_title_bar/gui_title_bar_skin.cpp
               src/gui/gui_window/gui_window.cpp
               src/gui/gui_window/gui_window_skin.cpp
               src/gui/gui_event_system/gui_events.cpp
               src/gui/gui_abstract_container_widget/gui_abstract_container_widget.cpp
               src/gui/gui_drag/gui_move_functor.cpp
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

add_executable(TestFontText Test/test_my_font_text.cpp)

target_link_libraries(glib PUBLIC sfml-graphics)
target_link_libraries(gui PUBLIC glib)
target_link_libraries(Repin PUBLIC gui)
target_link_libraries(TestFontText PUBLIC glib)
target_link_libraries(TestFontText PUBLIC gui)
