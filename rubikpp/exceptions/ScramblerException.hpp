#include <exception>

class ScramblerException : public std::exception {
    public:
    char * what () {
        return "ERR: Something Wrong happened in the Scrambler";
    }
};
