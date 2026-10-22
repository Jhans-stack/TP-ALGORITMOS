#pragma once
#include <string>
using namespace std;

class Paciente {
private:
    string dni;
    string nombreCompleto;
    int edad;
    string fechaIngreso;

public:
    Paciente(string dni, string nombreCompleto, int edad, string fechaIngreso) {
        this->dni = dni;
        this->nombreCompleto = nombreCompleto;
        this->edad = edad;
        this->fechaIngreso = fechaIngreso;
    }

    string getDni() {
        return dni;
    }

    string getNombreCompleto() {
        return nombreCompleto;
    }

    int getEdad() {
        return edad;
    }

    string getFechaIngreso() {
        return fechaIngreso;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }
};
