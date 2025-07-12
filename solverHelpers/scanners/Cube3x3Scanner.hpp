#pragma once
#include "../../rubikpp/data/cube.hpp"
#include "Cube2x2Scanner.hpp"

class Cube3x3Scanner : public Cube2x2Scanner {
    public:
        std::string scanCenter(Cube cube, std::string orient){
            std::map<std::string, std::string> hmap;
            
            hmap["up"] = cube.up[1][1];
            hmap["front"] = cube.front[1][1];
            hmap["left"] = cube.left[1][1];
            hmap["right"] = cube.right[1][1];
            hmap["down"] = cube.down[1][1];
            hmap["back"] = cube.back[1][1];

            return (hmap.count(orient)==1) ? hmap[orient] : "???";
        }

        std::string scanEdge(Cube cube, std::string orient){
            std::map<std::string, std::string> hmap;
            int last = cube.front.size() - 1;

            hmap["up_front"] = cube.up[last][1]+"_"+cube.front[0][1];
            hmap["up_left"] = cube.up[1][0]+"_"+cube.left[0][1];
            hmap["up_right"] = cube.up[1][last]+"_"+cube.right[0][1];
            hmap["up_back"] = cube.up[0][1]+"_"+cube.back[0][1];

            hmap["front_right"] = cube.front[1][last]+"_"+cube.right[1][0];
            hmap["front_left"] = cube.front[1][0]+"_"+cube.left[1][last];
            hmap["back_left"] = cube.back[1][last]+"_"+cube.left[1][0];
            hmap["back_right"] = cube.back[1][0]+"_"+cube.right[1][last];

            hmap["down_front"] = cube.down[0][1]+"_"+cube.front[last][1];
            hmap["down_left"] = cube.down[1][0]+"_"+cube.left[last][1];
            hmap["down_right"] = cube.down[1][last]+"_"+cube.right[last][1];
            hmap["down_back"] = cube.down[last][1]+"_"+cube.back[last][1];

            return (hmap.count(orient)==1) ? hmap[orient] : "???";
        }

        std::map<std::string, std::string> scanEdges(Cube cube){
            std::map<std::string, std::string> hmap;
            hmap["up_front"] = this->scanEdge(cube, "up_front");
            hmap["up_left"] = this->scanEdge(cube, "up_left");
            hmap["up_right"] = this->scanEdge(cube, "up_right");
            hmap["up_back"] = this->scanEdge(cube, "up_back");
            
            hmap["front_left"] = this->scanEdge(cube, "front_left");
            hmap["front_right"] = this->scanEdge(cube, "front_right");
            hmap["back_left"] = this->scanEdge(cube, "back_left");
            hmap["back_right"] = this->scanEdge(cube, "back_right");

            hmap["down_front"] = this->scanEdge(cube, "down_front");
            hmap["down_left"] = this->scanEdge(cube, "down_left");
            hmap["down_right"] = this->scanEdge(cube, "down_right");
            hmap["down_back"] = this->scanEdge(cube, "down_back");
            return hmap;
        }
};
