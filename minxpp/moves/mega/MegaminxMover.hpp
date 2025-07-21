#pragma once

#include "../minx_mover.hpp"
#include "../../data/models/megaminx.hpp"

class MegaminxMover : public MinxMover {
    public:
        Megaminx simpleMove(Megaminx minx, std::string mv){
            //todo: implement this
            return minx;
        }

        Megaminx multiMoves(Megaminx minx, std::string mvs){
            std::vector<std::string> mvVec = this->split(mvs, ' ');
            for(std::string mv : mvVec)
                minx = this->simpleMove(minx, mv);
            return minx;
        }
};