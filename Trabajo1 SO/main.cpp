#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

// Declaracion de Funciones utilizadas
bool usuarioExiste(const string& nombreUsuario, const string& nombreArchivo, vector<int>& permisos);
vector<int> convertirlo(const string& v);
int calcularModa(const vector<int>& numeros);


int main(int argc, char* argv[]){
    string u,v;
    int c;
    while ((c = getopt(argc, argv, "u:v:")) != -1){
        switch(c) {
            case 'u':
                u = optarg;
                break;
            case 'v':
                v = optarg;
                break;
        }
    }

    vector<int> permisos; // Se crea un vector con los permisos del usuario u
    if (!usuarioExiste(u, "BD.txt", permisos)) {
        cout << "Usuario No encontrado en la Base de Datos!!" << endl;
        exit(EXIT_FAILURE);
    }

    vector<int> vector = convertirlo(v); // aqui se convierte a vector el string v
    
    cout << endl;

    // Aqui comienza la iteracion con el usuario
    int eleccion;
    while (true) {
        ifstream archivo("opciones.txt");
        string linea;

        cout << "Opciones disponibles:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        cout << "Ingrese su eleccion (0 para salir): ";
        cin >> eleccion;
        cout << endl;

        if (eleccion == 0) {
            break;
        }


        // Este if verifica que la eleccion este en el vector permisos de BD.txt
        if (find(permisos.begin(), permisos.end(), eleccion) != permisos.end()){
            switch (eleccion) {
                case 1:
                    cout << "La suma de su vector v es: " << accumulate(vector.begin(), vector.end(), 0) << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "El promedio de su vector v es: " << 
                    static_cast<double>(accumulate(vector.begin(), vector.end(), 0)) / vector.size() << endl;
                    cout << endl;
                    break;
                case 3:
                    cout << "La moda de su vector v es: " << calcularModa(vector) << endl;
                    cout << endl;
                    break;
                case 4:
                    cout << "Usted tiene " << vector.size() << " elementos en su vector" << endl;
                    cout << endl;
                    break;
                default:
                    cout << "Opcion no disponible." << endl;
                    cout << endl;
                    break;
            }
        } else{
            cout << "No tiene permiso para escoger la opcion " << eleccion << endl;
            cout << endl;
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

        if (agregar == "1") {
            string nuevoElemento;
            cin.ignore();  // Limpiar el buffer antes de getline
            cout << "Ingrese una nueva línea: ";
            getline(cin, nuevoElemento);
            archivo << nuevoElemento << endl;
            cout << "Agregado!!" << endl;
            cout << endl;
        } else if (agregar == "0") {
            break;
        } else {
            cout << "Entrada no válida. Ingrese '1' o '0'." << endl;
        }
    }

    archivo.close();
    cout << "Elementos agregados al archivo." << endl;

    return EXIT_SUCCESS;
}

bool usuarioExiste(const string& nombreUsuario, const string& nombreArchivo, vector<int>& permisos) {
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        size_t espacio = linea.find(' ');
        if (espacio != string::npos) {
            string usuarioEnArchivo = linea.substr(0, espacio);
            if (usuarioEnArchivo == nombreUsuario) {
                string permisosStr = linea.substr(espacio + 1);
                permisos.clear();
                stringstream ss(permisosStr);
                string token;
                while (getline(ss, token, ',')) {
                    permisos.push_back(stoi(token));
                }
                return true;
            }
        }
    }
    return false;
}

vector<int> convertirlo(const string& v) {
    vector<int> vec;
    string token = "";
    for (char ch : v) {
        if (ch != ',') {
            token += ch;
        } else {
            vec.push_back(stoi(token));
            token = "";
        }
    }
    if (!token.empty()) {
        vec.push_back(stoi(token));
    }
    return vec;
}


int calcularModa(const vector<int>& numeros) {
    vector<int> numerosOrdenados = numeros;
    sort(numerosOrdenados.begin(), numerosOrdenados.end());

    int moda = 0;
    int maxFrecuencia = 0;
    int currentFrecuencia = 1;

    for (size_t i = 1; i < numerosOrdenados.size(); i++) {// size_t se usa para comparar elementos vecinos con el anterior
        if (numerosOrdenados[i] == numerosOrdenados[i - 1]) {
            currentFrecuencia++;
        } else {
            currentFrecuencia = 1;
        }

        if (currentFrecuencia > maxFrecuencia) {
            maxFrecuencia = currentFrecuencia;
            moda = numerosOrdenados[i];
        }
    }

    return moda;
}


