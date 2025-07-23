#include <iostream>

#include "rubikpp/all.hpp"
#include "solver5x5/all.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "begin program..." << endl;

    // init objects
    CubeBuilder builder;
    CubePrinter printer;
    CubeMover mover;
    Cube cube = builder.build(5);
    std::string scrambling = "Uw' F2 L2 Dw2 Fw2 Lw' D2 Uw Rw D' L' Uw Fw2 Uw' D R Bw' Rw2 D Dw2 Dw' B D' L Uw D R' D' R2 ";
    scrambling += "D Rw Dw' U' Fw2 D' R Uw2 Lw' Dw2 Lw' B2 Rw' Dw2 Uw2 F' Uw Dw Rw' D2 D Lw Uw2 B2 Rw' Fw R F2 L2 Rw2 Uw ";

    Solver5x5 solver;

    // first shuffle the puzzle
    cube = mover.multiMoves(cube, scrambling);
    cout << printer.printCube(cube) << endl;

    // then solve
    cube = solver.solve(cube);
    cout << printer.printCube(cube) << endl;

    cout << "end program..." << endl;
    
    return 0;
}
