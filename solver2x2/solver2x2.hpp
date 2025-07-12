#pragma once

#include "handlers/StartHandler.hpp"
#include "handlers/FirstLayerHandler.hpp"
#include "handlers/LastLayerHandler.hpp"

class Solver2x2 {
    private:
        StartHandler startHandler;
        FirstLayerHandler firstLayerHandler;
        LastLayerHandler lastLayerHandler;
    public:
        Solver2x2(){
            StartHandler StartHandler;
            FirstLayerHandler firstLayerHandler;
            LastLayerHandler lastLayerHandler;
        }

        Cube solve(Cube cube){
            // Solve the cube
            cube = this->startHandler.start(cube);
            cube = this->firstLayerHandler.handle(cube);
            cube = this->lastLayerHandler.handle(cube);
            return cube;
        }
};
