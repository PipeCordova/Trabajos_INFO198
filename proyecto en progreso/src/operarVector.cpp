#include "../include/metodos.h"


// Esto queda igual.
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