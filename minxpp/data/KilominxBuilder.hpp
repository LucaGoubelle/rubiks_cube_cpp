#pragma once

#include "kilominx.hpp"

class KilominxBuilder {
    public:

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

        /**
        * Build a full Kilominx
        * @author: LucaGoubelle
        */
        Kilominx build(){
            Face up = buildFace("grey");
            Face front = buildFace("magenta");
            Face left = buildFace("lime");
            Face right = buildFace("beige");
            Face downLeft = buildFace("blue");
            Face downRight = buildFace("red");
            Face absLeft = buildFace("yellow");
            Face absRight = buildFace("green");
            Face backLeft = buildFace("orange");
            Face backRight = buildFace("cyan");
            Face back = buildFace("purple");
            Face down = buildFace("white");

            return Kilominx(
                up, front, left, right, downLeft, downRight, 
                absLeft, absRight, backLeft, backRight, 
            back, down);
        }
};
