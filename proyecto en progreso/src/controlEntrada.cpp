#include "../include/metodos.h"


// Esta funcion valida que las entradas no sean vacias.
bool algunParametroVacio(const string &param, const string &nombreParametro) {
    if (param.empty()) {
        cerr << "El parámetro " << nombreParametro << " es OBLIGATORIO\n";
        return true;
    }
    return false;
}

// Esto esta bien.
/*
Esta funcion retorna el permiso del usuario, la cual viene desde la funcion usuarioExiste(..).
Si usuarioExiste retorna falso significa que el usuario no existe, entonces se termina el programa.
*/
string obtenerPermisosDesdeArchivo(const string& rutaArchivo, const string& usuario) {
    pair<bool, string> valores = usuarioExiste(usuario, rutaArchivo);
    bool flag = valores.first;
    string permiso = valores.second;
    if (!flag) {
        cout << endl << permiso << endl << endl;
        exit(EXIT_FAILURE);
    }
    return permiso;
}

/*
Esta funcion retorna 2 valores:
    - 1. true/false --> Si es que el usuario existe en BD.txt. Si el usuario existe retorna true y su permiso.
    Si el usuario no existe retorna false y un mensaje diciendo que no existe en BD.txt.
    - 2. permiso (admin, userGeneral, userRookie)
*/
pair <bool, string> usuarioExiste(const string& nombreUsuario, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        size_t espacio = linea.find(' ');
        if (espacio != string::npos) {
            string usuarioEnArchivo = linea.substr(0, espacio);
            if (usuarioEnArchivo == nombreUsuario) {
                return make_pair(true, linea.substr(espacio));
            }
        }
    }
    return make_pair(false, "Usuario NO encontrado en la Base de Datos!!");
}


// Listo. Esta funcion convierte a vector el "vector" v ingresado como string en el parametro de entrada.
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
