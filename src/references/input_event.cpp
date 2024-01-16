#include "input_event.hpp"

#include "raylib.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include "scene_tree.hpp"

namespace rre {

    InputEvent::InputEvent() {
        mouse_pos = ivec2(0,0);
    }

    InputEvent::~InputEvent() {

    }


    void InputEvent::check_update(SceneTree* scene_tree) {
        //======== Mouse

        //Mouse Movement
        Vector2 new_mouse_pos = GetMousePosition();

        if (mouse_pos != ivec2(new_mouse_pos.x, new_mouse_pos.y)) {
            mouse_pos = ivec2(new_mouse_pos.x, new_mouse_pos.y);
            
            // std::cout << "mouse changed pos: " << to_string(mouse_pos) << "\n";
        }
    }
}