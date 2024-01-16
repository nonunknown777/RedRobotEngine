#include "panel.hpp"

namespace rre {
    
    Panel::Panel() {
        panel = new StyleBoxFlat();
    }

    Panel::~Panel() {
        free(panel);
    }

    void Panel::_draw() {
        DrawRectangle((int)position.x,(int)position.y,(int)size.x,(int)size.y,((StyleBoxFlat*)panel)->bg_color);
    }
}