#include <exception>

class MoverException : public std::exception {
    public:
    char * what () {
        std::string message = "ERR: Something Wrong happened in the Mover class";
        return message.data();
    }
};
