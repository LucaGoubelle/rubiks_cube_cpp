#pragma once

#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../rubikpp/moves/mover.hpp"
#include "../../../../solverHelpers/seekers/Center5Seeker.hpp"

class MiddleYellowBarHandler {
    public:
        Cube handle(Cube cube){
            return cube;
        }
};
