#pragma once

#include "../../../minxpp/data/models/kilominx.hpp"
#include "../../../minx_solver_helpers/all.hpp"

class StartHandler {
    private:
        KilominxScanner scanner;

        Kilominx _handleFirstCorner(Kilominx minx){
            //todo: implement this
            return minx;
        }
    public:
        StartHandler(){
            KilominxScanner scanner;
        }
    
        Kilominx handle(Kilominx minx){
            //todo: implement this
            std::string cornerDownLeftRight = this->scanner.scanCorner(minx, "down_downLeft_downRight");
            if(cornerDownLeftRight == "white_blue_red")
                return minx; // nothing to do
            return this->_handleFirstCorner(minx);
        }
};