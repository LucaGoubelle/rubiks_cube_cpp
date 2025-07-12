#pragma once

#include "../../rubikpp/data/cube.hpp"
#include "../../rubikpp/moves/mover.hpp"
#include "../../solverHelpers/all.hpp"

class SecondLayerHandler {
    private:
        CubeMover mover;
        Edge3Seeker edgeSeeker;

        Cube insertBR(Cube cube){
            // seek the Blue Red piece
            std::string BRPos = this->edgeSeeker.seekEdgeInfos(cube, "blue_red", "red_blue");
            // case 1: already at the good place
            if(BRPos=="front_right::blue_red")
                return cube;
            // case 2: on the top
            std::map<std::string, std::string> hmap;
            hmap["up_front::red_blue"] = CubeAlgorithms::RIGHT_BELGIUM;
            hmap["up_right::red_blue"] = "U "+CubeAlgorithms::RIGHT_BELGIUM;
            hmap["up_back::red_blue"] = "U2 "+CubeAlgorithms::RIGHT_BELGIUM;
            hmap["up_left::red_blue"] = "U' "+CubeAlgorithms::RIGHT_BELGIUM;

            hmap["up_front::blue_red"] = "U' y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            hmap["up_right::blue_red"] = "y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            hmap["up_left::blue_red"] = "U2 y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            hmap["up_back::blue_red"] = "U y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            // case 3: already on a slot
            hmap["front_right::red_blue"] = CubeAlgorithms::RIGHT_BELGIUM + " U2 " + CubeAlgorithms::RIGHT_BELGIUM;
            hmap["front_left::blue_red"] = CubeAlgorithms::LEFT_BELGIUM+" U y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            hmap["front_left::red_blue"] = CubeAlgorithms::LEFT_BELGIUM+" U2 "+CubeAlgorithms::RIGHT_BELGIUM;
            
            hmap["back_left::blue_red"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2 U' y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            hmap["back_left::red_blue"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2 "+CubeAlgorithms::RIGHT_BELGIUM;
            hmap["back_right::blue_red"] = "y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2 U' y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            hmap["back_right::red_blue"] = "y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2 "+CubeAlgorithms::RIGHT_BELGIUM;

            return (hmap.count(BRPos)) ? this->mover.multiMoves(cube, hmap[BRPos]) : cube;
        }

        Cube insertGR(Cube cube){
            std::string GRPos = this->edgeSeeker.seekEdgeInfos(cube, "green_red", "red_green");

            if(GRPos=="back_right::green_red")
                return cube;

            std::map<std::string, std::string> hmap;

            hmap["up_front::red_green"] = "U2 y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
            hmap["up_left::red_green"] = "U y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
            hmap["up_right::red_green"] = "U' y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
            hmap["up_back::red_green"] = "y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";

            hmap["up_front::green_red"] = "U' y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            hmap["up_right::green_red"] = "y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            hmap["up_left::green_red"] = "U2 y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            hmap["up_back::green_red"] = "U y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            // case is on slot
            hmap["back_right::red_green"] = "y "+CubeAlgorithms::RIGHT_BELGIUM+" U2 "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            
            hmap["back_left::green_red"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" U' y' "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            hmap["back_left::red_green"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" U2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";

            hmap["front_left::green_red"] = CubeAlgorithms::LEFT_BELGIUM+" U y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            hmap["front_left::red_green"] = CubeAlgorithms::LEFT_BELGIUM+" y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";

            return (hmap.count(GRPos)) ? this->mover.multiMoves(cube, hmap[GRPos]) : cube;
        }

        Cube insertGO(Cube cube){
            std::string GOPos = this->edgeSeeker.seekEdgeInfos(cube, "green_orange", "orange_green");
            
            if(GOPos=="back_left::green_orange")
                return cube;

            std::map<std::string, std::string> hmap;
            
            hmap["up_front::orange_green"] = "U2 y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            hmap["up_left::orange_green"] = "U y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            hmap["up_right::orange_green"] = "U' y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            hmap["up_back::orange_green"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";

            hmap["up_front::green_orange"] = "U y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            hmap["up_left::green_orange"] = "y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            hmap["up_right::green_orange"] = "U2 y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            hmap["up_back::green_orange"] = "U' y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            // todo : implement middle cases
            hmap["back_left::orange_green"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" U2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            
            hmap["front_left::green_orange"] = CubeAlgorithms::LEFT_BELGIUM+" U' y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            hmap["front_left::orange_green"] = CubeAlgorithms::LEFT_BELGIUM+" y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";

            return (hmap.count(GOPos)) ? this->mover.multiMoves(cube, hmap[GOPos]) : cube;
        }

        Cube insertBO(Cube cube){
            std::string BOPos = this->edgeSeeker.seekEdgeInfos(cube, "blue_orange", "orange_blue");
            
            if(BOPos=="front_left::blue_orange")
                return cube;
            
            std::map<std::string, std::string> hmap;
            
            hmap["up_front::blue_orange"] = "U y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";
            hmap["up_left::blue_orange"] = "y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";
            hmap["up_right::blue_orange"] = "U2 y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";
            hmap["up_back::blue_orange"] = "U' y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";

            hmap["up_front::orange_blue"] = CubeAlgorithms::LEFT_BELGIUM;
            hmap["up_left::orange_blue"] = "U' "+CubeAlgorithms::LEFT_BELGIUM;
            hmap["up_right::orange_blue"] = "U "+CubeAlgorithms::LEFT_BELGIUM;
            hmap["up_back::orange_blue"] = "U2 "+CubeAlgorithms::LEFT_BELGIUM;
            
            hmap["front_left::orange_blue"] = CubeAlgorithms::LEFT_BELGIUM+" U2 "+CubeAlgorithms::LEFT_BELGIUM;

            return (hmap.count(BOPos)) ? this->mover.multiMoves(cube, hmap[BOPos]) : cube;
        }
    public:

        SecondLayerHandler(){
            CubeMover mover;
            Edge3Seeker edgeSeeker;
        }

        Cube handle(Cube cube){
            cube = this->insertBR(cube);
            cube = this->insertGR(cube);
            cube = this->insertGO(cube);
            cube = this->insertBO(cube);
            return cube;
        }
};
