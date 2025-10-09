#pragma once

#include "../../../rubikpp/data/cube.hpp"
#include "handler.hpp"

class YellowCrossHandler : public Handler {
    private:
        Cube create(Cube cube){
            std::string config = "";
            std::string upSticker = cube.up[0][1];
            std::string leftSticker = cube.up[1][0];
            std::string rightSticker = cube.up[1][2];
            std::string downSticker = cube.up[2][1];
            config += (upSticker=="yellow") ? "1" : "0";
            config += (leftSticker=="yellow") ? "1" : "0";
            config += (rightSticker=="yellow") ? "1" : "0";
            config += (downSticker=="yellow") ? "1" : "0";

            std::map<std::string, std::string> hmap;
            hmap["1100"] = "F R U R' U' R U R' U' F'";
            hmap["0101"] = "U F R U R' U' R U R' U' F'";
            hmap["0011"] = "U2 F R U R' U' R U R' U' F'";
            hmap["1010"] = "U' F R U R' U' R U R' U' F'";
            hmap["1001"] = "U F R U R' U' F'";
            hmap["0110"] = "F R U R' U' F'";
            hmap["0000"] = "F R U R' U' F' U2 F R U R' U' R U R' U' F'";
            return (hmap.count(config)) ? this->mover.multiMoves(cube, hmap[config]) : cube;
        }

        Cube correct(Cube cube){
            std::string result = "";
            result += cube.front[0][1]+"_";
            result += cube.right[0][1]+"_";
            result += cube.back[0][1]+"_";
            result += cube.left[0][1];

            std::string chair = "R U2 R' U' R U' R'";
            std::map<std::string, std::string> hmap;
            
            hmap["green_red_blue_orange"] = chair+" U2 y' "+chair+" y U2";
            hmap["blue_orange_red_green"] = chair + " U'";
            hmap["blue_orange_green_red"] = chair + " U " + chair + " U2";

            hmap["orange_red_green_blue"] = "y' "+chair+" U' y";
            hmap["orange_green_blue_red"] = chair;
            hmap["orange_blue_green_red"] = "U2 "+chair+" U";

            hmap["red_blue_green_orange"] = chair+" U'";
            hmap["red_blue_orange_green"] = chair+" U "+chair+" U";

            return (hmap.count(result)) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        } 
    public:
        Cube handle(Cube cube){
            cube = this->create(cube);
            cube = this->correct(cube);
            return cube;
        }
};
