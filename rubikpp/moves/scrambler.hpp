#pragma once
#include "../data/cube.hpp"
#include "../exceptions/ScramblerException.hpp"
#include "moves.hpp"

class CubeScrambler {
private:
    CubeMover mover;

    /**
     * return a random integer between min and max
     * @param nMin 
     * @param nMax 
     * @return int 
     */
    int RandU(int nMin, int nMax)
    {
        return nMin + (int)((double)rand() / (RAND_MAX+1) * (nMax-nMin+1));
    }
public:
    CubeScrambler(){
        CubeMover mover;
    }

    /**
     * @brief Scramble a given cube, return the altered cube
     * @author LucaGoubelle
     * @param cube 
     * @return Cube 
     */
    Cube scramble(Cube cube){
        try{
            std::vector<std::string> scrambles = {
                "U' R2 F U F2 R U2 F' R U2 F R' F R F U2 F U' F2 R2 F2 U2 F' U2 R",
                "U F U2 R2 F R' F2 R2 F2 U R2 F' R2 U R2 F U2 F2 U2 F2 R' F' U2 F2 U2",
                "F' R2 F2 R2 U' F R U2 F R2 F R' U2 R' U F' U2 F2 U' F' R2 U' F2 U2 R2",
                "U R' F R2 F2 R' F' R2 U F' R2 U R' F2 U' R2 U' R' U' F2 R F' R2 U R'",
                "U' F' U' F' R2 F2 U' R2 U F' U2 F2 U' F U R U2 F' R F' U R' F' R' U'"
            };
            // int randint = RandU(0,4);
            std::string scramble = scrambles[0];
            cube = this->mover.multiMoves(cube, scramble);
            return cube;
        } catch(...){
            throw ScramblerException();
        }
    }
};