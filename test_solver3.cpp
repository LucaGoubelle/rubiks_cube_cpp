#include <iostream>

#include "rubikpp/all.hpp"
#include "solver3x3/all.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "begin program..." << endl;

    // init objects
    CubeBuilder builder;
    CubePrinter printer;
    CubeMover mover;
    Cube cube = builder.build(3);
    std::string scrambling = "D2 F R2 U F L2 R F' D L' R2 U D U' F' L2 D' U2 L' U' F2 F2 R' U2 D' F D F R2 R' L2 D2 R' L' U2 R2 D2 L' F2 U2 D'";

    Solver3x3 solver;

    // first shuffle the puzzle
    cube = mover.multiMoves(cube, scrambling);
    cout << printer.printCube(cube) << endl;

    cout << "\n----------------------------------------------------------------\n" << endl;

    // then solve
    cube = solver.solve(cube);
    cout << printer.printCube(cube) << endl;

    return 0;
}
