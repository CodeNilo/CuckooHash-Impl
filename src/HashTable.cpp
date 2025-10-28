#include "../include/HashTable.h"
#include <iostream>
using namespace std;

// INTEGRANTE 1: Constructor y métodos de verificación

// Constructor: reserva espacio e inicializa celdas vacías
HashTable::HashTable(int espacio)
    : HashTable_1(espacio, ""), HashTable_2(espacio, ""), tam(espacio) {}

// Verifica si la posición de la primera tabla está vacía
bool HashTable::estaVacio_Hashtable1(int pos) const {
    return (pos >= 0 && pos < tam) && HashTable_1[pos].empty();
}

// Verifica si la posición de la segunda tabla está vacía
bool HashTable::estaVacio_Hashtable2(int pos) const {
    return (pos >= 0 && pos < tam) && HashTable_2[pos].empty();
}


// INTEGRANTE 2: Métodos de inserción


// INTEGRANTE 3: Método de redimensionamiento
void HashTable::redimensionar(int nuevoTam) {
    if (nuevoTam <= 0) return;

    // Recolectar claves actuales
    vector<string> elementos;
    for (const auto &s : HashTable_1) if (!s.empty()) elementos.push_back(s);
    for (const auto &s : HashTable_2) if (!s.empty()) elementos.push_back(s);

    // Tablas nuevas
    vector<string> newHT1(nuevoTam, "");
    vector<string> newHT2(nuevoTam, "");

    // Intento de inserción estilo cuckoo con límite de kicks
    auto intentarInsertar = [&](const string &clave) -> bool {
        string cur = clave;
        int tabla = 1;
        int maxKicks = max(10, nuevoTam * 2); // seguridad mínima
        for (int k = 0; k < maxKicks; ++k) {
            if (tabla == 1) {
                int pos = firstHash(cur, nuevoTam);
                if (newHT1[pos].empty()) { newHT1[pos] = cur; return true; }
                swap(cur, newHT1[pos]);
                tabla = 2;
            } else {
                int pos = secondHash(cur, nuevoTam);
                if (newHT2[pos].empty()) { newHT2[pos] = cur; return true; }
                swap(cur, newHT2[pos]);
                tabla = 1;
            }
        }
        return false;
    };

    // Reinsertar todas las claves; si falla, aumentar tamaño y reintentar
    for (const auto &clave : elementos) {
        if (!intentarInsertar(clave)) {
            // Si la inserción falla incluso con la tabla más grande, doblamos y reintentamos
            redimensionar(nuevoTam * 2);
            return;
        }
    }

    // Reemplazar tablas y actualizar tamaño
    HashTable_1.swap(newHT1);
    HashTable_2.swap(newHT2);
    tam = nuevoTam;
}

int firstHash(string word, int size){
            int hash = 0;
            
            for(int i = 0; i < word.size(); i++){
                hash = hash + (word[i] * word[i]);
            }
            
            return hash % size;
        }
        
        int secondHash(string word, int size){
            int hash = 0;
            
            for(int i = 0; i < word.size(); i++){
                hash = hash + ((2 * word[i]) * (2 * word[i]));
            }
            
            return hash % size;
        }

void printTablaHash(){
        for(int i = 0; i < HashTable_1.size(); i++){
            cout << i << ")" <<HashTable_1[i] << "-";
        }
        cout << endl;
        
        for(int i = 0; i < HashTable_2.size(); i++){
            cout << i << ")" <<HashTable_2[i] << "-";
        }
        cout << endl;
    }