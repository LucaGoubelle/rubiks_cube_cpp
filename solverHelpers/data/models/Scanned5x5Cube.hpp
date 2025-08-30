#pragma once

#include <map>
#include "../../../rubikpp/data/cube.hpp"

class Scanned5x5Cube {
    public:
        std::map<std::string, std::string> centers;

        Scanned5x5Cube(Cube cube){
            std::map<std::string, std::string> centers;
            centers["front"] = cube.front[2][2];
            centers["front_up"] = cube.front[1][2];
            centers["front_down"] = cube.front[3][2];
            centers["front_left"] = cube.front[2][1];
            centers["front_right"] = cube.front[2][3];
            centers["front_up_left"] = cube.front[1][1];
            centers["front_up_right"] = cube.front[1][3];
            centers["front_down_left"] = cube.front[3][1];
            centers["front_down_right"] = cube.front[3][3];
        }
};
