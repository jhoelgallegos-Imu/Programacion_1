// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 10
/* Problema planteado: Escribe un programa que elimine todos los dígitos de una cadena.
                 Entrada: "abc123def456"
                 Salida: "abcdef"                       */ 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void EliminarDigitos(string p){
    string nuevo;
    for (int i = 0; i < p.size(); i++)
    {
        if (!(p[i] >= '0' && p[i] <= '9')) 
        {
            nuevo += p[i]; 
        }
    }
    cout<<"La cadena sin digitos es: "<<nuevo;
}

int main () {
    string alfanumericos="";
    cout<<"Ingrese la combinacion de alfanumericos para eliminar los digitos: "<<endl;
    getline(cin, alfanumericos);
    cout<<"-----------------------------------------------------------------"<<endl;
    EliminarDigitos(alfanumericos);
    return 0;
}