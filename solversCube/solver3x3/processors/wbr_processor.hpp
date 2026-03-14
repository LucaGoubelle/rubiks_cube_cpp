#pragma once
#include "./processor.hpp"

class WBRProcessor : public Processor {
    public:
        WBRProcessor(){
            this->data["up_front_right::white_red_blue"] = "R U R' U' R U R' U' R U R' U'";
            this->data["up_front_right::blue_white_red"] = "U R U' R'";
            this->data["up_front_right::red_blue_white"] = "R U R'";

            this->data["up_front_left::white_blue_red"] = "R U2 R' U R U' R'";
            this->data["up_front_left::blue_red_white"] = "R U' R'";
            this->data["up_front_left::red_white_blue"] = "U' R U R'";

            this->data["up_back_right::white_blue_red"] = "U' R U R' U R U' R'";
            this->data["up_back_right::blue_red_white"] = "U2 R U' R'";
            this->data["up_back_right::red_white_blue"] = "U R U R'";

            this->data["up_back_left::white_red_blue"] = "U2 R U R' U' R U R' U' R U R' U'";
            this->data["up_back_left::blue_white_red"] = "U' R U' R'";
            this->data["up_back_left::red_blue_white"] = "U2 R U R'";
            //down
            this->data["down_front_right::red_white_blue"] = "R U' R' U R U' R'";
            this->data["down_front_right::blue_red_white"] = "R U R' U' R U R' U'";

            this->data["down_front_left::white_red_blue"] = "L' U' L R U R'";
            this->data["down_front_left::blue_white_red"] = "L' U' L R U R' U' R U R' U' R U R' U'";
            this->data["down_front_left::red_blue_white"] = "L' U' L U R U' R'";

            this->data["down_back_left::white_blue_red"] = "L U2 L' U R U' R'";
            this->data["down_back_left::red_white_blue"] = "L U' L' R U2 R'";
            this->data["down_back_left::blue_red_white"] = "L U2 L' R U R'";

            this->data["down_back_right::white_red_blue"] = "R' U2 R U' R U R'";
            this->data["down_back_right::blue_white_red"] = "R' U R U R U R'";
            this->data["down_back_right::red_blue_white"] = "R' U2 R2 U' R'";
        }
        
};
