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

