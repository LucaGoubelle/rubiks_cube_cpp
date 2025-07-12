#pragma once

#include <map>
#include "../../minxpp/data/models/kilominx.hpp"

class KilominxScanner {
    public:

        /**
         * Scan a corner of the kilominx, return a string of the colors scanned
         * @author LucaGoubelle
         * @param minx 
         * @return std::string 
         */
        std::string scanCorner(Kilominx minx, std::string orient){
            std::map<std::string, std::string> hmap;
            hmap["up_front_left"] = minx.up[3]+"_"+minx.front[0]+"_"+minx.left[1];
            hmap["up_front_right"] = minx.up[2]+"_"+minx.front[1]+"_"+minx.right[0];
            //todo: implement other cases
            return (hmap.count(orient)) ? hmap[orient] : "???";
        }

        /**
         * Scan all the corners of the kilominx, return a map of the orients => colors
         * @author LucaGoubelle
         * @param minx 
         * @return std::map<std::string, std::string> 
         */
        std::map<std::string, std::string> scanCorners(Kilominx minx){
            std::map<std::string, std::string> hmap;
            hmap["up_front_left"] = this->scanCorner(minx, "up_front_left");
            hmap["up_front_right"] = this->scanCorner(minx, "up_front_right");
            return hmap;
        }
};