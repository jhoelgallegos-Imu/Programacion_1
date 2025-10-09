// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 11
/* Problema planteado: Escribe un programa que divida una cadena en tokens (subcadenas) separadas por un
delimitador. Por ejemplo, dividir una oración en palabras.
// Entrada: "Esto,es,una,cadena,separada,por,comas", delimitador: ','
// Salida:
// Esto
// es
// una
// cadena
// separada
// por
// comas */ 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void separador(string ora, char sep){
    for (int i = 0; i < ora.size(); i++) //en esta parte si detecta el separador hace un salto de linea
    {
        if (ora[i]== sep)
        {
            cout<<endl;
        }
        else // si no detecta el separador imprime la palabra
        {
            cout<<ora[i];
        }
        
    }
    
}

int main () {
    string palabra;
    char separadores;
    cout<<"Ingrese le separador que quiera usar para la palabra"<<endl;
    cin>>separadores;
    cin.ignore();
    cout<<"-----------------------------------------------------"<<endl
    <<"Ingrese la palabra para dividirla con "<<separadores<<" :"<<endl;
    getline(cin, palabra);
    cout<<"-----------------------------------------------------"<<endl;
    separador(palabra, separadores);
    return 0;
}