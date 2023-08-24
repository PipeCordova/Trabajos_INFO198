#include "metodos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric> 

using namespace std;

void crearArchivo(const string &rutaCompleta, const string &contenido) {
    ofstream archivo(rutaCompleta);
    if (!archivo) {
        cerr << "Error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    
    archivo << contenido;
    
    cout << "Archivo '" << rutaCompleta << "' creado exitosamente!!" << endl << endl;
}

void agregarLineaArchivo(const string& nombreArchivo, const string& linea) {
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo << linea << endl;
        archivo.close();
        cout << "Línea agregada en: " << nombreArchivo << endl << endl;
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl << endl;
    }
}


void agregarElementosBD() {
    ofstream archivo("BD.txt", ios::app);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return;
    }

    string agregar;
    while (true) {
        cout << "¿Desea agregar elementos a BD.txt?" << endl;
        cout << "Ingrese '1' para SI" << endl;
        cout << "Ingrese '0' para NO" << endl;
        cout << "¿Cuál?: ";
        cin >> agregar;
        cout << endl;

        if (agregar == "1") {
            string nuevoElemento;
            cin.ignore(); // Limpiar el buffer antes de getline
            cout << "Ingrese una nueva línea: ";
            getline(cin, nuevoElemento);
            archivo << nuevoElemento << endl;
            cout << "Agregado!!" << endl;
        } else if (agregar == "0") {
            break;
        } else {
            cout << "Entrada no válida. Ingrese '1' o '0'." << endl;
        }
        cout << endl;
    }

    archivo.close();
    cout << endl;
}




