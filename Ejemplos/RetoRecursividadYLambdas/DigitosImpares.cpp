#include <iostream>

using namespace std;

// digitosImpares: cuenta y suma (por referencia) los digitos impares de n.
// Recursividad pura: sin bucles y sin variables globales.
int digitosImpares(int n, int& suma) {
    if (n == 0) return 0;

    int digito = n % 10;
    if (digito % 2 != 0) suma += digito;

    return (digito % 2 != 0) + digitosImpares(n / 10, suma);
}

int main() {
    int n, suma = 0;
    cout << "Ingrese un numero: "; cin >> n;

    int cantidad = digitosImpares(n, suma);

    cout << "Cantidad: " << cantidad << endl;
    cout << "Suma: " << suma << endl;

    system("pause");
    return 0;
}
