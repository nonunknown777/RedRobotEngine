#pragma once

#include "common.hpp"

namespace rre {

class StyleBoxFlat : public StyleBox {


public:
    StyleBoxFlat();
    ~StyleBoxFlat();

    Color bg_color;

    void empty() override {};
    

};

}