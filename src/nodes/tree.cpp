#include "tree.hpp"
#include <iostream>
#include "utils.hpp"

#include "temp_data.hpp"
#include "panel.hpp"
#include "v_box_container.hpp"
#include "menu_bar.hpp"
#include "popup_menu.hpp"

SceneTree::SceneTree() {
    root = new Window("MainWindow");

    //Create the editor
    Window* main_window = root;

    Panel* panel = new Panel();
    panel->style_box_flat->bg_color = DARKGRAY;
    panel->position = Vector2(0,0);
    
    main_window->add_child(panel);

    VBoxContainer* vbox = new VBoxContainer();
    vbox->size = Vector2(40,40);
    panel->add_child(vbox);

    MenuBar* menu_bar = new MenuBar();

    vbox->add_child(menu_bar);

    PopupMenu* menu_popup = new PopupMenu("Scene");

    menu_bar->add_child(menu_popup);



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

    Control* control = dynamic_cast<Control*>(node);

    if (control != nullptr) control->_draw();
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
            if (current->get_parent() == root) {
                if (current->iteration_index+1 < current->get_child_count()) {
                    if (up == false) action_down(current);
                    current->iteration_index++;
                    current = current->get_child(current->iteration_index);
                    continue;
                } else {
                    action(current, delta);
                    current->iteration_index = -1;
                    break; // finished traversing tree;
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

        Node* old = current;
        current->iteration_index++;
        current = current->get_child(current->iteration_index);
        is_first = false;
        old->iteration_index = -1;

    }

    // std::cout << result + "\n";
    TIMER_END("update");

}