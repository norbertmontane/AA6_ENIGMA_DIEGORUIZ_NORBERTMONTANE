#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {
private:
    std::string wiring;
    char notch;
    int position;

public:
    Rotor();
    bool cargardesdearchivo(const std::string& filename);
    bool guardarenelarchivo(const std::string& filename);

    void ponerposicion(char c);
    void siguienteposicionrotor();
    bool girorotor() const;

    char encriptar(char c) const;
    char desencriptar(char c) const;

    static bool permutacionvalida(const std::string& perm);
};

#endif

