#pragma once

#include "common.hpp"


namespace rre {

constexpr uint32_t UMAX = std::numeric_limits<uint32_t>::max();

struct Iteration {
    std::vector<uint32_t> index;

    Iteration() {
        index = std::vector<uint32_t>(3);
        for (size_t i = 0; i < index.size(); i++)
        {
            index[i] = UMAX;
        }
        
    }

    uint32_t& get_index_of_tp() {
        return index[0];
    }

    uint32_t& get_index_of_bt() {
        return index[1];
    }

    uint32_t& get_index_of(size_t at) {
        return index[at];
    }

};

typedef std::map<Node*, Iteration> IterationSystem;

class SceneTree {

    private:
        std::vector<FuncRef<Node*>> draw_buffer;
        IterationSystem iteration_system;
        Node* get_last_node(Node* from, bool change_iteration_index);
    public:
        SceneTree();
        ~SceneTree();
        Node* root;
        Node* current_scene;

        void traverse_bottom_top(FuncRef<Node*> action);
        void traverse_top_bottom(FuncRef<Node*> action);
        void register_node(Node* node);
};

}
