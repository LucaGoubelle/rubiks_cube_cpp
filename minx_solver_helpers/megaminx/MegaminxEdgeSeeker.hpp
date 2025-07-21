#pragma once
#include <algorithm>
#include "MegaminxScanner.hpp"

class MegaminxEdgeSeeker {
    private:
        MegaminxScanner scanner;
    public:
        MegaminxEdgeSeeker(){
            MegaminxScanner scanner;
        }

        std::string seekEdge(Megaminx minx, std::vector<std::string> posibilities){
            std::string targetedOrient = "";
            std::string targetedColors = "";
            std::map<std::string, std::string> edges = this->scanner.scanEdges(minx);
            for(auto const& x : edges){
                if(std::find(posibilities.begin(), posibilities.end(), x.second)!=posibilities.end()){
                    targetedOrient = x.first;
                    targetedColors = x.second;
                    break;
                }
            }
            return targetedOrient+"::"+targetedColors;
        }
};