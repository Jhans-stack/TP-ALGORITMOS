#pragma once
#include <iostream>
#include <string>

using namespace std;

class Lector {
public:
    int codigo;
    int edad;
    char genero;
    string tipo;

    Lector(int codigo, int edad, char genero, string tipo) {
        this->codigo = codigo;
        this->edad = edad;
        this->genero = genero;
        this->tipo = tipo;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << " | Edad: " << edad
             << " | Genero: " << genero << " | Tipo: " << tipo << endl;
    }
};
