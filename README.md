# Proyecto_Playlist_C-

Es un programa en C++ que permite crear y administrar una playlist de canciones.
El usuario puede agregar canciones con su información (título, artista, duración y género), mostrar la lista, eliminar canciones y ordenar por título.
Adicionalmente, el sistema permite gestionar una cola de reproducción (Queue) separada y carga y guarda la lista de canciones desde un archivo de texto "canciones.txt".

Se utiliza programación orientada a objetos con clases (Cancion y Playlist), un arreglo dinámico (vector) para la lista principal, y una estructura de datos de Queue implementada para la cola de reproducción.

---

## Descripción del avance 1

Este avance contiene la base del programa:

* Clase "Cancion" para almacenar información de cada canción.
* Clase "Playlist" que gestiona un vector de canciones.

### Funcionalidades implementadas:

* Agregar canciones al vector.
* Mostrar la lista de canciones numeradas.
* Eliminar canciones por índice.
* Ordenar canciones alfabéticamente por título usando Bubble Sort.
* Menú interactivo en consola para seleccionar las acciones.

---

## Descripción del avance 2

En este avance, se implementó y se integró una estructura de datos Queue para gestionar una cola de reproducción.

### Nuevas Clases/Estructuras:

* **Clase "QueuePlaylist"**: Se desarrolló una clase plantilla (template) en "queuePlaylist.h". Utiliza funciones como: "enqueue" y "dequeue", junto con punteros para una gestión eficiente de las operaciones de la cola.

### Funcionalidades implementadas:

* **Integración en "Playlist"**: La clase "Playlist" ahora contiene  "QueuePlaylist<Cancion> colaReproduccion" para manejar la cola de reproducción.
* **Agregar a la cola (Opción 5)**: Permite al usuario tomar una canción del vector principal (por su índice) y agregarla al final de la cola (enqueue).
* **Mostrar cola (Opción 6)**: Muestra el contenido actual de la cola sin modificarla.
* **Reproducir siguiente (Opción 7)**: Muestra la canción al frente de la cola (getFront) y luego la elimina (dequeue).

---

## Descripción del avance 3

Este avance implementa la permanencia de datos, permitiendo que la playlist se cargue desde y se guarde en un archivo de texto.

### Funcionalidades implementadas:

* **Carga de archivo (cargarDesdeArchivo)**: Al iniciar el programa, se leen las canciones del archivo "canciones.txt". La función usa "ifstream" y "stringstream" para recorrer cada línea  y agregar las canciones al vector principal.
* **Guardado de archivo (guardarEnArchivo)**: Después de agregar o eliminar una canción, el programa sobrescribe "canciones.txt" con el contenido actual del vector. Utiliza "ofstream".
* **Permanencia automática**: Los cambios en la lista principal (adiciones y eliminaciones) se guardan de forma inmediata en el archivo, asegurando que la playlist se conserve entre sesiones de uso del código.

---

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:   
g++ .\main.cpp .\playlist.cpp .\cancion.cpp -o playlist

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:
.\playlist.exe

---

## Descripción de las entradas del avance de proyecto

El programa recibe entradas de dos fuentes:

1.  **Archivo ¨canciones.txt¨**:
    * Al iniciar, el programa lee este archivo para cargar la playlist.
    * El formato debe ser (titulo,artista,duracion(s),genero) por cada línea.
    * Ejemplo: "Enter Sandman,Metallica,300,Rock"

2.  **Usuario (Consola)**:
    * El programa recibe entradas del usuario a través de la consola por medio de un menú interactivo.

### Para agregar una canción (Opción 1), se solicita:

* Título (string, puede contener espacios)
* Artista (string, puede contener espacios)
* Duración (int, en segundos)
* Género (string, puede contener espacios)

### Ejemplo de entrada para una canción:

Título: Beat It
Artista: Michael Jackson
Duración (segundos): 215
Género: Rock

---

## Descripción de las salidas del avance de proyecto

El programa muestra mensajes en consola confirmando las acciones.

### Salidas principales:

* **Mensaje de carga**: "Canciones base cargadas desde canciones.txt."
* **Canción agregada**: "Cancion agregada." (Esto también activa un guardado en archivo).
* **Lista de canciones (Opción 2)**: numerada y mostrando todos los datos de cada canción.
* **Canción eliminada**: "Cancion eliminada." (Esto también activa un guardado en archivo).
* **Playlist ordenada**: "Playlist ordenada por titulo." (Esto también activa un guardado en archivo).
* **Cola de reproducción (Opción 6)**: Muestra un listado de las canciones en la cola.
* **Reproducir siguiente (Opción 7)**: "Reproduciendo: (Título - Artista - Duración(s) - Género)"

