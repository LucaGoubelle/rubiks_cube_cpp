#pragma once

#include "../../../../../rubikpp/data/cube.hpp"
#include "../../../../../rubikpp/moves/mover.hpp"
#include "MiddleYellowBarHandler.hpp"
#include "SideYellowBarHandler.hpp"

class YellowCenterHandler {
    private:
        MiddleYellowBarHandler middleBarHandler;
        SideYellowBarHandler sideBarHandler;
    public:
        YellowCenterHandler(){
            MiddleYellowBarHandler middleBarHandler;
            SideYellowBarHandler sideBarHandler;
        }

        Cube handle(Cube cube){
            cube = this->middleBarHandler.handle(cube);
            cube = this->sideBarHandler.handle(cube);
            return cube;
        }
};
