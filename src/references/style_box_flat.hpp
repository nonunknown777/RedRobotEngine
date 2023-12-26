#ifndef STYLE_BOX_FLAT_H
#define STYLE_BOX_FLAT_H

#include "raylib.h"
#include "style_box.hpp"


class StyleBoxFlat : public StyleBox {


public:
    StyleBoxFlat();
    ~StyleBoxFlat();

    Color bg_color;

    void empty() override {};
    

};

#endif