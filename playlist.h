#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cancion {
private:
	// Atributos
    string titulo;
    string artista;
    int duracion;
    string genero;

public:
    // Constructor
    Cancion(string t = "", string a = "", int d = 0, string g = "");

    // Getters
    string getTitulo();
    string getArtista();
    int getDuracion();
    string getGenero();

    // Método para mostrar información
    void mostrar();
};

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

