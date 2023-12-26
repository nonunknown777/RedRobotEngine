#ifndef PANEL_H
#define PANEL_H

#include "../references/style_box_flat.hpp"
#include "control.hpp"

class Panel : public Control {

public:
    Panel(std::string name = "Panel");
    ~Panel();

    StyleBox* panel;

    void _draw() override;

};

#endif