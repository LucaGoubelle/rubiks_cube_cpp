#pragma once
#include <algorithm>

#include "../scanners/Cube3x3Scanner.hpp"

class Corner3Seeker {
private:
    Cube3x3Scanner cube3x3Scanner;
public:
    Corner3Seeker(){
        Cube3x3Scanner cube3x3Scanner;
    }

    std::string seekCorner(Cube cube, std::vector<std::string> posibilities){
        // return orient + colors
        std::string targetedOrient = "";
        std::string targetedColors = "";
        std::map<std::string, std::string> corners = this->cube3x3Scanner.scanCorners(cube);
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
