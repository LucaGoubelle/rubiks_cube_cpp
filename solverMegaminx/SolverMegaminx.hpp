#pragma once

#include "../minxpp/data/models/megaminx.hpp"

#include "handlers/firstFace/StartHandler.hpp"
#include "handlers/firstFace/WhiteStarHandler.hpp"
#include "handlers/firstFace/FirstCornersHandler.hpp"

#include "handlers/SecondLayerHandler.hpp"
#include "handlers/PrismsHandler.hpp"
#include "handlers/MiddleCornersHandler.hpp"
#include "handlers/LastFirstLayerHandler.hpp"

#include "handlers/lastFace/GreyStarHandler.hpp"
#include "handlers/lastFace/LastCornersHandler.hpp"

class SolverMegaminx {
    private:
        StartHandler startHandler;
        WhiteStarHandler whiteStarHandler;
        FirstCornersHandler firstCornersHandler;

        SecondLayerHandler secondLayerHandler;
        PrismsHandler prismsHandler;

        MiddleCornersHandler middleCornersHandler;
        LastFirstLayerHandler lastFirstLayerHandler;

        GreyStarHandler greyStarHandler;
        LastCornersHandler lastCornersHandler;

        Megaminx solveWhiteFace(Megaminx minx){
            minx = this->startHandler.handle(minx);
            minx = this->whiteStarHandler.handle(minx);
            minx = this->firstCornersHandler.handle(minx);
            return minx;
        }

        Megaminx solveSecondStep(Megaminx minx){
            minx = this->secondLayerHandler.handle(minx);
            minx = this->prismsHandler.handle(minx);
            return minx;
        }

        Megaminx solveThirdStep(Megaminx minx){
            minx = this->middleCornersHandler.handle(minx);
            minx = this->lastCornersHandler.handle(minx);
            return minx;
        }

        Megaminx solveLastFace(Megaminx minx){
            minx = this->greyStarHandler.handle(minx);
            minx = this->lastCornersHandler.handle(minx);
            return minx;
        }

    public:

        SolverMegaminx(){
            StartHandler startHandler;
            WhiteStarHandler whiteStarHandler;
            FirstCornersHandler firstCornersHandler;

            SecondLayerHandler secondLayerHandler;
            PrismsHandler prismsHandler;

            MiddleCornersHandler middleCornersHandler;
            LastFirstLayerHandler lastFirstLayerHandler;

            GreyStarHandler greyStarHandler;
            LastCornersHandler lastCornersHandler;
        }

        Megaminx solve(Megaminx minx){
            minx = this->solveWhiteFace(minx);
            minx = this->solveSecondStep(minx);
            minx = this->solveThirdStep(minx);
            minx = this->solveLastFace(minx);
            return minx;
        }
};
