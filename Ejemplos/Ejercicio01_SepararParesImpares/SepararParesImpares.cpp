#include <iostream>
#include "Lista.h"

using namespace std;

void separarArreglo(int pesos[], int n, int i, int pares[], int& np, int impares[], int& ni) {
    if (i == n) return;
    if (pesos[i] % 2 == 0)
        pares[np++] = pesos[i];
    else
        impares[ni++] = pesos[i];
    separarArreglo(pesos, n, i + 1, pares, np, impares, ni);
}

void procesarArreglo(int pesos[], int n) {
    int pares[20], impares[20];
    int np = 0, ni = 0;
    separarArreglo(pesos, n, 0, pares, np, impares, ni);

    cout << "Entrada: ";
    for (int i = 0; i < n; i++) cout << pesos[i] << " ";
    cout << endl << "Salida:  ";
    for (int i = 0; i < np; i++) cout << pares[i] << " ";
    for (int i = 0; i < ni; i++) cout << impares[i] << " ";
    cout << "(pares: " << np << ")" << endl << endl;
}

void separarLista(Nodo<int>* actual, ListaEnlazada<int>& pares, ListaEnlazada<int>& impares) {
    if (actual == nullptr) return;
    if (actual->dato % 2 == 0)
        pares.insertarFinal(actual->dato);
    else
        impares.insertarFinal(actual->dato);
    separarLista(actual->siguiente, pares, impares);
}

void mostrarNodos(Nodo<int>* actual) {
    for (; actual != nullptr; actual = actual->siguiente) cout << actual->dato << " ";
}

void procesarLista(ListaEnlazada<int>& entrada) {
    ListaEnlazada<int> pares, impares;
    separarLista(entrada.getInicio(), pares, impares);

    cout << "Entrada: ";
    mostrarNodos(entrada.getInicio());
    cout << endl << "Salida:  ";
    mostrarNodos(pares.getInicio());
    mostrarNodos(impares.getInicio());
    cout << "(pares: " << pares.longitud() << ")" << endl << endl;
}

int main() {
    int ejemplo1[] = { 5, 2, 8, 3, 6 };
    int ejemplo2[] = { 7, 4, 9, 1, 10, 12 };

    cout << "===== VERSION CON ARREGLO =====" << endl;
    procesarArreglo(ejemplo1, 5);
    procesarArreglo(ejemplo2, 6);

    cout << "===== VERSION CON LISTA ENLAZADA =====" << endl;
    ListaEnlazada<int> lista1, lista2;
    for (int x : ejemplo1) lista1.insertarFinal(x);
    for (int x : ejemplo2) lista2.insertarFinal(x);
    procesarLista(lista1);
    procesarLista(lista2);
    return 0;
}
