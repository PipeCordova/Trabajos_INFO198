#include "../include/metodos.h"


/*
Esta funcion valida que las entradas u,v,f,t,i,o no sean vacias.
*/
bool algunParametroVacio(const string &param, const string &nombreParametro) {
    if (param.empty()) {
        cerr << "El parámetro " << nombreParametro << " es OBLIGATORIO\n";
        return true;
    }
    return false;
}

/*
En esta funcion se realiza una llamada a una funcion pair usuarioExiste(), osea devuelve 2 valores. 
El primer valor que devuelve es un booleano que nos dice si el usuario u existe en la base de datos data/BD.txt.
El segundo valor es un string el cual se retorna. Este string es el permiso el cual tiene el usuario para usar
en el programa. Por ejemplo Clarita es Admin o LuisVeas es userGeneral.

Ejemplo caso true:
    valores = {True, Admin}
    flag = True
    permiso = Admin

    retornaría que es Admin ya que se saltaría el if

Ejemplo caso False:
    valores = {False, Usuario NO encontrado en la Base de Datos!!}
    flag = False
    permiso = Usuario NO encontrado en la Base de Datos!!
    
    El if se cumpliría ya que se está negando un False, osea es True. Por lo tanto imprimiría el mensaje
    que no se encontró en la base de datos y se saldría de la ejecucion del programa.
*/
string obtenerPermisosDesdeArchivo(const string& rutaArchivo, const string& usuario) {
    auto valores = usuarioExiste(usuario, rutaArchivo);
    bool flag = valores.first;
    string permiso = valores.second;
    if (!flag) {
        cout << endl;
        cout << permiso << endl;
        exit(EXIT_FAILURE);
    }
    return permiso;
}

/*
Esta función se invoca en obtenerPermisosDesdeArchivos(). Se encarga de hacer 2 cosas en el mismo archivo. 
Busca si el usuario u existe en la base de datos data/BD.txt, si existe retorna true y su permiso de usuario,
si no existe el usuario u retorna false y un mensaje advirtiendo la situación.

Por ejemplo en la base de datos data/BD.txt:
    Clarita Admin --> retorna {True,Admin}, ya que Clarita existe.
    Alexis userGeneral --> retorna {False, Usuario NO encontrado en la Base de Datos!!}, ya que Alexis no existe.
*/
pair <bool, string> usuarioExiste(const string& nombreUsuario, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        size_t espacio = linea.find(' '); // buscando el espacio, ya que la forma es userName Permiso
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

/*
Esta función convierte a vector el "vector" v ingresado como string en el parametro de entrada.

Por ejemplo:
    string "3,1,4,5,2,2,3" 

    retorna vector<int> vec = {3,1,4,5,2,2,3}
*/
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
