#include "button.hpp"

Button::Button(std::string name = "Button") : BaseButton(name) {
    size = Vector2(100,40);
    // panel = new StyleBoxFlat();

}

Button::~Button() {
}

void Button::_draw() {
    DrawRectangle(position.x,position.y,size.x,size.y,BLUE);
}