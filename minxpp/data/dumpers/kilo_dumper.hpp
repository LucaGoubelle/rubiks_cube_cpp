#pragma once
#include "../models/kilominx.hpp"
#include "minx_dumper.hpp"

class KilominxDumper : public MinxDumper {
    public:

        /**
         * Dump Kilominx object to JSON string
         * @author: LucaGoubelle
         */
        std::string dump(Kilominx minx){
            std::string content  = "{\n";

            content += "\"up\": "+ this->ringToString(minx.up);

            content += "\"left\": "+ this->ringToString(minx.left);
            content += "\"right\": "+ this->ringToString(minx.right);
            content += "\"front\": "+ this->ringToString(minx.front);
            content += "\"backLeft\": "+ this->ringToString(minx.backLeft);
            content += "\"backRight\": "+ this->ringToString(minx.backRight);
            
            content += "\"back\": "+ this->ringToString(minx.back);
            content += "\"absLeft\": "+ this->ringToString(minx.absLeft);
            content += "\"absRight\": "+ this->ringToString(minx.absRight);
            content += "\"downLeft\": "+ this->ringToString(minx.downLeft);
            content += "\"downRight\": "+ this->ringToString(minx.downRight);

            content += "\"down\": "+ this->ringToString(minx.down);

            content.pop_back();
            content.pop_back();
        
            content += "\n}\n";
            return content;
        }
};