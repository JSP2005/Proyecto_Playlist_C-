#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <string>
#include "cancion.h"
using namespace std;

class Playlist {
private:
	// Vector de canciones "Playlist"
    vector<Cancion> canciones;

public:
	// Métodos para modificar Playlist
    void agregarCancion(Cancion& cancion);
    void mostrarPlaylist();
    void ordenarPorTitulo();
    void eliminarCancion(int indice);
};

#endif

