#pragma once

#include "../../../../../rubikpp/data/cube.hpp"
#include "../handler.hpp"
#include "../../../../../solverHelpers/seekers/Center5Seeker.hpp"

class MiddleYellowBarHandler : public Handler {
    public:
        Cube handle(Cube cube){
            return cube;
        }
};
