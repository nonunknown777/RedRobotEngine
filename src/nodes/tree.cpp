#include "tree.hpp"
#include <iostream>
#include "utils.hpp"

#include "temp_data.hpp"
#include "panel.hpp"
#include "v_box_container.hpp"
#include "menu_bar.hpp"
#include "popup_menu.hpp"
#include "button.hpp"

#if DEBUG
#include <cassert>
#endif

SceneTree::SceneTree() {
    draw_buffer = std::vector<FuncRef<Node*>>();
    is_dirty = false;
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
   
    // Window* main_window = root;

    // Node* last = root;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     Panel* panel = new Panel();
    //     last->add_child(panel);
    //     last = panel;
    // }
    

    // Panel* panel = new Panel();
    // ((StyleBoxFlat*)panel->panel)->bg_color = BLACK;
    // panel->position = Vector2(0,0);
    // panel->size = Vector2(GetScreenWidth(),GetScreenHeight());

    // main_window->add_child(panel);

    // Button* button = new Button("Test");

    // panel->add_child(button);

    
    

    //End


    current_scene = nullptr;
}

SceneTree::~SceneTree() {
    free(root);
}


void SceneTree::action(Node* node, const float& delta) {
    node->_process(delta);

}

inline void action_down(Node* node) {

    node->_input();
    if (node->visible) node->_draw();
    // Control* control = dynamic_cast<Control*>(node);

    // if (control != nullptr) control->_draw();
}


//The tree will call _draw() for Control derived nodes when checking down
// and will call _process for all Nodes when going up

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
        // std::cout << "name: " << current->name << "\n";

        if (!is_first) {
            if (current == root && up == true) {
                action_down(current);
                break;
            }
            auto the_parent = current->get_parent();
            if (the_parent == root) {
                if (current->iteration_index+1 < current->get_child_count()) {
                    if (up == false) action_down(current);
                    current->iteration_index++;
                    current = current->get_child(current->iteration_index);
                    continue;
                } else {
                    action(current, delta);
                    current->iteration_index = -1;
                    if (up == false) {
                        action_down(current);
                        current = current->get_parent();
                        up = true;
                        continue;
                    } else {
                        current= current->get_parent();
                        current->iteration_index = -1;
                        continue;
                    }
                    
                }
            }
        }

        if (current->get_child_count() == 0) {

            
            if (up == false) action_down(current);
            action(current, delta);
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
                action(current, delta);
                current->iteration_index = -1;
                current = current->get_parent();
                continue;
            }

        }

        if (up == false) action_down(current);

        // Node* old = current;
        current->iteration_index++;
        current = current->get_child(current->iteration_index);
        is_first = false;
        // old->iteration_index = -1;

    }

    // std::cout << result + "\n";
    TIMER_END("update");

}

void SceneTree::traverse_bottom_top(FuncRef<Node*> action) {

    Node* current = get_last_node(root,true); //this already set iteration index, so its easy to traverse now
    action(current);
    current = current->get_parent();
    bool is_going_up = true;

    while(current != nullptr) {
        //if its in the root node;
        if (current->get_parent() == nullptr && is_going_up) {
            current->iteration_index--;

            if (current->iteration_index == -1) {
                action(current);
                break;
            }

            is_going_up = false;
            current = get_last_node(current->get_child(current->iteration_index), true);
            continue;
        }
        if (is_going_up) {
            if (current->iteration_index == current->get_child_count()-1) {
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


Node* SceneTree::get_last_node(Node* from, bool change_iteration_index) {
    TIMER_START();
    if (from->get_child_count() == 0) return from;

    Node* current = from->get_child(from->get_child_count()-1);

    if (change_iteration_index)
        current->get_parent()->iteration_index = current->get_parent()->get_child_count()-1;

    while(current->get_child_count() != 0) {
        current = current->get_child(current->get_child_count()-1);
        if (change_iteration_index) current->get_parent()->iteration_index = current->get_parent()->get_child_count()-1;
    }

    TIMER_END_PRINT("get_last_node");
    return current;
}