#include "../include/metodos.h"


int main(int argc, char *argv[]) {
    string u, v, f, t, i, o;
    int c;
    while ((c = getopt(argc, argv, "u:v:f:t:i:o:")) != -1) {
        switch (c) {
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
            case 'i':
                i = optarg;
                break;
            case 'o':
                o = optarg;
                break;
        }
    }

    if (algunParametroVacio(u, "-u") || algunParametroVacio(v, "-v") || algunParametroVacio(f, "-f") ||
        algunParametroVacio(t, "-t") || algunParametroVacio(i, "-i") || algunParametroVacio(o, "-o")) {
        exit(EXIT_FAILURE);
    }

    string rutaPermisos = getenv("DB_PERMISOS");
    string rutaMenu = getenv("DB_MENU");
    string rutaPerfiles = getenv("DB_PERFILES_USUARIOS");

    
    // Aqui se guarda string que corresponde al permiso del usuario, osea: admin, userGeneral, userCookie.
    string perfil = obtenerPermisosDesdeArchivo(rutaPermisos, u);
    vector<int> vectorEntrada = convertirlo(v); // Convertir a vector el "vector" v de la entrada.


    cout << "\n- Usuario: " << u << endl;
    cout << "- Perfil:" << perfil << endl << endl;
    
    vector<int> admin = obtenerVectorDesdeLinea(1, rutaPerfiles);
    vector<int> userGeneral = obtenerVectorDesdeLinea(2, rutaPerfiles);
    vector<int> userRokie = obtenerVectorDesdeLinea(3, rutaPerfiles);


    while (true) {
        ifstream archivo(rutaMenu);
        ifstream archivoTexto(f);
        ifstream archivoSalida(o);

        cout << "Opciones disponibles:" << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        int eleccion = obtenerEleccion();

        if (eleccion == 0) {
            break;
        } 
        if (eleccion >= 8) {
            cout << "Opcion " << eleccion << " aun no ha sido implementada!" << endl << endl;
        } else { // si no es >= 8 entonces si o si esta entre 1 y 7
            if (perfil == " admin") {
                ejecutarOpcion(eleccion, admin, vectorEntrada, archivoTexto, f, t, i, o, archivoSalida);
            }
            if (perfil == " userGeneral") {
                ejecutarOpcion(eleccion, userGeneral, vectorEntrada, archivoTexto, f, t, i, o, archivoSalida);
            }
            if (perfil == " userRookie") {
                ejecutarOpcion(eleccion, userRokie, vectorEntrada, archivoTexto, f, t, i, o, archivoSalida);
            }
        }

        cout << "Espere 5 segundos!!\n" << endl;
        this_thread::sleep_for(chrono::seconds(5)); // Esperar 5 segundos y se limpia la consola
        system("clear");
    }

    // agregarElementosBD(rutaPermisos);
    cout << "Trabajo terminado!!\n" << endl;
    return EXIT_SUCCESS;
}