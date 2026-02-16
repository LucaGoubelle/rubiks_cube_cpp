#pragma once
#include "../../../rubikpp/data/cube.hpp"
#include "../../../solverHelpers/all.hpp"
#include "handler.hpp"

class LastLayerHandler : public Handler {
    private:
        OLLScanner ollScanner;
        std::map<std::string, std::string> hmapOLL;
        std::map<std::string, std::string> hmapPLL;
        std::map<std::string, std::string> hmapAUF;

        Cube oll(Cube cube){
            std::string crownResult = this->ollScanner.scanOLL(cube);
            return (this->hmapOLL.count(crownResult)) ? this->mover.multiMoves(cube, this->hmapOLL[crownResult]) : cube;
        }

        Cube pll(Cube cube){
            PLLScanner pllScanner;
            std::string resultScan = pllScanner.scanPLL(cube);
            return (this->hmapPLL.count(resultScan)) ? this->mover.multiMoves(cube, this->hmapPLL[resultScan]) : cube;
        }

        Cube auf(Cube cube){
            std::string result = cube.front[0][0];
            return (this->hmapAUF.count(result)) ? this->mover.simpleMove(cube, this->hmapAUF[result]) : cube;
        }
    public:
        LastLayerHandler(){
            OLLScanner ollScanner;
            // ----- OLL -------
            // anti sune
            this->hmapOLL["00_1010_0001_10"] = "R U2 R' U' R U' R'";
            // H case
            this->hmapOLL["11_0000_0000_11"] = CubeAlgorithms::H_ORIENT;
            this->hmapOLL["00_1001_1001_00"] = "U "+CubeAlgorithms::H_ORIENT;
            //Pi case
            this->hmapOLL["01_1000_1000_01"] = CubeAlgorithms::PI_ORIENT;
            //todo: implement them
            //T cases
            //todo: implement them
            //U cases
            //todo: implement them
            // ----- PLL -------
            //T PERM
            this->hmapPLL["BR_GB_RG_OO"] = CubeAlgorithms::T_PERM;
            this->hmapPLL["OO_BR_GB_RG"] = "U "+CubeAlgorithms::T_PERM;
            this->hmapPLL["GB_RG_OO_BR"] = "U' "+CubeAlgorithms::T_PERM;
            this->hmapPLL["RG_OO_BR_GB"] = "U2 "+CubeAlgorithms::T_PERM;
            //Y PERM
            this->hmapPLL["BG_OR_GB_RO"] = CubeAlgorithms::Y_PERM;
            this->hmapPLL["RO_BG_OR_GB"] = CubeAlgorithms::Y_PERM;
            this->hmapPLL["OR_GB_RO_BG"] = CubeAlgorithms::Y_PERM;
            this->hmapPLL["GB_RO_BG_OR"] = CubeAlgorithms::Y_PERM;
            // todo : implement remaining cases if needed

            // ------ AUF -----------
            this->hmapAUF["green"] = "U2";
            this->hmapAUF["orange"] = "U";
            this->hmapAUF["red"] = "U'";
        }

        Cube handle(Cube cube){
            cube = this->oll(cube);
            cube = this->pll(cube);
            cube = this->auf(cube);
            return cube;
        }
};
