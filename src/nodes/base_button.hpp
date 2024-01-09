#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H

#include "control.hpp"
#include "../references/button_group.hpp"

enum ActionMode {
    ACTION_MODE_BUTTON_PRESS,
    ACTION_MODE_BUTTON_RELEASE
};

class BaseButton : public Control{

public:
    BaseButton(std::string name);
    ~BaseButton();

    ActionMode action_mode;
    ButtonGroup button_group;
    int button_mask;
    bool button_pressed;
    bool disabled;

    void _draw() override;

};

#endif
