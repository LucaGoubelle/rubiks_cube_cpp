#pragma once
#include <map>
#include <string>

class Processor {
    protected:
        std::map<std::string, std::string> data;

    public:
        Processor(){
            std::map<std::string, std::string> data;
        }

        /**
         * Return the matching sequence of moves based on 
         * inputData param
         * @author: LucaGoubelle
         */
        std::string process(std::string input_data){
            return (this->data.count(input_data)) ? this->data[input_data]: "???";
        }
};
