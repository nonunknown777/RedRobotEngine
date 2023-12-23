#ifndef V_BOX_CONTAINER_H
#define V_BOX_CONTAINER_H

#include "control.hpp"

//TODO: Should actually inherit BoxContainer <- Container <- Control
class VBoxContainer : public Control{
public:
    VBoxContainer(std::string name = "VBoxContainer");
    ~VBoxContainer();
};

#endif
