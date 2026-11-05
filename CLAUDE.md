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

`Ejemplos/Laboratorio01_MergeSortQuickSort/` es material oficial del
profesor (laboratorio de la Semana 09, con guia paso a paso de Visual
Studio incluida), asi que para el tema de ordenamiento avanzado (Merge
Sort / Quick Sort) tiene prioridad sobre cualquier otro ejemplo. Lo mismo
aplica a `Ejemplos/Ejercicio01_BusquedaBinaria/` y
`Ejemplos/Ejercicio02_ArbolMultiplos3/` (mismo profesor, mismo tipo de
guia paso a paso) para busqueda binaria y arboles binarios.

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
- `Ejemplos/Laboratorio01_MergeSortQuickSort/` — ordenar objetos
  (`Paciente`) con Merge Sort y QuickSort sobre `vector<Paciente*>`,
  validando el resultado con `estaOrdenado`.
- `Ejemplos/Ejercicio01_BusquedaBinaria/` — busqueda binaria iterativa
  (`busquedaBinariaMejor`) sobre `vector<int>` para encontrar la primera
  posicion que cumple una condicion (umbral), con una variable `int`
  global como valor centinela (`noEncontrado`).
- `Ejemplos/Ejercicio02_ArbolMultiplos3/` — arbol binario de busqueda
  (`struct Nodo` + `class Arbol`) que solo inserta valores que cumplen una
  condicion, con recorrido `enOrden`, conteo de nodos y calculo de altura.

Cada ejercicio nuevo va en su propia carpeta dentro de `Ejemplos/` (o en la
raiz si el profesor pide un solo archivo). Cada carpeta trae su propia
copia de la(s) estructura(s) que usa (`Lista.h`, `Cola.h`, `Pila.h`,
`ListaCircular.h`, `ListaDoble.h`, `Ordenamiento.h`) en vez de depender de
una sola copia global — asi se ve igual a como entregan los ejercicios de
examen.

## Estilo general

- C++ estandar de consola (`#include <iostream>`, `<string>`, etc.). El
  proyecto de Visual Studio SI se crea como "Aplicacion de consola CLR
  (.NET Framework)" (`CLRSupport=true` en el `.vcxproj`) porque es la
  plantilla que piden las guias del profesor — eso es una opcion de
  compilacion del proyecto, no algo que se escriba en el codigo. El
  **codigo fuente** nunca usa `using namespace System;` ni tipos/sintaxis
  de C++/CLI (`String^`, `gcnew`, etc.): sigue siendo C++ puro.
- `using namespace std;` al inicio del archivo.
- Nombres de variables y funciones en `camelCase` y en español
  (`monto`, `registrarPedido`, `calcularTotalYPromedio`). Clases en
  `PascalCase` (`Paciente`, `ListaEnlazada`, `Cola`, `Pila`).
- Cada funcion resuelve una sola pregunta/opcion del menu. Nombres de
  funcion que digan claramente que hacen: `registrarX`, `calcularX`,
  `eliminarX`, `modificarX`, `mostrarX`, `generarX`.
- Sin comentarios explicativos (nada de "esto hace X" encima de cada
  funcion). Solo comentarios cortos tipo etiqueta para separar bloques o
  algoritmos importantes dentro del archivo, como en
  `Laboratorio01_MergeSortQuickSort/OrdenamientoSemana09.cpp`:

  ```cpp
  // MERGE SORT
  void fusionar(...) { ... }
  void ordenarPorMezcla(...) { ... }

  // QUICKSORT
  void intercambiar(...) { ... }
  void particionar(...) { ... }

  // MENU
  int main() { ... }
  ```
- Programa dirigido por menu en `main()`: `do { ... } while (opcion != 0)`.
  Para el despacho de opciones, los ejercicios de examen usan una cadena de
  `if (opcion == 1) { ... } else if (opcion == 2) { ... }` en vez de
  `switch`; seguir ese formato salvo que el ejercicio sea muy simple (ahi
  `switch` tambien es valido, como en `EjercicioPedidos`). Nada de logica
  de negocio dentro de `main()`, solo el menu y el llamado a funciones.
- Validaciones con `if` simple (rango invalido, valor repetido, lista
  vacia) que imprime un mensaje y usa `continue`/`return` segun corresponda.
  No usar `try/catch` ni excepciones: no se ha visto en el curso.
