#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Cancion.h"
#include "ListaDoble.h"
#include "Ordenamiento.h"
#include "FisherYates.h"

using namespace std;

int NUM_GENEROS = 5;
string GENEROS[5] = { "Rock", "Pop", "Salsa", "Cumbia", "Jazz" };

void generarCanciones(ListaDoble<Cancion*>& canciones) {
    int n = 21 + rand() % 79;
    bool usado[1001] = { false };
    for (int i = 0; i < n; i++) {
        int codigo;
        do { codigo = 1 + rand() % 1000; } while (usado[codigo]);
        usado[codigo] = true;
        int duracion = 60 + rand() % 421;
        int anio = 1990 + rand() % 36;
        string genero = (i < NUM_GENEROS) ? GENEROS[i] : GENEROS[rand() % NUM_GENEROS];
        canciones.insertarFinal(new Cancion(codigo, duracion, anio, genero));
    }
}

void mostrarInicioFin(ListaDoble<Cancion*>& canciones) {
    if (canciones.esVacia()) { cout << "(lista vacia)" << endl; return; }
    for (Nodo<Cancion*>* actual = canciones.getCabeza(); actual != nullptr; actual = actual->siguiente)
        actual->dato->mostrar();
}

void mostrarFinInicio(ListaDoble<Cancion*>& canciones) {
    if (canciones.esVacia()) { cout << "(lista vacia)" << endl; return; }
    Nodo<Cancion*>* ultimo = canciones.getCabeza();
    while (ultimo->siguiente != nullptr) ultimo = ultimo->siguiente;

    int total = 0;
    for (Nodo<Cancion*>* actual = ultimo; actual != nullptr; actual = actual->anterior) {
        actual->dato->mostrar();
        total += actual->dato->duracion;
    }
    int minutos = total / 60, segundos = total % 60;
    cout << "Duracion total: " << minutos << ":" << (segundos < 10 ? "0" : "") << segundos << " (mm:ss)" << endl;
}

int contarGenero(Nodo<Cancion*>* nodo, string genero) {
    if (nodo == nullptr) return 0;
    return (nodo->dato->genero == genero ? 1 : 0) + contarGenero(nodo->siguiente, genero);
}

int eliminarMenoresDuracion(ListaDoble<Cancion*>& canciones, int segundos) {
    int eliminadas = 0;
    Nodo<Cancion*>* nodo = canciones.getCabeza();
    while (nodo != nullptr) {
        Nodo<Cancion*>* siguiente = nodo->siguiente;
        if (nodo->dato->duracion < segundos) {
            canciones.eliminar(nodo);
            eliminadas++;
        }
        nodo = siguiente;
    }
    return eliminadas;
}

void reproductor(ListaDoble<Cancion*>& canciones) {
    Nodo<Cancion*>* actual = canciones.getCabeza();
    if (actual == nullptr) { cout << "No hay canciones." << endl; return; }
    int opcion;
    do {
        cout << "\nReproduciendo: "; actual->dato->mostrar();
        cout << "1. Siguiente  2. Anterior  0. Salir del reproductor: ";
        cin >> opcion;
        if (opcion == 1) {
            if (actual->siguiente == nullptr) cout << "Es la ultima cancion de la lista." << endl;
            else actual = actual->siguiente;
        }
        else if (opcion == 2) {
            if (actual->anterior == nullptr) cout << "Es la primera cancion de la lista." << endl;
            else actual = actual->anterior;
        }
    } while (opcion != 0);
}

int main() {
    srand((unsigned)time(nullptr));
    ListaDoble<Cancion*> canciones;
    generarCanciones(canciones);

    int opcion;
    do {
        cout << "\n=== EJERCICIO 4: Ritmo Play ===" << endl;
        cout << "1. Mostrar lista (inicio a fin)" << endl;
        cout << "2. Mostrar lista (fin a inicio) y duracion total" << endl;
        cout << "3. Contar canciones de un genero (recursiva)" << endl;
        cout << "4. Eliminar canciones de menor duracion" << endl;
        cout << "5. Modo aleatorio (Fisher-Yates) y reproductor" << endl;
        cout << "6. Ordenar por duracion (Shell)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarInicioFin(canciones);
        }
        else if (opcion == 2) {
            mostrarFinInicio(canciones);
        }
        else if (opcion == 3) {
            string genero;
            cout << "Genero (Rock, Pop, Salsa, Cumbia, Jazz): ";
            cin >> genero;
            cout << "Canciones de " << genero << ": " << contarGenero(canciones.getCabeza(), genero) << endl;
        }
        else if (opcion == 4) {
            int segundos;
            cout << "Eliminar canciones con duracion menor a (segundos): ";
            cin >> segundos;
            cout << "-- Antes --" << endl; mostrarInicioFin(canciones);
            int eliminadas = eliminarMenoresDuracion(canciones, segundos);
            cout << "-- Despues --" << endl; mostrarInicioFin(canciones);
            cout << "Canciones eliminadas: " << eliminadas << endl;
        }
        else if (opcion == 5) {
            cout << "-- Antes de mezclar --" << endl; mostrarInicioFin(canciones);
            FisherYates<Cancion*> mezclador;
            mezclador.mezclar(canciones);
            cout << "-- Despues de mezclar --" << endl; mostrarInicioFin(canciones);
            reproductor(canciones);
        }
        else if (opcion == 6) {
            cout << "-- Antes de ordenar --" << endl; mostrarInicioFin(canciones);
            shellSort(canciones, [](Cancion* a, Cancion* b) { return a->duracion < b->duracion; });
            cout << "-- Despues de ordenar --" << endl; mostrarInicioFin(canciones);
        }
    } while (opcion != 0);

    return 0;
}
