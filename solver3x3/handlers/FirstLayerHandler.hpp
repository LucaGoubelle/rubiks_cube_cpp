#pragma once 
#include <algorithm>

#include "../../rubikpp/data/cube.hpp"
#include "../../rubikpp/moves/mover.hpp"
#include "../../solverHelpers/all.hpp"

class FirstLayerHandler {
    private:
        CubeMover mover;
        Corner3Seeker cornerSeeker;

        Cube processWBR(Cube cube, std::string targetedOrientColors){
            std::map<std::string, std::string> hmap;
            // up
            hmap["up_front_right::white_red_blue"] = "R U R' U' R U R' U' R U R' U'";
            hmap["up_front_right::blue_white_red"] = "U R U' R'";
            hmap["up_front_right::red_blue_white"] = "R U R'";

            hmap["up_front_left::white_blue_red"] = "R U2 R' U R U' R'";
            hmap["up_front_left::blue_red_white"] = "R U' R'";
            hmap["up_front_left::red_white_blue"] = "U' R U R'";

            hmap["up_back_right::white_blue_red"] = "U' R U R' U R U' R'";
            hmap["up_back_right::blue_red_white"] = "U2 R U' R'";
            hmap["up_back_right::red_white_blue"] = "U R U R'";

            hmap["up_back_left::white_red_blue"] = "U2 R U R' U' R U R' U' R U R' U'";
            hmap["up_back_left::blue_white_red"] = "U' R U' R'";
            hmap["up_back_left::red_blue_white"] = "U2 R U R'";
            //down
            hmap["down_front_right::red_white_blue"] = "R U' R' U R U' R'";
            hmap["down_front_right::blue_red_white"] = "R U R' U' R U R' U'";

            hmap["down_front_left::white_red_blue"] = "L' U' L R U R'";
            hmap["down_front_left::blue_white_red"] = "L' U' L R U R' U' R U R' U' R U R' U'";
            hmap["down_front_left::red_blue_white"] = "L' U' L U R U' R'";

            hmap["down_back_left::white_blue_red"] = "L U2 L' U R U' R'";
            hmap["down_back_left::red_white_blue"] = "L U' L' R U2 R'";
            hmap["down_back_left::blue_red_white"] = "L U2 L' R U R'";

            hmap["down_back_right::white_red_blue"] = "R' U2 R U' R U R'";
            hmap["down_back_right::blue_white_red"] = "R' U R U R U R'";
            hmap["down_back_right::red_blue_white"] = "R' U2 R2 U' R'";

            return (hmap.count(targetedOrientColors)) ? this->mover.multiMoves(cube, hmap[targetedOrientColors]) : cube;
        }

