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
#include <unordered_map>

using namespace std;

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
};


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

#endif 
