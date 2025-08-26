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

            std::map<std::string, std::string> hmapBack;
            hmapBack["back::up"] = cube.back[1][2];
            hmapBack["back::down"] = cube.back[3][2];
            hmapBack["back::right"] = cube.back[2][1];
            hmapBack["back::left"] = cube.back[2][3];

            std::map<std::string, std::string> hmapDown;
            hmapDown["down::front"] = cube.down[1][2];
            hmapDown["down::back"] = cube.down[3][2];
            hmapDown["down::left"] = cube.down[2][1];
            hmapDown["down::right"] = cube.down[2][3];

            if(face=="front")
                for(auto const& x : hmapFront)
                    if(x.second==color) return x.first;
            else if (face=="up")
                for(auto const& x : hmapUp)
                    if(x.second == color) return x.first;
            else if(face=="back")
                for(auto const& x : hmapBack)
                    if(x.second == color) return x.first;
            else if(face=="down")
                for(auto const& x : hmapDown)
                    if(x.second == color) return x.first;
            return "???";
        }

        std::string seekCenterCorner(Cube cube, std::string face, std::string color){
            std::map<std::string, std::string> hmapFront;
            hmapFront["front::up::right"] = cube.front[1][3];
            hmapFront["front::up::left"] = cube.front[1][1];
            hmapFront["front::down::right"] = cube.front[3][3];
            hmapFront["front::down::left"] = cube.front[3][1];

            std::map<std::string, std::string> hmapLeft;
            hmapLeft["left::up::back"] = cube.left[1][1];
            hmapLeft["left::up::front"] = cube.left[1][3];
            hmapLeft["left::down::back"] = cube.left[3][1];
            hmapLeft["left::down::front"] = cube.left[3][3];

            std::map<std::string, std::string> hmapRight;
            hmapRight["right::up::front"] = cube.right[1][1];
            hmapRight["right::up::back"] = cube.right[1][3];
            hmapRight["right::down::front"] = cube.right[3][1];
            hmapRight["right::down::back"] = cube.right[3][3];

            std::map<std::string, std::string> hmapUp;
            hmapUp["up::front::left"] = cube.up[3][1];
            hmapUp["up::front::right"] = cube.up[3][3];
            hmapUp["up::back::left"] = cube.up[1][1];
            hmapUp["up::back::right"] = cube.up[1][3];

            std::map<std::string, std::string> hmapBack;
            hmapBack["back::up::right"] = cube.back[1][1];
            hmapBack["back::up::left"] = cube.back[1][3];
            hmapBack["back::down::right"] = cube.back[3][1];
            hmapBack["back::down::left"] = cube.back[3][3];

            std::map<std::string, std::string> hmapDown;
            hmapDown["down::front::left"] = cube.down[1][1];
            hmapDown["down::front::right"] = cube.down[1][3];
            hmapDown["down::back::left"] = cube.down[3][1];
            hmapDown["down::back::right"] = cube.down[3][3];

            if(face=="front")
                for(auto const& x : hmapFront)
                    if(x.second==color) return x.first;
            else if(face=="left")
                for(auto const& x : hmapLeft)
                    if(x.second==color) return x.first;
            else if(face=="right")
                for(auto const& x: hmapRight)
                    if(x.second==color) return x.first;
            else if (face=="up")
                for(auto const& x : hmapUp)
                    if(x.second == color) return x.first;
            else if (face=="back")
                for(auto const& x : hmapBack)
                    if(x.second == color) return x.first;
            else if (face=="down")
                for(auto const& x : hmapDown)
                    if(x.second == color) return x.first;
            return "???";
        }
};
