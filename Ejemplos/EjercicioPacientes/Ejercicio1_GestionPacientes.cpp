#include <iostream>
#include <string>
#include "../Lista.h"
#include "Paciente.h"

using namespace std;

void mostrarMenu() {
    cout << endl << "Menu" << endl;
    cout << "1. Ingresar paciente" << endl;
    cout << "2. Mostrar todos los pacientes registrados" << endl;
    cout << "3. Mostrar pacientes por sede" << endl;
    cout << "4. Mostrar numero de pacientes por especialidad" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void ingresarPaciente(ListaEnlazada<Paciente*>* pacientes) {
    string dni, nombres, apellidos, especialidad, sede;

    cout << "Ingrese DNI: ";          cin >> dni;
    cout << "Ingrese nombres: ";      cin >> nombres;
    cout << "Ingrese apellidos: ";    cin >> apellidos;
    cout << "Ingrese especialidad: "; cin >> especialidad;
    cout << "Ingrese sede: ";         cin >> sede;

    Paciente* nuevo = new Paciente(dni, nombres, apellidos, especialidad, sede);
    pacientes->insertarFinal(nuevo);

    cout << endl << "Paciente registrado exitosamente." << endl;
}

void mostrarTodos(ListaEnlazada<Paciente*>* pacientes) {
    cout << endl << "Lista de pacientes:" << endl;

    if (pacientes->esVacia()) {
        cout << "(No hay pacientes registrados)" << endl;
        return;
    }

    Nodo<Paciente*>* actual = pacientes->getInicio();
    int n = 1;

    while (actual != nullptr) {
        cout << n << ". ";
        actual->dato->mostrar();
        cout << endl;
        n++;
        actual = actual->siguiente;
    }
}

void mostrarPorSede(ListaEnlazada<Paciente*>* pacientes) {
    string sede;
    cout << endl << "Ingrese sede a consultar: ";
    cin >> sede;

    cout << endl << "Pacientes en sede " << sede << ":" << endl;
    bool encontrado = false;

    Nodo<Paciente*>* actual = pacientes->getInicio();
    while (actual != nullptr) {
        if (actual->dato->getSede() == sede) {
            cout << "- ";
            actual->dato->mostrar();
            cout << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) cout << "(No hay pacientes registrados en esta sede)" << endl;
}

void mostrarPorEspecialidad(ListaEnlazada<Paciente*>* pacientes) {
    const int MAX_ESPECIALIDADES = 50;
    string especialidades[MAX_ESPECIALIDADES];
    int cantidades[MAX_ESPECIALIDADES];
    int total = 0;

    Nodo<Paciente*>* actual = pacientes->getInicio();
    while (actual != nullptr) {
        string esp = actual->dato->getEspecialidad();

        int i = 0;
        bool encontrado = false;
        while (i < total) {
            if (especialidades[i] == esp) {
                cantidades[i] = cantidades[i] + 1;
                encontrado = true;
                break;
            }
            i++;
        }

        if (!encontrado && total < MAX_ESPECIALIDADES) {
            especialidades[total] = esp;
            cantidades[total] = 1;
            total++;
        }

        actual = actual->siguiente;
    }

    cout << endl << "Resumen por especialidad:" << endl;
    if (total == 0) {
        cout << "(No hay pacientes registrados)" << endl;
        return;
    }
    for (int i = 0; i < total; i++) {
        cout << "- " << especialidades[i] << ": " << cantidades[i] << " paciente(s)" << endl;
    }
}

void liberarPacientes(ListaEnlazada<Paciente*>* pacientes) {
    Nodo<Paciente*>* actual = pacientes->getInicio();
    while (actual != nullptr) {
        delete actual->dato;
        actual = actual->siguiente;
    }
}

int main() {
    ListaEnlazada<Paciente*>* pacientes = new ListaEnlazada<Paciente*>();
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: ingresarPaciente(pacientes);       break;
        case 2: mostrarTodos(pacientes);            break;
        case 3: mostrarPorSede(pacientes);          break;
        case 4: mostrarPorEspecialidad(pacientes);  break;
        case 5: cout << endl << "Saliendo del programa..." << endl; break;
        default: cout << endl << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    liberarPacientes(pacientes);
    delete pacientes;
    system("pause");
    return 0;
}
