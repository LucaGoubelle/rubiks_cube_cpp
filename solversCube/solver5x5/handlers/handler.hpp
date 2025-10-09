#pragma once
#include "../../rubikpp/moves/mover.hpp"

class Handler {
    protected:
        CubeMover mover;
    public:
        Handler(){
            CubeMover mover;
        }
};
