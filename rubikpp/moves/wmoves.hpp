#pragma once
#include "../data/cube.hpp"
#include "helpers/move_utils.hpp"

class WMoves {
public:
    Cube moveUw(Cube cube, int nbLayer = 2){
        int size = cube.up.size();
        cube.up = MoveUtils::rotate(cube.up);

        Face newFront = MoveUtils::genEmptyFace(size);
        Face newLeft = MoveUtils::genEmptyFace(size);
        Face newRight = MoveUtils::genEmptyFace(size);
        Face newBack = MoveUtils::genEmptyFace(size);

        for(int j=0;j<nbLayer;j++){
            for(int i=0;i<size;i++){
                newFront[j][i] = cube.right[j][i];
                newRight[j][i] = cube.back[j][i];
                newLeft[j][i] = cube.front[j][i];
                newBack[j][i] = cube.left[j][i];
            }
        }

        cube.front = MoveUtils::transfert(cube.front, newFront);
        cube.left = MoveUtils::transfert(cube.left, newLeft);
        cube.right = MoveUtils::transfert(cube.right, newRight);
        cube.back = MoveUtils::transfert(cube.back, newBack);

        return cube;
    }

    Cube moveUwPrime(Cube cube, int nbLayer = 2){
        for(int i=0;i<3;i++)
            cube = moveUw(cube, nbLayer);
        return cube;
    }

    Cube moveUw2(Cube cube, int nbLayer = 2){
        for(int i=0;i<2;i++)
            cube = moveUw(cube, nbLayer);
        return cube;
    }

    Cube moveDw(Cube cube, int nbLayer = 2){
        int size = cube.down.size();
        cube.down = MoveUtils::rotate(cube.down);

        Face newFront = MoveUtils::genEmptyFace(size);
        Face newLeft = MoveUtils::genEmptyFace(size);
        Face newRight = MoveUtils::genEmptyFace(size);
        Face newBack = MoveUtils::genEmptyFace(size);

        for(int j=0;j<nbLayer;j++){
            for(int i=0;i<size;i++){
                newFront[size-(1+j)][i] = cube.left[size-(1+j)][i];
                newLeft[size-(1+j)][i] = cube.back[size-(1+j)][i];
                newRight[size-(1+j)][i] = cube.front[size-(1+j)][i];
                newBack[size-(1+j)][i] = cube.right[size-(1+j)][i];
            }
        }

        cube.front = MoveUtils::transfert(cube.front, newFront);
        cube.left = MoveUtils::transfert(cube.left, newLeft);
        cube.right = MoveUtils::transfert(cube.right, newRight);
        cube.back = MoveUtils::transfert(cube.back, newBack);
        return cube;
    }

    Cube moveDwPrime(Cube cube, int nbLayer = 2){
        for(int i=0 ; i<3;i++)
            cube = moveDw(cube, nbLayer);
        return cube;
    }

    Cube moveDw2(Cube cube, int nbLayer = 2){
        for(int i=0 ; i<2;i++)
            cube = moveDw(cube, nbLayer);
        return cube;
    }

    Cube moveLw(Cube cube, int nbLayer = 2){
        int size = cube.left.size();
        cube.left = MoveUtils::rotate(cube.left);

        Face newUp = MoveUtils::genEmptyFace(size);
        Face newFront = MoveUtils::genEmptyFace(size);
        Face newDown = MoveUtils::genEmptyFace(size);
        Face newBack = MoveUtils::genEmptyFace(size);

        for(int j=0;j<nbLayer;j++){
            for(int i=0;i<size;i++){
                newFront[i][j] = cube.up[i][j];
                newDown[i][j] = cube.front[i][j];
                newBack[i][j] = cube.down[i][j];
                newUp[i][size-(1+j)] = cube.back[i][size-(1+j)];
            }
        }

        cube.front = MoveUtils::transfert(cube.front, newFront);
        cube.up = MoveUtils::transfert(cube.up, MoveUtils::rotateTwice(newUp));
        cube.down = MoveUtils::transfert(cube.down, newDown);
        cube.back = MoveUtils::transfert(cube.back, MoveUtils::rotateTwice(newBack));
        return cube;
    }

    Cube moveLwPrime(Cube cube, int nbLayer = 2){
        for(int i = 0; i <3; i++)
            cube = moveLw(cube, nbLayer);
        return cube;
    }

    Cube moveLw2(Cube cube, int nbLayer = 2){
        for(int i = 0; i <2; i++)
            cube = moveLw(cube, nbLayer);
        return cube;
    }

    Cube moveRw(Cube cube, int nbLayer = 2){
        int size = cube.right.size();
        cube.right = MoveUtils::rotate(cube.right);

        Face newFront = MoveUtils::genEmptyFace(size);
        Face newUp = MoveUtils::genEmptyFace(size);
        Face newBack = MoveUtils::genEmptyFace(size);
        Face newDown = MoveUtils::genEmptyFace(size);

        for(int j=0;j<nbLayer;j++){
            for(int i=0;i<size;i++){
                newFront[i][size-(1+j)] = cube.down[i][size-(1+j)];
                newUp[i][size-(1+j)] = cube.front[i][size-(1+j)];
                newBack[i][size-(1+j)] = cube.up[i][size-(1+j)];
                newDown[i][j] = cube.back[i][j];
            }
        }

        cube.front = MoveUtils::transfert(cube.front, newFront);
        cube.up = MoveUtils::transfert(cube.up, newUp);
        cube.back = MoveUtils::transfert(cube.back, MoveUtils::rotateTwice(newBack));
        cube.down = MoveUtils::transfert(cube.down, MoveUtils::rotateTwice(newDown));
        
        return cube;
    }

    Cube moveRwPrime(Cube cube, int nbLayer = 2){
        for(int i=0;i<3;i++)
            cube = moveRw(cube, nbLayer);
        return cube;
    }

    Cube moveRw2(Cube cube, int nbLayer = 2){
        for(int i=0;i<2;i++)
            cube = moveRw(cube, nbLayer);
        return cube;
    }

    Cube moveFw(Cube cube, int nbLayer = 2){
        int size = cube.front.size();
        cube.front = MoveUtils::rotate(cube.front);

        Face newUp = MoveUtils::genEmptyFace(size);
        Face newLeft = MoveUtils::genEmptyFace(size);
        Face newRight = MoveUtils::genEmptyFace(size);
        Face newDown = MoveUtils::genEmptyFace(size);

        for(int j=0;j<nbLayer;j++){
            for(int i=0;i<size;i++){
                newUp[i][size-(1+j)] = cube.left[i][size-(1+j)];
                newLeft[j][i] = cube.down[j][i];
                newRight[size-(1+j)][i] = cube.up[size-(1+j)][i];
                newDown[i][j] = cube.right[i][j];
            }
        }

        cube.up = MoveUtils::transfert(cube.up, MoveUtils::rotate(newUp));
        cube.left = MoveUtils::transfert(cube.left, MoveUtils::rotate(newLeft));
        cube.right = MoveUtils::transfert(cube.right, MoveUtils::rotate(newRight));
        cube.down = MoveUtils::transfert(cube.down, MoveUtils::rotate(newDown));

        return cube;
    }

    Cube moveFwPrime(Cube cube, int nbLayer = 2){
        for(int i=0;i<3;i++)
            cube = moveFw(cube, nbLayer);
        return cube;
    }

    Cube moveFw2(Cube cube, int nbLayer = 2){
        for(int i=0;i<2;i++)
            cube = moveFw(cube, nbLayer);
        return cube;
    }
};
