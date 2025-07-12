#pragma once
#include <map>
#include "../../rubikpp/data/cube.hpp"

class Cube2x2Scanner {
    public:
        std::string scanCorner(Cube cube, std::string orient){
            std::map<std::string, std::string> hmap;
            int last = cube.front.size() - 1;

            hmap["up_front_right"] = cube.up[last][last]+"_"+cube.front[0][last]+"_"+cube.right[0][0];
            hmap["up_front_left"] = cube.up[last][0]+"_"+cube.front[0][0]+"_"+cube.left[0][last];
            hmap["up_back_left"] = cube.up[0][0]+"_"+cube.back[0][last]+"_"+cube.left[0][0];
            hmap["up_back_right"] = cube.up[0][last]+"_"+cube.back[0][0]+"_"+cube.right[0][last];

            hmap["down_front_left"] = cube.down[0][0]+"_"+cube.front[last][0]+"_"+cube.left[last][last];
            hmap["down_front_right"] = cube.down[0][last]+"_"+cube.front[last][last]+"_"+cube.right[last][0];
            hmap["down_back_right"] = cube.down[last][last]+"_"+cube.back[last][0]+""+cube.right[last][last];
            hmap["down_back_left"] = cube.down[last][0]+"_"+cube.back[last][last]+"_"+cube.left[last][0];

            return (hmap.count(orient)==1) ? hmap[orient] : "???";
        }

        std::map<std::string, std::string> scanCorners(Cube cube){
            std::map<std::string, std::string> hmap;
            hmap["up_front_right"] = this->scanCorner(cube, "up_front_right");
            hmap["up_front_left"] = this->scanCorner(cube, "up_front_left");
            hmap["up_back_left"] = this->scanCorner(cube, "up_back_left");
            hmap["up_back_right"] = this->scanCorner(cube, "up_back_right");
            
            hmap["down_front_left"] = this->scanCorner(cube, "down_front_left");
            hmap["down_front_right"] = this->scanCorner(cube, "down_front_right");
            hmap["down_back_right"] = this->scanCorner(cube, "down_back_right");
            hmap["down_back_left"] = this->scanCorner(cube, "down_back_left");
            return hmap;
        }
};
