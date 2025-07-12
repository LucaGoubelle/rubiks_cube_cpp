#pragma once
#include "../../rubikpp/all.hpp"
#include "../../solverHelpers/all.hpp"

class StartHandler {
    private:
        CubeMover mover;
        Cube2x2Scanner cube2x2Scanner;

        Cube analyseUpFrontRight(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "up_front_right");
            std::map<std::string, std::string> hmap;
            hmap["white_red_blue"] = "U' R2";
            hmap["red_blue_white"] = "R U R' U'";
            hmap["blue_white_red"] = "U R U' R'";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseUpBackRight(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "up_back_right");
            std::map<std::string, std::string> hmap;
            hmap["white_blue_red"] = "R2";
            hmap["red_white_blue"] = "U F";
            hmap["blue_red_white"] = "U R'";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseUpFrontLeft(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "up_front_left");
            std::map<std::string, std::string> hmap;
            hmap["white_blue_red"] = "U2 R2";
            hmap["red_white_blue"] = "U' F";
            hmap["blue_red_white"] = "U' R'";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseUpBackLeft(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "up_back_left");
            std::map<std::string, std::string> hmap;
            hmap["white_red_blue"] = "U R2";
            hmap["red_blue_white"] = "U2 F";
            hmap["blue_white_red"] = "U2 R'";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseDownFrontLeft(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "down_front_left");
            std::map<std::string, std::string> hmap;
            hmap["white_red_blue"] = "D";
            hmap["blue_white_red"] = "L D2";
            hmap["red_blue_white"] = "F'";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseDownBackLeft(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "down_back_left");
            std::map<std::string, std::string> hmap;
            hmap["white_blue_red"] = "D2";
            hmap["red_white_blue"] = "L' D";
            hmap["blue_red_white"] = "L' F'";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseDownBackRight(Cube cube){
            std::string result = this->cube2x2Scanner.scanCorner(cube, "down_back_right");
            std::map<std::string, std::string> hmap;
            hmap["white_red_blue"] = "D'";
            hmap["blue_white_red"] = "R";
            hmap["red_blue_white"] = "R2 F";
            return (hmap.count(result) == 1) ? this->mover.multiMoves(cube, hmap[result]) : cube;
        }

        Cube analyseUp(Cube cube){
            cube = this->analyseUpFrontRight(cube);
            cube = this->analyseUpFrontLeft(cube);
            cube = this->analyseUpBackRight(cube);
            cube = this->analyseUpBackLeft(cube);
            return cube;
        }

        Cube analyseDown(Cube cube){
            cube = this->analyseDownFrontLeft(cube);
            cube = this->analyseDownBackLeft(cube);
            cube = this->analyseDownBackRight(cube);
            return cube;
        }
    public:
        StartHandler(){
            CubeMover mover;
            Cube2x2Scanner cube2x2Scanner;
        }

        Cube start(Cube cube){
            std::string preResult = this->cube2x2Scanner.scanCorner(cube, "down_front_right");

            std::map<std::string, std::string> hmap;
            hmap["white_blue_red"] = "";
            hmap["blue_red_white"] = "R2 U R'";
            hmap["red_white_blue"] = "R U' R2";

            if(hmap.count(preResult) == 1){
                cube = this->mover.multiMoves(cube, hmap[preResult]);
                return cube;
            } else {
                cube = this->analyseUp(cube);
                cube = this->analyseDown(cube);
                return cube;
            }
        }
};
