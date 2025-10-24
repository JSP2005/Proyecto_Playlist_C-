/*
* cancion.h
* José Suberbie Pons
* A01713050
*/
#ifndef CANCION_H
#define CANCION_H

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
    friend ostream& operator<<(ostream& os, const Cancion& c);
};

#endif
