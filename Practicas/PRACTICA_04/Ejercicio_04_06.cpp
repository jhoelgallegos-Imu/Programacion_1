// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 16/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;

int sumatoria(int n);
int main () {
    int num=0;
    bool val=true;
    cout<<"Ingrese un numero para saber si su sumatoria permanece a los numeros primos "<<endl;
    cin>>num;
    for (int i = 2; i <sumatoria(num); i++) //se divide con todos a exepcion de 1 y si mismo
    {
        if (sumatoria(num)%i == 0)
        {
            val=false;
            break;
        }
    }
    if (val==true)
    {
        cout<<"Su sumatoria es un numero primo: "<<sumatoria(num);
    }
    else
    {
        cout<<"Su sumatoria no es un numero primo: "<<sumatoria(num);
    }
    
    return 0;
}
int sumatoria(int n){
    int resultado=n*(n+1)/2;
    return resultado;
}