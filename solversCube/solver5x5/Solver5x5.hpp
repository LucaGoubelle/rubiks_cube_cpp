#pragma once

#include "handlers/centers/white/WhiteCenterHandler.hpp"
#include "handlers/centers/yellow/YellowCenterHandler.hpp"
#include "handlers/centers/BlueCenterHandler.hpp"
#include "handlers/centers/RedCenterHandler.hpp"
#include "handlers/centers/LastCentersHandler.hpp"

#include "handlers/edges/WhiteEdgesHandler.hpp"
#include "handlers/edges/YellowEdgesHandler.hpp"
#include "handlers/edges/LastEdgesHandler.hpp"

class Solver5x5 {
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
            cube = this->whiteCenterHandler.handle(cube);
            cube = this->yellowCenterHandler.handle(cube);
            cube = this->blueCenterHandler.handle(cube);
            cube = this->redCenterHandler.handle(cube);
            cube = this->lastCentersHandler.handle(cube);
            return cube;
        }

        Cube solveEdges(Cube cube){
            this->whiteEdgesHandler.handle(cube);
            this->yellowEdgesHandler.handle(cube);
            this->lastEdgesHandler.handle(cube);
            return cube;
        }

    public:

        Solver5x5(){
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
            // implement other lines
            return cube;
        }
};
