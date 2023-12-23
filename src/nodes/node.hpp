#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

#include "raylib.h"
#include "../references/input_event.hpp"

class Node {

    private:
        std::vector<Node*> children;
        // std::vector<Node*> siblings;
        Node* parent;
        std::string name;

    public:
        Node(std::string name = "NewNode");
        ~Node();

        std::string get_name() const;
        virtual void set_name(std::string name);

        int iteration_index;

        virtual void _ready();
        virtual void _process(float delta);
        virtual void _input();
        virtual void _unhandled_input(InputEvent event);
        // virtual void _physics_process(float delta);
        void add_child(Node* node);
        int get_child_count();
        Node* get_child(int p_index);
        Node* get_parent();
        std::vector<Node*> get_children();
    

};

#endif