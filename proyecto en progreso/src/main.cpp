#include "../include/metodos.h"

/* 
Funcion principal, se encarga de obtener la entrada de argumentos, obtener el valor de las variables de
entorno, realizar validaciones necesarias, crear los comandos para luego llamar a los procesos externos y al 
final tener un while true que esta en constante ejecucion hasta que se selecciona la opcion 0 para salir del menú.
*/


int main(int argc, char *argv[]) {
    string u, v;
    int c;
    Opciones opc;
    while ((c = getopt(argc, argv, "u:v:f:t:i:o:")) != -1) {
        switch (c) {
            case 'u':
                u = optarg;
                break;
            case 'v':
                v = optarg;
                break;
            case 'f':
                opc.f = optarg;
                break;
            case 't':
                opc.t = optarg;
                break;
            case 'i':
                opc.i = optarg;
                break;
            case 'o':
                opc.o = optarg;
                break;
        }
    }

    if (algunParametroVacio(u, "-u") || algunParametroVacio(v, "-v") || algunParametroVacio(opc.f, "-f") ||
        algunParametroVacio(opc.t, "-t") || algunParametroVacio(opc.i, "-i") || 
        algunParametroVacio(opc.o, "-o")) {
        exit(EXIT_FAILURE);
    }

    string rutaPermisos = getenv("DB_PERMISOS");
    string rutaMenu = getenv("DB_MENU");
    string rutaPerfiles = getenv("DB_PERFILES_USUARIOS");


    string ext = getenv("EXTENTION");
    string rutaIn = getenv("PATH_FILES_IN");
    opc.rutaOut = getenv("PATH_FILES_OUT");

    string nThreads = getenv("AMOUNT_THREADS");
    int nHilos = stoi(nThreads); // aqui se paso a int el string con el numero de threads

    opc.rutaIndex = getenv("INVERTED_INDEX_FILE");


    string TopK = getenv("TOPK");
    int topK = stoi(TopK);
    
    bool veinteArchivos = !hayAlMenos20Archivos(rutaIn, ext);

    auto resultado = archivosCumplen1MB(rutaIn, ext);
    bool todosCumplen = !resultado.first; // todos los archivos de 1 MB
    vector<string> archivosNoCumplen = resultado.second;

    bool errorDetectado = false;

    if (nHilos <= 0 || nHilos > 10 || rutaIn == opc.rutaOut || veinteArchivos || todosCumplen || topK <= 4) {
        cerr << "\nError: ";
        if (nHilos <= 0) {
            cerr << "nThreads debe ser mayor o igual a 1!";
        } else if (nHilos > 10) {
            cerr << "nThreads no debe ser mayor a 10!";
        } else if ( rutaIn == opc.rutaOut){
            cerr << "PATH_FILES_IN y PATH_FILES_OUT no pueden ser iguales!";
        } else if (veinteArchivos) {
            cerr << "No hay al menos 20 archivos " << ext << " en la carpeta " << rutaIn << " !";
            errorDetectado = true;
        } else if (todosCumplen) {
            cout << "Para este programa 1 MB = 1.048.576 bytes es decir (1024 * 1024 bytes)";
            cout << "\nArchivos que no cumplen en la carpeta {" << rutaIn << "} son: ";
            for (const string& nombreArchivo : archivosNoCumplen) {
                cout << nombreArchivo << " ";
            }
            cout << endl;
            errorDetectado = true;
        } else {
            cerr << "Debe tener minimo 5 TOPK!!";
        }
        cout << "\n";
        if (!errorDetectado) {
            cerr << "Debe modificar la variable de entorno .env!!" << endl;
        }
        exit(EXIT_FAILURE);
    } 
    
    string rutaPrepararDatos = getenv("RUTA_PREPARAR_DATOS");
    string rutaCrearIndice = getenv("RUTA_CREAR_INDICE");
    string rutaBuscador = getenv("RUTA_BUSCADOR");

    opc.comandoPrepararDatos = rutaPrepararDatos + " " + ext + " " + rutaIn + " " + opc.rutaOut + " " + nThreads;
    opc.comandoCrearIndice = rutaCrearIndice + " " + opc.rutaIndex + " " + opc.rutaOut;
    opc.comandoBuscador = rutaBuscador + " " + opc.rutaIndex + " " + TopK;

    
    // Aqui se guarda string que corresponde al permiso del usuario, osea: admin, userGeneral, userCookie.
    string perfil = obtenerPermisosDesdeArchivo(rutaPermisos, u);

    opc.vectorEntrada = convertirlo(v); // Convertir a vector el "vector" v de la entrada.

    cout << "\n- Usuario: " << u << endl;
    cout << "- Perfil:" << perfil << endl << endl;

    vector<vector<int>> perfiles;
    for (int i = 1; i <= 3; i++) {
        vector<int> perfil = obtenerVectorDesdeLinea(i, rutaPerfiles);
        perfiles.push_back(perfil);
    }
    // perfiles = {{0,1,2,3,4,5,6,7,8,9,10}, {0,1,2,3,4},{0,1,4}}

    if (perfil == " admin") {
        opc.vectorPerfil = perfiles[0];
    }
    if (perfil == " userGeneral") {
        opc.vectorPerfil = perfiles[1];
    }
    if (perfil == " userRookie") {
        opc.vectorPerfil = perfiles[2];
    }
    
    while (true) {
        ifstream archivo(rutaMenu);
        opc.archivoTexto.open(opc.f);
        opc.archivoSalida.open(opc.o);


        cout << "Opciones disponibles:" << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << "\t" << linea << endl;
        }

        opc.eleccion = obtenerEleccion();

        if (opc.eleccion == 0) {
            break;
        } 
        if (opc.eleccion >= 11) {
            cerr << "Opcion " << opc.eleccion << " aun no ha sido implementada!" << endl << endl;
        } else {
            ejecutarOpcion(opc);
        }

        cout << "Espere 7 segundos!!\n" << endl;
        this_thread::sleep_for(chrono::seconds(7)); // Esperar 7 segundos y se limpia la consola
        system("clear");
    }  

    cout << "Si va a ejecutar de nuevo el programa, verifique lo siguiente:" << endl;
    cout << "\t1) El archivo {" << opc.o << "} NO debe existir." << endl;
    cout << "\t2) El archivo {" << opc.rutaIndex << "} NO debe existir." << endl;
    cout << "\t3) Carpeta en la ruta {" << opc.rutaOut << "} esté completamente vacía." << endl;
    cout << "\nTrabajo terminado!!\n" << endl;
    return EXIT_SUCCESS;
}