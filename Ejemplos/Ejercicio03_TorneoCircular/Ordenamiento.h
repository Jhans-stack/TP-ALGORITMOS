#pragma once
#include "ListaCircular.h"

template <typename T, typename Criterio>
void insercion(ListaCircular<T>& A, Criterio criterio) {
    NodoCircular<T>* cabeza = A.getCabeza();
    if (cabeza == nullptr) return;

    for (NodoCircular<T>* i = cabeza->siguiente; i != cabeza; i = i->siguiente) {
        T aux = i->dato;
        NodoCircular<T>* p = cabeza;
        while (p != i && !criterio(aux, p->dato)) {
            p = p->siguiente;
        }
        if (p != i) {
            T arrastre = aux;
            for (NodoCircular<T>* q = p; ; q = q->siguiente) {
                T tmp = q->dato;
                q->dato = arrastre;
                arrastre = tmp;
                if (q == i) break;
            }
        }
    }
}
