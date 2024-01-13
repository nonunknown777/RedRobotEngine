#pragma once

#include "common.hpp"


namespace rre {


class PopupMenu : public Popup{
public:
    PopupMenu();
    ~PopupMenu();

    void _process(float delta); //TODO: override;
    void _input(); //TODO: override
};

}

