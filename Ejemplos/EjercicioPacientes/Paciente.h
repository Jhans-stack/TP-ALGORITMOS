#pragma once
#include <iostream>
#include <string>

using namespace std;

class Paciente {
private:
    string dni;
    string nombres;
    string apellidos;
    string especialidad;
    string sede;

public:
    Paciente(string dni, string nombres, string apellidos, string especialidad, string sede) {
        this->dni = dni;
        this->nombres = nombres;
        this->apellidos = apellidos;
        this->especialidad = especialidad;
        this->sede = sede;
    }

    string getDni() { return dni; }
    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getEspecialidad() { return especialidad; }
    string getSede() { return sede; }

    void mostrar() {
        cout << nombres << " " << apellidos
            << " | DNI: " << dni
            << " | Especialidad: " << especialidad
            << " | Sede: " << sede;
    }
};
