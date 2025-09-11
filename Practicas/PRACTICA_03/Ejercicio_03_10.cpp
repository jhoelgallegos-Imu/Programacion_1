// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 10
#include <iostream>
using namespace std;

double calcularTarifa(double kmR);

int main () {
    double km=0;
    cout<<"Ingrese los kilometros recorrigos"<<endl;
    cin>>km;
    cout<<"La tarifa total es de: "<<calcularTarifa(km)<<endl;
    return 0;
}

double calcularTarifa(double kmR){
    int tarifa=0;
    tarifa= (kmR*2)+10;
    if (kmR>10)
    {
        tarifa-=(tarifa*0.10);
    }
    return tarifa;
}