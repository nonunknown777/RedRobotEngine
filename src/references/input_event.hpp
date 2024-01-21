#pragma once

#include "glm/ext/vector_int2.hpp"
#include "utils.hpp"
using namespace glm;


namespace rre {

    class SceneTree;
    class Node;

    enum class InputType {
        MOUSE_MOVED = 0,
        KEYBOARD,
        JOYSTICK,
        TOUCH
    };

    class InputEvent {
        private:
            void action_captured(Node* node);
            FuncPtr<InputEvent,Node*> *action_captured_ptr;
            
        public:
            InputEvent();
            ~InputEvent();
            void check_update(SceneTree& scene_tree);
            InputType type;
            ivec2 mouse_pos; //TODO: maybe istead of having all values as public send packets (structs) as data boxes depending on event type

    };

}