#pragma once
#include <algorithm>
#include "KilominxScanner.hpp"

class KilominxCornerSeeker {
    private:
        KilominxScanner scanner;
    public:
        KilominxCornerSeeker(){
            KilominxScanner scanner;
        }

        /**
        * Seek for a specific corner, return his orientations + colors in a string
        * @author: LucaGoubelle
        */
        std::string seekCorner(Kilominx minx, std::vector<std::string> posibilities){
            std::string targetedOrient = "";
            std::string targetedColors = "";
            std::map<std::string, std::string> corners = this->scanner.scanCorners(minx);
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