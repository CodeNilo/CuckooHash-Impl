#include <iostream>
#include <vector>
#include <string>
#include "../include/HashTable.h"
using namespace std;

int main(){
    HashTable cucko(15);

    vector<string> palabras = {
        "computadora",
        "programacion",
        "algoritmo",
        "estructura",
        "hashing",
        "cuckoo",
        "diccionario",
        "funcion",
        "variable",
        "compilador",
        "software",
        "hardware",
        "debugging",
        "memoria",
        "sintaxis",
        "enlace",
        "optimizacion"
    };

    for (auto &p : palabras){
        cout << "Insertando: " << p << endl;
        cucko.insertar(p);
        cucko.printTablaHash();
        cout << "--------------------------" << endl;
    }

    return 0;
}