### Ejemplo de salida al mostrar playlist (Opción 2):

1. Título: You give love a bad name - Artista: Bon Jovi (180 seg, Rock)
2. Título: Summer of 69 - Artista: Bryan Adams (125 seg, Rock)

---
## Análisis de Complejidad

n = número de canciones en el vector principal
k = número de canciones en la Queue
m = número de líneas/canciones en el archivo

### Clase Cancion
* "Cancion" (Constructor) - **O(1)**
* "getTitulo" - **O(1)**
* "getArtista" - **O(1)**
* "getDuracion" - **O(1)**
* "getGenero" - **O(1)**
* "mostrar" - **O(1)**
* "operador << " - **O(1)**

### Clase QueuePlaylist
* "QueuePlaylist" (Constructor) - **O(1)**
* "~QueuePlaylist" (Destructor) - **O(k)**
* "empty" - **O(1)**
* "enqueue" - **O(1)**
* "dequeue" - **O(1)**
* "getFront" - **O(1)**
* "toString" - **O(k)**

### Clase Playlist
* "agregarCancion" - **O(1)** 
* "mostrarPlaylist" - **O(n)**
* "ordenarPorTitulo" - **O(n²)** (Bubble Sort)
* "eliminarCancion" - **O(n)**
* "agregarACola" - **O(1)**
* "mostrarCola" - **O(k)**
* "reproducirSiguiente" - **O(1)**
* "cargarDesdeArchivo" - **O(m)**
* "guardarEnArchivo" - **O(n)**

### main.cpp (Operaciones del Menú)
* **Inicio (Carga)** - **O(m)** (Llama a "cargarDesdeArchivo")
* **Opción 1: Agregar canción** - **O(n)** (Incluye "guardarEnArchivo")
* **Opción 2: Mostrar playlist** - **O(n)** (Llama a "mostrarPlaylist")
* **Opción 3: Ordenar por título** - **O(n²)** (Llama a "ordenarPorTitulo"(Bubble Sort))
* **Opción 4: Eliminar canción** - **O(n)** (Incluye "eliminarCancion" y "guardarEnArchivo")
* **Opción 5: Agregar a cola** - **O(1)** (Llama a "agregarACola")
* **Opción 6: Mostrar cola** - **O(k)** (Llama a "mostrarCola")
* **Opción 7: Reproducir siguiente** - **O(1)** (Llama a "reproducirSiguiente")
---

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

**Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.**

Se ha realizado un análisis de complejidad O(n²) para el algoritmo de ordenamiento **Bubble Sort** implementado, como se detalla en la sección "Análisis de Complejidad".

**Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.**

Se ha realizado un análisis detallado de la complejidad temporal para todas las estructuras de datos (Vector, Queue), sus métodos, y las operaciones del menú (incluyendo el manejo de archivos). Este análisis completo se encuentra en la sección "Análisis de Complejidad".

### SICT0302: Toma decisiones

**Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.**

* (Avance 1) Se decidió usar **Bubble Sort** para la funcionalidad de ordenamiento del proyecto. La elección se observa en el método "ordenarPorTitulo()" de la clase "Playlist".

**Selecciona una estructura de datos adecuada al problema y la usa correctamente.**

* (Avance 1) Se selecciona un **Vector** de canciones como estructura de datos principal. Es adecuada por su manejo dinámico, facilidad de recorrido y acceso por índice.
* (Avance 2) Se seleccionó una **Cola (Queue)**. Esta es la estructura de datos óptima para el requisito de "cola de reproducción", y su implementación garantiza operaciones de "enqueue" y "dequeue" en tiempo constante **O(1)**.

### SICT0303: Implementa acciones científicas

**Implementa mecanismos para consultar información de las estructuras correctos.**

* **Vector**: Se consulta con un bucle "for" e índices para "mostrarPlaylist" y se usa acceso directo "canciones[indice - 1]" en "agregarACola".
* **Cola**: Se consulta el frente con "getFront()" para "reproducirSiguiente" y se recorre de forma segura con el método "toString()" para "mostrarCola", sin modificar la estructura.

**Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.**

* (Avance 3) La función "cargarDesdeArchivo" implementa un mecanismo para la lectura de archivos:
    1.  Verifica si el archivo se abrió correctamente (is_open).
    2.  Lee el archivo línea por línea usando "getline".
    3.  Utiliza "stringstream" para leer cada línea individualmente.
    4.  Extrae cada campo usando "getline(ss, campo, ',')".
    5.  Convierte los tipos de datos (string a int) de forma segura.
    6.  Carga los datos en el "std::vector" usando "push_back".
