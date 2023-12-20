#ifndef TREE_H
#define TREE_H

#include "node.hpp"
#include "window.hpp"

class SceneTree {

    public:
        SceneTree();
        ~SceneTree();
        Window* root;
        Node* current_scene;

        void simulate_children();
        void update(float delta);
};

#endif