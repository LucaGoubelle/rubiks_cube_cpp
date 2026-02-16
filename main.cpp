#include <iostream>

#include "rubikpp/all.hpp"

using namespace std;

int main(int argc, char** argv){
    CubeBuilder builder;
    CubePrinter printer;
    DSVSaveHandler saveHandler;
    CubeStrDumper dumper;
    Cube cube = builder.build(3);

    cout << printer.printCube(cube) << endl;
    cout << dumper.dump(cube) << endl;

    cout << endl;
    cout << endl;

    saveHandler.save(cube, "test.dsv");

    cube = saveHandler.loadSave("test.dsv");
    cout << printer.printCube(cube) << endl;
    
    return 0;
}

