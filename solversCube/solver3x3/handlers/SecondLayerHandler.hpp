#pragma once

#include "../../../rubikpp/data/cube.hpp"
#include "../../../solverHelpers/seekers/Edge3Seeker.hpp"
#include "handler.hpp"
#include "../processors/br_processor.hpp"
#include "../processors/gr_processor.hpp"
#include "../processors/go_processor.hpp"
#include "../processors/bo_processor.hpp"

class SecondLayerHandler : public Handler {
    private:
        Edge3Seeker edgeSeeker;
        BRProcessor brProc;
        GRProcessor grProc;
        GOProcessor goProc;
        BOProcessor boProc;

        Cube insertBR(Cube cube){
            // seek the Blue Red piece
            std::string BRPos = this->edgeSeeker.seekEdgeInfos(cube, "blue_red", "red_blue");
            // case 1: already at the good place
            if(BRPos=="front_right::blue_red")
                return cube;
            // case 2: on the top
            return this->mover.multiMoves(cube, this->brProc.process(BRPos));
        }

        Cube insertGR(Cube cube){
            std::string GRPos = this->edgeSeeker.seekEdgeInfos(cube, "green_red", "red_green");

            if(GRPos=="back_right::green_red")
                return cube;

            return this->mover.multiMoves(cube, this->grProc.process(GRPos));
        }

        Cube insertGO(Cube cube){
            std::string GOPos = this->edgeSeeker.seekEdgeInfos(cube, "green_orange", "orange_green");
            
            if(GOPos=="back_left::green_orange")
                return cube;

            return this->mover.multiMoves(cube, this->goProc.process(GOPos));
        }

        Cube insertBO(Cube cube){
            std::string BOPos = this->edgeSeeker.seekEdgeInfos(cube, "blue_orange", "orange_blue");
            
            if(BOPos=="front_left::blue_orange")
                return cube;

            return this->mover.multiMoves(cube, this->boProc.process(BOPos));
        }
    public:

        SecondLayerHandler(){
            Edge3Seeker edgeSeeker;
            BRProcessor brProc;
            GRProcessor grProc;
            GOProcessor goProc;
            BOProcessor boProc;
        }

        Cube handle(Cube cube){
            cube = this->insertBR(cube);
            cube = this->insertGR(cube);
            cube = this->insertGO(cube);
            cube = this->insertBO(cube);
            return cube;
        }
};
