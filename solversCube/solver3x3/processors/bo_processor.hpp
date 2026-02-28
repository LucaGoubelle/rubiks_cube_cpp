#pragma once
#include <map>
#include <string>
#include <algorithm>
#include "../../../solverHelpers/CubeAlgorithms.hpp"

class BOProcessor {
    private:
        std::map<std::string, std::string> data;
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

        /**
         * Return the matching sequence of moves based on 
         * inputData param
         * @author: LucaGoubelle
         */
        std::string process(std::string inputData){
            return (this->data.count(inputData)) ? this->data[inputData] : "???";
        }

};
