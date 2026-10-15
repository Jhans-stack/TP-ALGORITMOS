#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;

    Nodo(T valor) {
        dato = valor;
        anterior = nullptr;
        siguiente = nullptr;
    }
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;

public:
    ListaDoble() {
        cabeza = nullptr;
    }

    void insertarInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = cabeza;
        if (cabeza != nullptr)
            cabeza->anterior = nuevo;
        cabeza = nuevo;
    }

    void insertarFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }
        Nodo<T>* temp = cabeza;
        while (temp->siguiente != nullptr)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
    }

    void eliminar(Nodo<T>* nodo) {
        if (nodo == nullptr) return;

        if (nodo->anterior != nullptr)
            nodo->anterior->siguiente = nodo->siguiente;
        else
            cabeza = nodo->siguiente;

        if (nodo->siguiente != nullptr)
            nodo->siguiente->anterior = nodo->anterior;

        delete nodo;
    }

    Nodo<T>* getCabeza() {
        return cabeza;
    }

    bool esVacia() {
        return cabeza == nullptr;
    }
};
