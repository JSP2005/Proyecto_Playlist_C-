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
    cout << "Canción agregada.\n";
}

void Playlist::mostrarPlaylist() {
    cout << "\n=== Playlist ===\n";
    if (canciones.empty()) {
        cout << "La playlist esta vacía.\n";
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
    cout << "\nPlaylist ordenada por título.\n";
}

void Playlist::eliminarCancion(int indice) {
    if (indice < 1 || indice > canciones.size()) {
        cout << "Índice inválido.\n";
        return;
    }
    canciones.erase(canciones.begin() + (indice - 1));
    cout << "Canción eliminada.\n";
}

