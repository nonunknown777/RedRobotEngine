#pragma once

//TODO: Change This to a union of all styleboxes possible

#include "resource.hpp"
#include "glm/vec4.hpp"
#include "raylib.h"
#include <type_traits>

using namespace glm;

namespace rre {

    class StyleBox : public Resource {
        public:
            StyleBox();
            ~StyleBox();

            virtual void draw(Rectangle& rect);

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

            void draw(Rectangle& rect) override;
    
    };

    // class StyleBoxEmpty : public StyleBox {
    //     public:
    //         void draw(Rectangle& rect) override;

    // };

    // class StyleBoxLine : public StyleBox {
    //     public:
    //         void draw(Rectangle& rect) override;


    // };

    // class StyleBoxTexture : public StyleBox {
    //     public:
    //         void draw(Rectangle& rect) override;


    // };


    template<class C>
    C* get_style(StyleBox* style_box) {
        return ((C*)style_box);
    }

}