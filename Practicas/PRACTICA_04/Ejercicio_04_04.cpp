// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 16/09/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;

double ConvertirCelciusAFahrenheit(double celcius);
double MayorTemperatura(double a, double b);
int main () {
    double c=0,x,y;
    cout<<"Ingrese la cantidad para hacer la conversion: "<<endl;
    cin>>c;
    cout<<"La cantidad convertida es igual a: "<<ConvertirCelciusAFahrenheit(c)<<endl;
    cout<<"Ingrese una cantidad para compararla: "<<endl;
    cin>>x;
    cout<<"Ingrese la cantidad a comparar: "<<endl;
    cin>>y;
    cout<<"El mayor es: ";
    if (MayorTemperatura(x,y)==1)
    {
        cout<<x;
    }
    else
    {
        cout<<y;
    }
    return 0;
}
double ConvertirCelciusAFahrenheit(double celcius){
    celcius=(celcius*9/5)+32;
    return celcius;
}
double MayorTemperatura(double a, double b) {
    if (a>b) //dependiendo de cual sea mayor regresara un numero o otro
    {
        return 1;
    }
    else
    {
        return 18;
    }
}