#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
using namespace std;

class HashTable{
    private:
        vector<string> HashTable_1;
        vector<string> HashTable_2;

        int tam;
        const int limite = 20;
    public:

        HashTable(int espacio);

        bool estaVacio_Hashtable1(int pos);

        bool estaVacio_Hashtable2(int pos);

        void insertar(string palabra);

        void CuckoHash(int indice, string palabra);

        void resizeHashTables();

        int firstHash(string word, int size);

        int secondHash(string word, int size);

        void printTablaHash();
};

#endif
