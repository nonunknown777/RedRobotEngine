#pragma once

#include "node.hpp"

namespace rre {
    class CanvasItem : public Node {
        public:
            CanvasItem();
            ~CanvasItem();
            virtual void _draw() = 0;
           

    };
}