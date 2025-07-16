#pragma once
#include <map>
#include <string>

#include "../../solverHelpers/CubeAlgorithms.hpp"

class WGOProcessor {
    private:
        std::map<std::string, std::string> data;
    public:
        WGOProcessor(){
            std::map<std::string, std::string> data;
            //up
            this->data["up_front_right::white_orange_green"] = "L U L' U L U' L'";
            this->data["up_front_right::green_white_orange"] = "L U2 L'";
            this->data["up_front_right::orange_green_white"] = "U2 L U L'";

            this->data["up_front_left::white_green_orange"] = "L' U L2 U' L";
            this->data["up_front_left::orange_white_green"] = "U L U L'";
            this->data["up_front_left::green_orange_white"] = "U2 L U' L'";

            this->data["up_back_left::white_orange_green"] = "y2 "+CubeAlgorithms::ELEVATOR+" y2";
            this->data["up_back_left::green_white_orange"] = "U L U' L'";
            this->data["up_back_left::orange_green_white"] = "L U L'";

            this->data["up_back_right::white_green_orange"] = "U' y2 "+CubeAlgorithms::ELEVATOR+" y2";
            this->data["up_back_right::orange_white_green"] = "U' L U L'";
            this->data["up_back_right::green_orange_white"] = "L U' L'";
            
            //down
            this->data["down_front_left::white_orange_green"] = "y' "+CubeAlgorithms::ELEVATOR+" y' U "+CubeAlgorithms::ELEVATOR+" y2";
            this->data["down_front_left::green_white_orange"] = "L' U L U L U L'";
            this->data["down_front_left::orange_green_white"] = "L' U2 L2 U' L'";
            
            this->data["down_back_left::orange_white_green"] = "L U' L' U L U' L'";
            this->data["down_back_left::green_orange_white"] = "L U L' U' L U L'";
        }

        std::string process(std::string inputData){
            return (this->data.count(inputData)) ? this->data[inputData] : "???";
        }
};
