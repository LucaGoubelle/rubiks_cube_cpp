#pragma once
#include <map>
#include "../../rubikpp/data/cube.hpp"


class PLLScanner {
    private:
        std::map<std::string, std::string> hmap;
    public:
        PLLScanner(){
            this->hmap["blue"] = "B";
            this->hmap["red"] = "R";
            this->hmap["orange"] = "O";
            this->hmap["green"] = "G";
        }

        /**
        * Return scanned PLL (Permutation Last Layer) config to a string of char colors
        * @author: LucaGoubelle
        */
        std::string scanPLL(Cube cube){
            std::string result = "";
            for(std::string elem : cube.front[0])
                result += this->hmap[elem];
            result += "_";
            for(std::string elem : cube.right[0])
                result += this->hmap[elem];
            result += "_";
            for(std::string elem : cube.back[0])
                result += this->hmap[elem];
            result += "_";
            for(std::string elem : cube.left[0])
                result += this->hmap[elem];
            return result;
        }
};
