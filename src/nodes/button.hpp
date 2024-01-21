#pragma once

#include "base_button.hpp"
#include "stylebox.hpp"

namespace rre {

    class Button : public BaseButton {
        private:
            StyleBox* style_normal;
            StyleBox* style_hover;
            StyleBox* style_pressed;
            StyleBox* style_disabled;
            StyleBox* style_focus;
            StyleBox* style_current;
        public:
            Button();
            ~Button();

            std::string text;
            void _draw() override;
            void _input(const InputEvent& event) override;


    };

}