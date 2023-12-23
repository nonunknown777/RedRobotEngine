#ifndef POPUP_MENU_H
#define POPUP_MENU_H

#include "popup.hpp"

class PopupMenu : public Popup{
public:
    PopupMenu(std::string name);
    ~PopupMenu();

    void _process(float delta) override;
    void _input() override;
};

#endif
