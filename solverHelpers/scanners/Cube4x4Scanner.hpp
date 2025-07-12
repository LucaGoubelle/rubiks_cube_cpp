#pragma once
#include "../../rubikpp/data/cube.hpp"
#include "Cube3x3Scanner.hpp"

class Cube4x4Scanner : public Cube3x3Scanner {
    public:
        std::string scanCenter(Cube cube, std::string orient, std::vector<int> coord){
            std::map<std::string, std::string> hmap;

            hmap["back"] = cube.back[coord[0]][coord[1]];
            hmap["up"] = cube.up[coord[0]][coord[1]];
            hmap["front"] = cube.front[coord[0]][coord[1]];
            hmap["left"] = cube.left[coord[0]][coord[1]];
            hmap["right"] = cube.right[coord[0]][coord[1]];
            hmap["down"] = cube.down[coord[0]][coord[1]];

            return (hmap.count(orient)==1) ? hmap[orient] : "???";
        }

        std::string scanEdge(Cube cube, std::string orient){
            std::map<std::string, std::string> hmap;

            hmap["up_front:left"] = "";
            hmap["up_front:right"] = "";
            hmap["up_back:left"] = "";
            hmap["up_back:right"] = "";
            hmap["up_left:front"] = "";
            hmap["up_left:back"] = "";
            hmap["up_right:front"] = "";
            hmap["up_right:back"] = "";

            hmap["front_left:up"] = "";
            hmap["front_left:down"] = "";
            hmap["front_right:up"] = "";
            hmap["front_right:down"] = "";
            hmap["back_left:up"] = "";
            hmap["back_left:down"] = "";
            hmap["back_right:up"] = "";
            hmap["back_right:down"] = "";

            hmap["down_front:left"] = "";
            hmap["down_front:right"] = "";
            hmap["down_back:left"] = "";
            hmap["down_back:right"] = "";
            hmap["down_left:front"] = "";
            hmap["down_left:back"] = "";
            hmap["down_right:front"] = "";
            hmap["down_right:back"] = "";

            return (hmap.count(orient)==1) ? hmap[orient] : "???";
        }
};
