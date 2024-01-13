#include "popup_menu.hpp"

namespace rre {


PopupMenu::PopupMenu() {
    position = Vector2(0,0);
    size = Vector2(100,40);
    
    visible = false;
}

PopupMenu::~PopupMenu() {
}

void PopupMenu::_process(float delta) {
    DrawText(get_name().c_str(), 0,0,16,GRAY);
}

void PopupMenu::_input() {

    if (CheckCollisionPointRec(GetMousePosition(), Rectangle(position.x,position.y,size.x,size.y))) {
        // std::cout << "hello world\n";
    }
}

}
