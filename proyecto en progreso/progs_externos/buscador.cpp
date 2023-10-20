/*
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
*/

/*
#include <filesystem> 
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
namespace fs = filesystem;


vector<pair<string, int>> separarVectorResults(string vectorResults);
unordered_map<string, vector<pair<string, int>>> makeUnorderedMap(string pathFile);

// El llamado seria ./buscador INVERTED_INDEX_FILE TOPK

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

    unordered_map<string, vector<pair<string, int>>> invertedIndex;
    invertedIndex = makeUnorderedMap(rutaFile);


    cout << "hola aqui en buscador!!" << endl;
    return 0;
}


unordered_map<string, vector<pair<string, int>>> makeUnorderedMap(string pathFile) {
    unordered_map<string, vector<pair<string, int>>> invertedIndex;
    ifstream inputFile(pathFile);
    string line;
    // line seria una linea del archivo .idx
    while (getline(inputFile, line)) {
        istringstream lineStream(line);
        string word, vectorResults;
        // Separo la linea en : y le doy los valores de word = palabra y vectorResults = vector
        while ((getline(lineStream, word, ':')) && (getline(lineStream, vectorResults, ':'))) {
            invertedIndex[word] = separarVectorResults(vectorResults);
        }
    }

    for (const auto& entry : invertedIndex) {
        cout << entry.first << ":";
        for (const auto& pair : entry.second) {
            cout << "(" << pair.first << "," << pair.second << ");";
        }
        cout << endl;
    }

    inputFile.close();
    return invertedIndex;
}

vector<pair<string, int>> separarVectorResults(string vectorResults) {
    vector<pair<string, int>> outputVector;
    // Le quito el ultimo ; que quedaba sobrando
    vectorResults = vectorResults.substr(0, vectorResults.size() - 1);
    istringstream lineStreamVector(vectorResults);
    string vector;
    while (getline(lineStreamVector, vector, ';')) {
        // Le quito los ( )
        vector = vector.substr(1, vector.size() - 2);
        istringstream lineStreamResult(vector);
        string file, amount;
        while ((getline(lineStreamResult, file, ',')) && (getline(lineStreamResult, amount, ','))) {
            outputVector.emplace_back(file, stoi(amount));
        }
    }
    return outputVector;

}

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <bits/stdc++.h> 

using namespace std;

vector<pair<string, int>> separarVectorResults(string vectorResults);
unordered_map<string, vector<pair<string, int>>>  makeUnorderedMap(string pathFile);


int main(int argc, char* argv[]) {
    system("clear");
    auto start = chrono::high_resolution_clock::now();
    unordered_map<string, vector<pair<string, int>>> invertedIndex;
    unordered_map<string, vector<pair<string, int>>> allSearchResults;
    unordered_map<string, vector<pair<string, int>>> goodSearchResults;
    if (argc < 3) {
        cerr << "No ingreso suficientes argumentos" << endl;
        return 1;
    }

    string rutaFile = argv[1]; // files/index/file.idx
    int topk = stoi(argv[2]); // 5

    invertedIndex = makeUnorderedMap(rutaFile);

    cout << "\tBUSCADOR BASADO EN INDICE INVERTIDO (" << getpid() << ")" << endl;
    cout << "\tLos TOP K documentos serán: " << topk << endl;

    // Creo la estructura de la busqueda
    string searchInput;
    cout << "\tEscriba texto a buscar: ";
    getline(cin, searchInput);
    istringstream inputStream(searchInput);
    // cout << searchInput << endl;
    string word;
    int searchInputSize = 0;

    while (getline(inputStream, word, ' ')) {
        searchInputSize++;
        if (invertedIndex.find(word) != invertedIndex.end()) {
            // Acceder al vector de pares asociado a la clave y recorrerlo
            for (const pair<string, int>& entry : invertedIndex[word]) {
                allSearchResults[entry.first].emplace_back(word, entry.second);
                // cout << entry.first << " " << word << " " << entry.second << endl;
            }
        }
        else {
            cout << "\tNo se encontro concidencias de la palabra: " << word << endl;
        }
    }

    // Paso todos los resultados que contengan la misma cant de palabras
    // Por ahora muestra solo los que tengan todas las palabras
    for (const auto& entry : allSearchResults) {
        int vectorSize = entry.second.size();
        if (vectorSize == searchInputSize) {
            goodSearchResults[entry.first] = entry.second;
        }
    }

    // Sumar las cantidades
    vector<pair<string, int>> endResults;
    cout << "\tRespuesta: " << endl;
    if (goodSearchResults.size() == 0) {
        cout << "\tNo existen coincidencias de todas las palabras en un solo archivo" << endl;

    }
    else {
        for (const auto& entry : goodSearchResults) {
            int sum = 0;
            const vector<pair<string, int>>& pairs = entry.second;
            for (const pair<string, int>& keyValue : pairs) {
                int value = keyValue.second;
                sum = sum + value;
            }
            endResults.emplace_back(entry.first, sum);
        }

        // Ver como funciona    
        std::sort(endResults.begin(), endResults.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
            });

        // Ahora, imprime los resultados ordenados.
        for (const pair<string, int>& result : endResults) {
            topk--;
            if (topk < 0) {
                break;
            }

            // Agregar para imprimir el vector de mayor a menor usando el int del pair y respetando el topk < 0
            string fileName = result.first;
            int value = result.second;
            cout << "\tArchivo: " << fileName << ", Cantidad: " << value << endl;
        }
    }

    // print vector

    // Print unordered map
    // for (const auto& entry : goodSearchResults) {
    //     cout << entry.first << ":";
    //     for (const auto& pair : entry.second) {
    //         cout << "(" << pair.first << "," << pair.second << ");";
    //     }
    //     cout << endl;
    // }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "\tTiempo de ejecucion " << duration << " ns" << endl;

    char sigue;
    cout << "\n\tDesea salir? (s/n): ";
    cin >> sigue;
    if (sigue == 's' || sigue == 'S') {
        return 0;
    }

}

unordered_map<string, vector<pair<string, int>>> makeUnorderedMap(string pathFile) {
    unordered_map<string, vector<pair<string, int>>> invertedIndex;
    ifstream inputFile(pathFile);
    string line;
    // line seria una linea del archivo .idx
    while (getline(inputFile, line)) {
        istringstream lineStream(line);
        string word, vectorResults;
        // Separo la linea en : y le doy los valores de word = palabra y vectorResults = vector
        while ((getline(lineStream, word, ':')) && (getline(lineStream, vectorResults, ':'))) {
            invertedIndex[word] = separarVectorResults(vectorResults);
        }
    }

    // for (const auto& entry : invertedIndex) {
    //     cout << entry.first << ":";
    //     for (const auto& pair : entry.second) {
    //         cout << "(" << pair.first << "," << pair.second << ");";
    //     }
    //     cout << endl;
    // }

    inputFile.close();
    return invertedIndex;
}

vector<pair<string, int>> separarVectorResults(string vectorResults) {
    vector<pair<string, int>> outputVector;
    // Le quito el ultimo ; que quedaba sobrando
    vectorResults = vectorResults.substr(0, vectorResults.size() - 1);
    istringstream lineStreamVector(vectorResults);
    string vector;
    while (getline(lineStreamVector, vector, ';')) {
        // Le quito los ( )
        vector = vector.substr(1, vector.size() - 2);
        istringstream lineStreamResult(vector);
        string file, amount;
        while ((getline(lineStreamResult, file, ',')) && (getline(lineStreamResult, amount, ','))) {
            outputVector.emplace_back(file, stoi(amount));
        }
    }
    return outputVector;

}