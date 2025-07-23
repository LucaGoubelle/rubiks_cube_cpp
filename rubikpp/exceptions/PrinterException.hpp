#include <exception>

class PrinterException : public std::exception {
    public:
    char * what () {
        std::string message = "ERR: Something Wrong happened in the CubePrinter class";
        return message.data();
    }
};
