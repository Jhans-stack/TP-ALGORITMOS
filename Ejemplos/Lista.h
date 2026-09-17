#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* inicio;
public:
    ListaEnlazada() {
        inicio = nullptr;
    }

    void insertarInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }

    void insertarFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);

        if (inicio == nullptr) {
            inicio = nuevo;
            return;
        }

        Nodo<T>* actual = inicio;

        while (actual->siguiente != nullptr)
            actual = actual->siguiente;

        actual->siguiente = nuevo;
    }

    bool buscar(T valor) {
        Nodo<T>* actual = inicio;

        while (actual != nullptr) {
            if (actual->dato == valor)
                return true;
            actual = actual->siguiente;
        }

        return false;
    }

    void eliminar(T valor) {
        if (inicio == nullptr) return;

        if (inicio->dato == valor) {
            Nodo<T>* temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
            return;
        }

        Nodo<T>* actual = inicio;

        while (actual->siguiente != nullptr && actual->siguiente->dato != valor)
            actual = actual->siguiente;

        if (actual->siguiente != nullptr) {
            Nodo<T>* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
        }
    }

    ~ListaEnlazada() {
        while (inicio != nullptr) {
            Nodo<T>* temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
        }
    }

    Nodo<T>* getInicio() {
        return inicio;
    }

    int longitud() {
        int contador = 0;
        Nodo<T>* actual = inicio;

        while (actual != nullptr) {
            contador++;
            actual = actual->siguiente;
        }

        return contador;
    }

    bool esVacia() {
        return inicio == nullptr;
    }
};
