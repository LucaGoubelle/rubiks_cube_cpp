#pragma once

#include "../models/kilominx.hpp"

class KilominxBuilder {
    private:
        /**
        * Build a Kilominx's face, fill it with 'elem' param
        * @author: LucaGoubelle
        */
        Face buildFace(std::string elem){
            Face face;
            for(int i=0;i<5;i++)
                face.push_back(elem);
            return face;
        }

    public:
        /**
        * Build a full Kilominx
        * @author: LucaGoubelle
        */
        Kilominx build(){
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

            return Kilominx(
                up, front, left, right, downLeft, downRight, 
                absLeft, absRight, backLeft, backRight, 
            back, down);
        }
};
