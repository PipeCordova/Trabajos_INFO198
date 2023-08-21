#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

bool usuarioExiste(const string& nombreUsuario, const string& nombreArchivo, vector<int>& permisos) {
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        size_t espacio = linea.find(' ');
        if (espacio != string::npos) {
            string usuarioEnArchivo = linea.substr(0, espacio);
            if (usuarioEnArchivo == nombreUsuario) {
                string permisosStr = linea.substr(espacio + 1);
                permisos.clear();
                stringstream ss(permisosStr);
                string token;
                while (getline(ss, token, ',')) {
                    permisos.push_back(stoi(token));
                }
                return true;
            }
        }
    }
    return false;
}

vector<int> convertirlo(const string& v) {
    vector<int> vec;
    string token = "";
    for (char ch : v) {
        if (ch != ',') {
            token += ch;
        } else {
            vec.push_back(stoi(token));
            token = "";
        }
    }
    if (!token.empty()) {
        vec.push_back(stoi(token));
    }
    return vec;
}

int calcularModa(const vector<int>& numeros) {
    vector<int> numerosOrdenados = numeros;
    sort(numerosOrdenados.begin(), numerosOrdenados.end());
    int moda = 0;
    int maxFrecuencia = 0;
    int currentFrecuencia = 1;

    for (size_t i = 1; i < numerosOrdenados.size(); i++) {
        if (numerosOrdenados[i] == numerosOrdenados[i - 1]) {
            currentFrecuencia++;
        } else {
            currentFrecuencia = 1;
        }

        if (currentFrecuencia > maxFrecuencia) {
            maxFrecuencia = currentFrecuencia;
            moda = numerosOrdenados[i];
        }
    }
    return moda;
}

void crearArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo.close();
        cout << "Archivo creado exitosamente: " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo crear el archivo: " << nombreArchivo << endl;
    }
}

void agregarLineaArchivo(const string& nombreArchivo, const string& linea) {
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo << linea << endl;
        archivo.close();
        cout << "Línea agregada al archivo: " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }
}
