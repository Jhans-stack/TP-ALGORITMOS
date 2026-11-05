
#include "pch.h"
#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}
};

class Arbol {
private:
    Nodo* raiz;

    Nodo* insertarNodo(Nodo* nodo, int valor) {
        if (nodo == nullptr) return new Nodo(valor);
        if (valor < nodo->valor) nodo->izq = insertarNodo(nodo->izq, valor);
        else                     nodo->der = insertarNodo(nodo->der, valor);
        return nodo;
    }

    void enOrdenNodo(Nodo* nodo) {
        if (nodo == nullptr) return;
        enOrdenNodo(nodo->izq);
        cout << nodo->valor << " ";
        enOrdenNodo(nodo->der);
    }

    int contarNodos(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + contarNodos(nodo->izq) + contarNodos(nodo->der);
    }

    int alturaNodo(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int alturaIzq = alturaNodo(nodo->izq);
        int alturaDer = alturaNodo(nodo->der);
        return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
    }

    void liberarNodo(Nodo* nodo) {
        if (nodo == nullptr) return;
        liberarNodo(nodo->izq);
        liberarNodo(nodo->der);
        delete nodo;
    }

public:
    Arbol() : raiz(nullptr) {}
    ~Arbol() { liberarNodo(raiz); }

    void insertar(int edad) {
        if (edad % 3 == 0)
            raiz = insertarNodo(raiz, edad);
    }

    void enOrden() { enOrdenNodo(raiz); cout << endl; }
    int cantidad() { return contarNodos(raiz); }
    int altura()   { return alturaNodo(raiz); }
};

int main()
{
    int edades[] = { 45, 32, 60, 28, 50, 30, 70, 33 };
    int cantidadEdades = sizeof(edades) / sizeof(edades[0]);

    Arbol arbol;
    for (int i = 0; i < cantidadEdades; i++)
        arbol.insertar(edades[i]);

    cout << "EnOrden: ";
    arbol.enOrden();
    cout << "Cantidad: " << arbol.cantidad() << endl;
    cout << "Altura: " << arbol.altura() << endl;

    return 0;
}
