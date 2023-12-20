#include "tree.hpp"
#include <iostream>
#include "utils.hpp"

#include "temp_data.hpp"

SceneTree::SceneTree() {
    root = new Window("MainWindow");

    //Create the editor
    Window* main_window = root;
    main_window->size = WINDOW_SIZE;
    
    main_window->flags |= ImGuiWindowFlags_NoDecoration;
    main_window->flags |= ImGuiWindowFlags_NoMove;
    main_window->flags |= ImGuiWindowFlags_MenuBar;


    //End


    current_scene = nullptr;
}

SceneTree::~SceneTree() {
    free(root);
}

void SceneTree::simulate_children() {


    Node* node_a = new Node("A");
    Node* node_c = new Node("C");
    Node* node_b = new Node("B");
    Node* node_d = new Node("D");
    Node* node_e = new Node("E");
    Node* node_f = new Node("F");
    Node* node_g = new Node("G");
    Node* node_h = new Node("H");
    Node* node_i = new Node("I"); 

    root->add_child(node_a);
    node_a->add_child(node_b);
    node_b->add_child(node_d);
    node_d->add_child(node_e);
    node_a->add_child(node_g);
    node_g->add_child(node_h);
    node_g->add_child(node_i);
    node_i->add_child(node_c);
    node_c->add_child(node_f);

}

/*

        output must be:
         
        E
        D
        B
        H
        F
        C
        I
        G
        A
*/
void SceneTree::update(float delta) {
    TIMER_START();

    // std::string result = "Result: ";

    Node* current = root;

    if (current == nullptr) return;

    bool is_first = true;
    bool up = false;

    // current->iteration_index = 0;

    while(true)
    {
        std::cout << "name: " << current->name << "\n";

        if (!is_first) {
            if (current->get_parent() == root) {
                if (current->iteration_index+1 < current->get_child_count()) {
                    current->iteration_index++;
                    current = current->get_child(current->iteration_index);
                    continue;
                } else {
                    current->_process(delta);
                    // result += current->name + ", ";
                    current->iteration_index = -1;
                    break; // finished traversing tree;
                }
            }
        }

        if (current->get_child_count() == 0) {

            

            current->_process(delta);
            // result += current->name + ", ";
            current->iteration_index = -1; //reset index
            
            if (is_first) break;
            
            current = current->get_parent();
            up = true;


            continue;
        } else if (up) {
            
            if ( current->iteration_index+1 < current->get_child_count() ) {
                current->iteration_index++;// 0 - 1
                current = current->get_child(current->iteration_index);
                continue;
            } else {
                current->_process(delta);
                // result += current->name + ", ";
                current->iteration_index = -1;
                current = current->get_parent();
                continue;
            }

        }

        current->iteration_index++;
        current = current->get_child(current->iteration_index);
        is_first = false;

    }

    // std::cout << result + "\n";
    TIMER_END("update");

}