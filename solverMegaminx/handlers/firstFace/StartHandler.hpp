#pragma once

#include "../../../minxpp/data/models/megaminx.hpp"
#include "../../../minx_solver_helpers/all.hpp"

class StartHandler {
    private:
        MegaminxScanner scanner;

        Megaminx _startOrienting(Megaminx minx, std::string data){
            // implement this
            return minx;
        }
    
    public:
        StartHandler(){
            MegaminxScanner scanner;
        }

        Megaminx handle(Megaminx minx){
            std::string centerDown = scanner.scanCenter(minx, "down");
            std::string centerDownLeft = scanner.scanCenter(minx, "downLeft");
            std::string centerDownRight = scanner.scanCenter(minx, "downRight");
            std::string data = centerDown+"_"+centerDownLeft+"_"+centerDownRight;
            if(data=="white_blue_red")
                return minx;
            return this->_startOrienting(minx, data);
        }

    
};
