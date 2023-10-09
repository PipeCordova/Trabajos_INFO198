#include "../include/metodos.h"


void crearArchivo(const string &rutaCompleta) {
    ofstream archivo(rutaCompleta);
    if (!archivo) {
        cerr << "Error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    
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


/* 
Esta funcion se encarga de retornar los permisos de usuario correspondiente a admin, userGeneral o userRookie.
Se le pasa como parametro el numero de la linea y la ruta.
*/

vector<int> obtenerVectorDesdeLinea(int numeroLinea, const string& rutaArchivo) {
    vector<int> numeros;
    
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return numeros;
    }

    string linea;
    for (int i = 0; i < numeroLinea; i++) {
        if (!getline(archivo, linea)) {
            cerr << "No se pudo leer la línea " << numeroLinea << " del archivo." << endl << endl;
            exit(EXIT_FAILURE);
        }
    }
    
    size_t pos = linea.find('=');
    if (pos != string::npos) {
        string numerosStr = linea.substr(pos + 1);
        
        istringstream ss(numerosStr);
        int numero;
        char comma;
        while (ss >> numero >> comma) {
            numeros.push_back(numero);
        }
        ss >> numero;
        numeros.push_back(numero);
    }
    
    return numeros;
}


/*

// aqui solo se leeran los archivos en la carpeta files/in que sean txt
void listaArchivos(const string& dir, vector<string>& archivos, const string& ext){
    string elem;
    DIR *directorio; //Tipo de Dato
    struct dirent * elemento;
    if (directorio = opendir(dir.c_str())) {
        while(elemento = readdir(directorio)) {
            elem = elemento -> d_name;
            if (elem.length() >= 4 && elem.substr(elem.length() - 4) == "." + ext){
                archivos.push_back(elem);
            }
        }
    } else {
        cout << "Error al abrir directorio " << dir << "\nEscribió mal la dirección o no existe!" << endl;
    }
    closedir(directorio);
}

*/