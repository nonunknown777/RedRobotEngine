#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <stdexcept>
#include <iostream>

#include "input_event.hpp"

namespace rre {

class SceneTree;

class Node {

    private:
        std::vector<Node*> children;
        // std::vector<Node*> siblings;
        Node* parent;
        std::string name;
        SceneTree* tree;
    public:
        Node();
        Node(const std::string& name);
        ~Node();

        std::string get_name() const;
        virtual void set_name(std::string name);
        // SceneTree* tree;

        bool visible = true;
        virtual void _ready();
        virtual void _process(float delta);
        virtual void _input(const InputEvent& event);


        // virtual void _physics_process(float delta);
        void add_child(Node* node);
        uint32_t get_child_count();
        SceneTree* get_tree();
        void set_tree(SceneTree* tree);
        Node* get_child(int p_index);
        Node* get_parent();
        std::vector<Node*> get_children();
    

};

}
