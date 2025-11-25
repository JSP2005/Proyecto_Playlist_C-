/*
* playlist.h
* Jose Suberbie Pons
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
	// Queue para orden de reproduccion de canciones
	QueuePlaylist<Cancion> colaReproduccion;

    void mergeSort(int l, int r);
    void merge(int l, int m, int r);
    
public:
	// Metodos para modificar Playlist
    void agregarCancion(Cancion& cancion);
    void mostrarPlaylist();
    void ordenarPorTitulo();
    void eliminarCancion(int indice);
    // Metodos para manejar Queue
    void agregarACola(int indice);
    void mostrarCola();
    void reproducirSiguiente();
    // Metodos para manejo de archivos
    void cargarDesdeArchivo(const string& nombreArchivo);
    void guardarEnArchivo(const string& nombreArchivo);
    void cargarColaDesdeArchivo(const string& nombreArchivo);
    void guardarColaEnArchivo(const string& nombreArchivo);
};

#endif

