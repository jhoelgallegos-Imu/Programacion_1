// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 13
/* Problema planteado: Crea una función que reciba un String de cualquier tipo y se encargue de poner en
mayúscula la primera letra de cada palabra.
- No se pueden utilizar operaciones del lenguaje que lo resuelvan directamente. */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

char aMayuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A'); // diferencia entre minúscula y mayúscula
    }
    return c;
}

// Función que pone en mayúscula la primera letra de cada palabra
string CapitalizarPalabras(string texto) {
    if (texto.empty()) return texto;
    texto[0] = aMayuscula(texto[0]); 
    for (int i = 1; i < texto.size(); i++) {
        if (texto[i-1] == ' ') {
            texto[i] = aMayuscula(texto[i]);
        }
    }
    return texto;
}

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);
    string resultado = CapitalizarPalabras(frase);
    cout << "Resultado: " << resultado << endl;
    return 0;
}