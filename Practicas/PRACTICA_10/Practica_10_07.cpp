// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 7
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

struct Estudiante {
    string nombre;
    vector<float> notas;
    float promedio;
};

void LeerArchivo(vector<Estudiante> &lista, const char nombreArchivo[30]) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Estudiante temp;
        ss >> temp.nombre;
        float nota;
        while (ss >> nota) {
            temp.notas.push_back(nota);
        }
        lista.push_back(temp);
    }
    archivo.close();
}

void CalcularPromedios(vector<Estudiante> &lista) {
    for (auto &e : lista) {
        float suma = 0;
        for (float n : e.notas) {
            suma += n;
        }
        if (!e.notas.empty()) {
            e.promedio = suma / e.notas.size();
        } else {
            e.promedio = 0;
        }
    }
}

void GuardarPromedios(const vector<Estudiante> &lista, const char nombreArchivo[30]) {
    ofstream archivo(nombreArchivo); //despues de generar los promedios lo guarda en un nuevo archivo de texto
    for (const auto &e : lista) {
        archivo << e.nombre << " " << e.promedio << endl;
    }
    archivo.close();
}

void MostrarPromedios(const vector<Estudiante> &lista) {
    cout << "\nListado de promedios:" << endl;
    for (const auto &e : lista) {
        cout << "\t" << e.nombre << ": " << e.promedio << endl;
    }
}

int main() {
    vector<Estudiante> estudiantes;
    char archivoEntrada[30] = "calificaciones.txt";
    char archivoSalida[30] = "promedios.txt";
    LeerArchivo(estudiantes, archivoEntrada);
    if (estudiantes.empty()) {
        cout << "El archivo esta vacio o no se pudo leer correctamente." << endl;
        return 0;
    }
    CalcularPromedios(estudiantes);
    GuardarPromedios(estudiantes, archivoSalida);
    system("cls");
    MostrarPromedios(estudiantes);
    cout << "\nSe ha generado el archivo '" << archivoSalida << "' con los promedios." << endl;
    return 0;
}
