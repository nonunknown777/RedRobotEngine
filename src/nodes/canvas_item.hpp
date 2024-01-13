#pragma once

#include "common.hpp"


namespace rre {


class CanvasItem : public Node {


    public:
        CanvasItem();
        ~CanvasItem();

        void _input() override;

};

}
