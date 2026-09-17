#include <iostream>
#include <vector>

// Ordena un vector de enteros usando el algoritmo de burbuja
void bubbleSort(std::vector<int>& datos) {
    int n = datos.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (datos[j] > datos[j + 1]) {
                std::swap(datos[j], datos[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> numeros = {5, 2, 9, 1, 5, 6};

    std::cout << "Vector original: ";
    for (int n : numeros) std::cout << n << " ";
    std::cout << std::endl;

    bubbleSort(numeros);

    std::cout << "Vector ordenado: ";
    for (int n : numeros) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
