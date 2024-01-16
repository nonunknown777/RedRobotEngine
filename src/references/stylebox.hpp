#pragma once

//TODO: Change This to a union of all styleboxes possible

#include "resource.hpp"
#include "glm/vec4.hpp"
#include "raylib.h"

using namespace glm;

namespace rre {

    class StyleBox : public Resource {
        public:
            StyleBox();
            ~StyleBox();

        vec4 content_margin;
        

    };

    class StyleBoxFlat : public StyleBox {
        public:
            StyleBoxFlat();
            ~StyleBoxFlat();

        
            Color bg_color;
            Color border_color;
            vec4 border_width;
            bool draw_center;
            vec4 expand_margin;
    
    };

    class StyleBoxEmpty : public StyleBox {

    };

    class StyleBoxLine : public StyleBox {

    };

    class StyleBoxTexture : public StyleBox {

    };

}