#pragma once

#include <iostream>

using namespace std;

template <typename T>
class NodoCola {
public:
	T dato;
	NodoCola<T>* siguiente;

	NodoCola(T valor) {
		dato = valor;
		siguiente = nullptr;
	}
};

template <typename T>
class Cola {
private:
	NodoCola<T>* frente;
	NodoCola<T>* final;
	int contador;

public:
	Cola() {
		frente = nullptr;
		final = nullptr;
		contador = 0;
	}

	~Cola() {
		while (!isEmpty()) dequeue();
	}

	void enqueue(T valor) {
		NodoCola<T>* nuevo = new NodoCola<T>(valor);
		contador++;
		if (final == nullptr) {
			frente = final = nuevo;
			return;
		}
		final->siguiente = nuevo;
		final = nuevo;
	}

	void dequeue() {
		if (frente == nullptr) return;
		NodoCola<T>* temp = frente;
		frente = frente->siguiente;
		if (frente == nullptr)
			final = nullptr;
		delete temp;
		contador--;
	}

	T front() {
		return frente ? frente->dato : nullptr;
	}

	bool isEmpty() {
		return frente == nullptr;
	}

	int size() {
		return contador;
	}

	void mostrar() {
		for (NodoCola<T>* actual = frente; actual != nullptr; actual = actual->siguiente)
			actual->dato->mostrar();
	}
};
