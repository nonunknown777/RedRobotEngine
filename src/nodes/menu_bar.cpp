#include "menu_bar.hpp"

MenuBar::MenuBar(std::string name) : Control(name) {
}

MenuBar::~MenuBar() {
}

void MenuBar::set_name(std::string name) {
    Control::set_name(name);
    size = Vector2(MeasureText(get_name().c_str(),16),size.y);
}