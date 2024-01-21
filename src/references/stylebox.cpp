#include "stylebox.hpp"


namespace rre {


    // STYLEBOX =====================
    StyleBox::StyleBox() {
        content_margin = vec4(0);
    }

    StyleBox::~StyleBox() {

    }

    void StyleBox::draw(Rectangle& rect) {
        
    }

    // STYLEBOX =====================
    
    // STYLEBOX FLAT =====================

    StyleBoxFlat::StyleBoxFlat() {
        Color bg_color = Color{100,100,100,255};
        Color border_color = Color{200,200,200,255};
        vec4 border_width = vec4(10.0);
        bool draw_center = true;
        vec4 expand_margin = vec4(0.0);
    }

    StyleBoxFlat::~StyleBoxFlat() {

    }

    void StyleBoxFlat::draw(Rectangle& rect) {
        DrawRectanglePro(rect,Vector2(0,0),0,bg_color);
        DrawRectangleLinesEx(rect,border_width.x,border_color);
    }

    // STYLEBOX FLAT =====================

}