#pragma once

#include "control.hpp"

namespace rre {

    class BaseButton : public Control {
        public:
            BaseButton();
            ~BaseButton();

            bool button_pressed;
            bool disabled;
            bool toggle_mode;
    };

}