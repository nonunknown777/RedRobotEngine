#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "node.hpp"

class Viewport : public Node {
    public:
        Viewport(std::string name = "Viewport") : Node(name) {};
        ~Viewport();
};

#endif