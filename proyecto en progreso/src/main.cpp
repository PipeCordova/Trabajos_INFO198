#include "../include/metodos.h"


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
    // perfiles = {{0,1,2,3,4,5,6,7}, {0,1,2,3,4},{0,1,4}}

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
            cout << linea << endl;
        }

        opc.eleccion = obtenerEleccion();

        if (opc.eleccion == 0) {
            break;
        } 
        if (opc.eleccion >= 8) {
            cout << "Opcion " << opc.eleccion << " aun no ha sido implementada!" << endl << endl;
        } else {
            ejecutarOpcion(opc);
        }

        cout << "Espere 5 segundos!!\n" << endl;
        this_thread::sleep_for(chrono::seconds(5)); // Esperar 5 segundos y se limpia la consola
        system("clear");
    }

    cout << "Trabajo terminado!!\n" << endl;
    return EXIT_SUCCESS;
}