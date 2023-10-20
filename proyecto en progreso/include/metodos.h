#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <dirent.h>         // directorios
#include <filesystem> // es para comprobar si la carpeta out esta vacia o no


using namespace std;
namespace fs = filesystem;

struct Opciones {
    int eleccion;
    vector<int> vectorPerfil;
    vector<int> vectorEntrada;
    ifstream archivoTexto;
    string f;
    string t;
    string i;
    string o;
    ifstream archivoSalida;
    string rutaOut; // se agrego en la estructura para asi poder verificar si la carpeta out esta vacia o no
    string rutaIndex;
    ifstream archivoIndex; // este se agrego para abrir el archivo index y comprobar si existe o no
    string comandoPrepararDatos;
    string comandoCrearIndice;
    string comandoBuscador;
};

// Declaración de todas las funciones utilizadas en el programa principal

bool algunParametroVacio(const string &param, const string &nombreParametro);
string obtenerPermisosDesdeArchivo(const string& rutaArchivo, const string& usuario);
pair <bool, string> usuarioExiste(const string& nombreUsuario, const string& nombreArchivo);
vector<int> convertirlo(const string& v);
int calcularModa(const vector<int>& numeros);
vector<int> obtenerVectorDesdeLinea(int numeroLinea, const string& rutaArchivo);
void ejecutarOpcion(const Opciones& opciones);
int obtenerEleccion();
void crearArchivo(const string& nombreArchivo);
void agregarLineaArchivo(const string& nombreArchivo, const string& linea);
void procesarArchivo(const string & i, const string & o);
void ordenarPorFrecuencia(vector<pair<string, int>>& paresPalabraFrecuencia);
vector<string> dividirTexto(const string& texto);
string limpiarPalabra(const string &palabra);
bool hayAlMenos20Archivos(const string& rutaIn, const string& extension);
pair<bool, vector<string>> archivosCumplen1MB(const string& rutaIn, const string& extension);
void realizarAccion8(const string& rutaOut, const string& comando);
void realizarAccion9_10(const string& rutaOut, const string& comando);

#endif 
