#pragma once

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
            // implement this
            std::string result_left = this->centerSeeker.seekCenterCorner(cube, "left", "white");
            std::string result_right = this->centerSeeker.seekCenterCorner(cube, "right", "white");
            std::string result_back = this->centerSeeker.seekCenterCorner(cube, "back", "white");
            std::string result_up = this->centerSeeker.seekCenterCorner(cube, "up", "white");

            std::map<std::string, std::string> hmap_left;
            //todo: implement cases here
            hmap_left[""] = "";

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
