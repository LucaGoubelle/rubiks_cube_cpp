#pragma once

#include "../scanners/Cube3x3Scanner.hpp"

class Edge3Seeker {
    private:
        Cube3x3Scanner cube3x3Scanner;
    public:

        Edge3Seeker(){
            Cube3x3Scanner cube3x3Scanner;
        }

        // deprecated => to remove
        std::string seekEdge(Cube cube, std::string colors1, std::string colors2){
            // get the piece orientation
            std::string targetedOrient = "";
            std::map<std::string, std::string> edges = this->cube3x3Scanner.scanEdges(cube);
            for(auto const& x : edges){
                if(x.second == colors1 || x.second == colors2){
                    targetedOrient = x.first;
                    break;
                }
            }
            return targetedOrient;
        }

        /**
        * Return the info of an edge seeked
        * @author: LucaGoubelle
        */
        std::string seekEdgeInfos(Cube cube, std::string colors1, std::string colors2){
            // get the piece orientation
            std::string targetedOrient = "";
            std::string targetedColor = "";
            std::map<std::string, std::string> edges = this->cube3x3Scanner.scanEdges(cube);
            for(auto const& x : edges){
                if(x.second == colors1 || x.second == colors2){
                    targetedOrient = x.first;
                    targetedColor = x.second;
                    break;
                }
            }
            return targetedOrient+"::"+targetedColor;
        }
};