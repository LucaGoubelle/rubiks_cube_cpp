#pragma once
#include <exception>

class BuilderException : public std::exception {
    public:
        char * what(){
            std::string message = "ERR: Something Wrong happened in the CubeBuilder class";
            return message.data();
        }
};
