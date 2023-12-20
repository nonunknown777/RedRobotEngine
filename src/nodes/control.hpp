#ifndef CONTROL_H
#define CONTROL_H

#include "canvas_item.hpp"

class Control : public CanvasItem {
    public:
        Control(std::string name = "Control") : CanvasItem(name) {};
        ~Control();
};

#endif