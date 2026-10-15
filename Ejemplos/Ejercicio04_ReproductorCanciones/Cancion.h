#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cancion {
public:
    int codigo;
    int duracion;
    int anio;
    string genero;

    Cancion(int codigo, int duracion, int anio, string genero) {
        this->codigo = codigo;
        this->duracion = duracion;
        this->anio = anio;
        this->genero = genero;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << " | Duracion: " << duracion / 60 << ":"
             << (duracion % 60 < 10 ? "0" : "") << duracion % 60
             << " | Anio: " << anio << " | Genero: " << genero << endl;
    }
};
