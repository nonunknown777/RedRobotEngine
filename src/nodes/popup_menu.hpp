#ifndef POPUP_MENU_H
#define POPUP_MENU_H

#include "popup.hpp"

class PopupMenu : public Popup{
public:
    PopupMenu(std::string name);
    ~PopupMenu();

    virtual void _process(float delta) override;
};

#endif
