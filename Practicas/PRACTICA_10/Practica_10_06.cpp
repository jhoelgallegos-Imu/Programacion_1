// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 6
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Ciudad {
    string nombre;
    float temperatura;
};

void LeerArchivo(vector<Ciudad> &lista, const char nombreArchivo[30]) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {  //si el archivo no se puede abrir saltara este texto
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    Ciudad temp;
    while (archivo >> temp.nombre >> temp.temperatura) {
        lista.push_back(temp);
    }
    archivo.close();
}

void GenerarArchivoAltas(const vector<Ciudad> &lista, const char nombreArchivo[30], float limite) {
    ofstream archivo(nombreArchivo);
    for (const auto &c : lista) {
        if (c.temperatura > limite) {
            archivo << c.nombre << " " << c.temperatura << endl;
        }
    }
    archivo.close();
}

void MostrarCiudadesAltas(const vector<Ciudad> &lista, float limite) {
    cout << "\nCiudades con temperatura mayor a " << limite << "C:" << endl;
    for (const auto &c : lista) {
        if (c.temperatura > limite) {
            cout << "\t" << c.nombre << " -> " << c.temperatura << "C" << endl;
        }
    }
}

int main() {
    vector<Ciudad> ciudades;
    char nombreArchivo[30] = "temperaturas.txt";
    char salidaArchivo[30] = "altas_temperaturas.txt";
    float limite;
    LeerArchivo(ciudades, nombreArchivo);
    if (ciudades.empty()) {
        cout << "El archivo esta vacio o no se pudo leer correctamente." << endl;
        return 0;
    }
    cout << "Ingrese el limite de temperatura (C): ";
    cin >> limite;
    GenerarArchivoAltas(ciudades, salidaArchivo, limite);
    system("cls");
    MostrarCiudadesAltas(ciudades, limite);
    cout << "\nSe ha generado el archivo '" << salidaArchivo << "' con las ciudades filtradas." << endl;
    return 0;
}