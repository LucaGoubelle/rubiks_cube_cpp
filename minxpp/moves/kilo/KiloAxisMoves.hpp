#pragma once
#include "../../data/models/kilominx.hpp"

class KiloAxisMoves {
    public:
        Kilominx moveY(Kilominx minx){
            //todo: implement this
            return minx;
        }

        Kilominx moveYPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveY(minx);
            return minx;
        }

        Kilominx moveY2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveY(minx);
            return minx;
        }


        Kilominx moveX(Kilominx minx){
            //todo: implement this
            return minx;
        }

        Kilominx moveXPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveX(minx);
            return minx;
        }

        Kilominx moveX2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveX(minx);
            return minx;
        }


        Kilominx moveZ(Kilominx minx){
            //todo: implement this
            return minx;
        }

        Kilominx moveZPrime(Kilominx minx){
            for(int i=0;i<3;i++)
                minx = this->moveZ(minx);
            return minx;
        }

        Kilominx moveZ2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveZ(minx);
            return minx;
        }
};
