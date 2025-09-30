#pragma once

#include <map>
#include "cube.hpp"

class CubeStrDumper {
    private:
        std::map<std::string, std::string> hmap;

        std::string dumpFace(Face face){
            std::string content = "";
            for(std::vector<std::string> row : face)
                for(std::string elem : row)
                    content += (this->hmap.count(elem)) ? this->hmap[elem] : "?";
            return content;
        }
    
    public:

        CubeStrDumper(){
            std::map<std::string, std::string> hmap;
            hmap["green"] = "G";
            hmap["blue"] = "B";
            hmap["red"] = "R";
            hmap["orange"] = "O";
            hmap["white"] = "W";
            hmap["yellow"] = "Y";
        }

        std::string dump(Cube cube){
            std::string content = "";
            content += this->dumpFace(cube.back) + "_";
            content += this->dumpFace(cube.up) + "_";
            content += this->dumpFace(cube.front) + "_";
            content += this->dumpFace(cube.left) + "_";
            content += this->dumpFace(cube.right) + "_";
            content += this->dumpFace(cube.down);
            return content;
        }
};
