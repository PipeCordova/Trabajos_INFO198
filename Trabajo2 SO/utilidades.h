#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
#include <vector>

using namespace std;

bool usuarioExiste(const string& nombreUsuario, const string& nombreArchivo, vector<int>& permisos);
vector<int> convertirlo(const string& v);
int calcularModa(const vector<int>& numeros);
void crearArchivo(const string& nombreArchivo, const string &contenido);
void agregarLineaArchivo(const string& nombreArchivo, const string& linea);

#endif // UTILIDADES_H
