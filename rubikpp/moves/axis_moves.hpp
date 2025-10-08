#pragma once
#include "../data/cube.hpp"
#include "moves.hpp"

// ###################
// # axis moves ######
// ###################

class AxisMoves : public Moves {
    public:
        Cube moveY(Cube cube){
            cube.up = this->moveUtils.rotate(cube.up);
            cube.down = this->moveUtils.rotateAsync(cube.down);

            Face newFront = cube.right;
            Face newBack = cube.left;
            Face newRight = cube.back;
            Face newLeft = cube.front;

            cube.front = this->moveUtils.transfert(cube.front, newFront);
            cube.right = this->moveUtils.transfert(cube.right, newRight);
            cube.back = this->moveUtils.transfert(cube.back, newBack);
            cube.left = this->moveUtils.transfert(cube.left, newLeft);

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
            cube.right = this->moveUtils.rotate(cube.right);
            cube.left = this->moveUtils.rotateAsync(cube.left);

            Face newFront = cube.down;
            Face newUp = cube.front;
            Face newBack = this->moveUtils.rotateTwice(cube.up);
            Face newDown = this->moveUtils.rotateTwice(cube.back);

            cube.front = this->moveUtils.transfert(cube.front, newFront);
            cube.up = this->moveUtils.transfert(cube.up, newUp);
            cube.back = this->moveUtils.transfert(cube.back, newBack);
            cube.down = this->moveUtils.transfert(cube.down, newDown);

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
            cube.front = this->moveUtils.rotate(cube.front);
            cube.back = this->moveUtils.rotateAsync(cube.back);

            Face newUp = this->moveUtils.rotate(cube.left);
            Face newRight = this->moveUtils.rotate(cube.up);
            Face newLeft = this->moveUtils.rotate(cube.down);
            Face newDown = this->moveUtils.rotate(cube.right);

            cube.up = this->moveUtils.transfert(cube.up, newUp);
            cube.right = this->moveUtils.transfert(cube.right, newRight);
            cube.left = this->moveUtils.transfert(cube.left, newLeft);
            cube.down = this->moveUtils.transfert(cube.down, newDown);

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
