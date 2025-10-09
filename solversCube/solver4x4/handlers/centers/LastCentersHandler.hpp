#pragma once

#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../solverHelpers/all.hpp"
#include "../handler.hpp"

class LastCentersHandler : public Handler {
    private:
        Cube createFirstBar(Cube cube){
            // implement this
            return cube;
        }

        Cube createSecondBar(Cube cube){
            // implement this
            return cube;
        }
    public:
        Cube solve(Cube cube){
            cube = this->createFirstBar(cube);
            cube = this->createSecondBar(cube);
            return cube;
        }
};
