#pragma once

#include "common.hpp"


namespace rre {


class Window : public Viewport {

    private:
        bool active = true;

    public:
        Window();
        ~Window();

        int flags = 0;
        Vector2 size;
        Vector2 position;

     
};

}
