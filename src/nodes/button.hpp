#pragma once

#include "common.hpp"


namespace rre {


class Button : public BaseButton{
public:
    Button();
    ~Button();

    std::string text;

    StyleBox* panel;

    void _draw() override;

};

}
