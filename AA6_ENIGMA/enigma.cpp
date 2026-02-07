#include "Enigma.h"

bool Enigma::loadRotors() {
    return r1.loadFromFile("Rotor1.txt") &&
        r2.loadFromFile("Rotor2.txt") &&
        r3.loadFromFile("Rotor3.txt");
}

void Enigma::setPositions(char a, char b, char c) {
    r1.setPosition(a);
    r2.setPosition(b);
    r3.setPosition(c);
}

char Enigma::encryptChar(char c) {
    r1.step();
    if (r1.atNotch()) r2.step();
    if (r2.atNotch()) r3.step();

    c = r1.encrypt(c);
    c = r2.encrypt(c);
    c = r3.encrypt(c);

    return c;
}

char Enigma::decryptChar(char c) {
    r1.step();
    if (r1.atNotch()) r2.step();
    if (r2.atNotch()) r3.step();

    c = r3.decrypt(c);
    c = r2.decrypt(c);
    c = r1.decrypt(c);

    return c;
}

std::string Enigma::encryptMessage(const std::string& msg) {
    std::string result;
    for (char c : msg)
        result += encryptChar(c);
    return result;
}

std::string Enigma::decryptMessage(const std::string& msg) {
    std::string result;
    for (char c : msg)
        result += decryptChar(c);
    return result;
}
