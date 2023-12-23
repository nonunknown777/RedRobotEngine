#ifndef WINDOW_H
#define WINDOW_H


#include "viewport.hpp"

class Window : public Viewport {

    private:
        bool active = true;

    public:
        Window(std::string name);
        ~Window();

        int flags = 0;

     
};

#endif