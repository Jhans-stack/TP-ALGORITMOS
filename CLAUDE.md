# TP-ALGORITMOS — Guia de estilo

Repositorio de ejercicios del curso de Estructuras de Datos Avanzadas. Todo
ejercicio nuevo que se pida en este repo debe seguir el mismo nivel y estilo
de codigo que ya se viene usando en clase (ver `Ejemplos/`). El objetivo es
que el codigo se vea como lo escribiria un alumno del curso, no como una
solucion "de libro" con tecnicas que todavia no se han visto.

## Estructura del repo

- `Ejemplos/Lista.h` — plantilla generica de lista enlazada (`Nodo<T>`,
  `ListaEnlazada<T>`) usada como base en varios ejercicios.
- `Ejemplos/EjercicioPedidos/` — ejercicio de gestion de pedidos (lista
  enlazada + menu).
- `Ejemplos/EjercicioPacientes/` — ejercicio de gestion de pacientes (lista
  enlazada de punteros a objetos + menu).
- `Ejemplos/RetoRecursividadYLambdas/` — reto de recursividad pura y de
  lambdas.

Cada ejercicio nuevo va en su propia carpeta dentro de `Ejemplos/` (o en la
raiz si el profesor pide un solo archivo), reutilizando `Lista.h` cuando
aplique en vez de duplicarla.

## Estilo general

- C++ estandar de consola (`#include <iostream>`, `<string>`, etc.),
  compilado como consola simple. **No** habilitar CLR/C++-CLI ni usar
  `using namespace System;` — eso es de C#/.NET, no de C++ puro, y no se usa
  en el curso aunque algun proyecto de Visual Studio lo traiga por defecto.
- `using namespace std;` al inicio del archivo.
- Nombres de variables y funciones en `camelCase` y en español
  (`monto`, `registrarPedido`, `calcularTotalYPromedio`). Clases en
  `PascalCase` (`Paciente`, `ListaEnlazada`, `Nodo`).
- Cada funcion resuelve una sola pregunta/opcion del menu. Nombres de
  funcion que digan claramente que hacen: `registrarX`, `calcularX`,
  `eliminarX`, `modificarX`, `mostrarX`.
- Un comentario de una linea encima de cada funcion "de pregunta",
  indicando que pregunta del enunciado resuelve. No comentar lo obvio
  dentro del cuerpo de la funcion.
- Programa dirigido por menu en `main()`: `do { ... } while (opcion != salir)`
  con un `switch` que llama a una funcion por opcion. Nada de logica de
  negocio dentro de `main()`.
- Validaciones con `if` simple (rango invalido, valor repetido, lista
  vacia) que imprime un mensaje y usa `continue`/`return` segun corresponda.
  No usar `try/catch` ni excepciones: no se ha visto en el curso.

## Listas y estructuras

- Usar la lista enlazada propia (`Nodo<T>` / `ListaEnlazada<T>`) en vez de
  `std::list`, `std::vector` u otros contenedores de la STL, salvo que el
  enunciado del ejercicio lo pida explicitamente.
- Recorridos manuales con `while (actual != nullptr) { ... actual =
  actual->siguiente; }`, tal como en `Ejemplos/EjercicioPedidos` y
  `Ejemplos/EjercicioPacientes`.
- Si la lista guarda punteros a objetos (`ListaEnlazada<Paciente*>`), liberar
  cada objeto con `delete` antes de destruir la lista (ver
  `liberarPacientes` en el ejemplo de pacientes).

## Recursividad (cuando el ejercicio lo pida)

Basado en `Ejemplos/RetoRecursividadYLambdas/DigitosImpares.cpp`:

- Caso base explicito al inicio de la funcion.
- Sin `while`/`for` dentro de una funcion recursiva: cada llamada
  recursiva reemplaza a una iteracion.
- Sin variables globales. Si hace falta acumular un resultado entre
  llamadas, pasarlo por referencia (`int& suma`).
- Si dos funciones tendrian la misma estructura (por ejemplo, una que
  suma y otra que cuenta lo mismo), unificarlas en una sola funcion.

## Lambdas (cuando el ejercicio lo pida)

Basado en `Ejemplos/RetoRecursividadYLambdas/DescuentoConLambdas.cpp`:

- Una lambda, una responsabilidad (no mezclar calculo + filtro + impresion
  en la misma lambda).
- Captura (`[]`) solo para valores que ya existen antes de la lambda y no
  cambian entre llamadas. Lo que cambia en cada llamada (por ejemplo
  `precio[i]` dentro de un `for`) va como parametro, no como captura.

## Memoria dinamica

- Todo `new` debe tener su `delete` y todo `new[]` su `delete[]` antes de
  terminar el programa (liberar en la propia funcion o en una funcion de
  limpieza llamada antes de salir, como en los ejemplos).

## Lo que NO usar (a menos que el profesor lo pida)

- Contenedores/algoritmos de la STL (`std::vector`, `std::sort`,
  `std::for_each`, etc.).
- Punteros inteligentes (`unique_ptr`, `shared_ptr`), `try/catch`,
  `structured bindings`, plantillas variadicas u otro C++ moderno que no
  aparezca ya en los ejemplos.
- `using namespace System;` / CLR support (ver arriba).

Cuando se pida un ejercicio nuevo: reusar `Ejemplos/Lista.h` si trabaja con
listas, seguir el mismo formato de menu + funciones + validaciones de los
ejemplos, y evitar cualquier tecnica que no aparezca en `Ejemplos/`.
