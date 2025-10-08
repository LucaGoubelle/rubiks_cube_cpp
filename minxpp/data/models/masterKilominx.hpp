#pragma once
#include "Minx.hpp"

using Face = std::vector<std::vector<std::string> >;

/**
* Master Kilominx data model, each faces is a vector of vector of string (size 15 - 5)
* @author: LucaGoubelle
*/
class MasterKilominx : public Minx {
    
    public:
        Face up;
        Face front;
        Face left;
        Face right;
        Face downLeft;
        Face downRight;
        Face absLeft;
        Face absRight;
        Face backLeft;
        Face backRight;
        Face back;
        Face down;

        MasterKilominx(Face up, Face front, Face left, Face right, Face downLeft, Face downRight,
            Face absLeft, Face absRight, Face backLeft, Face backRight, Face back, Face down
        ){
            this->up = up;
            this->front = front;
            this->left = left;
            this->right = right;
            this->downLeft = downLeft;
            this->downRight = downRight;
            this->absLeft = absLeft;
            this->absRight = absRight;
            this->backLeft = backLeft;
            this->backRight = backRight;
            this->back = back;
            this->down = down;
        }
};
