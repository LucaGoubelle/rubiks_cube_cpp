#pragma once

#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../rubikpp/moves/mover.hpp"
#include "MiddleWhiteBarHandler.hpp"
#include "SideWhiteBarHandler.hpp"

class WhiteCenterHandler {
    private:
        MiddleWhiteBarHandler middleBarHandler;
        SideWhiteBarHandler sideWhiteBarHandler;
        CubeMover mover;
    public:
        WhiteCenterHandler(){
            CubeMover mover;
            MiddleWhiteBarHandler middleBarHandler;
            SideWhiteBarHandler sideWhiteBarHandler;
        }

        Cube handle(Cube cube){
            // implement this
            cube = this->middleBarHandler.handle(cube);
            cube = this->sideWhiteBarHandler.handle(cube);
            return cube;
        }
};
