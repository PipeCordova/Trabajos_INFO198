#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <numeric>
#include "utilidades.h"

using namespace std;

int main(int argc, char* argv[]){
    string u,v,f,t;
    int c;
    while ((c = getopt(argc, argv, "u:v:f:t:")) != -1){
        switch(c) {
            case 'u':
                u = optarg;
                break;
            case 'v':
                v = optarg;
                break;
            case 'f':
                f = optarg;
                break;
            case 't':
                t = optarg;
                break;
        }
    }

    /* El if verifica que el usuario exista en la BD, osea Tarea 1.
    El else if verifica que el nombre del archivo que viene en el parametro -f no este creado ya en la carpeta.*/
    
    vector<int> permisos; // Se crea un vector con los permisos del usuario u
    if (!usuarioExiste(u, "BD.txt", permisos)) {
        cout << "Usuario No encontrado en la Base de Datos!!" << endl << endl;
        exit(EXIT_FAILURE);
    }



    vector<int> vector = convertirlo(v); // aqui se convierte a vector el string v
    
    cout << endl;

    // Aqui comienza la iteracion con el usuario

    int eleccion;
    
    while (true) {
        ifstream archivo("menu.txt");
        ifstream archivoTexto(f);
        string linea;

        cout << "Opciones disponibles:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        cout << "Ingrese su eleccion: ";
        cin >> eleccion;
        cout << endl;

        if (eleccion == 0) {
            break;
        }

        // Este if verifica que la eleccion este en el vector permisos de BD.txt

        if (find(permisos.begin(), permisos.end(), eleccion) != permisos.end()){
            switch (eleccion) {
                case 1:
                    cout << "La suma de su vector v es: " << accumulate(vector.begin(), vector.end(), 0) << endl << endl;
                    break;
                case 2:
                    cout << "El promedio de su vector v es: " << 
                    static_cast<double>(accumulate(vector.begin(), vector.end(), 0)) / vector.size() << endl << endl;
                    break;
                case 3:
                    cout << "La moda de su vector v es: " << calcularModa(vector) << endl << endl;
                    break;
                case 4:
                    cout << "Usted tiene " << vector.size() << " elementos en su vector" << endl << endl;
                    break;
                case 5:
                    if (archivoTexto.is_open()) {
                        cout << "El archivo ya existe!!" << endl << endl;
                    } else { 
                        crearArchivo(f,t);
                    }
                    break;
                case 6:
                    if (!archivoTexto.is_open()){
                        cout << "El archivo NO existe!!" << endl << endl;
                    } else{
                        agregarLineaArchivo(f,t);
                    }
                    break;
                default:
                    cout << "Opcion " << eleccion << " aun no ha sido implementada!" << endl;
                    break;
                }
        } else {
            cout << "No tiene permiso para escoger la opcion " << eleccion << endl << endl;
        }
    }
    cout << endl;

    ofstream archivo("BD.txt", ios::app);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string agregar;
    while (true) {
        cout << "¿Desea agregar elementos a BD.txt?" << endl;
        cout << "Ingrese '1' para SI" << endl;
        cout << "Ingrese '0' para NO" << endl;
        cout << "¿Cuál?: ";
        cin >> agregar;
        cout << endl;

        if (agregar == "1") {
            string nuevoElemento;
            cin.ignore();  // Limpiar el buffer antes de getline
            cout << "Ingrese una nueva línea: ";
            getline(cin, nuevoElemento);
            archivo << nuevoElemento << endl;
            cout << "Agregado!!" << endl;
        } else if (agregar == "0") {
            break;
        } else {
            cout << "Entrada no válida. Ingrese '1' o '0'." << endl;
        }
        cout << endl;
    }

    archivo.close();
    cout << "Elementos agregados al archivo." << endl;
    cout << "Programa terminado exitosamente!!" << endl;
    cout << endl;
    return EXIT_SUCCESS;
}
