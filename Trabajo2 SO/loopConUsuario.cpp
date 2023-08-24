#include "metodos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric> 

using namespace std;

int obtenerEleccion() {
    int eleccion;
    cout << "Ingrese su eleccion: ";
    cin >> eleccion;
    cout << endl;
    return eleccion;
}

void ejecutarOpcion(int eleccion, const vector<int>& permisos, const vector<int>& vector, ifstream& archivoTexto, const string& f, const string& t) {
    if (find(permisos.begin(), permisos.end(), eleccion) != permisos.end()) {
        switch (eleccion) {
            case 1:
                cout << "La suma de su vector v es: " << accumulate(vector.begin(), vector.end(), 0) << endl << endl;
                break;
            case 2:
                cout << "El promedio de su vector v es: " <<
                static_cast<double>(accumulate(vector.begin(), vector.end(), 0)) / vector.size() << endl << endl;
                break;
            case 3:
                cout << "La moda de su vector v es: " << calcularModa(vector) << endl << endl; // Asegúrate de tener calcularModa implementada
                break;
            case 4:
                cout << "Usted tiene " << vector.size() << " elementos en su vector" << endl << endl;
                break;
            case 5:
                if (archivoTexto.is_open()) {
                    cout << "El archivo ya existe!!" << endl << endl;
                } else { 
                    crearArchivo(f, t);
                }
                break;
            case 6:
                if (!archivoTexto.is_open()) {
                    cout << "El archivo NO existe!!" << endl << endl;
                } else {
                    agregarLineaArchivo(f, t);
                }
                break;
        }
    } else {
        cout << "No tiene permiso para escoger la opcion " << eleccion << endl << endl;
    }
}