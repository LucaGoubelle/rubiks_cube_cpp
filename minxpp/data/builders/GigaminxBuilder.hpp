#pragma once

#include "../models/gigaminx.hpp"

class GigaminxBuilder {
    private:
        /**
        * Build a Gigaminx's face, fill it with 'elem' param
        * @author: LucaGoubelle
        */
        Face buildFace(std::string elem){
            Face face;
            std::vector<std::string> row;
            std::vector<std::string> row2;
            std::vector<std::string> row3;
            for(int i=0;i<20;i++)
                row.push_back(elem);
            for(int i=0;i<10;i++)
                row2.push_back(elem);
            row3.push_back(elem);
            face.push_back(row);
            face.push_back(row2);
            face.push_back(row3);
            return face;
        }

    public:

        /**
        * Build a full Gigaminx
        * @author: LucaGoubelle
        */
        Gigaminx build(){
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
            return Gigaminx(up, front, left, right, downLeft, downRight, absLeft, absRight, backLeft, backRight, back, down);
        }
};
