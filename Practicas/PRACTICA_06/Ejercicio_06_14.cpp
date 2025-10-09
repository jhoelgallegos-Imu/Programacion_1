// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 14
/* Problema planteado: Realizar el ejercicio de este video (Contando cada vocal en una frase):
https://www.youtube.com/watch?v=CuQzFZGqTP8 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ContarVocales(string frase){
    int a=0,e=0,i=0,o=0,u=0;
    char val ;
    for (int i = 0; i < frase.size() ; i++)
    {
        if (frase[i]>='A' && frase[i]<='Z') //para que cuente las mayusculas
        {
            val=frase[i]-32;
        }
        else
        {
            val=frase[i];
        }
        switch (val)
        {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        }
    }
    cout<<"Hay "<<a<<" a's en la oracion // Hay "<<e<<" e's en la oracion"<<endl<<
    "Hay "<<i<<" i's en la oracion // Hay "<<o<<" o's en la oracion"<<endl<<
    "Hay "<<u<<" u's en la oracion"<<endl;
}

int main () {
    string frase;
    cout<<"Ingrese la frase que quiera contar sus vocales: "<<endl;
    getline(cin, frase);
    cout<<"=----------------------------------------------="<<endl;
    ContarVocales(frase);
    return 0;
}