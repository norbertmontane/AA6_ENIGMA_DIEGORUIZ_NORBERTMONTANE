#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include <string>

class Enigma {
private:
    Rotor r1, r2, r3;

public:
    bool loadRotors();
    void setPositions(char a, char b, char c);

    char encryptChar(char c);
    char decryptChar(char c);

    std::string encryptMessage(const std::string& msg);
    std::string decryptMessage(const std::string& msg);
};

#endif

