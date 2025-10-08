#pragma once
#include "../../../rubikpp/all.hpp"
#include "../../../solverHelpers/all.hpp"
#include "../processors/wbr_processor.hpp"

class StartHandler {
    private:
        CubeMover mover;
        Cube2x2Scanner cube2x2Scanner;
        Corner2Seeker seeker;
        WBRProcessor proc;

        Cube handleFirstCorner(Cube cube){
            std::vector<std::string> possibilities = {
                "white_blue_red", "white_red_blue", 
                "blue_white_red", "blue_red_white",
                "red_white_blue", "red_blue_white"
            };
            std::string inputConfig = this->seeker.seekCorner(cube, possibilities);
            std::string sequence = this->proc.process("");
            cube = this->mover.multiMoves(cube, sequence);
            return cube;
        }
        
    public:
        StartHandler(){
            CubeMover mover;
            Cube2x2Scanner cube2x2Scanner;
            Corner2Seeker seeker;
            WBRProcessor proc;
        }

        /**
         * Find and put the first corner on the right place
         * @author: LucaGoubelle
         */
        Cube handle(Cube cube){
            std::string preResult = this->cube2x2Scanner.scanCorner(cube, "down_front_right");
            if(preResult =="white_blue_red")
                return cube; // nothing to do
            return this->handleFirstCorner(cube);
        }
};
