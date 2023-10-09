#include <iostream>
#include <dirent.h>  //directorios
#include <vector>
#include <string>
#include <thread>
#include <mutex>  // biblioteca para utilizar objetos mutex, que se utilizan para sincronizar el acceso a datos compartidos entre hilos.
#include <fstream>          //leer archivos
#include <unordered_map>    //hash
#include <algorithm>        //sort
#include <unistd.h> // pid


using namespace std;

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


string limpiarPalabra(const string &palabra) {
    string limpia = "";
    for (char c : palabra) {
        if (isalpha(c)) { // isalpha retorna True cuando el char 'c' es del alfabeto
            limpia += tolower(c);
        }
    }
    return limpia;
}

void cuentaPalabras(const string &i, const string &o) {
    ifstream input(i);
    if (!input) {
        cout << "- Error al abrir el archivo de entrada '" << i << "'\n\n";
        return;
    }

    unordered_map<string, int> contadorPalabras; // Hash para contar las palabras
    string palabra;
    while (input >> palabra) { // se va leyendo palabra a palabra desde el input y se guarda en 'palabra'
        palabra = limpiarPalabra(palabra);
        if (!palabra.empty()) {
            contadorPalabras[palabra]++;
        }
    }
    input.close();
    ofstream output(o);
    if (!output) {
        cerr << "- Error al crear el archivo de salida '" << o << "'\n\n";
        return;
    }
    // Ordenar las palabras según su cantidad de repeticiones
    // Transferir los elementos del unordered_map a un vector de pares (clave, valor)
    vector<pair<string, int>> elementos(contadorPalabras.begin(), contadorPalabras.end());

    // Ordenar el vector en función del valor (int) en orden descendente
    sort(elementos.begin(), elementos.end(), [](const auto &a, const auto &b) { // Se implementa una funcion lambda para comparar el INT del par
        return a.second > b.second;
    });

    for (const auto &pair : elementos) {
        output << pair.first << "; " << pair.second << endl;
    }
    output.close();
}


int main(int argc, char *argv[]){
    if (argc != 5) {
        cout << "Uso: " << argv[0] << " <EXTENTION> <PATH_FILES_IN> <PATH_FILES_OUT> <AMOUNT_THREADS>" << endl;
        exit(EXIT_FAILURE);
    }

    string extension = argv[1];
    string rutaIn = argv[2];
    string rutaOut = argv[3];
    int nHilos = stoi(argv[4]);

    mutex mtx;

    vector<string> archivos;
    listaArchivos(rutaIn, archivos, extension);

    int archivosPorThread = archivos.size() / nHilos;

    // Si se detectan mas threads que archivos, se ajusta para que cada thread ejecute un archivo, si no da error
    if(nHilos > archivos.size()) {
        archivosPorThread = 1;
        nHilos = archivos.size();
    }

    int clearResult = system("clear");
    //cout << "Comenzando la creación de hilos...\n\n";
    vector<thread> hilos;

    for (int i = 0; i < nHilos; i++) {
        // Define el rango de archivos para este hilo
        int inicio = i * archivosPorThread;
        int fin;
        if (i == (nHilos - 1)) {
            fin = archivos.size(); // El último hilo procesa todos los archivos restantes
        } else {
            fin = (i + 1) * archivosPorThread; // Los hilos anteriores procesan un rango específico de archivos
        }

        // Crea un hilo para procesar el grupo de archivos
        thread hilo([inicio, fin, i, rutaIn, rutaOut, archivos, &mtx]() {
            for (int j = inicio; j < fin; j++) {
                cuentaPalabras(rutaIn + "/" + archivos[j], rutaOut + "/" + archivos[j]);
                mtx.lock();
                cout << "Proceso PID = " << getpid() << " - archivo " << rutaIn + "/" + archivos[j] << ", procesado por el thread " << i << endl;
                mtx.unlock();
            }
        });

        // Agrega el hilo al vector de hilos
        hilos.push_back(move(hilo));
    }
    // Espera a que todos los hilos terminen
    for (thread& hilo : hilos) {
        hilo.join();
    }

    cout << "\nTodos los hilos han terminado.\n" << endl;
    

    return 0;
}
