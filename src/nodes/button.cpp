

#include "button.hpp"

namespace rre {


Button::Button(){
    size = Vector2(100,40);
    // panel = new StyleBoxFlat();

}

Button::~Button() {
}

void Button::_draw() {
    DrawRectangle(position.x,position.y,size.x,size.y,BLUE);
}

}
