#pragma once
#include <string>

/**
* Cube Algorithms, from basics to advanced
*/
struct CubeAlgorithms
{
    // BASICS
    inline static const std::string SEXY_MOVES = "R U R' U'";
    inline static const std::string ELEVATOR = "R U R' U' R U R' U' R U R' U'";
    inline static const std::string THREE_MOVES = "R U R'";
    inline static const std::string EDGE_CONTROL = "R' F R F'";
    inline static const std::string LEFT_BELGIUM = "U' L' U L U F U' F'";
    inline static const std::string RIGHT_BELGIUM = "U R U' R' U' F' U F";
    inline static const std::string FRIENDS = "R U' L' U R' U' L U";

    // OLLs
    inline static const std::string SUNE_ORIENT = "R U R' U R U2 R'";
    inline static const std::string ANTISUNE_ORIENT = "R U2 R' U' R U' R'";
    inline static const std::string U_ORIENT = "R2 D R' U2 R D' R' U2 R'";
    inline static const std::string T_ORIENT = "Rw U R' U' L' U R U' x'";
    inline static const std::string L_ORIENT = "Lw' U R D' R' U' R D x'";
    inline static const std::string H_ORIENT = "F R U R' U' R U R' U' R U R' U' F'";
    inline static const std::string PI_ORIENT = "R U2 R2 U' R2 U' R2 U2 R";

    // PLL
    inline static const std::string T_PERM = "R U R' U' R' F R2 U' R' U' R U R' F'";
    inline static const std::string J_PERM = "R U R' F' R U R' U' R' F R2 U' R' U'";
    inline static const std::string Y_PERM = "F R U' R' U' R U R' F' R U R' U' R' F R F'";
};
