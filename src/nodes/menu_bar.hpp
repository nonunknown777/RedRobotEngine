#pragma once

#include "common.hpp"


namespace rre {


class MenuBar : public Control{
    public:
        MenuBar();
        ~MenuBar();

        void set_name(std::string name);
};

}
