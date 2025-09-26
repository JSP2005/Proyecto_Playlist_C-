#include "playlist.h"
#include "cancion.h"

int main() {
    Playlist miPlaylist;
    int opcion;

    do {
        cout << "\n--- Menu Playlist ---\n";
        cout << "1. Agregar cancion\n";
        cout << "2. Mostrar playlist\n";
        cout << "3. Ordenar por titulo\n";
        cout << "4. Eliminar cancion\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string titulo; 
			string artista;
			string genero;
            int duracion;

            cout << "Titulo: ";
            getline(cin, titulo);
            cout << "Artista: ";
            getline(cin, artista);
            cout << "Duracion (segundos): ";
            cin >> duracion;
            cin.ignore();
            cout << "Genero: ";
            getline(cin, genero);

            Cancion cancion(titulo, artista, duracion, genero);
            miPlaylist.agregarCancion(cancion);
        }
        else if (opcion == 2) {
            miPlaylist.mostrarPlaylist();
        }
        else if (opcion == 3) {
            miPlaylist.ordenarPorTitulo();
        }
        else if (opcion == 4) {
            int indice;
            cout << "Numero de la cancion a eliminar: ";
            cin >> indice;
            cin.ignore();
            miPlaylist.eliminarCancion(indice);
        }

    } while (opcion != 0);

    return 0;
}

