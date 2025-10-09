#pragma once

#include "handlers/StartHandler.hpp"
#include "handlers/WhiteCrossHandler.hpp"
#include "handlers/FirstLayerHandler.hpp"
#include "handlers/SecondLayerHandler.hpp"
#include "handlers/YellowCrossHandler.hpp"
#include "handlers/LastCornersHandler.hpp"

class Solver3x3 {
    private:
        StartHandler startHandler;
        WhiteCrossHandler whiteCrossHandler;
        FirstLayerHandler firstLayerHandler;
        SecondLayerHandler secondLayerHandler;
        YellowCrossHandler yellowCrossHandler;
    public:
        Solver3x3(){
            StartHandler startHandler;
            WhiteCrossHandler whiteCrossHandler;
            FirstLayerHandler firstLayerHandler;
            SecondLayerHandler secondLayerHandler;
            YellowCrossHandler yellowCrossHandler;
        }
        
        Cube solve(Cube cube){
            cube = this->startHandler.start(cube);
            cube = this->whiteCrossHandler.handle(cube);
            cube = this->firstLayerHandler.handle(cube);
            cube = this->secondLayerHandler.handle(cube);
            cube = this->yellowCrossHandler.handle(cube);
            // cube = this->lastCornersHandler.handle(cube);
            return cube;
        }
};
