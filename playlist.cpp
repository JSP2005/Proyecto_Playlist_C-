/*
* playlist.cpp
* José Suberbie Pons
* A01713050
*/

#include "playlist.h"
#include "cancion.h"

// Implementación de métodos de clase Playlist

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

// Implementación de Bubble sort para ordenar playlist por título

void Playlist::ordenarPorTitulo() {
    for (int i = canciones.size() - 1; i > 0; i--) {       
        for (int j = 0; j < i; j++) {                      
            if (canciones[j].getTitulo() > canciones[j + 1].getTitulo()) {
                swap(canciones[j], canciones[j + 1]);      
            }
        }
    }
    cout << "\nPlaylist ordenada por titulo.\n";
}

void Playlist::eliminarCancion(int indice) {
    if (indice < 1 || indice > canciones.size()) {
        cout << "Indice invalido.\n";
        return;
    }
    canciones.erase(canciones.begin() + (indice - 1));
    cout << "Cancion eliminada.\n";
}

// Implementación de métodos para Queue

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
    colaReproduccion.dequeue();
}
