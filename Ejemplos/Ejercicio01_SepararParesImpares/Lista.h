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

    void insertarIncial(T valor) {
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

    void mostar() {
        Nodo<T>* actual = inicio;

        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }

        cout << "NULL" << endl;
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

    void eliminarPos(int pos) {
        if (inicio == nullptr || pos < 1) return;

        if (pos == 1) {
            Nodo<T>* temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
            return;
        }

        Nodo<T>* anterior = inicio;
        for (int i = 1; i < pos - 1; i++) {
            if (anterior->siguiente == nullptr) return;
            anterior = anterior->siguiente;
        }

        if (anterior->siguiente == nullptr) return;

        Nodo<T>* temp = anterior->siguiente;
        anterior->siguiente = temp->siguiente;
        delete temp;
    }

    void modificarPos(T valor, int pos) {
        Nodo<T>* actual = inicio;
        int i = 1;

        while (actual != nullptr && i < pos) {
            actual = actual->siguiente;
            i++;
        }

        if (actual != nullptr) actual->dato = valor;
    }
};
