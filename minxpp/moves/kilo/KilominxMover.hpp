#pragma once
#include "../../data/models/kilominx.hpp"
#include "../minx_mover.hpp"

class KilominxMover : public MinxMover {
    public:
        Kilominx simpleMove(Kilominx minx, std::string mv){
            //todo: implement this
            return minx;
        }

        Kilominx multiMoves(Kilominx minx, std::string mvs){
            std::vector<std::string> mvVec = this->split(mvs, ' ');
            for(std::string mv : mvVec)
                minx = this->simpleMove(minx, mv);
            return minx;
        }
};