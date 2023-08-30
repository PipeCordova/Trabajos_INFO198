#ifndef METODOS_H
#define METODOS_H

#include <string>
#include <vector>

using namespace std;

// Declaracion de metodos a utilizar

// Estas se implementan en procEntrada.cpp
void leerConfiguracion(string& rutaPermisos, string& rutaVector, string& rutaPerfiles);
string obtenerPermisosDesdeArchivo(const string& rutaArchivo, const string& usuario);
pair <bool, string> usuarioExiste(const string& nombreUsuario, const string& nombreArchivo);
vector<int> convertirlo(const string& v);

// Esto se implementa en operarVector.cpp
int calcularModa(const vector<int>& numeros);

// Esto se implementa en vectorPermisos.cpp
vector<int> obtenerVectorDesdeLinea(int numeroLinea, const string& rutaArchivo);

// Esta es la funcion principal de interaccion con el usuario. Se implementa en loopConUsuario.cpp.
// Ademas se creó una funcion de tipo int que retorna la eleccion del usuario segun menu.txt
void ejecutarOpcion(int eleccion, const vector<int>& vectrPerfil, const vector<int>& vectorEntrada, ifstream& archivoTexto, const string& f, const string& t, const string & i, const string & o, ifstream& archivoSalida);
int obtenerEleccion();

// Estas funciones son las encargadas de las opciones 5 y 6 de menu.txt.
// Estan implementadas en operarArchivo.txt
void crearArchivo(const string& nombreArchivo);
void agregarLineaArchivo(const string& nombreArchivo, const string& linea);

// Este metodo se encarga de agregar elementos a la Base de Datos BD.txt.
// Esta implementada en operarArchivo.txt
void agregarElementosBD(const string &rutaPermisos);

// Estos metodos se encargan de trabajar la opcion 7, osea contar las palabras del cuento
void procesarArchivo(const string & i, const string & o);
void ordenarPorFrecuencia(vector<pair<string, int>>& paresPalabraFrecuencia);
vector<string> dividirTexto(const string& texto);

#endif 
