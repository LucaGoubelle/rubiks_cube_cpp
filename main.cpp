#include <iostream>

#include "rubikpp/all.hpp"

using namespace std;

int main(int argc, char** argv){
    CubeBuilder builder;
    CubePrinter printer;
    Cube cube = builder.build(3);

    cout << printer.printCube(cube);
    
    return 0;
}

