#ifndef PANEL_H
#define PANEL_H

#include "../references/style_box_flat.hpp"
#include "control.hpp"

class Panel : public Control {

public:
    Panel(std::string name = "Panel");
    ~Panel();

    StyleBoxFlat* style_box_flat;

    void _draw() override;

};

#endif