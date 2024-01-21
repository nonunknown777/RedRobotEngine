#include "base_button.hpp"

namespace rre {

    BaseButton::BaseButton() {
        toggle_mode = false;
        disabled = false;
        button_pressed = false;
    }

    BaseButton::~BaseButton() {

    }
}