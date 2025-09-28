/*
* playlist.cpp
* Jos� Suberbie Pons
* A01713050
*/

#include "playlist.h"
#include "cancion.h"

// Implementaci�n de m�todos de clase Playlist

void Playlist::agregarCancion(Cancion& cancion) {
    canciones.push_back(cancion);
    cout << "Canci�n agregada.\n";
}

void Playlist::mostrarPlaylist() {
    cout << "\n=== Playlist ===\n";
    if (canciones.empty()) {
        cout << "La playlist esta vac�a.\n";
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

// Implementaci�n de Bubble sort para ordenar playlist por t�tulo

void Playlist::ordenarPorTitulo() {
    for (int i = canciones.size() - 1; i > 0; i--) {       
        for (int j = 0; j < i; j++) {                      
            if (canciones[j].getTitulo() > canciones[j + 1].getTitulo()) {
                swap(canciones[j], canciones[j + 1]);      
            }
        }
    }
    cout << "\nPlaylist ordenada por t�tulo.\n";
}

void Playlist::eliminarCancion(int indice) {
    if (indice < 1 || indice > canciones.size()) {
        cout << "�ndice inv�lido.\n";
        return;
    }
    canciones.erase(canciones.begin() + (indice - 1));
    cout << "Canci�n eliminada.\n";
}

