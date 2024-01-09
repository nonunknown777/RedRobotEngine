#ifndef TREE_H
#define TREE_H

#include "node.hpp"
#include "window.hpp"
#include "utils.hpp"

class SceneTree {

    private:
        std::vector<FuncRef<Node*>> draw_buffer;
        Node* get_last_node(Node* from, bool change_iteration_index);
        bool is_dirty;
    public:
        SceneTree();
        ~SceneTree();
        Node* root;
        Node* current_scene;

        void update(float delta);
        void action(Node* node, const float& delta);
        void traverse_bottom_top(FuncRef<Node*> action);
};

#endif