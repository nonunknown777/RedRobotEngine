#include "panel.hpp"

namespace rre {
    
    Panel::Panel() {
        panel = new StyleBoxFlat();
    }

    Panel::~Panel() {
        free(panel);
    }

    void Panel::_draw() {
        Rectangle rect = Rectangle(position.x, position.y, size.x, size.y);
        panel->draw(rect);
    }
}