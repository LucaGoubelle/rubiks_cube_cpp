#pragma once
#include <string>
#include <map>

#include "../../rubikpp/data/cube.hpp"

class Center5Seeker {
    public:
        std::string seekCenterEdge(Cube cube, std::string face, std::string color){
            std::map<std::string, std::string> hmapFront;
            hmapFront["front::up"] = cube.front[1][2];
            hmapFront["front::down"] = cube.front[3][2];
            hmapFront["front::right"] = cube.front[2][3];
            hmapFront["front::left"] = cube.front[2][1];

            std::map<std::string, std::string> hmapUp;
            hmapUp["up::front"] = cube.up[3][2];
            hmapUp["up::left"] = cube.up[2][1];
            hmapUp["up::right"] = cube.up[2][3];
            hmapUp["up::back"] = cube.up[1][2];

            if(face=="front")
                for(auto const& x : hmapFront)
                    if(x.second==color) return x.first;
            else if (face=="up")
                for(auto const& x : hmapUp)
                    if(x.second == color) return x.first;
            else return "???";
        }

        std::string seekCenterCorner(Cube cube, std::string face, std::string color){
            //todo: implement this
            return "???";
        }
};
