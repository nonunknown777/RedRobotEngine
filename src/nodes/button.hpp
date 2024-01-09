#ifndef BUTTON_H
#define BUTTON_H

#include "base_button.hpp"
#include "../references/style_box.hpp"
#include "../references/style_box_flat.hpp"

class Button : public BaseButton{
public:
    Button(std::string name);
    ~Button();

    std::string text;

    StyleBox* panel;

    void _draw() override;

};

#endif
