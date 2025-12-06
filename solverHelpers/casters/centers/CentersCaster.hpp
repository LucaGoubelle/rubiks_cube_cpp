#pragma once
#include "../../../rubikpp/data/cube.hpp"

class CentersCaster {
    protected:
        int size;

        Face getActualFace(Cube cube, std::string face){
            if(face == "up") return cube.up;
            else if(face == "front") return cube.front;
            else if(face == "left") return cube.left;
            else if(face == "right") return cube.right;
            else if(face == "down") return cube.down;
            else if(face == "back") return cube.back;
            else return cube.front;
        }
    
        std::string getStringCenters(std::string colorToFilter, Face centers){
            std::string content = "";
            for(std::vector<std::string> row : centers)
                for(std::string elem : row)
                    content += (elem == colorToFilter) ? "1" : "0"; 
            return content;
        }

        Face extractCenters(Face actualFace){
            Face face;
            return face;
        }

    public:
        CentersCaster(){
            this->size = 0;
        }

        std::string cast(Cube cube, std::string face, std::string colorToFilter){
            if(cube.front.size() != this->size)
                throw "Cube must be a "+std::to_string(this->size)+"x"+std::to_string(this->size)+" to use CenterCaster class";
            Face actualFace = this->getActualFace(cube, face);
            Face actualCenters = this->extractCenters(actualFace);
            return this->getStringCenters(colorToFilter, actualCenters);
        }
};
