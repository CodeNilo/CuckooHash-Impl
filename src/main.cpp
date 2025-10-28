#include <iostream>
#include <vector>
#include <string>
#include "../include/HashTable.h"
using namespace std;

int main(){
    HashTable cuckoo(15);

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
        cuckoo.insertar(p);
        cuckoo.printTablaHash();
        cout << "--------------------------" << endl;
    }

    return 0;
}
