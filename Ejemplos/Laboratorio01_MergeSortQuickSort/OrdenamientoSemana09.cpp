#include <iostream>
#include <string>
#include <vector>
#include "Paciente.h"
using namespace std;

// LISTA DE PACIENTES

vector<Paciente*> crearPacientes() {
    vector<Paciente*> lista;
    lista.push_back(new Paciente("45123678", "Carlos Gutierrez Perez", 34, "2026-05-02"));
    lista.push_back(new Paciente("10234567", "Maria Lopez Rios",       58, "2026-05-03"));
    lista.push_back(new Paciente("72345891", "Jose Ramos Diaz",        27, "2026-05-03"));
    lista.push_back(new Paciente("08456123", "Ana Salinas Cruz",       61, "2026-05-04"));
    lista.push_back(new Paciente("60987654", "Luis Herrera Soto",      45, "2026-05-04"));
    lista.push_back(new Paciente("33445566", "Rosa Medina Vega",       39, "2026-05-05"));
    lista.push_back(new Paciente("71234500", "Pedro Castro Ruiz",      22, "2026-05-05"));
    lista.push_back(new Paciente("20456789", "Elena Navarro Paz",      50, "2026-05-06"));
    lista.push_back(new Paciente("55667788", "Jorge Vilca Mamani",     67, "2026-05-06"));
    lista.push_back(new Paciente("41231234", "Lucia Fernandez Ortiz",  31, "2026-05-07"));
    lista.push_back(new Paciente("09876543", "Miguel Torres Luna",     72, "2026-05-07"));
    lista.push_back(new Paciente("76543210", "Sofia Mendoza Arce",     19, "2026-05-08"));
    lista.push_back(new Paciente("30123456", "Diego Quispe Huaman",    43, "2026-05-08"));
    lista.push_back(new Paciente("48765432", "Patricia Rojas Leon",    36, "2026-05-09"));
    lista.push_back(new Paciente("12345678", "Raul Campos Silva",      55, "2026-05-09"));
    lista.push_back(new Paciente("65432109", "Carmen Flores Ponce",    48, "2026-05-10"));
    lista.push_back(new Paciente("23456780", "Hugo Paredes Cano",      29, "2026-05-10"));
    lista.push_back(new Paciente("78901234", "Valeria Chavez Rey",     24, "2026-05-11"));
    lista.push_back(new Paciente("39012345", "Andres Salazar Gil",     64, "2026-05-11"));
    lista.push_back(new Paciente("51234987", "Gabriela Ortega Mejia",  41, "2026-05-12"));
    lista.push_back(new Paciente("02345678", "Fernando Aguilar Baca",  70, "2026-05-12"));
    return lista;
}

void mostrarPacientes(vector<Paciente*>& lista, string titulo) {
    cout << endl << titulo << endl;
    cout << "DNI - Nombre - Edad - Fecha de ingreso" << endl;
    for (int i = 0; i < lista.size(); i++) {
        cout << lista[i]->getDni() << " - "
             << lista[i]->getNombreCompleto() << " - "
             << lista[i]->getEdad() << " - "
             << lista[i]->getFechaIngreso() << endl;
    }
}

bool estaOrdenado(vector<Paciente*>& lista) {
    for (int i = 1; i < lista.size(); i++) {
        if (lista[i - 1]->getDni() > lista[i]->getDni())
            return false;
    }
    return true;
}

void liberarPacientes(vector<Paciente*>& lista) {
    for (int i = 0; i < lista.size(); i++)
        delete lista[i];
    lista.clear();
}

// MERGE SORT

void fusionar(vector<Paciente*>& lista,
              int izq, int med, int der) {
    vector<Paciente*> izquierda, derecha;
    for (int x = izq; x <= med; x++)
        izquierda.push_back(lista[x]);
    for (int x = med + 1; x <= der; x++)
        derecha.push_back(lista[x]);

    int i = 0, j = 0, k = izq;
    while (i < izquierda.size() && j < derecha.size()) {
        if (izquierda[i]->getDni() <= derecha[j]->getDni())
            lista[k++] = izquierda[i++];
        else
            lista[k++] = derecha[j++];
    }
    while (i < izquierda.size()) lista[k++] = izquierda[i++];
    while (j < derecha.size()) lista[k++] = derecha[j++];
}

void ordenarPorMezcla(vector<Paciente*>& lista,
                      int izq, int der) {
    if (izq >= der) return;
    int med = izq + (der - izq) / 2;
    ordenarPorMezcla(lista, izq, med);
    ordenarPorMezcla(lista, med + 1, der);
    fusionar(lista, izq, med, der);
}

// QUICKSORT

void intercambiar(vector<Paciente*>& lista,
                  int a, int b) {
    Paciente* temporal = lista[a];
    lista[a] = lista[b];
    lista[b] = temporal;
}

int particionar(vector<Paciente*>& lista,
                int inicio, int fin) {
    string pivote = lista[fin]->getDni();
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (lista[j]->getDni() <= pivote) {
            i++;
            intercambiar(lista, i, j);
        }
    }
    intercambiar(lista, i + 1, fin);
    return i + 1;
}

void ordenarRapido(vector<Paciente*>& lista,
                   int inicio, int fin) {
    if (inicio < fin) {
        int posPivote = particionar(lista, inicio, fin);
        ordenarRapido(lista, inicio, posPivote - 1);
        ordenarRapido(lista, posPivote + 1, fin);
    }
}

// MENU

void usarMergeSort() {
    vector<Paciente*> lista = crearPacientes();
    mostrarPacientes(lista, "PACIENTES ANTES DE ORDENAR");
    ordenarPorMezcla(lista, 0, (int)lista.size() - 1);
    mostrarPacientes(lista, "PACIENTES DESPUES DE ORDENAR CON MERGE SORT (por DNI)");
    if (estaOrdenado(lista))
        cout << endl << "Validacion: el orden es CORRECTO" << endl;
    else
        cout << endl << "Validacion: el orden es INCORRECTO" << endl;
    liberarPacientes(lista);
}

void usarQuickSort() {
    vector<Paciente*> lista = crearPacientes();
    mostrarPacientes(lista, "PACIENTES ANTES DE ORDENAR");
    ordenarRapido(lista, 0, (int)lista.size() - 1);
    mostrarPacientes(lista, "PACIENTES DESPUES DE ORDENAR CON QUICKSORT (por DNI)");
    if (estaOrdenado(lista))
        cout << endl << "Validacion: el orden es CORRECTO" << endl;
    else
        cout << endl << "Validacion: el orden es INCORRECTO" << endl;
    liberarPacientes(lista);
}

int main()
{
    int opcion;
    do {
        cout << endl << "===== ORDENAMIENTO DE PACIENTES - SEMANA 09 =====" << endl;
        cout << "1. Ordenar con Merge Sort" << endl;
        cout << "2. Ordenar con QuickSort" << endl;
        cout << "0. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        }

        switch (opcion) {
        case 1: usarMergeSort(); break;
        case 2: usarQuickSort(); break;
        case 0: cout << "Hasta luego" << endl; break;
        default: cout << "Opcion no valida" << endl; break;
        }
    } while (opcion != 0);

    return 0;
}
