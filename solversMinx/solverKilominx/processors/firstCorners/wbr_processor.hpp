#pragma once
#include <string>
#include <map>

class WBRProcessor {
    private:
        std::map<std::string, std::string> data;
    public:
        WBRProcessor(){
            std::map<std::string, std::string> data;
        }

        std::string process(std::string inputData){
            return (this->data.count(inputData)) ? this->data[inputData] : "???";
        }
};
