#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <unistd.h> // pid

namespace fs = std::filesystem;
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <INVERTED_INDEX_FILE> <PATH_FILES_OUT>" << endl;
        exit(EXIT_FAILURE);
    }

    string archivo_salida = argv[1];
    string carpeta_entrada = argv[2]; // la carpeta de entrada seria la carpeta de salida en la opcion 8

    // Crear un mapa para almacenar las palabras y sus conteos globales en archivos
    unordered_map<string, unordered_map<string, int>> conteo_palabras_globales;

    // Recorrer todos los archivos en la carpeta de entrada
    for (const auto& entrada : fs::directory_iterator(carpeta_entrada)) {
        if (entrada.is_regular_file()) {
            ifstream archivo(entrada.path());
            string nombre_archivo = entrada.path().filename();
            string palabra;
            int cantidad;

            // Leer el archivo línea por línea
            while (getline(archivo, palabra, ';')) {
                archivo >> cantidad;
                archivo.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea

                // Incrementar el contador global de la palabra en este archivo
                if (!palabra.empty()) {
                    conteo_palabras_globales[palabra][nombre_archivo] += cantidad;
                }
            }
        }
    }

    // Escribir los resultados en el archivo de salida
    ofstream salida(archivo_salida);
    for (const auto& palabra_conteo : conteo_palabras_globales) {
        salida << palabra_conteo.first << ":";
        for (const auto& archivo_conteo : palabra_conteo.second) {
            salida << "(" << archivo_conteo.first << "," << archivo_conteo.second << ");";
        }
        salida << "\n";
    }

    cout << "El proceso PID = " << getpid() << " generó el archivo: " << archivo_salida << endl;

    return 0;
}

