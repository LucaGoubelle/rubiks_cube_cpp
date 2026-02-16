#pragma once
#include <map>
#include <string>

class WBRProcessor {
    private:
        std::map<std::string, std::string> data;
    public:
        WBRProcessor(){
            //todo: implement cases here
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