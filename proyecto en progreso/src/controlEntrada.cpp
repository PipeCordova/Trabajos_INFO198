#include "../include/metodos.h"


// Esta funcion valida que las entradas no sean vacias.
bool algunParametroVacio(const string &param, const string &nombreParametro) {
    if (param.empty()) {
        cerr << "El parámetro " << nombreParametro << " es OBLIGATORIO\n";
        return true;
    }
    return false;
}

/*
Esta funcion retorna el permiso del usuario, la cual viene desde la funcion usuarioExiste(..).
Si usuarioExiste retorna falso significa que el usuario no existe, entonces se termina el programa.
*/
string obtenerPermisosDesdeArchivo(const string& rutaArchivo, const string& usuario) {
    auto valores = usuarioExiste(usuario, rutaArchivo);
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

/* Esta funcion se encarga de validar si hay al menos 20 archivos con la extension definida como 
variable de entorno EXTENTION. 
*/
bool hayAlMenos20Archivos(const string& rutaIn, const string& extension) {
    int contador = 0;
    for (const auto& entrada : fs::directory_iterator(rutaIn)) {
        if (fs::is_regular_file(entrada) && entrada.path().extension() == "." + extension) {
            contador++;
            if (contador >= 20) {
                return true;
            }
        }
    }
    cout << contador << endl;
    return false;
}

/* Esta funcion se encarga de validar que los archivos en la carpeta PATH_FILES_IN sean de al menos 1 MB,
por eso devuelve un booleano. Ademas se agregó para que devuelva un vector con los nombres de los archivos 
que no son de 1 MB, para que el usuario pueda ver en pantalla cuales archivos no son de 1 MB. Es por esta 
razon que la funcion es de tipo pair. 
*/

pair<bool, vector<string>> archivosCumplen1MB(const string& rutaIn, const string& extension) {
    bool todosCumplen = true;
    vector<string> archivosNoCumplen;

    for (const auto& archivo : fs::directory_iterator(rutaIn)) {
        if (archivo.is_regular_file() && archivo.path().extension() == "." + extension) {
            ifstream file(archivo.path(), ios::binary);
            if (file) {
                file.seekg(0, ios::end);
                streampos fileSize = file.tellg();
                // 1 MB equivale a 1.048.576 bytes (1024 * 1024 bytes)
                if (fileSize < 1024 * 1024) {
                    todosCumplen = false;
                    archivosNoCumplen.push_back(archivo.path().filename().string());
                }
                file.close();
            }
        }
    }
    return make_pair(todosCumplen, archivosNoCumplen);
}

// Esta funcion convierte a vector el "vector" v ingresado como string en el parametro de entrada.
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
