#pragma once

#include "glm/ext/vector_int2.hpp"
#include "utils.hpp"
using namespace glm;


namespace rre {

    class SceneTree;
    class Node;

    enum InputType {
        MOUSE = 0,
        KEYBOARD,
        JOYSTICK,
        TOUCH
    };

    class InputEvent {
        private:
            ivec2 mouse_pos;
            void action_captured(Node* node);
            FuncPtr<InputEvent,Node*> *action_captured_ptr;
            
        public:
            InputEvent();
            ~InputEvent();
            void check_update(SceneTree& scene_tree);

    };

}