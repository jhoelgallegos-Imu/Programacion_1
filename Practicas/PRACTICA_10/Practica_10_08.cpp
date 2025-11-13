// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 8
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Contador {
    int lineas;
    int palabras;
    int caracteres;
};

void ContarArchivo(const char nombreArchivo[30], Contador &datos) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    string linea;
    datos.lineas = 0;
    datos.palabras = 0;
    datos.caracteres = 0;
    while (getline(archivo, linea)) {
        datos.lineas++;
        datos.caracteres += linea.length();
        bool enPalabra = false;
        for (char c : linea) {
            if (!isspace(c) && !enPalabra) {
                datos.palabras++;
                enPalabra = true;
            } else if (isspace(c)) {
                enPalabra = false;
            }
        }
    }
    archivo.close();
}

void MostrarResultados(const Contador &datos) { //menu para mostrar esteticamente los resultados
    cout << "=========================================" << endl;
    cout << "Total de lineas: " << datos.lineas << endl;
    cout << "Total de palabras: " << datos.palabras << endl;
    cout << "Total de caracteres: " << datos.caracteres << endl;
    cout << "=========================================" << endl;
}

int main() {
    Contador resultados;
    char nombreArchivo[30] = "ESTUDIANTES.txt";
    ContarArchivo(nombreArchivo, resultados);
    system("cls");
    MostrarResultados(resultados);
    return 0;
}
