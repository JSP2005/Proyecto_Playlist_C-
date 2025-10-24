/*
* cancion.cpp
* José Suberbie Pons
* A01713050
*/

#include "cancion.h"

// Implementación de métodos de clase Cancion 

Cancion::Cancion(string t, string a, int d, string g)
    : titulo(t), artista(a), duracion(d), genero(g) {}

string Cancion::getTitulo() { 
	return titulo; 
}

string Cancion::getArtista() { 
	return artista; 
}

int Cancion::getDuracion() { 
	return duracion; 
}

string Cancion::getGenero() { 
	return genero; 
}

void Cancion::mostrar() {
    cout << titulo << " - " << artista
         << " (" << duracion << " seg, " << genero << ")";
}

ostream& operator<<(ostream& os, const Cancion& c) {
    os << c.titulo << " - " << c.artista << " (" << c.duracion << "s, " << c.genero << ")";
    return os;
}

