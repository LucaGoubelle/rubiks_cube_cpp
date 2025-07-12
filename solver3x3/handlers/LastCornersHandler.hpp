#pragma once

#include "../../rubikpp/data/cube.hpp"
#include "../../rubikpp/moves/mover.hpp"
#include "../../solverHelpers/all.hpp"

class LastCornersHandler {
    private:
        CubeMover mover;
        OLLScanner ollScanner;
        Corner3Seeker cornerSeeker;

        Cube permute(Cube cube){
            // todo : implement this method
            
            // 1: search for YBO corner and place it
            std::vector<std::string> posibilities = {
                "yellow_blue_orange", "yellow_orange_blue",
                "blue_yellow_orange", "blue_orange_yellow",
                "orange_blue_yellow", "orange_yellow_blue"
            };
            std::string resultYBO = this->cornerSeeker.seekCorner(cube, posibilities);

            std::map<std::string, std::string> hmapYBO;
            
            hmapYBO["up_front_right::yellow_orange_blue"] = "y' "+CubeAlgorithms::FRIENDS+" "+CubeAlgorithms::FRIENDS+" y";
            hmapYBO["up_back_right::yellow_blue_orange"] = "y' "+CubeAlgorithms::FRIENDS+" y";
            hmapYBO["up_back_left::yellow_orange_blue"] = "y "+CubeAlgorithms::FRIENDS+" y'";

            hmapYBO["up_front_right::blue_yellow_orange"] = "y2 "+CubeAlgorithms::FRIENDS+" "+CubeAlgorithms::FRIENDS+" y2";
            hmapYBO["up_back_right::blue_orange_yellow"] = "y' "+CubeAlgorithms::FRIENDS+" y";
            hmapYBO["up_back_left::blue_yellow_orange"] = "y2 "+CubeAlgorithms::FRIENDS+" y2";

            hmapYBO["up_front_right::orange_blue_yellow"] = "y' "+CubeAlgorithms::FRIENDS+" "+CubeAlgorithms::FRIENDS+" y";
            hmapYBO["up_back_right::orange_yellow_blue"] = "y' "+CubeAlgorithms::FRIENDS+" y";
            hmapYBO["up_back_left::orange_blue_yellow"] = "y2 "+CubeAlgorithms::FRIENDS+" y2";

            cube = (hmapYBO.count(resultYBO)) ? this->mover.multiMoves(cube, hmapYBO[resultYBO]) : cube;

            // 2: apply friends alg to put other corner on good spot
            // first verify
            std::vector<std::string> posibilities2 = {
                "yellow_blue_red", "yellow_red_blue",
                "blue_yellow_red", "blue_red_yellow",
                "red_blue_yellow", "red_yellow_blue"
            };
            std::string resultYBR = this->cornerSeeker.seekCorner(cube, posibilities2);

            bool exitCondition1 = resultYBR == "up_front_right::yellow_blue_red";
            bool exitCondition2 = resultYBR == "up_front_right::red_yellow_blue";
            bool exitCondition3 = resultYBR == "up_front_right::blue_red_yellow";
            bool exitCondition = exitCondition1 || exitCondition2 || exitCondition3;
            if (exitCondition)
                return cube;
            else {
                std::map<std::string, std::string> hmap;

                hmap["up_back_right::yellow_red_blue"] = CubeAlgorithms::FRIENDS+" "+CubeAlgorithms::FRIENDS;
                hmap["up_back_right::red_blue_yellow"] = CubeAlgorithms::FRIENDS+" "+CubeAlgorithms::FRIENDS;
                hmap["up_back_right::blue_yellow_red"] = CubeAlgorithms::FRIENDS+" "+CubeAlgorithms::FRIENDS;

                hmap["up_back_left::yellow_blue_red"] = CubeAlgorithms::FRIENDS;
                hmap["up_back_left::red_yellow_blue"] = CubeAlgorithms::FRIENDS;
                hmap["up_back_left::blue_red_yellow"] = CubeAlgorithms::FRIENDS;

                return (hmap.count(resultYBR)) ? this->mover.multiMoves(cube, hmap[resultYBR]) : cube;
            }
        }

        Cube orient(Cube cube){
            // 1: use an OLLScanner
            std::string resultOll = this->ollScanner.scanOLL(cube);
            // 2: map the cases
            std::map<std::string, std::string> hmap;

            // antisune cases
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";

            // sune cases
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";

            // h cases
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";

            // pi cases
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";

            // l cases
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";
            hmap[""] = "???";

            return cube;
        }
    public:
        LastCornersHandler(){
            CubeMover mover;
            OLLScanner ollScanner;
            Corner3Seeker cornerSeeker;
        }

        Cube handle(Cube cube){
            cube = this->permute(cube);
            cube = this->orient(cube);
            return cube;
        }
};