- Al leer la opcion del menu con `cin >> opcion`, recuperar el stream si
  fallo (texto donde se esperaba un numero) en vez de dejar que el `cin`
  quede trabado — confirmado como patron oficial en
  `Laboratorio01_MergeSortQuickSort`:

  ```cpp
  cin >> opcion;
  if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      opcion = -1;
  }
  ```

## Proyecto de Visual Studio

Plantilla: "Aplicacion de consola CLR (.NET Framework)". La mayoria de
las guias del profesor (`Ejercicio1_GestionPacientes`,
`Ejercicio01_BusquedaBinaria`, `Ejercicio02_ArbolMultiplos3`) usan el
scaffold completo que genera Visual Studio por defecto con esa plantilla:
`pch.h` + `pch.cpp` (encabezado precompilado), `AssemblyInfo.cpp`,
`Resource.h`, `app.rc`, `app.ico`, y el `.cpp` principal **empieza con
`#include "pch.h"`** (esa primera linea no se borra; todo lo demas del
archivo si se reemplaza). Solo `Laboratorio01_MergeSortQuickSort` usa un
proyecto simplificado sin precompilado (`PrecompiledHeader=NotUsing`, sin
`pch.h`) — es la excepcion, no la regla. Por defecto, para un ejercicio
nuevo armar el proyecto completo con `pch.h` como primera linea del
`.cpp`, salvo que el ejercicio sea claramente de la familia de
Merge/Quick Sort.

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

Ese estilo (atributos publicos) aparecio en los ejercicios de examen
02-04, pero tanto el material oficial del profesor
(`Laboratorio01_MergeSortQuickSort/Paciente.h`) como el zip de clase
original (`Ejercicio1_GestionPacientes`) y lo pedido en el parcial usan
`private` + getters/setters `public`. Como el profesor SI valora el
ambito (`private`/`public`) como criterio de nota, usar **`private` +
getters por defecto** para clases de datos nuevas, y reservar los
atributos publicos solo si el propio ejercicio los trae asi (por ejemplo,
al reutilizar `Lector.h`/`Participante.h`/`Cancion.h` tal cual). Dentro de
la clase, los metodos pueden seguir usando los atributos directo (son
miembros de la misma clase); el resto del programa (otras funciones,
`main`) debe pasar siempre por los getters, nunca acceder al atributo
directamente.

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
reutiliza `Nodo<T>` entre estructuras distintas). El `Nodo<T>` (o
`NodoCola<T>`, `NodoPila<T>`, `NodoCircular<T>`) va **en el mismo archivo**
que su clase contenedora, no en un header aparte — asi lo hacen los 5
headers de estructura que trae el curso (`Lista.h`, `Cola.h`, `Pila.h`,
`ListaCircular.h`, `ListaDoble.h`: cada uno define primero el `Nodo`
correspondiente y despues la clase que lo usa, en el mismo archivo). Esto
es distinto de las clases de datos (`Alumno`, `Lector`, `Paciente`, etc.),
que si van cada una en su propio `.h` porque son independientes de la
estructura que las contiene.

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
- `Arbol` (`struct Nodo` con `izq`/`der`) — ver "Arbol binario" mas abajo.
  A diferencia de las listas, el `Nodo` de arbol es un `struct` (no
  `class`) y no esta templado (`int valor`, no `T`). No es un arbol
  binario de busqueda: `insertar` es iterativo (por niveles, con una
  `Cola<T>`); los recorridos, contar y altura son recursivos.

El `Lista.h` base que trae el curso usa los nombres `insertarIncial` y
`mostar` (asi, tal cual, con esa ortografia) ademas de `insertarInicio` /
`insertarFinal` / `buscar` / `eliminar` / `eliminarPos` / `modificarPos`.
Si el ejercicio reutiliza ese `Lista.h` tal cual, respetar esos nombres
aunque tengan typos; si se escribe una estructura nueva desde cero, usar
los nombres bien escritos (`insertarInicio`, `mostrar`).

## Arbol binario

**No es un arbol binario de busqueda.** Por defecto, insertar NO compara
valores para decidir izquierda/derecha — eso seria un BST. La regla del
curso es la generica de "arbol binario": el nodo nuevo se coloca en el
**primer lugar libre, de arriba hacia abajo y de izquierda a derecha**
(recorriendo por niveles con una cola hasta encontrar el primer hijo
vacio). El nodo es un `struct` simple con campos publicos (no una `class`
con getters, como los `Nodo` de las listas):

```cpp
struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
    Nodo(int v) : valor(v), izq(nullptr), der(nullptr) {}
};
```

