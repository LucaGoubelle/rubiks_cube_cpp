#pragma once
#include "../data/cube.hpp"
#include "helpers/move_utils.hpp"

// ###################
// # axis moves ######
// ###################

class AxisMoves {
    public:
        Cube moveY(Cube cube){
            cube.up = MoveUtils::rotate(cube.up);
            cube.down = MoveUtils::rotateAsync(cube.down);

            Face newFront = cube.right;
            Face newBack = cube.left;
            Face newRight = cube.back;
            Face newLeft = cube.front;

            cube.front = MoveUtils::transfert(cube.front, newFront);
            cube.right = MoveUtils::transfert(cube.right, newRight);
            cube.back = MoveUtils::transfert(cube.back, newBack);
            cube.left = MoveUtils::transfert(cube.left, newLeft);

            return cube;
        }

        Cube moveYPrime(Cube cube){
            for(int i=0;i<3;i++)
                cube = this->moveY(cube);
            return cube;
        }

        Cube moveY2(Cube cube){
            for(int i=0;i<2;i++)
                cube = this->moveY(cube);
            return cube;
        }

        Cube moveX(Cube cube){
            cube.right = MoveUtils::rotate(cube.right);
            cube.left = MoveUtils::rotateAsync(cube.left);

            Face newFront = cube.down;
            Face newUp = cube.front;
            Face newBack = MoveUtils::rotateTwice(cube.up);
            Face newDown = MoveUtils::rotateTwice(cube.back);

            cube.front = MoveUtils::transfert(cube.front, newFront);
            cube.up = MoveUtils::transfert(cube.up, newUp);
            cube.back = MoveUtils::transfert(cube.back, newBack);
            cube.down = MoveUtils::transfert(cube.down, newDown);

            return cube;
        }

        Cube moveXPrime(Cube cube){
            for(int i=0;i<3;i++)
                cube = this->moveX(cube);
            return cube;
        }

        Cube moveX2(Cube cube){
            for(int i=0;i<2;i++)
                cube = this->moveX(cube);
            return cube;
        }

        Cube moveZ(Cube cube){
            cube.front = MoveUtils::rotate(cube.front);
            cube.back = MoveUtils::rotateAsync(cube.back);

            Face newUp = MoveUtils::rotate(cube.left);
            Face newRight = MoveUtils::rotate(cube.up);
            Face newLeft = MoveUtils::rotate(cube.down);
            Face newDown = MoveUtils::rotate(cube.right);

            cube.up = MoveUtils::transfert(cube.up, newUp);
            cube.right = MoveUtils::transfert(cube.right, newRight);
            cube.left = MoveUtils::transfert(cube.left, newLeft);
            cube.down = MoveUtils::transfert(cube.down, newDown);

            return cube;
        }

        Cube moveZPrime(Cube cube){
            for(int i=0;i<3;i++)
                cube = this->moveZ(cube);
            return cube;
        }

        Cube moveZ2(Cube cube){
            for(int i=0;i<2;i++)
                cube = this->moveZ(cube);
            return cube;
        }
};
