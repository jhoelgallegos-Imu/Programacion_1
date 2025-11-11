// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
using namespace std;

void leerArchivo(const char nombreArchivo[30], int & contador) { //reeutilizo la funcion del anterior ejercicio
    ifstream archivo(nombreArchivo);
    char palabra[30];
    while (archivo >> palabra) {
        contador++;
    }
    archivo.close();
}

int main (){
    char nombreArchivo[30] = "Nombres.txt"; //se reemplaza el archivo de aqui nomas para usar otro
    int contador=0;
    leerArchivo(nombreArchivo, contador);
    cout<<"El archivo tiene: "<<contador<<" palabras";
    return 0;
}