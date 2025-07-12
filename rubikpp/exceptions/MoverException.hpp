#include <exception>

class MoverException : public std::exception {
    public:
    char * what () {
        return "ERR: Something Wrong happened in the Mover class";
    }
};
