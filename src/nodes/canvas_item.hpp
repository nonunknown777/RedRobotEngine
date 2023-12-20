#ifndef CANVAS_ITEM_H
#define CANVAS_ITEM_H

#include "node.hpp"

class CanvasItem : public Node {
    public:
        CanvasItem(std::string name = "CanvasItem") : Node(name) {};
        ~CanvasItem();
};

#endif