#pragma once

#include "CrownScanner.hpp"

class CrownCaster {
public:

    /**
    * cast values of a crown to a string with bits inside, 
    * 1 if match with "yellow", 0 if not
    * @author: LucaGoubelle
    */
    std::string cast(Crown crown){
        std::string result = "";
        for(Row row : crown){
            for(std::string elem : row){
                result += (elem=="yellow") ? "1" : "0";
            }
            result += "_";
        }
        return result;
    }
};