La clase `Arbol` guarda `Nodo* raiz` como atributo `private`. Insertar es
iterativo (recorrido por niveles, reutilizando la `Cola<T>` propia del
curso — nunca `std::queue`); el resto de operaciones (recorridos, contar,
altura, liberar) son recursivas: un metodo **privado** que recibe un
`Nodo*` como parametro hace el trabajo real, y un metodo **publico** sin
parametros llama al privado pasando `raiz`:

```cpp
class Arbol {
private:
    Nodo* raiz;

    void enOrdenNodo(Nodo* nodo) {
        if (nodo == nullptr) return;
        enOrdenNodo(nodo->izq);
        cout << nodo->valor << " ";
        enOrdenNodo(nodo->der);
    }

    int contarNodos(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        return 1 + contarNodos(nodo->izq) + contarNodos(nodo->der);
    }

    int alturaNodo(Nodo* nodo) {
        if (nodo == nullptr) return 0;
        int alturaIzq = alturaNodo(nodo->izq);
        int alturaDer = alturaNodo(nodo->der);
        return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
    }

    void liberarNodo(Nodo* nodo) {
        if (nodo == nullptr) return;
        liberarNodo(nodo->izq);
        liberarNodo(nodo->der);
        delete nodo;
    }

public:
    Arbol() : raiz(nullptr) {}
    ~Arbol() { liberarNodo(raiz); }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (raiz == nullptr) { raiz = nuevo; return; }

        Cola<Nodo*> cola;
        cola.enqueue(raiz);
        while (!cola.isEmpty()) {
            Nodo* actual = cola.front();
            cola.dequeue();

            if (actual->izq == nullptr) { actual->izq = nuevo; return; }
            cola.enqueue(actual->izq);

            if (actual->der == nullptr) { actual->der = nuevo; return; }
            cola.enqueue(actual->der);
        }
    }

    void enOrden() { enOrdenNodo(raiz); cout << endl; }
    int cantidad() { return contarNodos(raiz); }
    int altura()   { return alturaNodo(raiz); }
};
```

- Caso base siempre `if (nodo == nullptr) return ...;` en los metodos
  recursivos — nada de verificar null antes de llamar, se verifica al
  entrar a la funcion.
- Como no es BST, ningun recorrido sale ordenado por valor: **preorden**
  (nodo, izquierda, derecha), **inorden/enOrden** (izquierda, nodo,
  derecha), **postorden** (izquierda, derecha, nodo) y **por niveles**
  (con una `Cola<T>`, igual que `insertar`) solo definen el *orden de
  visita*, no un orden de valores. Usar el que pida el enunciado.
