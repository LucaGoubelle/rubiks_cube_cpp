#pragma once

#include "../../../rubikpp/data/cube.hpp"
#include "../../../rubikpp/moves/mover.hpp"
#include "../../../solverHelpers/all.hpp"

class StartHandler {
    private:
        CubeMover mover;
        Cube3x3Scanner cube3x3Scanner;
    public:
        StartHandler(){
            CubeMover mover;
            Cube3x3Scanner cube3x3Scanner;
        }

        Cube start(Cube cube){
            // todo : implement this method
            std::string result1 = this->cube3x3Scanner.scanCenter(cube, "up");
            std::string result2 = this->cube3x3Scanner.scanCenter(cube, "front");
            std::string result = result1 +"_"+ result2;
            std::map<std::string, std::string> hmap;
            
            hmap["yellow_green"] = "y2";
            hmap["yellow_red"] = "y'";
            hmap["yellow_orange"] = "y";

            hmap["white_blue"] = "z2";
            hmap["white_green"] = "x2";
            hmap["white_red"] = "y z2";
            hmap["white_orange"] = "y' z2";

            hmap["blue_white"] = "x'";
            hmap["blue_yellow"] = "x y2";
            hmap["blue_red"] = "z' y'";
            hmap["blue_orange"] = "z y";

            hmap["green_white"] = "x z2";
            hmap["green_yellow"] = "x";
            hmap["green_red"] = "z y'";
            hmap["green_orange"] = "z' y";

            hmap["red_white"] = "z x'";
            hmap["red_yellow"] = "x y";
            hmap["red_green"] = "x z'";
            hmap["red_blue"] = "z";

            hmap["orange_white"] = "z' x'";
            hmap["orange_yellow"] = "x y'";
            hmap["orange_green"] = "z y2";
            hmap["orange_blue"] = "z'";

            return (hmap.count(result)) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }
};
