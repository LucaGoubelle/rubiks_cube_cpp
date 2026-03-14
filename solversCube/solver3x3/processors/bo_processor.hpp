#pragma once
#include "./processor.hpp"
#include "../../../solverHelpers/CubeAlgorithms.hpp"

class BOProcessor : public Processor {
    public:
        BOProcessor(){
            this->data["up_front::blue_orange"] = "U y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";
            this->data["up_left::blue_orange"] = "y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";
            this->data["up_right::blue_orange"] = "U2 y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";
            this->data["up_back::blue_orange"] = "U' y' "+CubeAlgorithms::RIGHT_BELGIUM+" y";

            this->data["up_front::orange_blue"] = CubeAlgorithms::LEFT_BELGIUM;
            this->data["up_left::orange_blue"] = "U' "+CubeAlgorithms::LEFT_BELGIUM;
            this->data["up_right::orange_blue"] = "U "+CubeAlgorithms::LEFT_BELGIUM;
            this->data["up_back::orange_blue"] = "U2 "+CubeAlgorithms::LEFT_BELGIUM;
            
            this->data["front_left::orange_blue"] = CubeAlgorithms::LEFT_BELGIUM+" U2 "+CubeAlgorithms::LEFT_BELGIUM;
        }

};
