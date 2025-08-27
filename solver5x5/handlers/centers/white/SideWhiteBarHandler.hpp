#pragma once

#include <iostream>
#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../rubikpp/moves/mover.hpp"
#include "../../../../solverHelpers/seekers/Center5Seeker.hpp"

class SideWhiteBarHandler {
    private:
        Center5Seeker centerSeeker;
        CubeMover mover;

        Cube _handleBar(Cube cube){
            cube = this->_handleBar_part1(cube);
            cube = this->_handleBar_part2(cube);
            cube = this->_handleBar_part3(cube);
            return cube;
        }

        Cube _handleBar_part1(Cube cube){
            int count = 0;
            while(count < 4){
                std::string result = this->centerSeeker.seekCenterEdge(cube, "front", "white");
                std::string result2 = this->centerSeeker.seekCenterEdge(cube, "up", "white");
                //map front
                std::map<std::string, std::string> hmap;
                hmap["front::up"] = "F ";
                hmap["front::down"] = "F' ";
                hmap["front::right"] = "";
                hmap["front::left"] = "F2 ";

                //map up
                std::map<std::string, std::string> hmap2;
                hmap2["up::front"] = "U' Rw'";
                hmap2["up::back"] = "U Rw'";
                hmap2["up::left"] = "U2 Rw'";
                hmap2["up::right"] = "Rw' ";

                if(hmap.count(result)){
                    cube = this->mover.multiMoves(cube, hmap[result]);
                    break;
                } else if(hmap2.count(result2)){
                    cube = this->mover.multiMoves(cube, hmap2[result2]);
                    break;
                } else {
                    cube = this->mover.multiMoves(cube, "D y");
                    count++;
                }
            }
            return cube;
        }

        Cube _handleBar_part2(Cube cube){
            std::string result_front = this->centerSeeker.seekCenterCorner(cube, "front", "white");
            std::string result_left = this->centerSeeker.seekCenterCorner(cube, "left", "white");
            std::string result_right = this->centerSeeker.seekCenterCorner(cube, "right", "white");
            std::string result_back = this->centerSeeker.seekCenterCorner(cube, "back", "white");
            std::string result_up = this->centerSeeker.seekCenterCorner(cube, "up", "white");

            std::map<std::string, std::string> hmap_front;
            hmap_front["front::up::left"] = "Uw' R Uw";
            hmap_front["front::down::left"] = "Dw' L2 Dw Uw'";
            hmap_front["front::up::right"] = "";
            hmap_front["front::down::right"] = "";

            std::map<std::string, std::string> hmap_left;
            hmap_left["left::up::front"] = "Uw' ";
            hmap_left["left::down::front"] = "L' Uw'";
            hmap_left["left::up::back"] = "L Uw'";
            hmap_left["left::down::back"] = "L2 Uw'";

            std::map<std::string, std::string> hmap_right;
            hmap_right["right::up::front"] = "R Uw";
            hmap_right["right::down::front"] = "R2 Uw";
            hmap_right["right::up::back"] = "Uw ";
            hmap_right["right::down::back"] = "R' Uw";

            std::map<std::string, std::string> hmap_back;
            hmap_back["back::up::left"] = "Uw2 ";
            hmap_back["back::up::right"] = "Uw' L Uw'";
            hmap_back["back::down::left"] = "y2 F' y2 Uw2";
            hmap_back["back::down::right"] = "y2 F2 y2 Uw2";

            std::map<std::string, std::string> hmap_up;
            hmap_up["up::front::left"] = "U F' Lw F Lw'";
            hmap_up["up::front::right"] = "F Rw' F Rw F2";
            hmap_up["up::back::left"] = "F' Lw F Lw'";
            hmap_up["up::back::right"] = "U F Rw' F Rw F2";

            std::cout << "result_back: " << result_back << std::endl;
            std::cout << "result_up: " << result_up << std::endl;
            std::cout << "result_left: " << result_left << std::endl;
            std::cout << "result_right: " << result_right << std::endl;
            std::cout << "result_front: " << result_front << std::endl;

            if (hmap_front.count(result_front)){
                cube = this->mover.multiMoves(cube, hmap_front[result_front]);
                return cube;
            } else if(hmap_left.count(result_left)){
                cube = this->mover.multiMoves(cube, hmap_left[result_left]);
                return cube;
            } else if (hmap_right.count(result_right)){
                cube = this->mover.multiMoves(cube, hmap_right[result_right]);
                return cube;
            } else if (hmap_back.count(result_back)){
                cube = this->mover.multiMoves(cube, hmap_back[result_back]);
                return cube;
            } else if(hmap_up.count(result_up)){
                cube = this->mover.multiMoves(cube, hmap_up[result_up]);
                return cube;
            }

            return cube;
        }

        Cube _handleBar_part3(Cube cube){
            // implement this
            return cube;
        }

    public:
        SideWhiteBarHandler(){
            Center5Seeker centerSeeker;
            CubeMover mover;
        }

        Cube handle(Cube cube){
            cube = this->_handleBar(cube);
            cube = this->mover.multiMoves(cube, "D2");
            cube = this->_handleBar(cube);
            return cube;
        }
};
