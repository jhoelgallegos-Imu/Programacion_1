// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;

float CelciusAFahrenheit(float grado);

int main () {
    float num;
    cout<<"Ingrese una cantidad de grados para hacer la conversion"<<endl;
    cin>>num;
    cout<<"Sus grados convertidos son: "<<CelciusAFahrenheit(num)<<"* F"<<endl;
    return 0;
}
float CelciusAFahrenheit(float grado){
    float faren;
    faren=(grado*9/5)+32;
    return faren;
}