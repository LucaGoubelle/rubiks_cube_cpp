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
    std::string scrambling = "???";

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
