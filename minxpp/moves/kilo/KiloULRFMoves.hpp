#pragma once
#include "../../data/models/kilominx.hpp"
#include "KiloMoves.hpp"

class KiloULRFMoves : public KilominxMoves {
    public:
        Kilominx moveU(Kilominx minx){
            // todo: implement this
            return minx;
        }

        Kilominx moveUPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveU(minx);
            return minx;
        }

        Kilominx moveU2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveU(minx);
            return minx;
        }


        Kilominx moveL(Kilominx minx){
            // todo: implement this
            return minx;
        }

        Kilominx moveLPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveL(minx);
            return minx;
        }

        Kilominx moveL2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveL(minx);
            return minx;
        }


        Kilominx moveR(Kilominx minx){
            // todo: implement this
            return minx;
        }

        Kilominx moveRPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveR(minx);
            return minx;
        }

        Kilominx moveR2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveR(minx);
            return minx;
        }


        Kilominx moveF(Kilominx minx){
            // todo: implement this
            return minx;
        }

        Kilominx moveFPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveF(minx);
            return minx;
        }

        Kilominx moveF2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveF(minx);
            return minx;
        }
};
