#pragma once

#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../rubikpp/moves/mover.hpp"
#include "MiddleWhiteBarHandler.hpp"

class WhiteCenterHandler {
    private:
        MiddleWhiteBarHandler middleBarHandler;
        CubeMover mover;
    public:
        WhiteCenterHandler(){
            CubeMover mover;
            MiddleWhiteBarHandler middleBarHandler;
        }

        Cube handle(Cube cube){
            // implement this
            cube = this->middleBarHandler.handle(cube);
            return cube;
        }
};
