#include "Enigma.h"

bool Enigma::loadRotors() {
    return r1.cargardesdearchivo("Rotor1.txt") &&
        r2.cargardesdearchivo("Rotor2.txt") &&
        r3.cargardesdearchivo("Rotor3.txt");
}

void Enigma::setPositions(char a, char b, char c) {
    r1.ponerposicion(a);
    r2.ponerposicion(b);
    r3.ponerposicion(c);
}

char Enigma::encryptChar(char c) {
    r1.siguienteposicionrotor();
    if (r1.girorotor()) r2.siguienteposicionrotor();
    if (r2.girorotor()) r3.siguienteposicionrotor();

    c = r1.encriptar(c);
    c = r2.encriptar(c);
    c = r3.encriptar(c);

    return c;
}

char Enigma::decryptChar(char c) {
    r1.siguienteposicionrotor();
    if (r1.girorotor()) r2.siguienteposicionrotor();
    if (r2.girorotor()) r3.siguienteposicionrotor();

    c = r3.desencriptar(c);
    c = r2.desencriptar(c);
    c = r1.desencriptar(c);

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
