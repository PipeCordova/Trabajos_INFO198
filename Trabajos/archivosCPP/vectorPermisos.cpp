#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


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

