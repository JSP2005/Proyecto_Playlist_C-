# Proyecto_Playlist_C-

Es un programa en C++ que permite crear y administrar una playlist de canciones.  
El usuario puede agregar canciones con su información (título, artista, duración y género), mostrar la lista, eliminar canciones y ordenar por título.  
Se utiliza programación orientada a objetos con clases (Cancion y Playlist) y arreglos dinámicos (vector).  

## Descripción del avance 1

### Este avance contiene la base del programa:

Clase Cancion para almacenar información de cada canción.  
Clase Playlist que gestiona un vector de canciones.

### Funcionalidades implementadas:

Agregar canciones al vector.  
Mostrar la lista de canciones numeradas.  
Eliminar canciones por índice.  
Ordenar canciones alfabéticamente por título usando Bubble Sort.  
Menú interactivo en consola para seleccionar las acciones.  

## Instrucciones para compilar el avance de proyecto

Ejecuta el siguiente comando en la terminal:  
g++ .\main.cpp .\playlist.cpp .\cancion.cpp -o playlist  

## Instrucciones para ejecutar el avance de proyecto

Ejecuta el siguiente comando en la terminal:  
.\playlist.exe  

## Descripción de las entradas del avance de proyecto

El programa recibe entradas del usuario a través de la consola por medio de un menú interactivo  

### Para agregar una canción, se solicita:

Título (string, puede contener espacios)  
Artista (string, puede contener espacios)  
Duración (int, en segundos)  
Género (string, puede contener espacios)  

### Ejemplo de entrada para una canción:

Título: Beat It  
Artista: Michael Jackson  
Duración (segundos): 215  
Género: Rock  

## Descripción de las salidas del avance de proyecto

### El programa muestra mensajes en consola confirmando las acciones, por ejemplo:

Canción agregada: "Canción agregada correctamente."  
Lista de canciones: numerada y mostrando todos los datos de cada canción.  
Canción eliminada: "Canción eliminada correctamente."  
Playlist ordenada: "Playlist ordenada por título."  

### Ejemplo de salida al mostrar playlist:

1. Título: You give love a bad name  
   Artista: Bon Jovi  
   Duración: 183 seg  
   Género: Rock  

2. Título: Summer of 69  
   Artista: Bryan Adams  
   Duración: 125 seg  
   Género: Rock  

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.  

En este proyecto se implementó Bubble Sort para ordenar las canciones por título.  
Se analiza la eficiencia considerando que es un algoritmo de complejidad O(n²) en el peor caso.  
Esto demuestra comprensión de la complejidad de los algoritmos y cómo afecta el desempeño del programa.  

### SICT0302: Toma decisiones
Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.  

Se decidió usar Bubble Sort por su facilidad de implementación con vectores y para efectos educativos del proyecto.  
La elección del algoritmo se observa en el método ordenarPorTitulo() de la clase Playlist.  
Además, se selecciona un vector de canciones como estructura de datos adecuada, por su manejo dinámico y facilidad de ordenamiento.  
