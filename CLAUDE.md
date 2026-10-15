# TP-ALGORITMOS — Guia de estilo

Repositorio de ejercicios del curso de Estructuras de Datos Avanzadas. Todo
ejercicio nuevo que se pida en este repo debe seguir el mismo nivel y estilo
de codigo que ya se viene usando en clase y en examenes (ver `Ejemplos/`).
El objetivo es que el codigo se vea como lo escribiria un alumno del curso,
no como una solucion "de libro" con tecnicas que todavia no se han visto.

Los ejercicios de examen (`Ejemplos/Ejercicio01...04`) son el nivel de
referencia mas reciente y mas completo: cuando haya diferencia de estilo
con los ejemplos de clase mas simples (`EjercicioPedidos`,
`EjercicioPacientes`, `RetoRecursividadYLambdas`), priorizar lo que hacen
los ejercicios de examen.

## Estructura del repo

- `Ejemplos/Lista.h` — plantilla generica de lista enlazada simple
  (`Nodo<T>`, `ListaEnlazada<T>`), usada como base en los ejemplos de clase
  (`EjercicioPedidos`, `EjercicioPacientes`).
- `Ejemplos/EjercicioPedidos/`, `Ejemplos/EjercicioPacientes/` — ejemplos de
  clase: lista enlazada simple + menu + validaciones.
- `Ejemplos/RetoRecursividadYLambdas/` — reto de recursividad pura y de
  lambdas basicas.
- `Ejemplos/Ejercicio01_SepararParesImpares/` — mismo problema resuelto con
  arreglo y con lista enlazada, usando recursion con parametros de salida
  por referencia.
- `Ejemplos/Ejercicio02_Biblioteca/` — lista enlazada + `Cola<T>` (FIFO) +
  datos generados aleatoriamente + funciones genericas con lambda
  (`contar_si`, `buscar_primero`) + ordenamiento por seleccion.
- `Ejemplos/Ejercicio03_TorneoCircular/` — `ListaCircular<T>` + `Pila<T>`
  (LIFO) + recursion sobre nodos + ordenamiento por insercion.
- `Ejemplos/Ejercicio04_ReproductorCanciones/` — `ListaDoble<T>` (con
  `anterior`/`siguiente`) + Fisher-Yates + Shell sort, todos con lambda
  como criterio.

Cada ejercicio nuevo va en su propia carpeta dentro de `Ejemplos/` (o en la
raiz si el profesor pide un solo archivo). Cada carpeta trae su propia
copia de la(s) estructura(s) que usa (`Lista.h`, `Cola.h`, `Pila.h`,
`ListaCircular.h`, `ListaDoble.h`, `Ordenamiento.h`) en vez de depender de
una sola copia global — asi se ve igual a como entregan los ejercicios de
examen.

## Estilo general

- C++ estandar de consola (`#include <iostream>`, `<string>`, etc.),
  compilado como consola simple. **No** habilitar CLR/C++-CLI ni usar
  `using namespace System;` — eso es de C#/.NET, no de C++ puro.
- `using namespace std;` al inicio del archivo.
- Nombres de variables y funciones en `camelCase` y en español
  (`monto`, `registrarPedido`, `calcularTotalYPromedio`). Clases en
  `PascalCase` (`Paciente`, `ListaEnlazada`, `Cola`, `Pila`).
- Cada funcion resuelve una sola pregunta/opcion del menu. Nombres de
  funcion que digan claramente que hacen: `registrarX`, `calcularX`,
  `eliminarX`, `modificarX`, `mostrarX`, `generarX`.
- Un comentario de una linea encima de cada funcion "de pregunta" o cuando
  el nombre no basta para explicar que resuelve. No comentar lo obvio
  dentro del cuerpo de la funcion.
- Programa dirigido por menu en `main()`: `do { ... } while (opcion != 0)`.
  Para el despacho de opciones, los ejercicios de examen usan una cadena de
  `if (opcion == 1) { ... } else if (opcion == 2) { ... }` en vez de
  `switch`; seguir ese formato salvo que el ejercicio sea muy simple (ahi
  `switch` tambien es valido, como en `EjercicioPedidos`). Nada de logica
  de negocio dentro de `main()`, solo el menu y el llamado a funciones.
