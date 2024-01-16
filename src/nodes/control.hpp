#pragma once

#include "canvas_item.hpp"
#include "glm/vec4.hpp"
#include "glm/vec2.hpp"

using namespace glm;



namespace rre {

    enum MouseFilter {
        STOP = 0,
        PASS,
        IGNORE
    };

    class Control : public CanvasItem {
        public:
            Control();
            ~Control();

            vec4 anchors;
            vec2 min_size;
            vec2 global_position;
            MouseFilter mouse_filter;
            vec4 offset;
            vec2 pivot_offset;
            vec2 position;
            float rotation_degrees;
            vec2 scale;
            vec2 size;
            std::string tooltip;

            void _draw() override {};




    };
}