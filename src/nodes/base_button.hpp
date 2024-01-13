#pragma once

#include "common.hpp"

namespace rre {


enum ActionMode {
    ACTION_MODE_BUTTON_PRESS,
    ACTION_MODE_BUTTON_RELEASE
};

class BaseButton : public Control{

public:
    BaseButton();
    ~BaseButton();

    ActionMode action_mode;
    ButtonGroup button_group;
    int button_mask;
    bool button_pressed;
    bool disabled;

    void _draw() override;

};

}
