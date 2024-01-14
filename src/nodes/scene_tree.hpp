#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <limits>
#include <map> //TODO: Change to unordered map

#include "node.hpp"
#include "utils.hpp"

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

    inline uint32_t& get_index_of_tb() {
        return index[0];
    }

    inline uint32_t& get_index_of_bt() {
        return index[1];
    }

    inline uint32_t& get_index_of(size_t at) {
        return index[at];
    }

};

typedef std::map<Node*, Iteration> IterationMap;

class SceneTree {

    private:
        std::vector<FuncRef<Node*>> draw_buffer;
        IterationMap iteration_map;
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
