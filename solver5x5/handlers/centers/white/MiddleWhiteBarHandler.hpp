
#pragma once

#include "../../../../rubikpp/data/cube.hpp"
#include "../../../../rubikpp/moves/mover.hpp"
#include "../../../../solverHelpers/seekers/Center5Seeker.hpp"

class MiddleWhiteBarHandler {
    private:
        Center5Seeker centerSeeker;
        CubeMover mover;

        Cube _handle_first_center_edge(Cube cube){
            int count = 0;
            while(count < 4){
                std::string result = this->centerSeeker.seekCenterEdge(cube, "front", "white");
                std::string result2 = this->centerSeeker.seekCenterEdge(cube, "up", "white");
                // map front
                std::map<std::string, std::string> hmap;
                hmap["front::up"] = "F Rw' D2";
                hmap["front::down"] = "F' Rw' D2";
                hmap["front::left"] = "F2 Rw' D2";
                hmap["front::right"] = "Rw' D2";

                // map up
                std::map<std::string, std::string> hmap2;
                hmap["up::front"] = "U' Rw2 D2";
                hmap["up::right"] = "Rw2 D2";
                hmap["up::back"] = "U Rw2 D2";
                hmap["up::left"] = "U2 Rw2 D2";

                if(hmap.count(result)){
                    cube = this->mover.multiMoves(cube, hmap[result]);
                    break;
                } else if(hmap2.count(result2)) {
                    cube = this->mover.multiMoves(cube, hmap2[result2]);
                    break;
                } else {
                    cube = this->mover.multiMoves(cube, "D y");
                    count++;
                }
            }
            return cube;
        }

        Cube _handle_second_center_edge(Cube cube){
            int count = 0;
            while(count < 4){
                std::string result = this->centerSeeker.seekCenterEdge(cube, "front", "white");
                std::string result2 = this->centerSeeker.seekCenterEdge(cube, "up", "white");
                // map front
                std::map<std::string, std::string> hmap;
                hmap["front::up"] = "F Rw' D";
                hmap["front::down"] = "F' Rw' D";
                hmap["front::left"] = "F2 Rw' D";
                hmap["front::right"] = "Rw' D";

                // map up
                std::map<std::string, std::string> hmap2;
                hmap["up::front"] = "U' Rw2 D";
                hmap["up::right"] = "Rw2 D";
                hmap["up::back"] = "U Rw2 D";
                hmap["up::left"] = "U2 Rw2 D";

                if(hmap.count(result)){
                    cube = this->mover.multiMoves(cube, hmap[result]);
                    break;
                } else if(hmap2.count(result2)) {
                    cube = this->mover.multiMoves(cube, hmap2[result2]);
                    break;
                } else {
                    cube = this->mover.multiMoves(cube, "D y");
                    count++;
                }
            }
            return cube;
        }

    public:

        MiddleWhiteBarHandler(){
            Center5Seeker centerSeeker;
            CubeMover mover;
        }

        Cube handle(Cube cube){
            cube = this->_handle_first_center_edge(cube);
            cube = this->_handle_second_center_edge(cube);
            return cube;
        }
};
