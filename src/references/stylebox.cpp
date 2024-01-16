#include "stylebox.hpp"


namespace rre {


    // STYLEBOX =====================
    StyleBox::StyleBox() {
        content_margin = vec4(0);
    }

    StyleBox::~StyleBox() {

    }

    // STYLEBOX =====================
    
    // STYLEBOX FLAT =====================

    StyleBoxFlat::StyleBoxFlat() {
        Color bg_color = Color{100,100,100,255};
        Color border_color = Color{200,200,200,255};
        vec4 border_width = vec4(1.0);
        bool draw_center = true;
        vec4 expand_margin = vec4(0.0);
    }

    StyleBoxFlat::~StyleBoxFlat() {

    }

    // STYLEBOX FLAT =====================

}