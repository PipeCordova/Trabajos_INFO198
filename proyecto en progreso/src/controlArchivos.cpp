#include "../include/metodos.h"


/*
Esta función tiene como parámetro la ruta tipo: ft/hola.py, entonces la función crea el archivo hola.py
en la carpeta ft. Puede recibir cualquier tipo de extensión. Se ejecuta cuando se selecciona la opción 5
en el menú.
*/

void crearArchivo(const string &rutaCompleta) {
    ofstream archivo(rutaCompleta);
    if (!archivo) {
        cerr << "Error al abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }
    
    cout << "Archivo {" << rutaCompleta << "} creado exitosamente!!" << endl << endl;
}

/*
Esta función agrega una linea al archivo ya creado con la función crearArchivo(). Por ejemplo en el archivo
hola.py se puede agregar código python como un print. Se ejecuta cuando se selecciona la opción 6 en el menú.

*/
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
Esta funcion retornar los permisos de usuario correspondiente a admin, userGeneral o userRookie desde la base 
de datos data/perfilesUsuarios.txt. Notar que la forma del tipo de usuario es por ejemplo: userRookie = 0,1,4 
entonces lo que hace la funcion es devolver un vector de la forma {0,1,4}, según corresponda.

Se le pasa como parametro el número de la línea ya que esta predefinida y la ruta de la base de datos.  
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
