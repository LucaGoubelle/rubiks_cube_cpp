#pragma once
#include <map>
#include <sstream>

#include "../data/cube.hpp"
#include "../exceptions/MoverException.hpp"

#include "moves.hpp"
#include "wmoves.hpp"
#include "axis_moves.hpp"

class CubeMover {
private:
    AxisMoves axisMoves;
    WMoves wMoves;

    int getMoveCode(std::string mv){
        std::map<std::string, int> hmap;
        hmap["U"] = 1; 
        hmap["U'"] = 2; 
        hmap["U2"] = 3;

        hmap["D"] = 4; 
        hmap["D'"] = 5; 
        hmap["D2"] = 6;

        hmap["L"] = 7; 
        hmap["L'"] = 8; 
        hmap["L2"] = 9;

        hmap["R"] = 10; 
        hmap["R'"] = 11; 
        hmap["R2"] = 12;

        hmap["F"] = 13; 
        hmap["F'"] = 14;
        hmap["F2"] = 15;

        hmap["y"] = 16; 
        hmap["y'"] = 17; 
        hmap["y2"] = 18;

        hmap["x"] = 19; 
        hmap["x'"] = 20; 
        hmap["x2"] = 21;

        hmap["z"] = 22; 
        hmap["z'"] = 23; 
        hmap["z2"] = 24;

        hmap["Uw"] = 25;
        hmap["Uw'"] = 26;
        hmap["Uw2"] = 27;

        hmap["Dw"] = 28;
        hmap["Dw'"] = 29;
        hmap["Dw2"] = 30;

        hmap["Rw"] = 31;
        hmap["Rw'"] = 32;
        hmap["Rw2"] = 33;

        hmap["Lw"] = 34;
        hmap["Lw'"] = 35;
        hmap["Lw2"] = 36;

        hmap["Fw"] = 37;
        hmap["Fw'"] = 38;
        hmap["Fw2"] = 39;

        hmap["Uww"] = 40;
        hmap["Uww'"] = 41;
        hmap["Uww2"] = 42;

        hmap["Dww"] = 43;
        hmap["Dww'"] = 44;
        hmap["Dww2"] = 45;

        hmap["Rww"] = 46;
        hmap["Rww'"] = 47;
        hmap["Rww2"] = 48;

        hmap["Lww"] = 49;
        hmap["Lww'"] = 50;
        hmap["Lww2"] = 51;

        hmap["Fww"] = 52;
        hmap["Fww'"] = 53;
        hmap["Fww2"] = 54;

        int code = (hmap.count(mv)==1) ? hmap[mv] : 0 ;
        return code;
    }

    std::vector<std::string> split(std::string str, char del){
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string temp = "";
        while(getline(ss, temp, del))
            result.push_back(temp);
        return result;
    }

public:
    CubeMover(){
        AxisMoves axisMoves;
        WMoves wMoves;
    }

    /**
     * @brief Rotate the cube based on mv param
     * @author LucaGoubelle
     * @param cube 
     * @param mv 
     * @return Cube 
     */
    Cube simpleMove(Cube cube, std::string mv){
        int code = this->getMoveCode(mv);
        switch(code){
            case 1: cube = moveU(cube); break;
            case 2: cube = moveUPrime(cube); break;
            case 3: cube = moveU2(cube); break;
            case 4: cube = moveD(cube); break;
            case 5: cube = moveDPrime(cube); break;
            case 6: cube = moveD2(cube); break;
            case 7: cube = moveL(cube); break;
            case 8: cube = moveLPrime(cube); break;
            case 9: cube = moveL2(cube); break;
            case 10: cube = moveR(cube); break;
            case 11: cube = moveRPrime(cube); break;
            case 12: cube = moveR2(cube); break;
            case 13: cube = moveF(cube); break;
            case 14: cube = moveFPrime(cube); break;
            case 15: cube = moveF2(cube); break;
            case 16: cube = this->axisMoves.moveY(cube); break;
            case 17: cube = this->axisMoves.moveYPrime(cube); break;
            case 18: cube = this->axisMoves.moveY2(cube); break;
            case 19: cube = this->axisMoves.moveX(cube); break;
            case 20: cube = this->axisMoves.moveXPrime(cube); break;
            case 21: cube = this->axisMoves.moveX2(cube); break;
            case 22: cube = this->axisMoves.moveZ(cube); break;
            case 23: cube = this->axisMoves.moveZPrime(cube); break;
            case 24: cube = this->axisMoves.moveZ2(cube); break;
            case 25: cube = this->wMoves.moveUw(cube); break;
            case 26: cube = this->wMoves.moveUwPrime(cube); break;
            case 27: cube = this->wMoves.moveUw2(cube); break;
            case 28: cube = this->wMoves.moveDw(cube); break;
            case 29: cube = this->wMoves.moveDwPrime(cube); break;
            case 30: cube = this->wMoves.moveDw2(cube); break;
            case 31: cube = this->wMoves.moveRw(cube); break;
            case 32: cube = this->wMoves.moveRwPrime(cube); break;
            case 33: cube = this->wMoves.moveRw2(cube); break;
            case 34: cube = this->wMoves.moveLw(cube); break;
            case 35: cube = this->wMoves.moveLwPrime(cube); break;
            case 36: cube = this->wMoves.moveLw2(cube); break;
            case 37: cube = this->wMoves.moveFw(cube); break;
            case 38: cube = this->wMoves.moveFwPrime(cube); break;
            case 39: cube = this->wMoves.moveFw2(cube); break;
            case 40: cube = this->wMoves.moveUw(cube, 3); break;
            case 41: cube = this->wMoves.moveUwPrime(cube, 3); break;
            case 42: cube = this->wMoves.moveUw2(cube, 3); break;
            case 43: cube = this->wMoves.moveDw(cube, 3); break;
            case 44: cube = this->wMoves.moveDwPrime(cube, 3); break;
            case 45: cube = this->wMoves.moveDw2(cube, 3); break;
            case 46: cube = this->wMoves.moveRw(cube, 3); break;
            case 47: cube = this->wMoves.moveRwPrime(cube, 3); break;
            case 48: cube = this->wMoves.moveRw2(cube, 3); break;
            case 49: cube = this->wMoves.moveLw(cube, 3); break;
            case 50: cube = this->wMoves.moveLwPrime(cube, 3); break;
            case 51: cube = this->wMoves.moveLw2(cube, 3); break;
            case 52: cube = this->wMoves.moveFw(cube, 3); break;
            case 53: cube = this->wMoves.moveFwPrime(cube, 3); break;
            case 54: cube = this->wMoves.moveFw2(cube, 3); break;
            default: break;
        }
        return cube;
    }

    /**
     * @brief rotate multiple times the cube, provide a string of moves with the cube param
     * @author: LucaGoubelle
     * @param cube 
     * @param mvs 
     * @return Cube 
     */
    Cube multiMoves(Cube cube, std::string mvs){
        try{
            std::vector<std::string> arrayMoves = this->split(mvs, ' ');
            for(std::string mv : arrayMoves)
                cube = this->simpleMove(cube, mv);
            return cube;
        } catch(...){
            throw MoverException();
        }
    }
};
