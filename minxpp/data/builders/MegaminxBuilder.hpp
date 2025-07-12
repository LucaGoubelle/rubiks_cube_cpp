#pragma once

#include "../models/megaminx.hpp"

class MegaminxBuilder {
    private:
        /**
        * Build a megaminx's face, fill it with 'elem' param
        * @author: LucaGoubelle
        */
        Face buildFace(std::string elem){
            Face face;
            std::vector<std::string> row;
            std::vector<std::string> row2;
            for(int i=0;i<10;i++)
                row.push_back(elem);
            row2.push_back(elem);
            face.push_back(row);
            face.push_back(row2);
            return face;

        }

    public:

        /**
        * Build a full Megaminx
        * @author: LucaGoubelle
        */
        Megaminx build(){
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
            return Megaminx(up, front, left, right, downLeft, downRight, absLeft, absRight, backLeft, backRight, back, down);
        }
};
