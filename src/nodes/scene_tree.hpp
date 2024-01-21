#pragma once

#include <vector>
#include <string>
#include <cstdint>
#include <limits>
#include <map> //TODO: Change to unordered map

#include "node.hpp"
#include "panel.hpp"
#include "utils.hpp"
#include "rendering_server.hpp"

namespace rre {

constexpr uint32_t UMAX = std::numeric_limits<uint32_t>::max();

struct Iteration {
    std::vector<uint32_t> index;

    enum RESERVED {
        TB = 0, // Traverse Top to bottom
        BT = 1, // Traverse Bottom to top
        IE = 2 // Traverse Bottom to top for InputEvent
    };

    Iteration() {
        index = std::vector<uint32_t>(3);
        for (size_t i = 0; i < index.size(); i++)
        {
            index[i] = UMAX;
        }
        
    }

    inline uint32_t& get_index_of_tb() {
        return index[RESERVED::TB];
    }

    inline uint32_t& get_index_of_bt() {
        return index[RESERVED::BT];
    }

    inline uint32_t& get_index_of(size_t at) {
        return index[at];
    }

};

typedef std::map<Node*, Iteration> IterationMap; 

class SceneTree {

    private:
        IterationMap iteration_map;
        Node* get_last_node(Node* from, bool change_iteration_index, size_t iteration_id);
        void add_to_buffer(Node* node);
    public:
        SceneTree();
        ~SceneTree();
        Node* root;
        Node* current_scene;
        void redraw(); //TODO: should be private
        void traverse_bottom_top(FuncPtr<SceneTree, Node*>& action);
        void traverse_bottom_top(FuncPtr<InputEvent, Node*>& action);

        void traverse_top_bottom(FuncPtr<SceneTree, Node*>& action);
        void register_node(Node* node);
};

}
