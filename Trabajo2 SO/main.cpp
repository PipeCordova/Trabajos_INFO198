#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <numeric>
#include "metodos.h"
#include <chrono>
#include <thread> 

using namespace std;

int main(int argc, char *argv[]) {
    string u, v, f, t;
    int c;
    while ((c = getopt(argc, argv, "u:v:f:t:")) != -1) {
        switch (c) {
            case 'u':
                u = optarg;
                break;
            case 'v':
                v = optarg;
                break;
            case 'f':
                f = optarg;
                break;
            case 't':
                t = optarg;
                break;
        }
    }

    vector<int> permisos = obtenerPermisos(u);
    vector<int> vector = convertirlo(v);

    cout << endl;

    while (true) {
        ifstream archivo("menu.txt");
        ifstream archivoTexto(f);

        cout << "Opciones disponibles:" << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        int eleccion = obtenerEleccion();

        if (eleccion == 0) {
            break;
        }
        if (eleccion >= 7) {
            cout << "Opcion " << eleccion << " aun no ha sido implementada!" << endl << endl;
        } else {
            ejecutarOpcion(eleccion, permisos, vector, archivoTexto, f, t);
        }
        cout << "Espere 10 segundos!!" << endl << endl;
        this_thread::sleep_for(chrono::seconds(10)); // Esperar 10 segundos y se limpia la consola
        system("clear");
    }

    agregarElementosBD();
    cout << "Trabajo 2 terminado!!" << endl << endl;
    return EXIT_SUCCESS;
}