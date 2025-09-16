// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 16/09/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;

const float salario=6.189;
float tarifa(int time);
float extra(int tiempo);
int main () {
    int horas=0;
    cout<<"Ingrese las horas que haya trabajado: "<<endl;
    cin>>horas;
    cout<<"La tarifa total por sus horas de trabajo es de: "<<tarifa(horas)<<endl;
    if (horas>8)
    {
        cout<<"La bonificacion sera de: "<<extra(horas);
    }
    
    return 0;
}
float tarifa(int time){
    float money= time*salario;
    if (time>8)
    {
        money=8*salario;
    }
    return money;
}
float extra(int tiempo){
    tiempo-=8; //para solo calcular el tiempo extra y no todo el tiempo
    float money=tiempo*salario;
    return money;
}