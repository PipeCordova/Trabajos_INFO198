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

void ejecutarOpcion(int eleccion, const vector<int>& vectorPerfil, const vector<int>& vectorEntrada, ifstream& archivoTexto, const string& f, const string& t, const string & i, const string & o, ifstream& archivoSalida) {
    if (find(vectorPerfil.begin(), vectorPerfil.end(), eleccion) != vectorPerfil.end()) {
        switch (eleccion) {
            case 1:
                cout << "La suma de su vector v es: " << accumulate(vectorEntrada.begin(), vectorEntrada.end(), 0) << endl << endl;
                break;
            case 2:
                cout << "El promedio de su vector v es: " <<
                static_cast<double>(accumulate(vectorEntrada.begin(), vectorEntrada.end(), 0)) / vectorEntrada.size() << endl << endl;
                break;
            case 3:
                cout << "La moda de su vector v es: " << calcularModa(vectorEntrada) << endl << endl;
                break;
            case 4:
                cout << "Usted tiene " << vectorEntrada.size() << " elementos en su vector\n" << endl;
                break;
            case 5:
                if (archivoTexto.is_open()) {
                    cout << "El archivo ya existe!!\n" << endl;
                } else { 
                    crearArchivo(f);
                }
                break;
            case 6:
                if (!archivoTexto.is_open()) {
                    cout << "El archivo NO existe!!\n" << endl;
                } else {
                    agregarLineaArchivo(f, t);
                }
                break;
            
            case 7:
                if(archivoSalida.is_open()){
                    cout << "El archivo ya existe!!\n" << endl;
                } else {
                    procesarArchivo(i, o);
                }
                break;
        }
    } else {
        cout << "No tiene permiso para escoger la opcion " << eleccion << endl << endl;
    }
}


