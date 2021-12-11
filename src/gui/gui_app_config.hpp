#ifndef GUI_APP_CONFIG_HPP
#define GUI_APP_CONFIG_HPP


#include "glib_tools.hpp"


namespace gui {
  static const int APP_WIDTH             = 1200;
  static const int APP_HEIGHT            = 800;
  static const int CANVAS_DEFAULT_WIDTH  = 800;
  static const int CANVAS_DEFAULT_LENGTH = 600;

  static const char* AQUA_SKIN_FOLDER_PATH = "Skins/aqua";

  static const int WINDOW_SHADOW_THICKNESS = 2;
  static const glib::Vector2i WINDOW_SHADOW_SIZE(WINDOW_SHADOW_THICKNESS,
                                                 WINDOW_SHADOW_THICKNESS);
}


#endif /* gui_app_config.hpp */
