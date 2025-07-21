#pragma once
#include "../../data/models/kilominx.hpp"
#include "../minx_mover.hpp"
#include "KiloULRFMoves.hpp"
#include "KiloAxisMoves.hpp"

class KilominxMover : public MinxMover {
    private:
        KiloULRFMoves ulrfMoves;
        KiloAxisMoves axisMoves;
    public:
        KilominxMover(){
            KiloULRFMoves ulrfMoves;
            KiloAxisMoves axisMoves;
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

            else if(mv=="x") return this->axisMoves.moveX(minx);
            else if(mv=="x'") return this->axisMoves.moveXPrime(minx);
            else if(mv=="x2") return this->axisMoves.moveX2(minx);
            else if(mv=="y") return this->axisMoves.moveY(minx);
            else if(mv=="y'") return this->axisMoves.moveYPrime(minx);
            else if(mv=="y2") return this->axisMoves.moveY2(minx);
            else if(mv=="z") return this->axisMoves.moveZ(minx);
            else if(mv=="z'") return this->axisMoves.moveZPrime(minx);
            else if(mv=="z2") return this->axisMoves.moveZ2(minx);

            else return minx;
        }
};
