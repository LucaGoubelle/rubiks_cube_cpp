#include <iostream>

#include "rubikpp/all.hpp"
#include "solver4x4/all.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "begin program..." << endl;

    // init objects
    CubeBuilder builder;
    CubePrinter printer;
    CubeMover mover;
    Cube cube = builder.build(4);
    std::string scrambling = "???";

    Solver4x4 solver;

    // first shuffle the puzzle
    cube = mover.multiMoves(cube, scrambling);
    cout << printer.printCube(cube) << endl;

    // then solve
    cube = solver.solve(cube);
    cout << printer.printCube(cube) << endl;

    cout << "end program..." << endl;
    
    return 0;
}
