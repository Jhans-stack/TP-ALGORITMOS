#include <string>
#include <iostream>
#include "../Lista.h"

using namespace std;

void mostrar(ListaEnlazada<float>* lista, string mensaje) {
    cout << mensaje << endl;

    Nodo<float>* actual = lista->getInicio();

    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }

    cout << endl;
}

// Pregunta 01 -> registrarPedido: registra pedidos validando que el monto
// este entre 10.0 y 500.0 y que no se repita.
void registrarPedido(ListaEnlazada<float>* lista) {
    int cantidad;
    cout << "Cuantos pedidos?" << endl;
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {
        float monto;
        cout << "Monto:" << endl;
        cin >> monto;

        if (monto < 10.0 || monto > 500.0) {
            cout << monto << " -> No se registra (debe estar entre 10.0 y 500.0)" << endl;
            continue;
        }

        if (lista->buscar(monto)) {
            cout << monto << " -> No se registra (ya existe)" << endl;
            continue;
        }

        lista->insertarFinal(monto);
        cout << monto << " -> Se registro con exito" << endl;
    }

    mostrar(lista, "Pedidos registrados:");
}

// Pregunta 02 -> calcularTotalYPromedio: calcula el total y el promedio de
// los pedidos registrados.
void calcularTotalYPromedio(ListaEnlazada<float>* lista) {
    mostrar(lista, "Lista actual:");

    if (lista->esVacia()) {
        cout << "No hay pedidos registrados." << endl;
        return;
    }

    float total = 0.0;
    int contador = 0;

    Nodo<float>* actual = lista->getInicio();

    while (actual != nullptr) {
        total += actual->dato;
        contador++;
        actual = actual->siguiente;
    }

    float promedio = total / contador;
    cout << "El total de pedidos es: S/" << total << " y el promedio es: S/" << promedio << endl;
}

// Pregunta 03 -> eliminarMenorMonto: elimina el pedido de menor monto registrado.
void eliminarMenorMonto(ListaEnlazada<float>* lista) {
    mostrar(lista, "Lista actual:");

    if (lista->esVacia()) {
        cout << "No hay pedidos registrados." << endl;
        return;
    }

    Nodo<float>* actual = lista->getInicio();
    float menorMonto = actual->dato;
    actual = actual->siguiente;

    while (actual != nullptr) {
        if (actual->dato < menorMonto) {
            menorMonto = actual->dato;
        }
        actual = actual->siguiente;
    }

    cout << "Menor monto encontrado: " << menorMonto << endl;

    lista->eliminar(menorMonto);
    cout << "Pedido eliminado." << endl;
    mostrar(lista, "Lista luego de eliminar:");
}

// Pregunta 04 -> modificarPedidoMayor: modifica el primer pedido mayor a S/100
// aplicandole un descuento del 10%.
void modificarPedidoMayor(ListaEnlazada<float>* lista) {
    mostrar(lista, "Lista actual:");

    Nodo<float>* actual = lista->getInicio();
    while (actual != nullptr && actual->dato <= 100.0) {
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "No hay ningun pedido mayor a S/100." << endl;
        return;
    }

    cout << "Pedido encontrado: " << actual->dato << endl;

    float nuevoMonto = actual->dato * 0.9f;

    if (nuevoMonto < 10.0) {
        cout << "No se puede modificar el pedido, el nuevo monto es menor a S/10.00" << endl;
        return;
    }

    actual->dato = nuevoMonto;
    cout << "Nuevo monto luego de modificar: " << nuevoMonto << endl;
    mostrar(lista, "Lista luego de modificar:");
}

int main() {
    ListaEnlazada<float>* pedidos = new ListaEnlazada<float>();

    int opcion;

    do {
        cout << "MENU" << endl;
        cout << "1. Registrar pedido" << endl;
        cout << "2. Calcular total y promedio de pedidos" << endl;
        cout << "3. Eliminar el pedido de menor monto" << endl;
        cout << "4. Modificar el primer pedido mayor a S/100" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opcion (0 para salir):" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1: registrarPedido(pedidos); break;
        case 2: calcularTotalYPromedio(pedidos); break;
        case 3: eliminarMenorMonto(pedidos); break;
        case 4: modificarPedidoMayor(pedidos); break;
        }

    } while (opcion != 0);

    delete pedidos;
    system("pause");
    return 0;
}
