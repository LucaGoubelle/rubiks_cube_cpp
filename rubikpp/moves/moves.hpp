#pragma once
#include "../data/cube.hpp"
#include "helpers/move_utils.hpp"


// horizontal moves

Cube moveU(Cube cube){
    int size = cube.up.size();
    cube.up = MoveUtils::rotate(cube.up);

    Face newFront = MoveUtils::genEmptyFace(size);
    Face newLeft = MoveUtils::genEmptyFace(size);
    Face newRight = MoveUtils::genEmptyFace(size);
    Face newBack = MoveUtils::genEmptyFace(size);

    for(int i=0;i<size;i++){
        newFront[0][i] = cube.right[0][i];
        newRight[0][i] = cube.back[0][i];
        newLeft[0][i] = cube.front[0][i];
        newBack[0][i] = cube.left[0][i];
    }

    cube.front = MoveUtils::transfert(cube.front, newFront);
    cube.left = MoveUtils::transfert(cube.left, newLeft);
    cube.right = MoveUtils::transfert(cube.right, newRight);
    cube.back = MoveUtils::transfert(cube.back, newBack);

    return cube;
}

Cube moveUPrime(Cube cube){
    for(int i=0; i<3;i++)
        cube = moveU(cube);
    return cube;
}

Cube moveU2(Cube cube){
    for(int i=0; i<2;i++)
        cube = moveU(cube);
    return cube;
}

Cube moveD(Cube cube){
    int size = cube.down.size();
    cube.down = MoveUtils::rotate(cube.down);

    Face newFront = MoveUtils::genEmptyFace(size);
    Face newLeft = MoveUtils::genEmptyFace(size);
    Face newRight = MoveUtils::genEmptyFace(size);
    Face newBack = MoveUtils::genEmptyFace(size);

    for(int i=0;i<size;i++){
        newFront[size-1][i] = cube.left[size-1][i];
        newLeft[size-1][i] = cube.back[size-1][i];
        newRight[size-1][i] = cube.front[size-1][i];
        newBack[size-1][i] = cube.right[size-1][i];
    }

    cube.front = MoveUtils::transfert(cube.front, newFront);
    cube.left = MoveUtils::transfert(cube.left, newLeft);
    cube.right = MoveUtils::transfert(cube.right, newRight);
    cube.back = MoveUtils::transfert(cube.back, newBack);

    return cube;
}

Cube moveDPrime(Cube cube){
    for(int i=0; i<3;i++)
        cube = moveD(cube);
    return cube;
}

Cube moveD2(Cube cube){
    for(int i=0; i<2;i++)
        cube = moveD(cube);
    return cube;
}

// vertical moves

Cube moveL(Cube cube){
    int size = cube.left.size();
    cube.left = MoveUtils::rotate(cube.left);

    Face newUp = MoveUtils::genEmptyFace(size);
    Face newFront = MoveUtils::genEmptyFace(size);
    Face newDown = MoveUtils::genEmptyFace(size);
    Face newBack = MoveUtils::genEmptyFace(size);

    for(int i=0;i<size;i++){
        newFront[i][0] = cube.up[i][0];
        newDown[i][0] = cube.front[i][0];
        newBack[i][0] = cube.down[i][0];
        newUp[i][size-1] = cube.back[i][size-1];
    }

    cube.front = MoveUtils::transfert(cube.front, newFront);
    cube.up = MoveUtils::transfert(cube.up, MoveUtils::rotateTwice(newUp));
    cube.down = MoveUtils::transfert(cube.down, newDown);
    cube.back = MoveUtils::transfert(cube.back, MoveUtils::rotateTwice(newBack));

    return cube;
}

Cube moveLPrime(Cube cube){
    for(int i=0; i<3;i++)
        cube = moveL(cube);
    return cube;
}

Cube moveL2(Cube cube){
    for(int i=0; i<2;i++)
        cube = moveL(cube);
    return cube;
}

Cube moveR(Cube cube){
    int size = cube.right.size();
    cube.right = MoveUtils::rotate(cube.right);

    Face newFront = MoveUtils::genEmptyFace(size);
    Face newUp = MoveUtils::genEmptyFace(size);
    Face newBack = MoveUtils::genEmptyFace(size);
    Face newDown = MoveUtils::genEmptyFace(size);

    for(int i=0;i<size;i++){
        newFront[i][size-1] = cube.down[i][size-1];
        newUp[i][size-1] = cube.front[i][size-1];
        newBack[i][size-1] = cube.up[i][size-1];
        newDown[i][0] = cube.back[i][0];
    }

    cube.front = MoveUtils::transfert(cube.front, newFront);
    cube.up = MoveUtils::transfert(cube.up, newUp);
    cube.back = MoveUtils::transfert(cube.back, MoveUtils::rotateTwice(newBack));
    cube.down = MoveUtils::transfert(cube.down, MoveUtils::rotateTwice(newDown));

    return cube;
}

Cube moveRPrime(Cube cube){
    for(int i=0; i<3;i++)
        cube = moveR(cube);
    return cube;
}

Cube moveR2(Cube cube){
    for(int i=0; i<2;i++)
        cube = moveR(cube);
    return cube;
}

// depth moves

Cube moveF(Cube cube){
    int size = cube.front.size();
    cube.front = MoveUtils::rotate(cube.front);

    Face newUp = MoveUtils::genEmptyFace(size);
    Face newLeft = MoveUtils::genEmptyFace(size);
    Face newRight = MoveUtils::genEmptyFace(size);
    Face newDown = MoveUtils::genEmptyFace(size);

    for(int i=0;i<size;i++){
        newUp[i][size-1] = cube.left[i][size-1];
        newLeft[0][i] = cube.down[0][i];
        newRight[size-1][i] = cube.up[size-1][i];
        newDown[i][0] = cube.right[i][0];
    }

    cube.up = MoveUtils::transfert(cube.up, MoveUtils::rotate(newUp));
    cube.left = MoveUtils::transfert(cube.left, MoveUtils::rotate(newLeft));
    cube.right = MoveUtils::transfert(cube.right, MoveUtils::rotate(newRight));
    cube.down = MoveUtils::transfert(cube.down, MoveUtils::rotate(newDown));

    return cube;
}

Cube moveFPrime(Cube cube){
    for(int i=0; i<3;i++)
        cube = moveF(cube);
    return cube;
}

Cube moveF2(Cube cube){
    for(int i=0; i<2;i++)
        cube = moveF(cube);
    return cube;
}
