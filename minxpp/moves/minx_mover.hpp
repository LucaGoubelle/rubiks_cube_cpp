#pragma once
#include <string>
#include <vector>
#include <sstream>

#include "../data/models/Minx.hpp"

class MinxMover {

    // Abs mother class for movers
    protected:
        std::vector<std::string> split(std::string str, char del){
            std::vector<std::string> result;
            std::stringstream ss(str);
            std::string temp = "";
            while(getline(ss, temp, del))
                result.push_back(temp);
            return result;
        }
    public:
        Minx simpleMove(Minx minx, std::string mv){}

        Minx multiMoves(Minx minx, std::string mvs){
            std::vector<std::string> mvVec = this->split(mvs, ' ');
            for(std::string mv : mvVec)
                minx = this->simpleMove(minx, mv);
            return minx;
        }
};
