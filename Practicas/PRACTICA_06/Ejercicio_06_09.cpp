// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 9
/* Problema planteado: Escribe un programa que invierta el orden de las palabras en una oración sin cambiar el
orden de los caracteres dentro de cada palabra.
• // Entrada: "Hola mundo desde C++"
• // Salida: "C++ desde mundo Hola"  */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ModoYoda(string ora){
    vector<string> palabras;
    string palabra = "";
    for (int i = 0; i < ora.size(); i++)
    {
        if (ora[i] == ' ') //si detecta una palabra la agrega
        {
            palabras.push_back(palabra);
            palabra = "";
        }
        else
        {
            palabra += ora[i];
        }
    }
    palabras.push_back(palabra);
    for (int i = palabras.size() - 1; i >= 0; i--) //recorre la palabra al revex
    {
        cout << palabras[i] << " ";
    }
}

int main () {
    string oracion=" ";
    cout<<"Ingrese una palabra para decirla como yoda: "<<endl;
    getline(cin, oracion);
    cout<<"------------------------------------------"<<endl;
    ModoYoda(oracion);
    return 0;
}