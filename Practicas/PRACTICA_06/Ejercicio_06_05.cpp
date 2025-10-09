// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 5
/* Problema planteado: Intersección de dos listas de clientes: dos empresas tienen listas de clientes y quieren
saber cuántos clientes tienen en común. Escribe un programa que compare dos vectores
de nombres y muestre los clientes repetidos. */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CompararClientes(vector<string>c1,vector<string>c2){
    bool valid=false;
    cout<<"Los clientes en comun son: "<<endl;
    for (int i = 0; i < c2.size() ; i++)
    {
        for (int j = 0 ; j < c1.size() ; j++)
        {
            if (c1[i]==c2[j])
            {
                cout<<c1[i]<<", ";
                valid=true;
            }
        }
    }
    if (valid==false)
    {
        cout<<"Ninguo";
    }
    
}

void MostrarLista(vector<string>v,int n){
    cout<<"Lista de clientes "<<n<<":"<<endl;
    cout<<"--------------------------------------"<<endl;
    for (int i = 0; i < v.size() ; i++)
    {
        cout<<v[i]<<endl;
    }
    
}

int main () {
    vector<string> listaA={"Ana", "Luis", "Marta", "Sofia", "Carlos", "Diego", "Elena", "Jose"};
    vector<string> listaB={"Marta", "Diego", "Jose", "Valeria", "Pablo", "Laura", "Andres", "Ana"};
//    vector<string> listaB={"Pepe", "Ted", "Juan", "Valeria", "Pablo", "Laura", "Andres", "Wally"}; //esto es por si quiere ver que pasa si no hay ninguno compatible
    cout<<"-----------------------------------"<<endl;
    MostrarLista(listaA,1);
    cout<<"-----------------------------------"<<endl;
    MostrarLista(listaB,2);
    cout<<"-----------------------------------"<<endl;
    CompararClientes(listaA, listaB);
    return 0;
}