#include <iostream>

#include "rubikpp/all.hpp"
#include "solversCube/solver6x6/all.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "begin program..." << endl;

    // init object
    CubeBuilder builder;
    CubePrinter printer;
    CubeMover mover;
    Cube cube = builder.build(6);
    std::string scrambling = "???";

    Solver6x6 solver;

    // first shuffle the puzzle
    cube = mover.multiMoves(cube, scrambling);
    cout << printer.printCube(cube) << endl;

    // then solve
    cube = solver.solve(cube);
    cout << printer.printCube(cube) << endl;

    cout << "end program..." << endl;
    
    return 0;
}
