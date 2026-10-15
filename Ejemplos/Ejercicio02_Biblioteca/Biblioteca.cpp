#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Lector.h"
#include "Lista.h"
#include "Cola.h"
#include "Ordenamiento.h"

using namespace std;

int NUM_TIPOS = 4;
string TIPOS[4] = { "Estudiante", "Docente", "Investigador", "Publico" };

void generarLectores(ListaEnlazada<Lector*>& lectores) {
    Lector* arreglo[150];
    int n = 31 + rand() % 119;
    bool usado[1001] = { false };
    for (int i = 0; i < n; i++) {
        int codigo;
        do { codigo = 1 + rand() % 1000; } while (usado[codigo]);
        usado[codigo] = true;
        int edad = 12 + rand() % 59;
        char genero = (rand() % 2 == 0) ? 'M' : 'F';
        string tipo = (i < NUM_TIPOS) ? TIPOS[i] : TIPOS[rand() % NUM_TIPOS];
        arreglo[i] = new Lector(codigo, edad, genero, tipo);
    }
    for (int i = 0; i < n; i++) lectores.insertarFinal(arreglo[i]);
}

void mostrarLista(ListaEnlazada<Lector*>& lectores) {
    if (lectores.esVacia()) { cout << "(lista vacia)" << endl; return; }
    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente)
        actual->dato->mostrar();
}

template <typename Criterio>
int contar_si(ListaEnlazada<Lector*>& lectores, Criterio criterio) {
    int contador = 0;
    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente)
        if (criterio(actual->dato)) contador++;
    return contador;
}

template <typename Criterio>
Lector* buscar_primero(ListaEnlazada<Lector*>& lectores, Criterio criterio) {
    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente)
        if (criterio(actual->dato)) return actual->dato;
    return nullptr;
}

int mayorEdadTipo(Nodo<Lector*>* nodo, string tipo) {
    if (nodo == nullptr) return -1;
    int mayor = mayorEdadTipo(nodo->siguiente, tipo);
    if (nodo->dato->tipo == tipo && nodo->dato->edad > mayor)
        mayor = nodo->dato->edad;
    return mayor;
}

void registrar_frecuentes(ListaEnlazada<Lector*>& lectores, ListaEnlazada<Lector*>& frecuentes) {
    while (!frecuentes.esVacia()) frecuentes.eliminarPos(1);

    double suma = 0;
    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente)
        suma += actual->dato->edad;
    double promedio = suma / lectores.longitud();
    cout << "Edad promedio: " << promedio << endl;

    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente)
        if (actual->dato->edad > promedio) frecuentes.insertarFinal(actual->dato);
    cout << "\n-- Lectores con edad mayor al promedio --" << endl;
    mostrarLista(frecuentes);

    Nodo<Lector*>* actual = frecuentes.getInicio();
    while (actual != nullptr) {
        Nodo<Lector*>* siguiente = actual->siguiente;
        if (actual->dato->codigo % 2 == 0) frecuentes.eliminar(actual->dato);
        actual = siguiente;
    }
    cout << "\n-- Lista final sin codigos pares --" << endl;
    mostrarLista(frecuentes);
}

void atender_lectores(ListaEnlazada<Lector*>& lectores) {
    Cola<Lector*> cola;
    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente)
        if (actual->dato->tipo == "Estudiante") cola.enqueue(actual->dato);

    int edadesPares = 0;
    while (!cola.isEmpty()) {
        cola.front()->mostrar();
        if (cola.front()->edad % 2 == 0) edadesPares++;
        cola.dequeue();
    }
    cout << "Estudiantes con edad par: " << edadesPares << endl;
}

int main() {
    srand((unsigned)time(nullptr));
    ListaEnlazada<Lector*> lectores;
    ListaEnlazada<Lector*> frecuentes;
    generarLectores(lectores);
    cout << "Se generaron " << lectores.longitud() << " lectores." << endl;

    int opcion;
    do {
        cout << "\n=== EJERCICIO 2 ===" << endl;
        cout << "1. Mostrar lectores" << endl;
        cout << "2. Lambdas: contar menores de 18 y buscar un tipo" << endl;
        cout << "3. Recursiva: mayor edad de un tipo" << endl;
        cout << "4. registrar_frecuentes" << endl;
        cout << "5. atender_lectores" << endl;
        cout << "6. Ordenar por seleccion los frecuentes" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarLista(lectores);
        }
        else if (opcion == 2) {
            cout << "Menores de 18: " << contar_si(lectores, [](Lector* l) { return l->edad < 18; }) << endl;
            string tipo;
            cout << "Tipo a buscar: ";
            cin >> tipo;
            Lector* primero = buscar_primero(lectores, [&tipo](Lector* l) { return l->tipo == tipo; });
            if (primero != nullptr) primero->mostrar();
            else cout << "No existe ese tipo." << endl;
        }
        else if (opcion == 3) {
            string tipo;
            cout << "Tipo: ";
            cin >> tipo;
            int mayor = mayorEdadTipo(lectores.getInicio(), tipo);
            if (mayor == -1) cout << "No existen lectores de ese tipo." << endl;
            else cout << "Mayor edad: " << mayor << endl;
        }
        else if (opcion == 4) {
            registrar_frecuentes(lectores, frecuentes);
        }
        else if (opcion == 5) {
            atender_lectores(lectores);
        }
        else if (opcion == 6) {
            if (frecuentes.esVacia()) {
                cout << "Primero ejecute la opcion 4." << endl;
            } else {
                cout << "-- Antes --" << endl;
                mostrarLista(frecuentes);
                seleccion(frecuentes, [](Lector* a, Lector* b) {
                    if (a->edad != b->edad) return a->edad > b->edad;
                    return a->codigo < b->codigo;
                });
                cout << "-- Despues --" << endl;
                mostrarLista(frecuentes);
            }
        }
    } while (opcion != 0);

    for (Nodo<Lector*>* actual = lectores.getInicio(); actual != nullptr; actual = actual->siguiente) delete actual->dato;
    return 0;
}
