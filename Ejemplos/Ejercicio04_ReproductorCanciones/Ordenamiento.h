#pragma once
#include "ListaDoble.h"

template <typename T>
int longitud(ListaDoble<T>& A) {
    int n = 0;
    for (Nodo<T>* p = A.getCabeza(); p != nullptr; p = p->siguiente) n++;
    return n;
}

template <typename T>
Nodo<T>* nodoEn(ListaDoble<T>& A, int pos) {
    Nodo<T>* p = A.getCabeza();
    for (int i = 0; i < pos && p != nullptr; i++) p = p->siguiente;
    return p;
}

template <typename T, typename Criterio>
void shellSort(ListaDoble<T>& A, Criterio criterio) {
    int n = longitud(A);
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; i++) {
            T temp = nodoEn(A, i)->dato;
            int j = i;
            while (j >= intervalo && criterio(temp, nodoEn(A, j - intervalo)->dato)) {
                nodoEn(A, j)->dato = nodoEn(A, j - intervalo)->dato;
                j -= intervalo;
            }
            nodoEn(A, j)->dato = temp;
        }
    }
}
