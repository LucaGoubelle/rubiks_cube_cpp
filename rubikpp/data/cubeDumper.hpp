#pragma once

#include "cube.hpp"

using Row = std::vector<std::string>;

class CubeDumper {
    
    private:
        std::string genRow(Row row){
            std::string content = "[";
            for(std::string elem : row)
                content += "\""+elem+"\"" + ", ";
            content.pop_back(); // remove trailing esp
            content.pop_back(); // remove trailing comma
            content += "],\n";
            return content;
        }

        std::string genFace(Face face){
            std::string content = "[\n";
            for(Row row : face)
                content += this->genRow(row);
            content.pop_back(); // remove trailing esp
            content.pop_back(); // remove trailing comma
            content += "],\n";
            return content;
        }
    public:
        /**
         * Dump the cube object to JSON format
         * @author: LucaGoubelle
         */
        std::string dump(Cube cube){
            std::string content = "{\n";
            content += "back: "+this->genFace(cube.back);
            content += "up: "+this->genFace(cube.up);
            content += "front: "+this->genFace(cube.front);
            content += "left: "+this->genFace(cube.left);
            content += "right: "+this->genFace(cube.right);
            content += "down: "+this->genFace(cube.down);
            content.pop_back(); // remove trailing esp
            content.pop_back(); // remove trailing comma
            content += "\n}\n";
            return content;
        }
};
