#include "control.hpp"
#include "utils.hpp"

Control::Control(std::string name) : CanvasItem(name) {
    position = Vector2(0,0);
    // Node* parent = get_parent();

    size = Vector2(GetScreenWidth(), GetScreenHeight());


}

Control::~Control() {
    
}

void Control::_draw() {
    #if DEBUG
    DrawRectangleLinesEx(Rectangle(position.x,position.y,size.x,size.y),2,RED);
    #endif
}