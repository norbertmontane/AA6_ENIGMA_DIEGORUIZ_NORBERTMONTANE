#include <iostream>
#include <fstream>
#include "Enigma.h"
#include "Utils.h"

using namespace std;

int main() {
    Enigma enigma;

    if (!enigma.loadRotors()) {
        cout << "[ERROR] No se pudieron cargar los rotors." << endl;
        return 1;
    }

    int opcion;
    do {
        cout << "\tENIGMA" << endl;
        cout << "=================" << endl;
        cout << "1. Cifrar mensaje" << endl;
        cout << "-----------------" << endl;
        cout << "2. Descifrar mensaje" << endl;
        cout << "-----------------" << endl;
        cout << "3. Salir" << endl;
        cout << "-----------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            char a, b, c;
            cout << "Posiciones iniciales (A B C): ";
            cin >> a >> b >> c;

            enigma.setPositions(a, b, c);

            cin.ignore();
            string texto;
            cout << "Introduce el mensaje: ";
            getline(cin, texto);

            string limpio = cleanText(texto);
            string cifrado = enigma.encryptMessage(limpio);
            groupFive(cifrado);

            ofstream out("Xifrat.txt");
            out << cifrado;
            out.close();

            cout << "[OK] Mensaje cifrado guardado en Xifrat.txt" << endl;
        }

        if (opcion == 2) {
            char a, b, c;
            cout << "Posiciones iniciales (A B C): ";
            cin >> a >> b >> c;

            enigma.setPositions(a, b, c);

            ifstream in("Xifrat.txt");
            string linea, texto;
            while (in >> linea) texto += linea;

            string descifrado = enigma.decryptMessage(texto);

            ofstream out("Desxifrat.txt");
            out << descifrado;
            out.close();

            cout << "[OK] Mensaje descifrado guardado en Desxifrat.txt" << endl;
        }

    } while (opcion != 3);

    return 0;
}
