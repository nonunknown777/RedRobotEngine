#include "tree.hpp"

namespace rre {


SceneTree::SceneTree() {
    draw_buffer = std::vector<FuncRef<Node*>>();
    iteration_system = IterationSystem();

    
    root = new Node("0");
    // root->tree = this;

    auto node1 = new Node("1");
    root->add_child(node1);
    auto node2 = new Node("2");
    node1->add_child(node2);
    auto node3 = new Node("3");
    root->add_child(node3);
    auto node4 = new Node("4");
    node3->add_child(node4);
    auto node5 = new Node("5");
    root->add_child(node5);
    auto node6 = new Node("6");
    node5->add_child(node6);

    auto test = [](Node* current){
        std::cout << "iterated at: " << current->get_name() << "\n";
    };

    traverse_bottom_top(test);
    // traverse_top_bottom(test);

    current_scene = nullptr;
}

SceneTree::~SceneTree() {
    free(root);
}

void SceneTree::register_node(Node* node) {
    Iteration iteration = Iteration();
    iteration_system.emplace(node, iteration);
}


void SceneTree::traverse_bottom_top(FuncRef<Node*> action) {

    Node* current = get_last_node(root,true); //this already set iteration index, so its easy to traverse now
    action(current);
    current = current->get_parent();
    bool is_going_up = true;

    while(current != nullptr) {
        //if its in the root node;
        if (current->get_parent() == nullptr && is_going_up) {
            
            iteration_system[current].get_index_of_bt()--;

            if (iteration_system[current].get_index_of_bt() == UMAX) {
                action(current);
                break;
            }

            is_going_up = false;
            current = get_last_node(current->get_child(iteration_system[current].get_index_of_bt()), true);
            continue;
        }
        if (is_going_up) {
            if (iteration_system[current].get_index_of_bt() == current->get_child_count()-1) {
                action(current);
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

}

void SceneTree::traverse_top_bottom(FuncRef<Node*> action) {

    // Node* current = root;



}


Node* SceneTree::get_last_node(Node* from, bool change_iteration_index) {
    TIMER_START();
    if (from->get_child_count() == 0) return from;

    Node* current = from->get_child(from->get_child_count()-1);

    if (change_iteration_index)
        iteration_system[current->get_parent()].get_index_of_bt() = current->get_parent()->get_child_count()-1;

    while(current->get_child_count() != 0) {
        current = current->get_child(current->get_child_count()-1);
        if (change_iteration_index) iteration_system[current->get_parent()].get_index_of_bt() = current->get_parent()->get_child_count()-1;
    }

    TIMER_END_PRINT("get_last_node");
    return current;
}

}
