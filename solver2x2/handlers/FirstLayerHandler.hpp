#pragma once
#include "../../rubikpp/all.hpp"
#include "../../solverHelpers/all.hpp"
#include "../processors/wgr_processor.hpp"
#include "../processors/wgo_processor.hpp"
#include "../processors/wbo_processor.hpp"

class FirstLayerHandler {
    private:
        CubeMover mover;
        Corner3Seeker cornerSeeker;
        WGRProcessor procWGR;
        WGOProcessor procWGO;
        WBOProcessor procWBO;

        Cube insertWGR(Cube cube){
            std::vector<std::string> posibilities = {
                "white_green_red", "white_red_green",
                "green_white_red", "green_red_white",
                "red_white_green", "red_green_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            std::string sequence = this->procWGR.process(targetedOrientColors);
            cube = this->mover.multiMoves(cube, sequence);
            return cube;
        }

        Cube insertWGO(Cube cube){
            std::vector<std::string> posibilities = {
                "white_orange_green", "white_green_orange",
                "orange_white_green", "orange_green_white",
                "green_white_orange", "green_orange_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            std::string sequence = this->procWGO.process(targetedOrientColors);
            cube = this->mover.multiMoves(cube, sequence);
            return cube;
        }

        Cube insertWBO(Cube cube){
            std::vector<std::string> posibilities = {
                "white_orange_blue", "white_blue_orange",
                "orange_white_blue", "orange_blue_white",
                "blue_white_orange", "blue_orange_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            std::string sequence = this->procWBO.process(targetedOrientColors);
            cube = this->mover.multiMoves(cube, sequence);
            return cube;
        }

    public:
        FirstLayerHandler(){
            CubeMover mover;
            Corner3Seeker cornerSeeker;
            WGRProcessor procWGR;
            WGOProcessor procWGO;
            WBOProcessor procWBO;
        }

        Cube handle(Cube cube){
            cube = this->insertWGR(cube);
            cube = this->insertWGO(cube);
            cube = this->insertWBO(cube);
            return cube;
        }
};
