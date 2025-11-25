/*
* playlist.cpp
* Jose Suberbie Pons
* A01713050
*/

#include "playlist.h"
#include "cancion.h"
#include <fstream>
#include <sstream>
#include <cstdlib> // Libreria para mandar comandos al sistema operativo (implementacion extra)

// Implementacion de metodos de clase Playlist

void Playlist::agregarCancion(Cancion& cancion) {
    canciones.push_back(cancion);
    cout << "Cancion agregada.\n";
}

void Playlist::mostrarPlaylist() {
    cout << "\n=== Playlist ===\n";
    if (canciones.empty()) {
        cout << "La playlist esta vacia.\n";
    } 
	else {
        for (int i = 0; i < canciones.size(); i++) {
            cout << i + 1 << ". ";
            canciones[i].mostrar();
            cout << "\n";
        }
    }
    cout << "================\n";
}

// Implementacion de metodos de ordenamiento (Merge Sort)

void Playlist::ordenarPorTitulo() {
    if (canciones.empty()) {
        cout << "La playlist esta vacia, no hay nada que ordenar.\n";
        return;
    }
    
    mergeSort(0, canciones.size() - 1);

    cout << "\nPlaylist ordenada por titulo (usando Merge Sort).\n";
}

void Playlist::mergeSort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }
}

void Playlist::merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<Cancion> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = canciones[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = canciones[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].getTitulo() <= R[j].getTitulo()) {
            canciones[k] = L[i];
            i++;
        } else {
            canciones[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        canciones[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        canciones[k] = R[j];
        j++;
        k++;
    }
}

void Playlist::eliminarCancion(int indice) {
    if (canciones.empty()) {
        cout << "La playlist esta vacia.\n";
        return;
    }
    if (indice < 1 || indice > canciones.size()) {
        cout << "Indice invalido.\n";
        return;
    }
    canciones.erase(canciones.begin() + (indice - 1));
    cout << "Cancion eliminada.\n";
}

// Implementacion de metodos para Queue

void Playlist::agregarACola(int indice) {
    if (indice < 1 || indice > canciones.size()) {
        cout << "Indice invalido.\n";
        return;
    }
    colaReproduccion.enqueue(canciones[indice - 1]);
    cout << "Cancion agregada a la cola de reproduccion.\n";
}

void Playlist::mostrarCola() {
    cout << "\n--- Cola de Reproduccion ---\n";
    cout << colaReproduccion.toString() << endl;
}

void Playlist::reproducirSiguiente() {
    if (colaReproduccion.empty()) {
        cout << "No hay canciones en la cola de reproduccion.\n";
        return;
    }

    Cancion actual = colaReproduccion.getFront();
    cout << "\nReproduciendo ahora: " << actual.getTitulo()
         << " - " << actual.getArtista() << endl;

    // Implementacion extra (usando IA) para abrir youtube en la cancion que se reproduce en la cola
  
        // 1. Concatenamos Título y Artista para la búsqueda
        string busqueda = actual.getTitulo() + " " + actual.getArtista();
        
        // 2. Reemplazamos los espacios por '+' para que sea una URL válida
        for (int i = 0; i < busqueda.length(); i++) {
            if (busqueda[i] == ' ') {
                busqueda[i] = '+';
            }
        }

        // 3. Preparamos el comando según el sistema operativo
        string url = "https://www.youtube.com/results?search_query=" + busqueda;
        string comando = "start " + url; 
        
        // 4. Ejecutamos el comando (convirtiendo string a const char*)
        system(comando.c_str());
         
    colaReproduccion.dequeue();
}

// Implementacion de metodos para manejo de archivos

void Playlist::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); // Abre el archivo en modo lectura

    // Verifica si el archivo se abrio correctamente
    if (!archivo.is_open()) {
        cout << "No se encontro el archivo base (" << nombreArchivo << ").\n";
        return; 
    }

    canciones.clear(); // Limpia el vector actual antes de cargar nuevas canciones

    string linea; // Guarda cada linea leida del archivo
    // Lee el archivo linea por linea
    while (getline(archivo, linea)) {
        stringstream ss(linea); // Convierte la linea en un flujo de texto
        // Variables para almacenar los datos de la cancion
        string titulo;
        string artista;
        string genero;
        int duracion;

        // Extrae el titulo hasta la primera coma
        getline(ss, titulo, ',');
        // Extrae el artista hasta la siguiente coma
        getline(ss, artista, ',');
        // Lee la duracion (numero entero)
        ss >> duracion;
        // Ignora la coma que sigue despues del numero
        ss.ignore();
        // Extrae el genero hasta el final de la linea
        getline(ss, genero);

        // Crea una nueva cancion con los datos leidos
        Cancion c(titulo, artista, duracion, genero);
        // Agrega la cancion al vector
        canciones.push_back(c);
    }

    // Cierra el archivo al terminar de leer
    archivo.close();
    cout << "Canciones base cargadas desde " << nombreArchivo << ".\n";
}

void Playlist::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo); // Abre el archivo en modo escritura (sobrescribe)

    // Verifica si el archivo se abrio correctamente
    if (!archivo.is_open()) {
        cout << "Error al guardar en " << nombreArchivo << ".\n";
        return;
    }

    // Recorre todas las canciones guardadas en el vector y las escribe en el archivo
    for (int i = 0; i < canciones.size(); i++) {
        archivo << canciones[i].getTitulo() << "," 
                << canciones[i].getArtista() << ","
                << canciones[i].getDuracion() << ","
                << canciones[i].getGenero() << endl;
    }


    // Cierra el archivo despues de escribir
    archivo.close();
    cout << "Cambios guardados en " << nombreArchivo << ".\n";
}

void Playlist::cargarColaDesdeArchivo(const string& nombreArchivo) {
    colaReproduccion.cargarDesdeArchivo(nombreArchivo);
    cout << "Cola de reproduccion cargada desde " << nombreArchivo << ".\n";
}

void Playlist::guardarColaEnArchivo(const string& nombreArchivo) {
    colaReproduccion.guardarEnArchivo(nombreArchivo);
    cout << "Cola guardada en " << nombreArchivo << endl;
}