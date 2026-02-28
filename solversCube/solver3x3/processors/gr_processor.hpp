#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "../../../solverHelpers/CubeAlgorithms.hpp"

class GRProcessor {
    private:
        std::map<std::string, std::string> data;
    public:
        GRProcessor(){
            this->data["up_front::red_green"] = "U2 y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
            this->data["up_left::red_green"] = "U y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
            this->data["up_right::red_green"] = "U' y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
            this->data["up_back::red_green"] = "y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";

            this->data["up_front::green_red"] = "U' y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            this->data["up_right::green_red"] = "y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            this->data["up_left::green_red"] = "U2 y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            this->data["up_back::green_red"] = "U y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            // case is on slot
            this->data["back_right::red_green"] = "y "+CubeAlgorithms::RIGHT_BELGIUM+" U2 "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            
            this->data["back_left::green_red"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" U' y' "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            this->data["back_left::red_green"] = "y2 "+CubeAlgorithms::RIGHT_BELGIUM+" U2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";

            this->data["front_left::green_red"] = CubeAlgorithms::LEFT_BELGIUM+" U y "+CubeAlgorithms::RIGHT_BELGIUM+" y'";
            this->data["front_left::red_green"] = CubeAlgorithms::LEFT_BELGIUM+" y2 "+CubeAlgorithms::LEFT_BELGIUM+" y2";
        }

        /**
         * Return the matching sequence of moves based on 
         * inputData param
         * @author: LucaGoubelle
         */
        std::string process(std::string inputData){
            return (this->data.count(inputData)) ? this->data[inputData] : "???";
        }
};