#ifndef METODOS_H
#define METODOS_H

#include <string>
#include <vector>

using namespace std;

// Declaracion de metodos a utilizar
bool usuarioExiste(const string& nombreUsuario, const string& nombreArchivo, vector<int>& permisos);
vector<int> convertirlo(const string& v);
int calcularModa(const vector<int>& numeros);
void crearArchivo(const string& nombreArchivo, const string &contenido);
void agregarLineaArchivo(const string& nombreArchivo, const string& linea);
void agregarElementosBD();
vector<int> obtenerPermisos(const string& usuario);
int obtenerEleccion();
void ejecutarOpcion(int eleccion, const vector<int>& permisos, const vector<int>& vector, ifstream& archivoTexto, const string& f, const string& t);


#endif 
