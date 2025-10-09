#pragma once

#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../rubikpp/moves/mover.hpp"
#include "../handler.hpp"

class YellowCenterHandler : public Handler {
    public:
        Cube handle(Cube cube){
            // implement this
            return cube;
        }
};
