// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 9
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Mensaje {
    string texto;
    string textoCifrado;
};

char CifrarCaracter(char c, int desplazamiento) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        c = (c - base + desplazamiento) % 26 + base;
    }
    return c;
}

void CifrarMensaje(Mensaje &msg, int desplazamiento) {
    msg.textoCifrado = "";
    for (char c : msg.texto) {
        msg.textoCifrado += CifrarCaracter(c, desplazamiento);
    }
}

void LeerArchivo(Mensaje &msg, const char nombreArchivo[30]) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    string linea;
    msg.texto = "";
    while (getline(archivo, linea)) {
        msg.texto += linea + "\n";
    }
    archivo.close();
}

void GuardarArchivoCifrado(const Mensaje &msg, const char nombreArchivo[30]) { //despues de generar el cifrado se guarda en un nuevo txt
    ofstream archivo(nombreArchivo);
    archivo << msg.textoCifrado;
    archivo.close();
}

int main() {
    Mensaje mensaje;
    char archivoEntrada[30] = "mensaje.txt";
    char archivoSalida[30] = "mensaje_cifrado.txt";
    int desplazamiento = 3;
    LeerArchivo(mensaje, archivoEntrada);
    if (mensaje.texto.empty()) {
        cout << "El archivo esta vacio o no se pudo leer correctamente." << endl;
        return 0;
    }
    CifrarMensaje(mensaje, desplazamiento);
    GuardarArchivoCifrado(mensaje, archivoSalida);
    system("cls");
    cout << "============================================" << endl;
    cout << "Mensaje original:" << endl << mensaje.texto << endl;
    cout << "Mensaje cifrado:" << endl << mensaje.textoCifrado << endl;
    cout << "Archivo '" << archivoSalida << "' generado correctamente." << endl;
    cout << "============================================" << endl;
    return 0;
}