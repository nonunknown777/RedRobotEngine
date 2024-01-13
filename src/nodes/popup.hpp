#pragma once

#include "common.hpp"


namespace rre {

class Popup : public Window{
public:
    Popup();
    ~Popup();

    StyleBox* panel;
};

}
