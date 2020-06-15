#ifndef H_EXCEPTIONS_H
#define H_EXCEPTIONS_H
#include <iostream>

class VLE : public std::exception {
public:
    const char* what() {
        return "Vector length cannot be 0 ";
    }
};


class SIE : public std::exception {
public:
    const char* what() {
        return " \"t\" interval must be between 0 and 1\n";
    }
};


class EPE : public std::exception {
public:
    EPE(int num1, int num2) {
        this->num1 = num1;
        this->num2 = num2;
    }
    const char* pointsException() {
        std::cout << num1 << " " << num2;
        return "Matching points";
    }
private:
    int num1;
    int num2;
};


#endif