#include "control.hpp"

namespace rre {
    Control::Control() {

        anchors = vec4(0);
        min_size = vec2(0);
        global_position = vec2(0);
        mouse_filter = MouseFilter::PASS;
        offset = vec4(0);
        pivot_offset = vec2(0);
        position = vec2(0);
        rotation_degrees = 0.0;
        scale = vec2(1);
        size = vec2(40);
        tooltip = "";
    }

    Control::~Control() {
        
    }

    
}