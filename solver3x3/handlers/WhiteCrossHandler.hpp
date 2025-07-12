#pragma once

#include "../../rubikpp/data/cube.hpp"
#include "../../solverHelpers/scanners/Cube3x3Scanner.hpp"
#include "../../solverHelpers/seekers/Edge3Seeker.hpp"
#include "../../rubikpp/moves/mover.hpp"

class WhiteCrossHandler {
    private:
        CubeMover mover;
        Edge3Seeker edgeSeeker;

        Cube processWB(Cube cube, std::string targetedOrient){
            // enum moves case for orientations
            std::map<std::string, std::string> hmap;

            hmap["up_front"] = "F2";
            hmap["up_left"] = "U' F2";
            hmap["up_right"] = "U F2";
            hmap["up_back"] = "U2 F2";
            
            hmap["down_left"] = "D";
            hmap["down_right"] = "D'";
            hmap["down_back"] = "D2";

            hmap["front_left"] = "F'";
            hmap["front_right"] = "F";
            hmap["back_left"] = "L2 F'";
            hmap["back_right"] = "R2 F";

            // do the moves for inserting the piece
            return (hmap.count(targetedOrient)) ? this->mover.multiMoves(cube, hmap[targetedOrient]) : cube;
        }

        Cube insertWB(Cube cube){
            std::string targetedOrient = this->edgeSeeker.seekEdge(cube, "white_blue", "blue_white");
            cube = this->processWB(cube, targetedOrient);
            // verify orientation in slot
            std::string finalVerif = Cube3x3Scanner::scanEdge(cube, "down_front");
            // correct the orientation
            cube = (finalVerif=="blue_white") ? this->mover.multiMoves(cube, "F2 U' R' F") : cube;
            return cube;
        }

        Cube processWR(Cube cube, std::string targetedOrient){
            // enum moves case for orientations
            std::map<std::string, std::string> hmap;

            hmap["up_front"] = "U' R2";
            hmap["up_left"] = "U2 R2";
            hmap["up_right"] = "R2";
            hmap["up_back"] = "U R2";
            
            hmap["down_left"] = "L2 U2 R2";
            hmap["down_back"] = "D' R D R'";

            hmap["front_left"] = "F2 R' F2";
            hmap["front_right"] = "R'";
            hmap["back_left"] = "L U2 R2";
            hmap["back_right"] = "R";

            // do the moves for inserting the piece
            return (hmap.count(targetedOrient)) ? this->mover.multiMoves(cube, hmap[targetedOrient]) : cube;
        }

        Cube insertWR(Cube cube){
            std::string targetedOrient = this->edgeSeeker.seekEdge(cube, "white_red", "red_white");
            cube = this->processWR(cube, targetedOrient);
            // verify orientation in slot
            std::string finalVerif = Cube3x3Scanner::scanEdge(cube, "down_right");
            // correct the orientation
            cube = (finalVerif=="red_white") ? this->mover.multiMoves(cube, "D' F' D R'") : cube;
            return cube;
        }

        Cube processWG(Cube cube, std::string targetedOrient){
            // enum moves case for orientations
            std::map<std::string, std::string> hmap;

            hmap["up_front"] = "D2 F2 D2";
            hmap["up_left"] = "D L2 D'";
            hmap["up_right"] = "D' R2 D";
            hmap["up_back"] = "y R2 y'";
            
            hmap["down_left"] = "L D L' D'";
            
            hmap["front_left"] = "D L D'";
            hmap["front_right"] = "D' R' D";
            hmap["back_left"] = "y' L y";
            hmap["back_right"] = "y R' y'";

            // do the moves for inserting the piece
            return (hmap.count(targetedOrient)) ? this->mover.multiMoves(cube, hmap[targetedOrient]) : cube;
        }

        Cube insertWG(Cube cube){
            std::string targetedOrient = this->edgeSeeker.seekEdge(cube, "white_green", "green_white");
            cube = this->processWG(cube, targetedOrient);
            // verify orientation in slot
            std::string finalVerif = Cube3x3Scanner::scanEdge(cube, "down_back");
            // correct the orientation
            cube = (finalVerif=="green_white") ? this->mover.multiMoves(cube, "y R D' F D y'") : cube;
            return cube;
        }

        Cube processWO(Cube cube, std::string targetedOrient){
            // enum moves case for orientations
            std::map<std::string, std::string> hmap;

            hmap["up_front"] = "U L2";
            hmap["up_left"] = "L2";
            hmap["up_right"] = "U2 L2";
            hmap["up_back"] = "U' L2";
            
            hmap["front_left"] = "L";
            hmap["front_right"] = "F2 L F2";
            hmap["back_left"] = "L'";
            hmap["back_right"] = "D2 R D2";

            // do the moves for inserting the piece
            return (hmap.count(targetedOrient)) ? this->mover.multiMoves(cube, hmap[targetedOrient]) : cube;
        }

        Cube insertWO(Cube cube){
            std::string targetedOrient = this->edgeSeeker.seekEdge(cube, "white_orange", "orange_white");;
            cube = this->processWO(cube, targetedOrient);
            // verify orientation in slot
            std::string finalVerif = Cube3x3Scanner::scanEdge(cube, "down_left");
            // correct the orientation
            cube = (finalVerif=="orange_white") ? this->mover.multiMoves(cube, "L2 D L F' L' D'") : cube;
            return cube;
        }
    public:
        WhiteCrossHandler(){
            CubeMover mover;
            Edge3Seeker edgeSeeker;
        }

        Cube handle(Cube cube){
            cube = this->insertWB(cube);
            cube = this->insertWR(cube);
            cube = this->insertWG(cube);
            cube = this->insertWO(cube);
            return cube;
        }
};
