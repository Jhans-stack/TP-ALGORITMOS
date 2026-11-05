#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int noEncontrado = -1;

int busquedaBinariaMejor(vector<int>& temperaturas, int umbral) {
    int inicio = 0;
    int fin = (int)temperaturas.size() - 1;
    int resultado = noEncontrado;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (temperaturas[medio] >= umbral) {
            resultado = medio;
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }
    return resultado;
}

int main()
{
    vector<int> temperaturas = { -5, -2, 0, 3, 6, 9, 12, 15, 18, 21 };
    int umbral = 10;

    int posicion = busquedaBinariaMejor(temperaturas, umbral);

    if (posicion == noEncontrado)
        cout << "Ninguna temperatura alcanza o supera " << umbral << endl;
    else
        cout << "La primera temperatura mayor o igual a " << umbral
             << " se encuentra en el indice: " << posicion << endl;

    return 0;
}
