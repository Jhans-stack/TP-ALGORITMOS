#pragma once
#include <iostream>

using namespace std;

template <typename T>
class NodoCircular {
public:
    T dato;
    NodoCircular<T>* siguiente;

    NodoCircular(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

template <typename T>
class ListaCircular {
private:
    NodoCircular<T>* cabeza;

public:
    ListaCircular() {
        cabeza = nullptr;
    }

    void insertarInicio(T valor) {
        NodoCircular<T>* nuevo = new NodoCircular<T>(valor);

        if (cabeza == nullptr) {
            cabeza = nuevo;
            nuevo->siguiente = nuevo;
            return;
        }

        NodoCircular<T>* temp = cabeza;
        while (temp->siguiente != cabeza)
            temp = temp->siguiente;

        nuevo->siguiente = cabeza;
        temp->siguiente = nuevo;
        cabeza = nuevo;
    }

    void eliminar(T valor) {
        if (cabeza == nullptr) return;

        NodoCircular<T>* actual = cabeza;
        NodoCircular<T>* previo = nullptr;

        do {
            if (actual->dato == valor) {
                if (actual->siguiente == actual) {
                    cabeza = nullptr;
                    delete actual;
                    return;
                }
                if (previo != nullptr)
                    previo->siguiente = actual->siguiente;
                else {
                    NodoCircular<T>* temp = cabeza;
                    while (temp->siguiente != cabeza)
                        temp = temp->siguiente;
                    cabeza = cabeza->siguiente;
                    temp->siguiente = cabeza;
                }
                delete actual;
                return;
            }
            previo = actual;
            actual = actual->siguiente;
        } while (actual != cabeza);
    }

    NodoCircular<T>* getCabeza() {
        return cabeza;
    }

    bool esVacia() {
        return cabeza == nullptr;
    }
};
