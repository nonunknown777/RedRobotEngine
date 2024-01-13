#pragma once

#include "common.hpp"

namespace rre {

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

}