- Validaciones con `if` simple (rango invalido, valor repetido, lista
  vacia) que imprime un mensaje y usa `continue`/`return` segun corresponda.
  No usar `try/catch` ni excepciones: no se ha visto en el curso.

## Clases de datos (registros)

Los ejercicios de examen usan clases simples con **atributos publicos**,
constructor y un metodo `mostrar()` — sin getters/setters privados (ver
`Lector.h`, `Participante.h`, `Cancion.h`):

```cpp
class Lector {
public:
    int codigo;
    int edad;
    char genero;
    string tipo;

    Lector(int codigo, int edad, char genero, string tipo) {
        this->codigo = codigo;
        this->edad = edad;
        this->genero = genero;
        this->tipo = tipo;
    }

    void mostrar() {
        cout << "Codigo: " << codigo << " | Edad: " << edad
             << " | Genero: " << genero << " | Tipo: " << tipo << endl;
    }
};
```

Usar este estilo (atributos publicos) por defecto para clases de datos
nuevas. El estilo anterior con `private` + getters (`Paciente.h`,
`Dispositivo.h`) tambien es valido si el enunciado pide explicitamente
encapsulamiento, pero ya no es la opcion por defecto.

## Generacion de datos (cuando el ejercicio no pide que el usuario los ingrese)

Cuando el enunciado dice "genera N elementos" en vez de "el usuario
ingresa N elementos", generar los datos con `rand()`(ver
`Ejercicio02_Biblioteca`, `Ejercicio03_TorneoCircular`,
`Ejercicio04_ReproductorCanciones`):

```cpp
srand((unsigned)time(nullptr));          // una sola vez, al inicio de main()

int n = 31 + rand() % 119;               // cantidad aleatoria dentro de un rango
bool usado[1001] = { false };            // para no repetir codigos/ids
for (int i = 0; i < n; i++) {
    int codigo;
    do { codigo = 1 + rand() % 1000; } while (usado[codigo]);
    usado[codigo] = true;
    // generar el resto de atributos con rand() y agregarlos a la lista
}
```

Requiere `#include <cstdlib>` y `#include <ctime>`. Si hay categorias fijas
(tipos, equipos, generos), asegurar que aparezcan todas al menos una vez
repartiendolas en las primeras posiciones y el resto al azar, tal como
`TIPOS[i]` / `EQUIPOS[i]` / `GENEROS[i]` en los ejemplos.

## Estructuras de datos disponibles

Cada una vive en su propio header, con su propio tipo de nodo (no se
reutiliza `Nodo<T>` entre estructuras distintas):

- `ListaEnlazada<T>` (`Nodo<T>`) — lista simple. Para recorridos e
  inserciones/eliminaciones generales.
- `Cola<T>` (`NodoCola<T>`) — FIFO (`enqueue`, `dequeue`, `front`,
  `isEmpty`). Para "atender en orden de llegada".
- `Pila<T>` (`NodoPila<T>`) — LIFO (`push`, `pop`, `top`, `isEmpty`). Para
  "deshacer" o procesar en orden inverso.
- `ListaCircular<T>` (`NodoCircular<T>`) — el ultimo nodo apunta al primero;
  recorrer con `do { ... } while (actual != cabeza)`. Para turnos/rondas.
- `ListaDoble<T>` (`Nodo<T>` con `anterior` y `siguiente`) — para recorrer
  en ambos sentidos (por ejemplo, un reproductor con siguiente/anterior).

El `Lista.h` base que trae el curso usa los nombres `insertarIncial` y
`mostar` (asi, tal cual, con esa ortografia) ademas de `insertarInicio` /
`insertarFinal` / `buscar` / `eliminar` / `eliminarPos` / `modificarPos`.
Si el ejercicio reutiliza ese `Lista.h` tal cual, respetar esos nombres
aunque tengan typos; si se escribe una estructura nueva desde cero, usar
los nombres bien escritos (`insertarInicio`, `mostrar`).

## Recursividad (cuando el ejercicio lo pida)

