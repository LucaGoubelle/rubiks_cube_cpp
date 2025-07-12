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

        /**
         * Solve a 2x2 puzzle, return altered cube object
         * @author: LucaGoubelle
         */
        Cube solve(Cube cube){
            // Solve the cube
            cube = this->startHandler.handle(cube);
            cube = this->firstLayerHandler.handle(cube);
            cube = this->lastLayerHandler.handle(cube);
            return cube;
        }
};
