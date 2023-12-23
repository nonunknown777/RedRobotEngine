#ifndef MENU_BAR_H
#define MENU_BAR_H

#include "control.hpp"

class MenuBar : public Control{
    public:
        MenuBar(std::string name = "MenuBar");
        ~MenuBar();

        void set_name(std::string name);
};

#endif
