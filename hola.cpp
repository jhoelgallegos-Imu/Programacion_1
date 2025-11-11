#include <iostream>
#include <fstream>
using namespace std;
//estructuras con vectores

int main() {
    ofstream archivo;
    archivo.open("Archivo.txt");
    archivo<<" hola mundo ";
    archivo.close();
    return 0;
}

