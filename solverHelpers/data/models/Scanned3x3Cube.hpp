#pragma once

#include <map>
#include "../../../rubikpp/data/cube.hpp"

class Scanned3x3Cube {
    public:
        std::map<std::string, std::string> centers;
        std::map<std::string, std::string> edges;
        std::map<std::string, std::string> corners;
    
        Scanned3x3Cube(Cube cube){
            std::map<std::string, std::string> centers;
            centers["front"] = cube.front[1][1];
            centers["up"] = cube.up[1][1];
            centers["left"] = cube.left[1][1];
            centers["right"] = cube.right[1][1];
            centers["down"] = cube.down[1][1];
            centers["back"] = cube.back[1][1];

            std::map<std::string, std::string> corners;
            corners["up_front_right"] = cube.up[2][2]+"_"+cube.front[0][2]+"_"+cube.right[0][0];
            corners["up_front_left"] = cube.up[2][0]+"_"+cube.front[0][0]+"_"+cube.left[0][2];
            corners["up_back_left"] = cube.up[0][0]+"_"+cube.back[0][2]+"_"+cube.left[0][0];
            corners["up_back_right"] = cube.up[0][2]+"_"+cube.back[0][0]+"_"+cube.right[0][2];

            corners["down_front_left"] = cube.down[0][0]+"_"+cube.front[2][0]+"_"+cube.left[2][2];
            corners["down_front_right"] = cube.down[0][2]+"_"+cube.front[2][2]+"_"+cube.right[2][0];
            corners["down_back_left"] = cube.down[2][0]+"_"+cube.back[2][2]+"_"+cube.left[2][0];
            corners["down_back_right"] = cube.down[2][2]+"_"+cube.back[2][0]+"_"+cube.right[2][2];

            std::map<std::string, std::string> edges;
            edges["up_front"] = cube.up[2][1]+"_"+cube.front[0][1];
            edges["up_left"] = cube.up[1][0]+"_"+cube.left[0][1];
            edges["up_right"] = cube.up[1][2]+"_"+cube.right[0][1];
            edges["up_back"] = cube.up[0][1]+"_"+cube.back[0][1];

            edges["front_left"] = cube.front[1][0]+"_"+cube.left[1][2];
            edges["front_right"] = cube.front[1][2]+"_"+cube.right[1][0];
            edges["back_left"] = cube.back[1][2]+"_"+cube.left[1][0];
            edges["back_right"] = cube.back[1][0]+"_"+cube.right[1][2];

            edges["down_front"] = cube.down[0][1]+"_"+cube.front[2][1];
            edges["down_left"] = cube.down[1][0]+"_"+cube.left[2][1];
            edges["down_right"] = cube.down[1][2]+"_"+cube.right[2][1];
            edges["down_back"] = cube.down[2][1]+"_"+cube.back[2][1];
        }
};
