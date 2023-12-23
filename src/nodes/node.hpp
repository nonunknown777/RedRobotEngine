#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

#include "raylib.h"

class Node {

    private:
        std::vector<Node*> children;
        // std::vector<Node*> siblings;
        Node* parent;

    public:
        Node(std::string name = "NewNode");
        ~Node();

        std::string name;
        int iteration_index;

        virtual void _ready();
        virtual void _process(float delta);
        // virtual void _physics_process(float delta);
        void add_child(Node* node);
        int get_child_count();
        Node* get_child(int p_index);
        Node* get_parent();
        std::vector<Node*> get_children();
    

};

#endif