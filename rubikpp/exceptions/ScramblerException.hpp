#pragma once
#include <exception>

class ScramblerException : public std::exception {
    public:
    char * what () {
        std::string message = "ERR: Something Wrong happened in the Scrambler";
        return message.data();
    }
};
