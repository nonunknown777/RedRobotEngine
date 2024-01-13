#pragma once

#include "common.hpp"


namespace rre {


//TODO: Should actually inherit BoxContainer <- Container <- Control
class VBoxContainer : public Control{
public:
    VBoxContainer();
    ~VBoxContainer();
};

}