        Cube insertWBR(Cube cube){
            std::vector<std::string> posibilities = {
                "white_blue_red", "white_red_blue",
                "blue_white_red", "blue_red_white",
                "red_white_blue", "red_blue_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            cube = this->processWBR(cube, targetedOrientColors);
            return cube;
        }

        Cube processWGR(Cube cube, std::string targetedOrientColors){
            std::map<std::string, std::string> hmap;

            // up
            hmap["up_front_right::white_green_red"] = "U' y "+CubeAlgorithms::ELEVATOR+" y'";
            hmap["up_front_right::red_white_green"] = "U' R' U' R";
            hmap["up_front_right::green_red_white"] = "U2 R' U R";

            hmap["up_front_left::white_red_green"] = "R' U' R U' R' U R";
            hmap["up_front_left::green_white_red"] = "U R' U R";
            hmap["up_front_left::red_green_white"] = "U2 R' U' R";

            hmap["up_back_right::white_red_green"] = "y "+CubeAlgorithms::ELEVATOR+" y'";
            hmap["up_back_right::green_white_red"] = "U' R' U R";
            hmap["up_back_right::red_green_white"] = "R' U' R";

            hmap["up_back_left::white_green_red"] = "U y"+CubeAlgorithms::ELEVATOR+" y'";
            hmap["up_back_left::red_white_green"] = "U R' U' R";
            hmap["up_back_left::green_red_white"] = "R' U R";

            // down
            hmap["down_front_left::white_green_red"] = "R' L' U2 R L";
            hmap["down_front_left::red_white_green"] = "L' U L R' U2 R";
            hmap["down_front_left::green_red_white"] = "L' U2 L R' U' R";

            hmap["down_back_left::white_red_green"] = "L U L' R' U' R";
            hmap["down_back_left::green_white_red"] = "L U' L' U R' U' R";
            hmap["down_back_left::red_green_white"] = "L U L' U' R' U R";

            hmap["down_back_right::red_white_green"] = "R' U R U' R' U R";
            hmap["down_back_right::green_red_white"] = "R' U' R U R' U' R";

            // todo: implement cases of hmap 
            return (hmap.count(targetedOrientColors)) ? this->mover.multiMoves(cube, hmap[targetedOrientColors]) : cube;
        }

        Cube insertWGR(Cube cube){
            std::vector<std::string> posibilities = {
                "white_green_red", "white_red_green",
                "green_white_red", "green_red_white",
                "red_white_green", "red_green_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            cube = this->processWGR(cube, targetedOrientColors);
            return cube;
        }

        Cube processWGO(Cube cube, std::string targetedOrientColors){
            // todo: implement this method
            std::map<std::string, std::string> hmap;

            //up
            hmap["up_front_right::white_orange_green"] = "L U L' U L U' L'";
            hmap["up_front_right::green_white_orange"] = "L U2 L'";
            hmap["up_front_right::orange_green_white"] = "U2 L U L'";

            hmap["up_front_left::white_green_orange"] = "L' U L2 U' L";
            hmap["up_front_left::orange_white_green"] = "U L U L'";
            hmap["up_front_left::green_orange_white"] = "U2 L U' L'";

            hmap["up_back_left::white_orange_green"] = "y2 "+CubeAlgorithms::ELEVATOR+" y2";
            hmap["up_back_left::green_white_orange"] = "U L U' L'";
            hmap["up_back_left::orange_green_white"] = "L U L'";

            hmap["up_back_right::white_green_orange"] = "U' y2 "+CubeAlgorithms::ELEVATOR+" y2";
            hmap["up_back_right::orange_white_green"] = "U' L U L'";
            hmap["up_back_right::green_orange_white"] = "L U' L'";
            
            //down
            hmap["down_front_left::white_orange_green"] = "y' "+CubeAlgorithms::ELEVATOR+" y' U "+CubeAlgorithms::ELEVATOR+" y2";
            hmap["down_front_left::green_white_orange"] = "L' U L U L U L'";
            hmap["down_front_left::orange_green_white"] = "L' U2 L2 U' L'";
            
            hmap["down_back_left::orange_white_green"] = "L U' L' U L U' L'";
            hmap["down_back_left::green_orange_white"] = "L U L' U' L U L'";

            return (hmap.count(targetedOrientColors)) ? this->mover.multiMoves(cube, hmap[targetedOrientColors]) : cube;
        }

        Cube insertWGO(Cube cube){
            std::vector<std::string> posibilities = {
                "white_orange_green", "white_green_orange",
                "orange_white_green", "orange_green_white",
                "green_white_orange", "green_orange_white"
            };
            std::string targetedOrientColors = this->cornerSeeker.seekCorner(cube, posibilities);
            cube = this->processWGO(cube, targetedOrientColors);
            return cube;
        }

        Cube processWBO(Cube cube, std::string targetedOrientColors){
            // todo: implement this method
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
        }

        Cube handle(Cube cube){
            cube = this->insertWBR(cube);
            cube = this->insertWGR(cube);
            cube = this->insertWGO(cube);
            cube = this->insertWBO(cube);
            return cube;
        }
};
