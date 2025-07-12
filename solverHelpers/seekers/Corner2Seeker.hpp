#pragma once
#include <algorithm>

#include "../scanners/Cube2x2Scanner.hpp"

class Corner2Seeker {
    private:
        Cube2x2Scanner cube2x2Scanner;
    public:
        Corner2Seeker(){
            Cube2x2Scanner cube2x2Scanner;
        }

        std::string seekCorner(Cube cube, std::vector<std::string> posibilities){
            std::string targetedOrient = "";
            std::string targetedColors = "";
            std::map<std::string, std::string> corners = this->cube2x2Scanner.scanCorners(cube);
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
