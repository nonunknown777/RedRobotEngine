#ifndef WINDOW_H
#define WINDOW_H


#include "viewport.hpp"

class Window : public Viewport {

    private:
        bool active = true;

    public:
        Window(std::string name);
        ~Window();

        ImVec2 size;
        ImVec2 position;

        int flags = 0;

        void _process(float delta) override;
};

#endif