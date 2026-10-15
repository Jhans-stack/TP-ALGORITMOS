#pragma once

#include <iostream>

using namespace std;

template <typename T>
class NodoPila {
public:
	T dato;
	NodoPila<T>* siguiente;

	NodoPila(T valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

template <typename T>
class Pila {
private:
	NodoPila<T>* cima;
	int contador;

public:
	Pila() {
		cima = nullptr;
		contador = 0;
	}

	~Pila() {
		while (!isEmpty()) pop();
	}

	void push(T valor) {
		NodoPila<T>* nuevo = new NodoPila<T>(valor);
		nuevo->siguiente = cima;
		cima = nuevo;
		contador++;
	}

	void pop() {
		if (cima == nullptr) return;
		NodoPila<T>* temp = cima;
		cima = cima->siguiente;
		delete temp;
		contador--;
	}

	T top() {
		return cima ? cima->dato : nullptr;
	}

	bool isEmpty() {
		return cima == nullptr;
	}

	int size() {
		return contador;
	}

	void mostrar() {
		for (NodoPila<T>* actual = cima; actual != nullptr; actual = actual->siguiente)
			actual->dato->mostrar();
	}
};
