#include "Rotor.h"
#include <fstream>

Rotor::Rotor() {
    wiring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    notch = 'Z';
    position = 0;
}

bool Rotor::cargardesdearchivo(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;

    getline(file, wiring);
    if (!permutacionvalida(wiring)) return false;

    if (file.peek() != EOF)
        file >> notch;
    else
        notch = 'Z';

    return true;
}

bool Rotor::guardarenelarchivo(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) return false;

    file << wiring << std::endl;
    file << notch << std::endl;
    return true;
}

bool Rotor::permutacionvalida(const std::string& perm) {
    if (perm.size() != 26) return false;

    bool used[26] = { false };

    for (char c : perm) {
        if (c < 'A' || c > 'Z') return false;
        if (used[c - 'A']) return false;
        used[c - 'A'] = true;
    }
    return true;
}

void Rotor::ponerposicion(char c) {
    position = c - 'A';
}

void Rotor::siguienteposicionrotor() {
    position = (position + 1) % 26;
}

bool Rotor::girorotor() const {
    return position == (notch - 'A');
}

char Rotor::encriptar(char c) const {
    int index = (c - 'A' + position) % 26;
    return wiring[index];
}

char Rotor::desencriptar(char c) const {
    int index = wiring.find(c);
    index = (index - position + 26) % 26;
    return char('A' + index);
}
