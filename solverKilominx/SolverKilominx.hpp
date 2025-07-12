#pragma once

#include "handlers/firstFace/StartHandler.hpp"
#include "handlers/firstFace/FirstFaceHandler.hpp"

class SolverKilominx {
    private:
        StartHandler startHandler;
        FirstFaceHandler firstFaceHandler;
    public:

        SolverKilominx(){
            StartHandler startHandler;
            FirstFaceHandler firstFaceHandler;
        }

        Kilominx solve(Kilominx minx){
            minx = this->startHandler.handle(minx);
            minx = this->firstFaceHandler.handle(minx);
            //todo: implement remaining logic...
            return minx;
        }
};