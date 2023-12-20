#ifndef MENUBAR_H
#define MENUBAR_H

#include "control.hpp"

class MenuBar : public Control {


    private:
        

    public:
        MenuBar(std::string name = "MenuBar") : Control(name) {};
        ~MenuBar();
};

#endif