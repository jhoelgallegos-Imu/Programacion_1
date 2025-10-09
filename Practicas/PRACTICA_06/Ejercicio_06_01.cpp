// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 7/10/2024
// Número de ejercicio: 1
// Problema planteado: Almacene en un arreglo las edades de varias personas (hasta ingresar un -1) y a partir
// de este arreglo determine la desviación típica.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

float DesviacionTipica(vector<int> edades, int tam, int prom){
    float DesTip=0;
    for (int i = 0; i < tam; i++)
    {
        DesTip+=pow(edades[i]-prom, 2);
    }
    DesTip/=tam;
    DesTip=sqrt(DesTip);
    return DesTip;
}
int main () {
    vector<int> edades;
    int n, prom=0, tam;
    do
    {
        cout<<"Ingrese una edad, si quiere dejar de ingresar -1 "<<endl;
        cin>>n;
        if (n!=-1)
        {
            edades.push_back(n);
        }
    } while (n!=-1);
    tam=edades.size();
    for (int i = 0; i < edades.size(); i++)
    {
        cout<<edades[i]<<"   ";
    }
    cout<<endl;
    for (int i = 0; i < edades.size(); i++)
    {
        prom+=edades[i];
    }
    prom/=tam;
    cout<<"La desviacion tipica de las edades es igual a: "<<DesviacionTipica(edades, tam, prom);
    return 0;
}