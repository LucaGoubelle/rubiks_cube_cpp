#pragma once
#include "../../rubikpp/data/cube.hpp"
#include "Cube4x4Scanner.hpp"

class Cube5x5Scanner : public Cube4x4Scanner {
    public:
        std::string scanEdge(Cube cube, std::string orient){
            std::map<std::string, std::string> hmap;

            hmap["up_front:left"] = "";
            hmap["up_front:right"] = "";
            hmap["up_front"] = "";
            hmap["up_back:left"] = "";
            hmap["up_back:right"] = "";
            hmap["up_back"] = "";
            hmap["up_left:front"] = "";
            hmap["up_left:back"] = "";
            hmap["up_left"] = "";
            hmap["up_right:front"] = "";
            hmap["up_right:back"] = "";
            hmap["up_right"] = "";

            hmap["front_left:up"] = "";
            hmap["front_left:down"] = "";
            hmap["front_left"] = "";
            hmap["front_right:up"] = "";
            hmap["front_right:down"] = "";
            hmap["front_right"] = "";
            hmap["back_left:up"] = "";
            hmap["back_left:down"] = "";
            hmap["back_left"] = "";
            hmap["back_right:up"] = "";
            hmap["back_right:down"] = "";
            hmap["back_right"] = "";

            hmap["down_front:left"] = "";
            hmap["down_front:right"] = "";
            hmap["down_front"] = "";
            hmap["down_back:left"] = "";
            hmap["down_back:right"] = "";
            hmap["down_back"] = "";
            hmap["down_left:front"] = "";
            hmap["down_left:back"] = "";
            hmap["down_left"] = "";
            hmap["down_right:front"] = "";
            hmap["down_right:back"] = "";
            hmap["down_right"] = "";

            return (hmap.count(orient)==1) ? hmap[orient] : "???";
        }
};
