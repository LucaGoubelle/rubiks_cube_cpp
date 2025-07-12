#pragma once
#include "../models/megaminx.hpp"
#include "minx_dumper.hpp"

class MegaminxDumper : public MinxDumper {
    public:
        /**
         * Dump Megaminx object to JSON string
         * @author: LucaGoubelle
         */
        std::string dump(Megaminx minx){
            std::string content  = "{\n";

            content += "\"up\": "+ this->faceToString(minx.up);

            content += "\"left\": "+ this->faceToString(minx.left);
            content += "\"right\": "+ this->faceToString(minx.right);
            content += "\"front\": "+ this->faceToString(minx.front);
            content += "\"backLeft\": "+ this->faceToString(minx.backLeft);
            content += "\"backRight\": "+ this->faceToString(minx.backRight);
            
            content += "\"back\": "+ this->faceToString(minx.back);
            content += "\"absLeft\": "+ this->faceToString(minx.absLeft);
            content += "\"absRight\": "+ this->faceToString(minx.absRight);
            content += "\"downLeft\": "+ this->faceToString(minx.downLeft);
            content += "\"downRight\": "+ this->faceToString(minx.downRight);

            content += "\"down\": "+ this->faceToString(minx.down);

            content.pop_back();
            content.pop_back();
        
            content += "\n}\n";
            return content;
        }
};
