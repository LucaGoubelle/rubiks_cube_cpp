#include <iostream>

#include "rubikpp/all.hpp"
#include "solversCube/solver7x7/all.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "begin program..." << endl;

    // init object
    CubeBuilder builder;
    CubePrinter printer;
    CubeMover mover;
    Cube cube = builder.build(7);
    std::string scrambling = "???";

    Solver7x7 solver;
    
    // first, shuffle the puzzle
    cube = mover.multiMoves(cube, scrambling);
    cout << printer.printCube(cube) << endl;

    // then, solving the puzzle
    cube = solver.solve(cube);
    cout << printer.printCube(cube) << endl;

    cout << "end program..." << endl;
    
    return 0;
}
