#pragma once
#include "./processor.hpp"
#include "../../../solverHelpers/CubeAlgorithms.hpp"

class WGRProcessor : public Processor {
    public:
        WGRProcessor(){
            // up
            this->data["up_front_right::white_green_red"] = "U' y "+CubeAlgorithms::ELEVATOR+" y'";
            this->data["up_front_right::red_white_green"] = "U' R' U' R";
            this->data["up_front_right::green_red_white"] = "U2 R' U R";

            this->data["up_front_left::white_red_green"] = "R' U' R U' R' U R";
            this->data["up_front_left::green_white_red"] = "U R' U R";
            this->data["up_front_left::red_green_white"] = "U2 R' U' R";

            this->data["up_back_right::white_red_green"] = "y "+CubeAlgorithms::ELEVATOR+" y'";
            this->data["up_back_right::green_white_red"] = "U' R' U R";
            this->data["up_back_right::red_green_white"] = "R' U' R";

            this->data["up_back_left::white_green_red"] = "U y"+CubeAlgorithms::ELEVATOR+" y'";
            this->data["up_back_left::red_white_green"] = "U R' U' R";
            this->data["up_back_left::green_red_white"] = "R' U R";

            // down
            this->data["down_front_left::white_green_red"] = "R' L' U2 R L";
            this->data["down_front_left::red_white_green"] = "L' U L R' U2 R";
            this->data["down_front_left::green_red_white"] = "L' U2 L R' U' R";

            this->data["down_back_left::white_red_green"] = "L U L' R' U' R";
            this->data["down_back_left::green_white_red"] = "L U' L' U R' U' R";
            this->data["down_back_left::red_green_white"] = "L U L' U' R' U R";

            this->data["down_back_right::red_white_green"] = "R' U R U' R' U R";
            this->data["down_back_right::green_red_white"] = "R' U' R U R' U' R";
        }

};
