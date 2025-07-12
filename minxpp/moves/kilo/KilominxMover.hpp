#pragma once
#include "../../data/models/kilominx.hpp"
#include "../minx_mover.hpp"
#include "KiloULRFMoves.hpp"

class KilominxMover : public MinxMover {
    private:
        KiloULRFMoves ulrfMoves;
    public:
        KilominxMover(){
            KiloULRFMoves ulrfMoves;
        }

        Kilominx simpleMove(Kilominx minx, std::string mv){
            if(mv=="U") return this->ulrfMoves.moveU(minx);
            else if(mv=="U'") return this->ulrfMoves.moveUPrime(minx);
            else if(mv=="U2") return this->ulrfMoves.moveU2(minx);
            else if(mv=="L") return this->ulrfMoves.moveL(minx);
            else if(mv=="L'") return this->ulrfMoves.moveLPrime(minx);
            else if(mv=="L2") return this->ulrfMoves.moveL2(minx);
            else if(mv=="R") return this->ulrfMoves.moveR(minx);
            else if(mv=="R'") return this->ulrfMoves.moveRPrime(minx);
            else if(mv=="R2") return this->ulrfMoves.moveR2(minx);
            else if(mv=="F") return this->ulrfMoves.moveF(minx);
            else if(mv=="F'") return this->ulrfMoves.moveFPrime(minx);
            else if(mv=="F2") return this->ulrfMoves.moveF2(minx);
            //todo: add axis moves
            else return minx;
        }

        Kilominx multiMoves(Kilominx minx, std::string mvs){
            std::vector<std::string> mvVec = this->split(mvs, ' ');
            for(std::string mv : mvVec)
                minx = this->simpleMove(minx, mv);
            return minx;
        }
};