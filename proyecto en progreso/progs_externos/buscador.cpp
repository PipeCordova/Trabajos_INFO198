#include <iostream>
#include <string>
#include <filesystem> 
#include <fstream>

using namespace std;
namespace fs = filesystem;

// el llamado seria ./buscador INVERTED_INDEX_FILE TOPK

int main(int argc, char *argv[]){
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <INVERTED_INDEX_FILE> <TOPK>" << endl;
        exit(EXIT_FAILURE);
    }
    
    string rutaFile = argv[1]; // files/index/file.idx
    int topK = stoi(argv[2]); // 5


    ifstream archivo(rutaFile);
    if(!archivo.is_open()){
        cerr << "\nEl archivo " << rutaFile << " debe existir!!" << endl;
        exit(EXIT_FAILURE);
    }


    cout << "hola aqui en buscador!!" << endl;
    return 0;
}
