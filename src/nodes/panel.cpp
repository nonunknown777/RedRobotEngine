#include "panel.hpp"
#include <iostream>

Panel::Panel(std::string name) : Control(name) {
    style_box_flat = new StyleBoxFlat();
    size = Vector2(100,100);
}

Panel::~Panel() {
    
}

void Panel::_draw() {
    DrawRectangle(position.x,position.y,size.x,size.y,style_box_flat->bg_color);
    Control::_draw();
}