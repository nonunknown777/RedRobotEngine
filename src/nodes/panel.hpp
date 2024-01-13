#pragma once

#include "common.hpp"

namespace rre {


class Panel : public Control {

public:
    Panel();
    ~Panel();

    StyleBox* panel;

    void _draw() override;

};

}
