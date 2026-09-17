#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int c;
    cout << "Cuantos precios? "; cin >> c;

    double* precio = new double[c];
    for (int i = 0; i < c; i++) {
        cout << "Precio " << i + 1 << ": ";
        cin >> precio[i];
    }

    // Cada lambda tiene una sola responsabilidad.
    auto aplicarDescuento = [](double p) { return p * 0.85; };
    auto esMenorACien = [](double p) { return p < 100.0; };

    for (int i = 0; i < c; i++) {
        double precioFinal = aplicarDescuento(precio[i]);
        if (esMenorACien(precioFinal))
            cout << "S/ " << fixed << setprecision(2) << precioFinal << endl;
    }

    delete[] precio;

    system("pause");
    return 0;
}
