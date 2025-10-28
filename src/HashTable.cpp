#include "../include/HashTable.h"
#include <iostream>
using namespace std;

// INTEGRANTE 1: Constructor y métodos de verificación


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
