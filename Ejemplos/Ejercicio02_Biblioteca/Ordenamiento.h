#pragma once
#include "Lista.h"

template <typename T, typename Criterio>
void seleccion(ListaEnlazada<T>& A, Criterio criterio) {
    for (Nodo<T>* i = A.getInicio(); i != nullptr; i = i->siguiente) {
        Nodo<T>* k = i;
        for (Nodo<T>* j = i->siguiente; j != nullptr; j = j->siguiente) {
            if (criterio(j->dato, k->dato)) {
                k = j;
            }
        }
        T aux = i->dato;
        i->dato = k->dato;
        k->dato = aux;
    }
}
