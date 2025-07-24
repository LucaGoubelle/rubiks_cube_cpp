#pragma once

#include "../../../../rubikpp/data/cube.hpp"

class SideWhiteBarHandler {
    private:
        Center5Seeker centerSeeker;
        CubeMover mover;

        Cube _handleFirstBar(Cube cube){
            // implement this
            return cube;
        }

        Cube _handleSecondBar(Cube cube){
            // implement this
            return cube;
        }
    public:
        SideWhiteBarHandler(){
            Center5Seeker centerSeeker;
            CubeMover mover;
        }

        Cube handle(Cube cube){
            cube = this->_handleFirstBar(cube);
            cube = this->_handleSecondBar(cube);
            return cube;
        }
};
