#include <iostream>

#include "rubikpp/all.hpp"
#include "solver2x2/all.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "begin program..." << endl;

    // init objects
    CubeBuilder builder;
    CubePrinter printer;
    CubeMover mover;
    Cube cube = builder.build(2);
    std::string scrambling = "D' U' R U2 F2 R' U' D' F'";

    Solver2x2 solver;

    // first shuffle the puzzle
    cube = mover.multiMoves(cube, scrambling);
    cout << printer.printCube(cube) << endl;

    cout << "\n----------------------------------------------------------------\n" << endl;

    // then solve
    cube = solver.solve(cube);
    cout << printer.printCube(cube) << endl;

    return 0;
}
