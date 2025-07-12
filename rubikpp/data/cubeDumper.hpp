#pragma once

#include "cube.hpp"

using Row = std::vector<std::string>;

class CubeDumper {
    /***************************************************************************
    * class to dump the cube data into JSON format
    * @author: LucaGoubelle
    ****************************************************************************/
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
                content += genRow(row);
            content.pop_back(); // remove trailing esp
            content.pop_back(); // remove trailing comma
            content += "],\n";
            return content;
        }
    public:
        std::string dump(Cube cube){
            std::string content = "{\n";
            content += "back: "+genFace(cube.back);
            content += "up: "+genFace(cube.up);
            content += "front: "+genFace(cube.front);
            content += "left: "+genFace(cube.left);
            content += "right: "+genFace(cube.right);
            content += "down: "+genFace(cube.down);
            content.pop_back(); // remove trailing esp
            content.pop_back(); // remove trailing comma
            content += "\n}\n";
            return content;
        }
};
