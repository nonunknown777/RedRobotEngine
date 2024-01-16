#include "scene_tree.hpp"
#include <iostream>

namespace rre {


SceneTree::SceneTree() {
    iteration_map = IterationMap();

    
    root = new Node("0");
    root->set_tree(this);
    // root->tree = this;

    auto node1 = new Panel();
    node1->set_name("Panel");
    node1->set_tree(this);
    node1->size = vec2(40,40);
    ((StyleBoxFlat*)node1->panel)->bg_color = Color(RED);
    root->add_child(node1);

    auto node2 = new Panel();
    node2->set_name("Panel2");
    node2->set_tree(this);
    node2->size = vec2(20,20);
    ((StyleBoxFlat*)node2->panel)->bg_color = Color(BLUE);
    node1->add_child(node2);

    auto node3 = new Node("3");
    root->add_child(node3);
    node3->set_tree(this);
    auto node4 = new Node("4");
    node3->add_child(node4);
    node4->set_tree(this);
    auto node5 = new Node("5");
    root->add_child(node5);
    node5->set_tree(this);
    auto node6 = new Node("6");
    node5->add_child(node6);
    node6->set_tree(this);

    register_node(root);
    register_node(node1);
    register_node(node2);
    register_node(node3);
    register_node(node4);
    register_node(node5);
    register_node(node6);


    auto add_to_buffer = [](Node* node){
        std::cout << "checking for register: " << node->get_name() << "\n";
        if (CanvasItem* canvas_item = dynamic_cast<CanvasItem*>(node)) {
            std::cout << "registering canvas_item into buffer: " << node->get_name() << "\n\n";
           RenderingServer::get_singleton().register_into_buffer(0, canvas_item);
        }
    };

    traverse_bottom_top(add_to_buffer);

    

    current_scene = nullptr;
}

SceneTree::~SceneTree() {
    free(root);
}

void SceneTree::register_node(Node* node) {
    Iteration iteration = Iteration();
    iteration_map.emplace(node, iteration);
}


void SceneTree::traverse_bottom_top(FuncRef<Node*> action) {

    Node* current = get_last_node(root,true); //this already set iteration index, so its easy to traverse now
    action(current);
    current = current->get_parent();
    bool is_going_up = true;

    #define iteration_index(node) iteration_map[node].get_index_of_bt()
    #define iteration_set_default(node) iteration_index(node) = UMAX;

    while(current != nullptr) {
        //if its in the root node;
        if (current->get_parent() == nullptr && is_going_up) {
            
            iteration_index(current)--;

            if (iteration_index(current) == UMAX) {
                action(current);
                break;
            }

            is_going_up = false;
            current = get_last_node(current->get_child(iteration_index(current)), true);
            continue;
        }
        if (is_going_up) {
            if (iteration_index(current) == current->get_child_count()-1) {
                action(current);
                iteration_set_default(current);
                current = current->get_parent();
                continue;
            }
            current = current->get_parent();
        } else {
            action(current);
            current = current->get_parent();
            is_going_up = true;
        }
    }

    #undef iteration_index

}

void SceneTree::traverse_top_bottom(FuncRef<Node*> action) {

    Node* current = root;

    #define iteration_index(node) iteration_map[node].get_index_of_tb()
    #define iteration_not_used(node) iteration_index(node) == UMAX
    #define iteration_set_default(node) iteration_index(node) = UMAX;

    while(true) {

        if (iteration_not_used(current)) {
            iteration_index(current) = 0;
            action(current);
            if (iteration_index(current) >= current->get_child_count()) {
                //reached a node with no children
                iteration_set_default(current);
                current = current->get_parent();
                continue;
            } else {
                Node* old = current;
                current = current->get_child(iteration_index(current));
                iteration_index(old)++;
                continue;
            }
        }
        uint32_t index = iteration_index(current);
        if (index < current->get_child_count()) {
            iteration_index(current)++;
            current = current->get_child(iteration_index(current)-1);
            continue;
        } else
        {
            //has no more children to iteration
            iteration_set_default(current);

            if (current == root) {
                std::cout << "finished";
                break;
            }

            current = current->get_parent();
        }
    }

    #undef iteration_index
    #undef iteration_set_default
    #undef iteration_not_used



}


Node* SceneTree::get_last_node(Node* from, bool change_iteration_index) {
    // TIMER_START();
    if (from->get_child_count() == 0) return from;

    Node* current = from->get_child(from->get_child_count()-1);

    if (change_iteration_index)
        iteration_map[current->get_parent()].get_index_of_bt() = current->get_parent()->get_child_count()-1;

    while(current->get_child_count() != 0) {
        current = current->get_child(current->get_child_count()-1);
        if (change_iteration_index) iteration_map[current->get_parent()].get_index_of_bt() = current->get_parent()->get_child_count()-1;
    }

    // TIMER_END_PRINT("get_last_node");
    return current;
}

void SceneTree::redraw() {
    RenderingServer::get_singleton().update();
}

}
