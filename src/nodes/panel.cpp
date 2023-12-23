#include "panel.hpp"
#include <iostream>

Panel::Panel(std::string name) : Control(name) {
    style_box_flat = new StyleBoxFlat();
}

Panel::~Panel() {
    
}

void Panel::_draw() {
    
    DrawRectangle(position.x,position.y,100,100,style_box_flat->bg_color);
}