// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 17/09/2025
// Número de ejercicio: 8
#include <iostream>
#include <cstdlib>  
#include <ctime>
using namespace std;

int main () {
    srand(time(0)); 
    int n=0;
    float IVA=0;
    float total=0;
    cout<<"Ingrese la cantidad de productos que quiera comprar"<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        float producto=(rand() % 31)+20; //se generan los productos en un rango de 20 a 50
        total += producto * 1.13;
        IVA+=producto*0.13;
    }
    cout<<"El total seria: "<<total<<endl;
    if (total>2500)
    {
        total = total * 0.95;
        cout<<"El total debido a la compra por mayor se reducira en 5% y ahora es: "<<total<<endl;
    }
    cout<<"El costo total al IVA seria: "<<IVA;
    return 0;
}