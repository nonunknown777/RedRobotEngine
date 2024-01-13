#pragma once

//General file with all includes

#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <array>
#include <map>
#include <thread>
#include <stdexcept>

#include "raylib.h"
#include "raymath.h"

namespace rre {

class Resource;
class InputEvent;
class ResourceLoader;
class ButtonGroup;
class StyleBox;
class StyleBoxFlat;
class Theme;
class Node;
class Viewport;
class Window;
class CanvasItem;
class Control;
class Panel;
class Popup;
class PopupMenu;
class MenuBar;
class BaseButton;
class Button;
class VBoxContainer;
class SceneTree;

}

#include "utils.hpp"
#include "temp_data.hpp"

#include "resource.hpp"
#include "input_event.hpp"
#include "resource_loader.hpp"
#include "button_group.hpp"
#include "style_box.hpp"
#include "style_box_flat.hpp"
#include "theme.hpp"

#include "node.hpp"
#include "viewport.hpp"
#include "window.hpp"
#include "canvas_item.hpp"
#include "control.hpp"

#include "panel.hpp"
#include "popup.hpp"
#include "popup_menu.hpp"
#include "menu_bar.hpp"
#include "base_button.hpp"
#include "button.hpp"
#include "v_box_container.hpp"

#include "tree.hpp"
