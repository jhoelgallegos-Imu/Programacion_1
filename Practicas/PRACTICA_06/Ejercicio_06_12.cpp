// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 12
/* Problema planteado: Escribe una función que reciba un texto y retorne verdadero o falso (Boolean) según
sean o no palíndromos.
Un Palíndromo es una palabra o expresión que es igual si se lee de izquierda a derecha
que de derecha a izquierda. NO se tienen en cuenta los espacios, signos de puntuación y
tildes.
Ejemplo: Ana lleva al oso la avellana.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void palindromos(string pal){
    string palin = "";
    string original = "";
    // crear versión sin espacios y en minúsculas
    for (int i = 0; i < pal.size(); i++){
        if (pal[i] != ' '){
            char c = tolower(pal[i]);
            original.push_back(c);
            palin.insert(palin.begin(), c); // construye invertido al mismo tiempo
        }
    }
    if (palin == original){
        cout << "Su palabra o frase es un palindromo :D " << endl;
    } else {
        cout << "Su palabra o frase no es un palindromo D:" << endl;
    }
}

int main () {
    string palabra;
    cout<<"Ingrese la palabra que quiera ver si es un palindromo: "<<endl;
    getline(cin, palabra);
    palindromos(palabra);
    return 0;
}