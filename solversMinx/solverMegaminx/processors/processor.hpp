#pragma once
#include <map>
#include <string>
#include <algorithm>

class Processor {
    protected:
        std::map<std::string, std::string> data;
    public:
        Processor(){
            std::map<std::string, std::string> data;
        }

        std::string process(std::string input_data){
            return (this->data.count(input_data)) ? this->data[input_data] : "???";
        }
        
};