#pragma once

#include "../models/masterKilominx.hpp"

class MasterKilominxBuilder {
    private:
        /**
        * Build a Master Kilominx's face, fill it with 'elem' param
        * @author: LucaGoubelle
        */
        Face buildFace(std::string elem){
            Face face;
            std::vector<std::string> row;
            std::vector<std::string> row2;
            for(int i=0;i<15;i++)
                row.push_back(elem);
            for(int i=0;i<5;i++)
                row2.push_back(elem);
            face.push_back(row);
            face.push_back(row2);
            return face;
        }

    public:

        /**
        * Build a full Master Kilominx
        * @author: LucaGoubelle
        */
        MasterKilominx build(){
            Face up = this->buildFace("grey");
            Face front = this->buildFace("magenta");
            Face left = this->buildFace("lime");
            Face right = this->buildFace("beige");
            Face downLeft = this->buildFace("blue");
            Face downRight = this->buildFace("red");
            Face absLeft = this->buildFace("yellow");
            Face absRight = this->buildFace("green");
            Face backLeft = this->buildFace("orange");
            Face backRight = this->buildFace("cyan");
            Face back = this->buildFace("purple");
            Face down = this->buildFace("white");
            return MasterKilominx(up, front, left, right, downLeft, downRight, absLeft, absRight, backLeft, backRight, back, down);
        }
};
