#include <iostream>

#include "rubikpp/all.hpp"

using namespace std;

int main(int argc, char** argv){
    CubeBuilder builder;
    CubePrinter printer;
    Cube cube = builder.build(3);

    cout << printer.printCube(cube) << endl;

    cout << endl;
    cout << endl;

    DSVSaveHandler saveHandler;
    saveHandler.save(cube, "test.dsv");

    cube = saveHandler.loadSave("test.dsv");
    cout << printer.printCube(cube) << endl;
    
    return 0;
}

