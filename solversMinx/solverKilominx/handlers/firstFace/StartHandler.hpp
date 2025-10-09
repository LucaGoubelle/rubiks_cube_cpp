#pragma once

#include "../../../../minxpp/data/models/kilominx.hpp"
#include "../handler.hpp"
#include "../../../../minx_solver_helpers/all.hpp"
#include "../../processors/firstCorners/wbr_processor.hpp"

class StartHandler : public Handler {
    private:
        KilominxScanner scanner;
        KilominxMover mover;
        KilominxCornerSeeker seeker;
        WBRProcessor procWBR;

        Kilominx _handleFirstCorner(Kilominx minx){
            std::vector<std::string> posibilities = {
                "white_blue_red","white_red_blue",
                "blue_white_red","blue_red_white",
                "red_white_blue","red_blue_white"
            };
            std::string inputData = this->seeker.seekCorner(minx, posibilities);
            std::string sequence = this->procWBR.process(inputData);
            minx = this->mover.multiMoves(minx, sequence);
            return minx;
        }
    public:
        StartHandler(){
            KilominxScanner scanner;
            KilominxMover mover;
            KilominxCornerSeeker seeker;
            WBRProcessor procWBR;
        }
    
        Kilominx handle(Kilominx minx){
            std::string cornerDownLeftRight = this->scanner.scanCorner(minx, "down_downLeft_downRight");
            if(cornerDownLeftRight == "white_blue_red")
                return minx; // nothing to do
            return this->_handleFirstCorner(minx);
        }
};