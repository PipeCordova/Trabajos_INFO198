#include "metodos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric> 

vector<int> obtenerPermisos(const string& usuario) {
    vector<int> permisos;
    if (!usuarioExiste(usuario, "BD.txt", permisos)) {
        cout << "Usuario No encontrado en la Base de Datos!!" << endl << endl;
        exit(EXIT_FAILURE);
    }
    return permisos;
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