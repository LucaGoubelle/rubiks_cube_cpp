#pragma once

#include "../../rubikpp/data/cube.hpp"

#include "handlers/centers/WhiteCenterHandler.hpp"
#include "handlers/centers/YellowCenterHandler.hpp"
#include "handlers/centers/BlueCenterHandler.hpp"
#include "handlers/centers/RedCenterHandler.hpp"
#include "handlers/centers/LastCentersHandler.hpp"

#include "handlers/edges/WhiteEdgesHandler.hpp"
#include "handlers/edges/YellowEdgesHandler.hpp"
#include "handlers/edges/LastEdgesHandler.hpp"

class Solver4x4 {
    private:
        WhiteCenterHandler whiteCenterHandler;
        YellowCenterHandler yellowCenterHandler;
        BlueCenterHandler blueCenterHandler;
        RedCenterHandler redCenterHandler;
        LastCentersHandler lastCentersHandler;

        WhiteEdgesHandler whiteEdgesHandler;
        YellowEdgesHandler yellowEdgesHandler;
        LastEdgesHandler lastEdgesHandler;

        Cube solveCenters(Cube cube){
            cube = this->whiteCenterHandler.solve(cube);
            cube = this->yellowCenterHandler.solve(cube);
            cube = this->blueCenterHandler.solve(cube);
            cube = this->redCenterHandler.solve(cube);
            cube = this->lastCentersHandler.solve(cube);
            return cube;
        }

        Cube solveEdges(Cube cube){
            cube = this->whiteEdgesHandler.handle(cube);
            cube = this->yellowEdgesHandler.handle(cube);
            cube = this->lastEdgesHandler.handle(cube);
            return cube;
        }
        
    public:
        Solver4x4(){
            WhiteCenterHandler whiteCenterHandler;
            YellowCenterHandler yellowCenterHandler;
            BlueCenterHandler blueCenterHandler;
            RedCenterHandler redCenterHandler;
            LastCentersHandler lastCentersHandler;

            WhiteEdgesHandler whiteEdgesHandler;
            YellowEdgesHandler yellowEdgesHandler;
            LastEdgesHandler lastEdgesHandler;
        }

        Cube solve(Cube cube){
            cube = this->solveCenters(cube);
            cube = this->solveEdges(cube);
            // implement remaining lines
            return cube;
        }
};
