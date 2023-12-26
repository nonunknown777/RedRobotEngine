#ifndef POPUP_H
#define POPUP_H

#include "window.hpp"
#include "../references/style_box.hpp"
#include "../references/style_box_flat.hpp"

class Popup : public Window{
public:
    Popup(std::string name);
    ~Popup();

    StyleBox* panel;
};

#endif
