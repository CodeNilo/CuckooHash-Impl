#include "../include/HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int espacio){
    HashTable_1.resize(espacio, "");
    HashTable_2.resize(espacio, "");
    tam = espacio;
}

bool HashTable::estaVacio_Hashtable1(int pos) {
    if (pos >= 0 && pos < tam && HashTable_1[pos] == "") {
        return true;
    }
        return false;
}

bool HashTable::estaVacio_Hashtable2(int pos) {
    if (pos >= 0 && pos < tam && HashTable_2[pos] == "") {
        return true;
    }
        return false;
}

void HashTable::insertar(string palabra){
    int indice = firstHash(palabra, tam);
    CuckooHash(indice,palabra);
}

void HashTable::CuckooHash(int indice, string palabra){
    if(estaVacio_Hashtable1(indice)){
        HashTable_1[indice] = palabra;
        return;
    } else {
        string aux = HashTable_1[indice];
        HashTable_1[indice] = palabra;

        int pos2;
        for(int i = 0; i < limite; i++){
            pos2 = secondHash(aux, tam);

            if(estaVacio_Hashtable2(pos2)){
                HashTable_2[pos2] = aux;
                return;
            } else {
                swap(aux, HashTable_2[pos2]);

                int pos1 = firstHash(aux, tam);
                if(estaVacio_Hashtable1(pos1)){
                    HashTable_1[pos1] = aux;
                    return;
                } else {
                    swap(aux, HashTable_1[pos1]);
                }
            }
        }

        cout << "No se pudo insertar después de " << limite << " reubicando..." <<endl;
        resizeHashTables();
        insertar(aux);
    }
}

void HashTable::resizeHashTables(){
    vector<string>elementos;
    elementos.reserve(HashTable_1.size() + HashTable_2.size());

    for (auto &s : HashTable_1) {
        if (s != "") elementos.push_back(s);
    }
    for (auto &s : HashTable_2) {
        if (s != "") elementos.push_back(s);
    }

    tam = tam * 2;

    HashTable_1.clear();
    HashTable_2.clear();
    HashTable_1.assign(tam,"");
    HashTable_2.assign(tam,"");

    for(auto palabra:elementos){
        insertar(palabra);
    }
}

int HashTable::firstHash(string word, int size){
    int hash = 0;

    for(int i = 0; i < word.size(); i++){
        hash = hash + (word[i] * word[i]);
    }

    return hash % size;
}

int HashTable::secondHash(string word, int size){
    int hash = 0;

    for(int i = 0; i < word.size(); i++){
        hash = hash + ((2 * word[i]) * (2 * word[i]));
    }

    return hash % size;
}

void HashTable::printTablaHash(){
    for(int i = 0; i < HashTable_1.size(); i++){
        cout << i << ")" <<HashTable_1[i] << "-";
    }
    cout << endl;

    for(int i = 0; i < HashTable_2.size(); i++){
        cout << i << ")" <<HashTable_2[i] << "-";
    }
    cout << endl;
}