- Si el ejercicio pide filtrar que se inserte (por ejemplo, "solo
  multiplos de 3"), ese filtro va en el metodo publico `insertar`, antes
  de crear el `Nodo` nuevo.
- `liberarNodo` + destructor liberan todo el arbol recursivamente, mismo
  patron que las listas pero recorriendo ambos hijos primero.

`Ejemplos/Ejercicio02_ArbolMultiplos3` es la excepcion: inserta
comparando valores (estilo BST) porque su enunciado pedia explicitamente
mostrar las edades ordenadas con `enOrden`, algo que solo un BST
garantiza. No copiar ese `insertarNodo` como plantilla general — usar la
insercion por niveles de arriba salvo que el enunciado necesite de verdad
un recorrido ordenado.

## Recursividad (cuando el ejercicio lo pida)

- Caso base explicito al inicio de la funcion.
- Sin `while`/`for` dentro de una funcion recursiva: cada llamada
  recursiva reemplaza a una iteracion.
- Sin variables globales **dentro de la funcion recursiva en si**: si hace
  falta acumular un resultado entre llamadas, pasarlo por referencia
  (`int& suma`) o devolverlo como `return`. Una variable global simple
  fuera de cualquier funcion (por ejemplo un centinela `int noEncontrado
  = -1;` que no cambia nunca, como en `Ejercicio01_BusquedaBinaria`) si es
  valida: no es un acumulador ni genera efectos secundarios entre
  llamadas, es solo un valor constante con nombre.
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

## Busqueda binaria

Basado en `Ejemplos/Ejercicio01_BusquedaBinaria`. Es **iterativa**
(`while`), no recursiva — a diferencia del resto del curso, aqui si se
usa un bucle porque no se pidio recursividad. Patron con `inicio`/`fin`/
`medio` y un acumulador `resultado` para quedarse con la ultima posicion
valida encontrada (util cuando se busca "la primera que cumple una
condicion", no un valor exacto):

```cpp
int noEncontrado = -1;

int busquedaBinariaMejor(vector<int>& datos, int umbral) {
    int inicio = 0;
    int fin = (int)datos.size() - 1;
    int resultado = noEncontrado;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (datos[medio] >= umbral) {
            resultado = medio;
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }
    return resultado;
}
```

- El vector debe estar ordenado (lo pide el enunciado, no se valida en
  codigo).
- `resultado` se actualiza cada vez que `medio` cumple la condicion, pero
  la busqueda sigue achicando el rango hacia el lado donde podria haber
  una respuesta *mejor* (aqui, mas a la izquierda) en vez de cortar de
  una — por eso no hace `return medio;` apenas encuentra una coincidencia.
- Comparar contra el centinela (`if (posicion == noEncontrado)`) en vez de
  contra `-1` directo en el `main`, para que el significado quede claro.

## Ordenamiento

Ningun ejercicio usa `std::sort`: siempre se implementa el algoritmo a
mano. Sobre las estructuras propias (lista, lista circular, lista doble)
se intercambia `->dato` entre nodos (sin tocar los punteros
`siguiente`/`anterior`), parametrizado con una lambda criterio. Algoritmos
ya usados asi: seleccion, insercion (sobre lista circular) y Shell sort
(con una funcion auxiliar `nodoEn(lista, pos)` para acceder por posicion).
Usar el mismo enfoque para ejercicios nuevos de ordenamiento simple en vez
de copiar los datos a un arreglo aparte.

### Merge Sort y Quick Sort

Para estos dos (ver `Ejemplos/Laboratorio01_MergeSortQuickSort`), la
estructura cambia porque ambos necesitan acceso por indice (`lista[i]`) y
dividir el rango en mitades, algo que una lista enlazada simple no da de
forma eficiente. Por eso aqui si se usa `vector<Paciente*>` en vez de
`ListaEnlazada<Paciente*>` — es la unica excepcion reconocida a "no usar
contenedores de la STL", y solo para este par de algoritmos.

- **Merge Sort**: `ordenarPorMezcla(lista, izq, der)` — caso base
  `izq >= der`, calcula `med`, ordena cada mitad por recursion y llama a
  `fusionar`. `fusionar(lista, izq, med, der)` copia las dos mitades a
  vectores auxiliares `izquierda`/`derecha` y las vuelve a escribir en
  `lista` tomando siempre el menor de los dos primeros.
- **Quick Sort**: `ordenarRapido(lista, inicio, fin)` — si
  `inicio < fin`, llama a `particionar` y se repite a cada lado del
  pivote. `particionar(lista, inicio, fin)` usa el **ultimo elemento**
  como pivote, compara cada elemento solo contra el pivote, y mueve los
  menores o iguales a la izquierda con `intercambiar` (swap manual con una
  variable `temporal`); al final coloca el pivote en su posicion y la
  devuelve.
- **Validar el resultado**: una funcion `estaOrdenado(lista)` que recorre
  comparando `lista[i-1]` con `lista[i]` y devuelve `false` en el primer
  par fuera de orden — mostrar el resultado de la validacion despues de
  ordenar, no asumir que salio bien.
- Liberar memoria igual que siempre: un `liberarPacientes(lista)` que
  recorre y hace `delete` a cada puntero antes de `lista.clear()`.

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
  `std::for_each`, `std::list`, etc.) y `std::function`. La unica
  excepcion es `std::vector<T*>` para Merge Sort / Quick Sort (ver
  "Ordenamiento" mas arriba) — y aun ahi, `std::sort` sigue sin usarse:
  el algoritmo se escribe a mano.
- Punteros inteligentes (`unique_ptr`, `shared_ptr`), `try/catch`,
  `structured bindings`, u otro C++ moderno que no aparezca ya en los
  ejemplos. (Los templates propios con un parametro de tipo, incluyendo uno
  para una lambda como `Criterio`, si estan permitidos: ver mas arriba.)
- `using namespace System;` ni ningun tipo/sintaxis de C++/CLI en el
  codigo (`String^`, `gcnew`, etc.) — aunque el proyecto en si tenga
  `CLRSupport=true`, ver "Estilo general".

Cuando se pida un ejercicio nuevo: elegir la estructura de `Ejemplos/` que
mejor calce con el enunciado (lista simple, cola, pila, circular o doble),
copiar su header a la carpeta del ejercicio nuevo, seguir el mismo formato
de menu + funciones + validaciones, y evitar cualquier tecnica que no
aparezca en `Ejemplos/`.
