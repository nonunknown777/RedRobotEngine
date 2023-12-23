#include "popup_menu.hpp"

PopupMenu::PopupMenu(std::string name = "PopupMenu") : Popup(name) {
}

PopupMenu::~PopupMenu() {
}

void PopupMenu::_process(float delta) {
    DrawText(name.c_str(), 0,0,16,GRAY);
}