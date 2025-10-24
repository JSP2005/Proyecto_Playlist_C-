/*
* playlist.h
* José Suberbie Pons
* A01713050
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <string>
#include "queuePlaylist.h"
#include "cancion.h"
using namespace std;

class Playlist {
private:
	// Vector de canciones "Playlist"
    vector<Cancion> canciones;
	// Queue para orden de reproducción de canciones
	QueuePlaylist<Cancion> colaReproduccion;
public:
	// Métodos para modificar Playlist
    void agregarCancion(Cancion& cancion);
    void mostrarPlaylist();
    void ordenarPorTitulo();
    void eliminarCancion(int indice);
    
    void agregarACola(int indice);
    void mostrarCola();
    void reproducirSiguiente();
};

#endif

