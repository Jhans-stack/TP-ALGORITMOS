#pragma once
#include <cstdlib>
#include "ListaDoble.h"
#include "Ordenamiento.h"

using namespace std;

template <typename T>
class FisherYates {
public:
    void mezclar(ListaDoble<T>& A) {
        int n = longitud(A);
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            Nodo<T>* a = nodoEn(A, i);
            Nodo<T>* b = nodoEn(A, j);
            T aux = a->dato;
            a->dato = b->dato;
            b->dato = aux;
        }
    }
};
