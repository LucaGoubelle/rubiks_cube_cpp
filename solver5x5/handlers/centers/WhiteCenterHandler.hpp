#pragma once

#include "../../../rubikpp/data/cube.hpp"
#include "../../../rubikpp/moves/mover.hpp"

class WhiteCenterHandler {
    private:
        CubeMover mover;

        // ##################################
        // ###### white center bar  #########
        // ##################################

        Cube solveWhiteCenterBar(Cube cube){
            // check the top of cube first
            std::vector<std::string> topCenterEdges;
            topCenterEdges.push_back(cube.up[1][2]);
            topCenterEdges.push_back(cube.up[2][1]);
            topCenterEdges.push_back(cube.up[2][3]);
            topCenterEdges.push_back(cube.up[3][2]);
            
            // already done step case
            if(this->_whiteCenterBarDone(topCenterEdges)){
                if(topCenterEdges[1] == "white" && topCenterEdges[2] == "white")
                    cube = this->mover.simpleMove(cube, "U");
                return cube;
            }

            // almost step case
            std::string almostConfig = "";
            almostConfig += (topCenterEdges[0]=="white") ? "1" : "0";
            almostConfig += (topCenterEdges[1]=="white") ? "1" : "0";
            almostConfig += (topCenterEdges[2]=="white") ? "1" : "0";
            almostConfig += (topCenterEdges[3]=="white") ? "1" : "0";

            std::map<std::string, std::string> hmapAlmost;
            hmapAlmost["1100"] = "Lw' U Lw U";
            hmapAlmost["1010"] = "Rw U' Rw' U";
            hmapAlmost["0101"] = "Lw U' Lw' U'";
            hmapAlmost["0011"] = "Rw U Rw' U";

            std::map<std::string, std::string> hmapAlmostAlmost;
            hmapAlmostAlmost["1000"] = "up";
            hmapAlmostAlmost["0100"] = "left";
            hmapAlmostAlmost["0010"] = "right";
            hmapAlmostAlmost["0001"] = "down";

            if(hmapAlmost.count(almostConfig)){
                cube = this->mover.multiMoves(cube, hmapAlmost[almostConfig]);
                return cube;
            } else if(hmapAlmostAlmost.count(almostConfig)) {
                // todo: insert the missing centerEdge
                return this->searchOneCenterEdge(cube, hmapAlmostAlmost[almostConfig]);
            } else {
                // todo: implement logic of solve white center bar
                return cube;
            }
        }

        bool _whiteCenterBarDone(std::vector<std::string> topCenterEdges){
            bool cond1 = topCenterEdges[0] == "white" && topCenterEdges[3] == "white";
            bool cond2 = topCenterEdges[1] == "white" && topCenterEdges[2] == "white";
            return cond1 || cond2;
        }

        Cube searchOneCenterEdge(Cube cube, std::string orientDone){
            // fix the one done
            std::map<std::string, std::string> hmapOrientDone;
            hmapOrientDone["up"] = "U'";
            hmapOrientDone["down"] = "U";
            hmapOrientDone["right"] = "U2";
            cube = (hmapOrientDone.count(orientDone)) ? this->mover.simpleMove(cube, hmapOrientDone[orientDone]) : cube;

            // todo: implement search one piece white center edge logic

            return cube;
        }

        std::string _searchFirstWhiteCenterEdge(Cube cube){
            // search for a random matching piece (the first white)
            std::string result = "";
            std::map<std::string, std::string> hmapCenterEdges;
            hmapCenterEdges["front:up"] = cube.front[1][2];
            hmapCenterEdges["front:down"] = cube.front[3][2];
            hmapCenterEdges["front:left"] = cube.front[2][1];
            hmapCenterEdges["front:right"] = cube.front[2][3];

            hmapCenterEdges["left:up"] = cube.left[1][2];
            hmapCenterEdges["left:down"] = cube.left[3][2];
            hmapCenterEdges["left:left"] = cube.left[2][1];
            hmapCenterEdges["left:right"] = cube.left[2][3];

            hmapCenterEdges["right:up"] = cube.right[1][2];
            hmapCenterEdges["right:down"] = cube.right[3][2];
            hmapCenterEdges["right:left"] = cube.right[2][1];
            hmapCenterEdges["right:right"] = cube.right[2][3];

            hmapCenterEdges["back:up"] = cube.back[1][2];
            hmapCenterEdges["back:down"] = cube.back[3][2];
            hmapCenterEdges["back:left"] = cube.back[2][1];
            hmapCenterEdges["back:right"] = cube.back[2][3];

            hmapCenterEdges["down:up"] = cube.down[1][2];
            hmapCenterEdges["down:down"] = cube.down[3][2];
            hmapCenterEdges["down:left"] = cube.down[2][1];
            hmapCenterEdges["down:right"] = cube.down[2][3];

            for(auto const& entry : hmapCenterEdges){
                if(entry.first=="white")
                    return entry.first;
            }

            //otherwise
            return "???";
        }

        // ##################################
        // ###### white side bars  ##########
        // ##################################


    public:
        WhiteCenterHandler(){
            CubeMover mover;
        }

        Cube handle(Cube cube){
            // implement this
            cube = this->solveWhiteCenterBar(cube);
            return cube;
        }
};
