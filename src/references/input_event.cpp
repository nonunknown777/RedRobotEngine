#include "input_event.hpp"

#include "raylib.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include "scene_tree.hpp"
#include "node.hpp"
namespace rre {

    InputEvent::InputEvent() {

        

        action_captured_ptr = new FuncPtr<InputEvent,Node*>(*this, &InputEvent::action_captured);

        mouse_pos = ivec2(0,0);

    }

    InputEvent::~InputEvent() {

    }

    void InputEvent::action_captured(Node* node) {
        node->_input(*this);
    }


    void InputEvent::check_update(SceneTree& scene_tree) {
        //======== Mouse

        //Mouse Movement
        Vector2 new_mouse_pos = GetMousePosition();

        if (mouse_pos != ivec2(new_mouse_pos.x, new_mouse_pos.y)) {
            mouse_pos = ivec2(new_mouse_pos.x, new_mouse_pos.y);
            scene_tree.traverse_bottom_top(*action_captured_ptr);
            
        }
    }
}