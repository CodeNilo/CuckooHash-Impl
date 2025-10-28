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

// INTEGRANTE 4: Método de impresión
