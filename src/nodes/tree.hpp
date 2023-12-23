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

        void update(float delta);
        void action(Node* node, const float& delta);
};

#endif