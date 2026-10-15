#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Participante.h"
#include "ListaCircular.h"
#include "Pila.h"
#include "Ordenamiento.h"

using namespace std;

int NUM_EQUIPOS = 4;
string EQUIPOS[4] = { "Rojo", "Azul", "Verde", "Amarillo" };

void generarParticipantes(ListaCircular<Participante*>& participantes) {
    int n = 11 + rand() % 29;
    bool usado[1001] = { false };
    for (int i = 0; i < n; i++) {
        int codigo;
        do { codigo = 1 + rand() % 1000; } while (usado[codigo]);
        usado[codigo] = true;
        int edad = 10 + rand() % 51;
        char genero = (rand() % 2 == 0) ? 'M' : 'F';
        string equipo = (i < NUM_EQUIPOS) ? EQUIPOS[i] : EQUIPOS[rand() % NUM_EQUIPOS];
        participantes.insertarInicio(new Participante(codigo, edad, genero, equipo));
    }
}

void mostrarCirculo(ListaCircular<Participante*>& participantes) {
    if (participantes.esVacia()) { cout << "(lista vacia)" << endl; return; }
    NodoCircular<Participante*>* actual = participantes.getCabeza();
    do {
        actual->dato->mostrar();
        actual = actual->siguiente;
    } while (actual != participantes.getCabeza());
}

int sumaEdadesEquipo(NodoCircular<Participante*>* actual, NodoCircular<Participante*>* cabeza, string equipo, bool primera = true) {
    if (actual == nullptr) return 0;
    if (actual == cabeza && !primera) return 0;
    int aporte = (actual->dato->equipo == equipo) ? actual->dato->edad : 0;
    return aporte + sumaEdadesEquipo(actual->siguiente, cabeza, equipo, false);
}

int eliminarMenores(ListaCircular<Participante*>& participantes, int edadMinima) {
    int eliminados = 0;
    bool encontrado = true;
    while (encontrado && !participantes.esVacia()) {
        encontrado = false;
        NodoCircular<Participante*>* actual = participantes.getCabeza();
        do {
            if (actual->dato->edad < edadMinima) {
                participantes.eliminar(actual->dato);
                eliminados++;
                encontrado = true;
                break;
            }
            actual = actual->siguiente;
        } while (actual != participantes.getCabeza());
    }
    return eliminados;
}

void jugarEliminacion(ListaCircular<Participante*>& participantes, int k) {
    if (participantes.esVacia()) { cout << "No hay participantes." << endl; return; }

    ListaCircular<Participante*> juego;
    int cantidad = 0;
    NodoCircular<Participante*>* actual = participantes.getCabeza();
    do {
        juego.insertarInicio(actual->dato);
        cantidad++;
        actual = actual->siguiente;
    } while (actual != participantes.getCabeza());

    Pila<Participante*> pila;
    NodoCircular<Participante*>* nodo = juego.getCabeza();
    cout << "\n-- Orden de eliminacion --" << endl;
    while (cantidad > 1) {
        for (int i = 1; i < k; i++) nodo = nodo->siguiente;
        NodoCircular<Participante*>* siguiente = nodo->siguiente;
        Participante* eliminado = nodo->dato;
        juego.eliminar(eliminado);
        pila.push(eliminado);
        eliminado->mostrar();
        nodo = siguiente;
        cantidad--;
    }
    Participante* ganador = juego.getCabeza()->dato;
    cout << "\nGANADOR: ";
    ganador->mostrar();

    cout << "\n-- Pila de eliminados (del ultimo al primero) --" << endl;
    int mismoEquipo = 0;
    while (!pila.isEmpty()) {
        pila.top()->mostrar();
        if (pila.top()->equipo == ganador->equipo) mismoEquipo++;
        pila.pop();
    }
    cout << "Eliminados del equipo " << ganador->equipo << ": " << mismoEquipo << endl;
}

int main() {
    srand((unsigned)time(nullptr));
    ListaCircular<Participante*> participantes;
    generarParticipantes(participantes);

    int opcion;
    do {
        cout << "\n=== EJERCICIO 3 ===" << endl;
        cout << "1. Mostrar el circulo" << endl;
        cout << "2. Recursiva: suma de edades de un equipo" << endl;
        cout << "3. Eliminar menores de una edad" << endl;
        cout << "4. Juego de eliminacion y pila" << endl;
        cout << "5. Ordenar por insercion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarCirculo(participantes);
        }
        else if (opcion == 2) {
            string equipo;
            cout << "Equipo: ";
            cin >> equipo;
            cout << "Suma de edades: " << sumaEdadesEquipo(participantes.getCabeza(), participantes.getCabeza(), equipo) << endl;
        }
        else if (opcion == 3) {
            int edad;
            cout << "Eliminar menores de: ";
            cin >> edad;
            cout << "-- Antes --" << endl;
            mostrarCirculo(participantes);
            int eliminados = eliminarMenores(participantes, edad);
            cout << "-- Despues (" << eliminados << " eliminados) --" << endl;
            mostrarCirculo(participantes);
        }
        else if (opcion == 4) {
            int k;
            cout << "Valor de k: ";
            cin >> k;
            if (k >= 1) jugarEliminacion(participantes, k);
        }
        else if (opcion == 5) {
            cout << "-- Antes --" << endl;
            mostrarCirculo(participantes);
            insercion(participantes, [](Participante* a, Participante* b) {
                if (a->edad != b->edad) return a->edad < b->edad;
                return a->codigo < b->codigo;
            });
            cout << "-- Despues --" << endl;
            mostrarCirculo(participantes);
        }
    } while (opcion != 0);

    return 0;
}
