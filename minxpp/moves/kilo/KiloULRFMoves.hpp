#pragma once
#include "../../data/models/kilominx.hpp"
#include "KiloMoves.hpp"

class KiloULRFMoves : public KilominxMoves {
    public:
        Kilominx moveU(Kilominx minx){
            minx.up = this->rotateUtils.rotate(minx.up);

            Face newLeft = this->rotateUtils.genEmptyFace();
            Face newFront = this->rotateUtils.genEmptyFace();
            Face newRight = this->rotateUtils.genEmptyFace();
            Face newBackLeft = this->rotateUtils.genEmptyFace();
            Face newBackRight = this->rotateUtils.genEmptyFace();

            for(int i=0;i<2;i++){
                newLeft[i] = minx.front[i];
                newRight[i] = minx.backRight[i];
                newFront[i] = minx.right[i];
                newBackLeft[i] = minx.left[i];
                newBackRight[i] = minx.backLeft[i];
            }

            minx.left = this->rotateUtils.transfert(minx.left, newLeft);
            minx.right = this->rotateUtils.transfert(minx.right, newRight);
            minx.front = this->rotateUtils.transfert(minx.front, newFront);
            minx.backLeft = this->rotateUtils.transfert(minx.backLeft, newBackLeft);
            minx.backRight = this->rotateUtils.transfert(minx.backRight, newBackRight);

            return minx;
        }

        Kilominx moveUPrime(Kilominx minx){
            for(int i=0;i<4;i++)
                minx = this->moveU(minx);
            return minx;
        }

        Kilominx moveU2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveU(minx);
            return minx;
        }


        Kilominx moveL(Kilominx minx){
            minx.left = this->rotateUtils.rotate(minx.left);
    
            Face newUp = {"", "", "", minx.backLeft[1], minx.backLeft[2]};
            Face newFront = {minx.up[4], "", "", "", minx.up[3]};
            Face newDownLeft = {minx.front[0], "", "", "", minx.front[4]};
            Face newBackLeft = {"", minx.absLeft[0], minx.absLeft[1], "", ""};
            Face newAbsLeft = {minx.downLeft[4], minx.downLeft[0], "", "", ""};
        
            minx.up = this->rotateUtils.transfert(minx.up, newUp);
            minx.front = this->rotateUtils.transfert(minx.front, newFront);
            minx.downLeft = this->rotateUtils.transfert(minx.downLeft, newDownLeft);
            minx.backLeft = this->rotateUtils.transfert(minx.backLeft, newBackLeft);
            minx.absLeft = this->rotateUtils.transfert(minx.absLeft, newAbsLeft);
        
            return minx;
        }

        Kilominx moveLPrime(Kilominx minx){
            for(int i=0;i<4;i++)
                minx = this->moveL(minx);
            return minx;
        }

        Kilominx moveL2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveL(minx);
            return minx;
        }


        Kilominx moveR(Kilominx minx){
            minx.right = this->rotateUtils.rotate(minx.right);
    
            Face newUp = {"", minx.front[1], minx.front[2], "", ""};
            Face newFront = {"", minx.downRight[0], minx.downRight[1], "", ""};
            Face newBackRight = {minx.up[2], "", "", "", minx.up[1]};
            Face newAbsRight = {minx.backRight[0], "", "", "", minx.backRight[4]};
            Face newDownRight = {minx.absRight[4], minx.absRight[0], "", "", ""};
            
            minx.up = this->rotateUtils.transfert(minx.up, newUp);
            minx.front = this->rotateUtils.transfert(minx.front, newFront);
            minx.backRight = this->rotateUtils.transfert(minx.backRight, newBackRight);
            minx.absRight = this->rotateUtils.transfert(minx.absRight, newAbsRight);
            minx.downRight = this->rotateUtils.transfert(minx.downRight, newDownRight);
        
            return minx;
        }

        Kilominx moveRPrime(Kilominx minx){
            for(int i=0;i<4;i++)
                minx = this->moveR(minx);
            return minx;
        }

        Kilominx moveR2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveR(minx);
            return minx;
        }


        Kilominx moveF(Kilominx minx){
            minx.front = this->rotateUtils.rotate(minx.front);
    
            Face newUp = {"", "", minx.left[1], minx.left[2], ""};
            Face newLeft = {"", minx.downLeft[0], minx.downLeft[1], "", ""};
            Face newRight = {minx.up[3], "", "", "", minx.up[2]};
            Face newDownLeft = {minx.downRight[4], minx.downRight[0], "", "", ""};
            Face newDownRight = {minx.right[0], "", "", "", minx.right[4]};
        
            minx.up = this->rotateUtils.transfert(minx.up, newUp);
            minx.left = this->rotateUtils.transfert(minx.left, newLeft);
            minx.right = this->rotateUtils.transfert(minx.right, newRight);
            minx.downLeft = this->rotateUtils.transfert(minx.downLeft, newDownLeft);
            minx.downRight = this->rotateUtils.transfert(minx.downRight, newDownRight);
        
            return minx;
        }

        Kilominx moveFPrime(Kilominx minx){
            for(int i=0;i<4;i++)
                minx = this->moveF(minx);
            return minx;
        }

        Kilominx moveF2(Kilominx minx){
            for(int i=0;i<2;i++)
                minx = this->moveF(minx);
            return minx;
        }
};
