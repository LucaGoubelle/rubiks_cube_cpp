#include <exception>

class PrinterException : public std::exception {
    public:
    char * what () {
        return "ERR: Something Wrong happened in the CubePrinter class";
    }
};
