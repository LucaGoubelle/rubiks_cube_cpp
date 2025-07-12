#pragma once
#include <algorithm>

#include "MegaminxScanner.hpp"

class MegaminxCornerSeeker {
    private:
        MegaminxScanner scanner;
    public:
        MegaminxCornerSeeker(){
            MegaminxScanner scanner;
        }

        std::string seekCorner(Megaminx minx, std::vector<std::string> posibilities){
            std::string targetedOrient = "";
            std::string targetedColors = "";
            std::map<std::string, std::string> corners = this->scanner.scanCorners(cube);
            for(auto const& x : corners){
                if(std::find(posibilities.begin(), posibilities.end(), x.second)!=posibilities.end()){
                    targetedOrient = x.first;
                    targetedColors = x.second;
                    break;
                }
            }
            return targetedOrient+"::"+targetedColors;
        }
};