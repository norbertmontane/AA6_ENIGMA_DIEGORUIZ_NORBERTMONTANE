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
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename);

    void setPosition(char c);
    void step();
    bool atNotch() const;

    char encrypt(char c) const;
    char decrypt(char c) const;

    static bool validPermutation(const std::string& perm);
};

#endif

