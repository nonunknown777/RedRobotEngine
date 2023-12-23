#include "control.hpp"

Control::Control(std::string name) : CanvasItem(name) {
    position = Vector2(0,0);
}

Control::~Control() {
    
}