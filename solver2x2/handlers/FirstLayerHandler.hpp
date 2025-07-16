#pragma once
#include "../../rubikpp/all.hpp"
#include "../../solverHelpers/all.hpp"
#include "../processors/wgr_processor.hpp"
#include "../processors/wgo_processor.hpp"

class FirstLayerHandler {
    private:
        CubeMover mover;
        Corner3Seeker cornerSeeker;
        WGRProcessor procWGR;
        WGOProcessor procWGO;

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

        Cube processWBO(Cube cube, std::string targetedOrientColors){
            // todo: use a processor class instead
            std::map<std::string, std::string> hmap;

            // up
            hmap["up_front_right::white_blue_orange"] = "L' U2 L U' L' U L";
            hmap["up_front_right::orange_white_blue"] = "U L' U' L";
            hmap["up_front_right::blue_orange_white"] = "L' U L";

            hmap["up_front_left::white_orange_blue"] = "y' "+CubeAlgorithms::ELEVATOR+" y";
            hmap["up_front_left::blue_white_orange"] = "U' L' U L";
            hmap["up_front_left::orange_blue_white"] = "L' U' L";

            hmap["up_back_left::white_blue_orange"] = "U' y' "+CubeAlgorithms::ELEVATOR+" y";
            hmap["up_back_left::orange_white_blue"] = "U' L' U' L";
            hmap["up_back_left::blue_orange_white"] = "U2 L' U L";

            hmap["up_back_right::white_orange_blue"] = "U2 y' "+CubeAlgorithms::ELEVATOR+" y";
            hmap["up_back_right::blue_white_orange"] = "L' U2 L";
            hmap["up_back_right::orange_blue_white"] = "U2 L' U' L";
            // down
            hmap["down_front_left::orange_white_blue"] = "L' U L U' L' U L";
            hmap["down_front_left::blue_orange_white"] = "L' U' L U L' U' L";

            return (hmap.count(targetedOrientColors)) ? this->mover.multiMoves(cube, hmap[targetedOrientColors]) : cube;
        }

        Cube insertWBO(Cube cube){
            std::vector<std::string> posibilities = {
                "white_orange_blue", "white_blue_orange",
                "orange_white_blue", "orange_blue_white",
                "blue_white_orange", "blue_orange_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            cube = this->processWBO(cube, targetedOrientColors);
            return cube;
        }

    public:
        FirstLayerHandler(){
            CubeMover mover;
            Corner3Seeker cornerSeeker;
            WGRProcessor procWGR;
            WGOProcessor procWGO;
        }

        Cube handle(Cube cube){
            cube = insertWGR(cube);
            cube = this->insertWGO(cube);
            cube = this->insertWBO(cube);
            return cube;
        }
};
