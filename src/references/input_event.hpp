#pragma once

#include "glm/ext/vector_int2.hpp"

using namespace glm;


namespace rre {

    class SceneTree;

    enum InputType {
        MOUSE = 0,
        KEYBOARD,
        JOYSTICK,
        TOUCH
    };

    class InputEvent {
        private:
            ivec2 mouse_pos;
        public:
            InputEvent();
            ~InputEvent();
            void check_update(SceneTree* scene_tree);

    };

}