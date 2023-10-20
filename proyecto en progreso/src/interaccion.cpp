#include "../include/metodos.h"


/*
Notemos que en la carpeta include hay un archivo .h con la definición de las funciones y con una estructura
Opciones, la cual tiene los mismos objetos que se definen en esta función. Esta función recibe la clase Opciones
que se rescatan desde el main, entonces aqui se están copiando los miembros de la estructura opc en variables
locales con nombres más cortos para facilitar su uso en el código. Se ejecuta cada opción seleccionada de acuerdo
al perfil del usuario. Por ejemplo Admin, tiene todos los permisos.
*/
void ejecutarOpcion(const Opciones& opc) {
    int eleccion = opc.eleccion;
    const vector<int>& vectorPerfil = opc.vectorPerfil;
    const vector<int>& vectorEntrada = opc.vectorEntrada;
    const ifstream& archivoTexto = opc.archivoTexto;
    const string& f = opc.f;
    const string& t = opc.t;
    const string& i = opc.i;
    const string& o = opc.o;
    const ifstream& archivoSalida = opc.archivoSalida;
    const string rutaOut = opc.rutaOut;
    const string rutaIndex = opc.rutaIndex;

    const ifstream& archivoIndex = opc.archivoIndex;

    const string comandoPrepararDatos = opc.comandoPrepararDatos;
    const string comandoCrearIndice = opc.comandoCrearIndice;
    const string comandoBuscador = opc.comandoBuscador;


    if (find(vectorPerfil.begin(), vectorPerfil.end(), eleccion) != vectorPerfil.end()) {
        switch (eleccion) {
            case 1:
                cout << "La suma de su vector v es: " << accumulate(vectorEntrada.begin(), vectorEntrada.end(), 0) << endl << endl;
                break;
            case 2:
                cout << "El promedio de su vector v es: " <<
                static_cast<double>(accumulate(vectorEntrada.begin(), vectorEntrada.end(), 0)) / vectorEntrada.size() << endl << endl;
                break;
            case 3:
                cout << "La moda de su vector v es: " << calcularModa(vectorEntrada) << endl << endl;
                break;
            case 4:
                cout << "Tiene " << vectorEntrada.size() << " elementos en su vector\n" << endl;
                break;
            case 5:
                if (archivoTexto.is_open()) {
                    cout << "El archivo ya existe en {" << f << "}." << endl;
                } else { 
                    crearArchivo(f);
                }
                break;
            case 6:
                if (!archivoTexto.is_open()) {
                    cout << "El archivo NO existe en {" << f << "}." << endl;
                } else {
                    agregarLineaArchivo(f, t); // aqui se agrega texto al archivo de la carpeta ft
                }
                break;
            case 7:
                if(archivoSalida.is_open()){
                    cout << "El archivo ya existe en {" << o << "}." << endl;
                } else {
                    procesarArchivo(i, o);
                }
                break;
            case 8:
                realizarAccion8(rutaOut, comandoPrepararDatos);
                break;
            case 9:
                if (archivoIndex.is_open()){
                    cerr << "El archivo ya existe en {" << rutaIndex << "}." << endl;
                } else {
                    realizarAccion9_10(rutaOut, comandoCrearIndice);
                }
                break;
            case 10:
                realizarAccion9_10(rutaOut, comandoBuscador);
                break;
        }
    } else {
        cout << "No tiene permiso para escoger la opcion " << eleccion << endl << endl;
    }
}

/*
Esta función se crea para validar que la opción 8 se ejecute solo una vez durante la ejecución del código, ya 
que si se selecciona más veces, se estaría escribiendo lo mismo en un archivo que ya esta creado, entonces para
evitar sobreescribir en los archivos de esa carpeta, se valida con el if si la carpeta esta vacía o no. Si es
primera vez que se selecciona la opción 8, significa que la carpeta esta vacia, entonces se llama al proceso 
externo. Si la carpeta no esta vacía significa que ya se ejecutó la opcion 8.
*/

void realizarAccion8(const string& rutaOut, const string& comando) {
    if (fs::is_directory(rutaOut)) {
        fs::directory_iterator it(rutaOut);
        if (it == fs::directory_iterator()) {
            system(comando.c_str());
        } else {
            cout << "No puede sobreescribir en los archivos de la carpeta {" << rutaOut << "}." << endl;
        }
    } else {
        cout << "La ruta no es una carpeta válida. Revise su archivo .env!!" << endl;
    }
}

/*
Esta función se creo para evitar repetir codigo en el case 9 y 10 del switch, ya que ambos casos se necesita
que la opción 8 se haya seleccionado previamente. Si la opción 8 ya fue seleccionada, entonces se llama al 
proceso externo con el comando correspondiente.
*/
void realizarAccion9_10(const string& rutaOut, const string& comando) {
    if (fs::is_directory(rutaOut)) {
        fs::directory_iterator it(rutaOut);
        if (it == fs::directory_iterator()) {
            cout << "Debe ejecutar la opción 8 primero!!" << endl;
        } else {
            system(comando.c_str());
        }
    } else {
        cout << "La ruta no es una carpeta válida. Revise su archivo .env!!" << endl;
    }
}

/*
Función creada para preguntarle al usuario que elección del menú desea y retornarla al while true del main.
*/
int obtenerEleccion() {
    int eleccion;
    cout << "Ingrese su eleccion: ";
    cin >> eleccion;
    cout << endl;
    return eleccion;
}

/*
Función que calcula la moda del vector, osea la opción 3.
*/
int calcularModa(const vector<int>& numeros) {
    vector<int> numerosOrdenados = numeros;
    sort(numerosOrdenados.begin(), numerosOrdenados.end());
    int moda = 0;
    int maxFrecuencia = 0;
    int currentFrecuencia = 1;

    for (size_t i = 1; i < numerosOrdenados.size(); i++) {
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