- Caso base explicito al inicio de la funcion.
- Sin `while`/`for` dentro de una funcion recursiva: cada llamada
  recursiva reemplaza a una iteracion.
- Sin variables globales. Si hace falta acumular un resultado entre
  llamadas, pasarlo por referencia (`int& suma`) o devolverlo como `return`.
- La recursion puede ser sobre un indice de arreglo (`separarArreglo`), un
  puntero a nodo (`sumaEdadesEquipo`, `contarGenero`), o ambos. Un
  parametro por defecto (`bool primera = true`) es valido para llevar
  estado extra entre llamadas sin agregarlo a la firma que usa el resto
  del programa (ver `sumaEdadesEquipo` en `Ejercicio03_TorneoCircular`).
- Si dos funciones tendrian la misma estructura (por ejemplo, una que
  suma y otra que cuenta lo mismo), unificarlas en una sola funcion.

## Lambdas y funciones genericas con criterio

- Una lambda, una responsabilidad (no mezclar calculo + filtro + impresion
  en la misma lambda).
- Captura (`[]`) solo para valores que ya existen antes de la lambda y no
  cambian entre llamadas (por ejemplo, un valor fijo buscado dentro de un
  mismo recorrido: `[&tipo](Lector* l) { return l->tipo == tipo; }`). Lo
  que cambia en cada llamada (por ejemplo `precio[i]` dentro de un `for`)
  va como parametro, no como captura.
- Las funciones que reciben una lambda la toman como parametro de template,
  sin fijar un tipo de funcion particular (ver `Ordenamiento.h` en los
  ejercicios 02-04):

```cpp
template <typename T, typename Criterio>
void seleccion(ListaEnlazada<T>& A, Criterio criterio) {
    // usa criterio(a, b) para comparar
}
```

  Este patron se usa para contar/filtrar (`contar_si`, `buscar_primero`) y
  para ordenar (`seleccion`, `insercion`, `shellSort`), pasandoles una
  lambda comparadora en el `main()`. No es "C++ moderno raro": es el mismo
  concepto de generalizacion con templates visto en clase, aplicado a una
  funcion en vez de a una clase.

## Ordenamiento

Los ejercicios de examen no usan `std::sort`: implementan el ordenamiento
a mano sobre la propia estructura, intercambiando `->dato` entre nodos (sin
tocar los punteros `siguiente`/`anterior`), parametrizado con una lambda
criterio. Algoritmos ya usados: seleccion, insercion (sobre lista
circular) y Shell sort (con una funcion auxiliar `nodoEn(lista, pos)` para
acceder por posicion). Usar el mismo enfoque para ejercicios nuevos de
ordenamiento en vez de copiar los datos a un arreglo aparte.

## Memoria dinamica

- Todo `new` debe tener su `delete` y todo `new[]` su `delete[]` antes de
  terminar el programa (liberar en la propia funcion o en una funcion/bucle
  de limpieza antes de salir, como en los ejemplos).
- Las estructuras (`Cola`, `Pila`, listas) liberan sus propios nodos en el
  destructor, pero no los objetos a los que apuntan sus `dato` si guardan
  punteros (`Lector*`, `Participante*`, `Cancion*`): esos se liberan aparte,
  normalmente en un bucle al final de `main()`.

## Lo que NO usar (a menos que el profesor lo pida)

- Contenedores/algoritmos de la STL (`std::vector`, `std::sort`,
  `std::for_each`, `std::list`, etc.) y `std::function`.
- Punteros inteligentes (`unique_ptr`, `shared_ptr`), `try/catch`,
  `structured bindings`, u otro C++ moderno que no aparezca ya en los
  ejemplos. (Los templates propios con un parametro de tipo, incluyendo uno
  para una lambda como `Criterio`, si estan permitidos: ver mas arriba.)
- `using namespace System;` / CLR support.

Cuando se pida un ejercicio nuevo: elegir la estructura de `Ejemplos/` que
mejor calce con el enunciado (lista simple, cola, pila, circular o doble),
copiar su header a la carpeta del ejercicio nuevo, seguir el mismo formato
de menu + funciones + validaciones, y evitar cualquier tecnica que no
aparezca en `Ejemplos/`.
