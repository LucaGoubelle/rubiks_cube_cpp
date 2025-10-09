#pragma once
#include "../../../rubikpp/data/cube.hpp"
#include "../../../solverHelpers/all.hpp"
#include "handler.hpp"

class LastLayerHandler : public Handler {
    private:
        OLLScanner ollScanner;

        Cube oll(Cube cube){
            // todo : implement other case in hmap
            std::string crownResult = this->ollScanner.scanOLL(cube);

            std::map<std::string, std::string> hmap;
            
            // anti sune
            hmap["00_1010_0001_10"] = "R U2 R' U' R U' R'";

            // H case
            hmap["11_0000_0000_11"] = CubeAlgorithms::H_ORIENT;
            hmap["00_1001_1001_00"] = "U "+CubeAlgorithms::H_ORIENT;

            //Pi case
            hmap["01_1000_1000_01"] = CubeAlgorithms::PI_ORIENT;

            //T cases

            //U cases

            return (hmap.count(crownResult)) ? this->mover.multiMoves(cube, hmap[crownResult]) : cube;
        }

        Cube pll(Cube cube){
            // todo : implement this
            PLLScanner pllScanner;
            std::string resultScan = pllScanner.scanPLL(cube);
            std::map<std::string, std::string> hmap;

            //T perm
            hmap["BR_GB_RG_OO"] = CubeAlgorithms::T_PERM;
            hmap["OO_BR_GB_RG"] = "U "+CubeAlgorithms::T_PERM;
            hmap["GB_RG_OO_BR"] = "U' "+CubeAlgorithms::T_PERM;
            hmap["RG_OO_BR_GB"] = "U2 "+CubeAlgorithms::T_PERM;

            //Y Perm
            hmap["BG_OR_GB_RO"] = CubeAlgorithms::Y_PERM;
            hmap["RO_BG_OR_GB"] = CubeAlgorithms::Y_PERM;
            hmap["OR_GB_RO_BG"] = CubeAlgorithms::Y_PERM;
            hmap["GB_RO_BG_OR"] = CubeAlgorithms::Y_PERM;

            return (hmap.count(resultScan)) ? this->mover.multiMoves(cube, hmap[resultScan]) : cube;
        }

        Cube auf(Cube cube){
            std::string result = cube.front[0][0];
            std::map<std::string, std::string> hmap;

            hmap["green"] = "U2";
            hmap["orange"] = "U";
            hmap["red"] = "U'";

            return (hmap.count(result)) ? this->mover.simpleMove(cube, hmap[result]) : cube;
        }
    public:
        LastLayerHandler(){
            OLLScanner ollScanner;
        }

        Cube handle(Cube cube){
            cube = this->oll(cube);
            cube = this->pll(cube);
            cube = this->auf(cube);
            return cube;
        }
};
