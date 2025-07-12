#pragma once
#include <string>
#include <vector>

class MinxDumper {
    // mother class for minx puzzles dumper
    protected:
        std::string ringToString(std::vector<std::string> ring){
            std::string content = "[ ";
            for(std::string elem : ring)
                content += "\""+elem+"\", ";
            content.pop_back();
            content.pop_back();
            content += " ], ";
            return content;
        }

        std::string faceToString(std::vector<std::vector<std::string> > face){
            std::string content = "[ ";
            for(std::vector<std::string> ring : face)
                content += this->ringToString(ring);
            content.pop_back();
            content.pop_back();
            content += " ], ";
            return content;
        }
};
