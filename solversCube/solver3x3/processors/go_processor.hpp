#pragma once
#include "./processor.hpp"
#include "../../../solverHelpers/CubeAlgorithms.hpp"

class GOProcessor : public Processor {
    public:
        GOProcessor(){
            this->data["up_front::orange_green"] = "U2 y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            this->data["up_left::orange_green"] = "U y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            this->data["up_right::orange_green"] = "U' y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            this->data["up_back::orange_green"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";

            this->data["up_front::green_orange"] = "U y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            this->data["up_left::green_orange"] = "y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            this->data["up_right::green_orange"] = "U2 y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            this->data["up_back::green_orange"] = "U' y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            
            this->data["back_left::orange_green"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" U2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
            
            this->data["front_left::green_orange"] = CubeAlgorithms::LEFT_BELGIUM+" U' y' "+CubeAlgorithms::LEFT_BELGIUM+" y";
            this->data["front_left::orange_green"] = CubeAlgorithms::LEFT_BELGIUM+" y2 "+CubeAlgorithms::RIGHT_BELGIUM+" y2";
        }

};
