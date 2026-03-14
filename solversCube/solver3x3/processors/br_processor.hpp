#pragma once
#include "./processor.hpp"
#include "../../../solverHelpers/CubeAlgorithms.hpp"

class BRProcessor : public Processor {
    public:
        BRProcessor(){
            this->data["up_front::red_blue"] = CubeAlgorithms::RIGHT_BELGIUM;
            this->data["up_right::red_blue"] = "U "+CubeAlgorithms::RIGHT_BELGIUM;
            this->data["up_back::red_blue"] = "U2 "+CubeAlgorithms::RIGHT_BELGIUM;
            this->data["up_left::red_blue"] = "U' "+CubeAlgorithms::RIGHT_BELGIUM;

            this->data["up_front::blue_red"] = "U' y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            this->data["up_right::blue_red"] = "y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            this->data["up_left::blue_red"] = "U2 y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            this->data["up_back::blue_red"] = "U y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            // case 3: already on a slot
            this->data["front_right::red_blue"] = CubeAlgorithms::RIGHT_BELGIUM + " U2 " + CubeAlgorithms::RIGHT_BELGIUM;
            this->data["front_left::blue_red"] = CubeAlgorithms::LEFT_BELGIUM+" U y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            this->data["front_left::red_blue"] = CubeAlgorithms::LEFT_BELGIUM+" U2 "+CubeAlgorithms::RIGHT_BELGIUM;
            
            this->data["back_left::blue_red"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2 U' y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            this->data["back_left::red_blue"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2 "+CubeAlgorithms::RIGHT_BELGIUM;
            this->data["back_right::blue_red"] = "y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2 U' y "+CubeAlgorithms::LEFT_BELGIUM+" y'";
            this->data["back_right::red_blue"] = "y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2 "+CubeAlgorithms::RIGHT_BELGIUM;
        }
        
};
