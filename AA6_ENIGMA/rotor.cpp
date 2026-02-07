#include "Rotor.h"
#include <fstream>

Rotor::Rotor() {
    wiring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    notch = 'Z';
    position = 0;
}

bool Rotor::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;

    getline(file, wiring);
    if (!validPermutation(wiring)) return false;

    if (file.peek() != EOF)
        file >> notch;
    else
        notch = 'Z';

    return true;
}

bool Rotor::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) return false;

    file << wiring << std::endl;
    file << notch << std::endl;
    return true;
}

bool Rotor::validPermutation(const std::string& perm) {
    if (perm.size() != 26) return false;

    bool used[26] = { false };

    for (char c : perm) {
        if (c < 'A' || c > 'Z') return false;
        if (used[c - 'A']) return false;
        used[c - 'A'] = true;
    }
    return true;
}

void Rotor::setPosition(char c) {
    position = c - 'A';
}

void Rotor::step() {
    position = (position + 1) % 26;
}

bool Rotor::atNotch() const {
    return position == (notch - 'A');
}

char Rotor::encrypt(char c) const {
    int index = (c - 'A' + position) % 26;
    return wiring[index];
}

char Rotor::decrypt(char c) const {
    int index = wiring.find(c);
    index = (index - position + 26) % 26;
    return char('A' + index);
}
