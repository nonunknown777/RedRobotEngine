#pragma once

#include "control.hpp"
#include "stylebox.hpp"

namespace rre {
    class Panel : public Control {
        public:
            Panel();
            ~Panel();

            StyleBox* panel;
            virtual void _draw() override;
    };
}