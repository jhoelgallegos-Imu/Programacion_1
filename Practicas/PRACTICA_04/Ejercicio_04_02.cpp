// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 15/09/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;

const double pi = 3.1416;
double CalcularVolumen(double radio, double altura);
int main () {
    double r, h=10;
    cout<<"Ingrese el radio: "<<endl;
    cin>>r;
    do
    {
        cout<<"Ingrese la altura (minimo tiene que ser de 10): "<<endl;
        cin>>h;
    } while (h==10);
    
    cout<<"El volumen del cilindro es de: "<<CalcularVolumen(r,h)<<endl;
    return 0;
}

double CalcularVolumen(double radio, double altura){
    double vol;
    vol=pi*(radio*radio);
    vol=vol*altura;
    return vol;
}