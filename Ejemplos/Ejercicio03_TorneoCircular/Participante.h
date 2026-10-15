#pragma once
#include <iostream>
#include <string>

using namespace std;

class Participante {
public:
    int codigo;
    int edad;
    char genero;
    string equipo;

    Participante(int codigo, int edad, char genero, string equipo) {
        this->codigo = codigo;
        this->edad = edad;
        this->genero = genero;
        this->equipo = equipo;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << " | Edad: " << edad
             << " | Genero: " << genero << " | Equipo: " << equipo << endl;
    }
};
