#ifndef STYLE_BOX_H
#define STYLE_BOX_H

#include "resource.hpp"

class StyleBox : public Resource{

public:
    StyleBox();
    ~StyleBox();

    float content_margin_bottom = -1;
    float content_margin_up = -1;
    float content_margin_left = -1;
    float content_margin_right = -1;

    virtual void empty() {};

};

#endif