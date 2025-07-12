#pragma once

#include <map>
#include "../minxpp/data/models/megaminx.hpp"

class MegaminxScanner {
    public:
        std::string scanCenter(Megaminx minx, std::string orient){
            std::map<std::string, std::string> hmap;
            hmap["up"] = minx.up[1][0];
            hmap["front"] = minx.front[1][0];
            hmap["left"] = minx.left[1][0];
            hmap["right"] = minx.right[1][0];
            hmap["downLeft"] = minx.downLeft[1][0];
            hmap["downRight"] = minx.downRight[1][0];
            hmap["absLeft"] = minx.absLeft[1][0];
            hmap["absRight"] = minx.absRight[1][0];
            hmap["backLeft"] = minx.backLeft[1][0];
            hmap["backRight"] = minx.backRight[1][0];
            hmap["back"] = minx.back[1][0];
            hmap["down"] = minx.down[1][0];
            return (hmap.count(orient)) ? hmap[orient] : "???";
        }

        std::string scanEdge(Megaminx minx, std::string orient){
            std::map<std::string, std::string> hmap;
            hmap["up_front"] = minx.up[0][5]+"_"+minx.front[0][1];
            //todo: implement other cases
            return (hmap.count(orient)) ? hmap[orient] : "???";
        }

        std::string scanCorner(Megaminx minx, std::string orient){
            std::map<std::string, std::string> hmap;
            hmap["up_front_left"] = minx.up[0][6]+"_"+minx.front[0][0]+"_"+minx.left[0][2];
            hmap["up_front_right"] = minx.up[0][4]+"_"+minx.front[0][2]+"_"+minx.right[0][0];
            //todo: implement other cases
            return (hmap.count(orient)) ? hmap[orient] : "???";
        }

        std::map<std::string, std::string> scanEdges(Megaminx minx){
            std::map<std::string, std::string> hmap;
            hmap["up_front"] = this->scanEdge(minx, "up_front");
            return hmap;
        }

        std::map<std::string, std::string> scanCorners(Megaminx minx){
            std::map<std::string, std::string> hmap;
            hmap["up_front_left"] = this->scanCorner(minx, "up_front_left");
            hmap["up_front_right"] = this->scanCorner(minx, "up_front_right");
            return hmap;
        }
};