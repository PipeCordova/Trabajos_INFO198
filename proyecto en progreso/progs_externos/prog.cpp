#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <unistd.h> // pid

namespace fs = std::filesystem;
using namespace std;


int main(int argc, char *argv[]){
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <INVERTED_INDEX_FILE> <PATH_FILES_OUT>" << endl;
        exit(EXIT_FAILURE);
    }

    string archivo_salida = argv[1];
    string carpeta_entrada = argv[2]; // la carpeta de entrada seria la carpera de salida en la opcion 8

    // Crear un mapa para almacenar las palabras, archivos y conteos
    unordered_map<string, vector<pair<string, int>>> conteo_palabras;

    // Recorrer todos los archivos en la carpeta de entrada
    for (const auto& entrada : fs::directory_iterator(carpeta_entrada)) {
        if (entrada.is_regular_file()) {
            ifstream archivo(entrada.path());
            string nombre_archivo = entrada.path().filename();
            string palabra;

            // Leer el archivo palabra por palabra y contar las apariciones
            while (archivo >> palabra) {
                // Eliminar signos de puntuación u otros caracteres no deseados
                // (puedes personalizar esta parte según tus necesidades)
                // Aquí se asume que solo se separan palabras por espacios.
                for (char& c : palabra) {
                    if (!isalpha(c)) {
                        c = ' ';
                    }
                }

                // Incrementar el contador de la palabra en el mapa
                if (!palabra.empty()) {
                    conteo_palabras[palabra].emplace_back(nombre_archivo, 1);
                }
            }
        }
    }

    // Escribir los resultados en el archivo de salida
    ofstream salida(archivo_salida);
    for (const auto& entrada : conteo_palabras) {
        salida << entrada.first << ":";
        for (const auto& archivo_conteo : entrada.second) {
            salida << "(" << archivo_conteo.first << ";" << archivo_conteo.second << ");";
        }
        salida << "\n";
    }

    cout << "El proceso PID = " << getpid() << " generó el archivo " << archivo_salida << endl;

    return 0;
}
