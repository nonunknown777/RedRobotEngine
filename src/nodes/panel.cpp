#include "panel.hpp"
#include <iostream>
#include "../references/style_box_flat.hpp"

Panel::Panel(std::string name) : Control(name) {
    panel = new StyleBoxFlat();
    StyleBoxFlat* flat = (StyleBoxFlat*)panel;
    flat->bg_color = BLUE;
    visible = true;
}

Panel::~Panel() {
    
}

void Panel::_draw() {
    DrawRectangle(position.x,position.y,size.x,size.y,((StyleBoxFlat*)panel)->bg_color);
    Control::_draw();
}