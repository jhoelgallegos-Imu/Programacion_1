// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;

int dias(int anno, int mes);

int main () {
    int anno, mes;
    cout<<"Ingrese el anno"<<endl;
    cin>>anno;
    cout<<"Ingrese el mes"<<endl;
    cin>>mes;
    cout<<"Los dias que tiene el mes que selecciono son: "<<dias(anno,mes);
    return 0;
}

int dias(int anno, int mes){
    int resultado =0;
    switch (mes)
    {
    case 1:
        resultado=31;
        break;
    case 2: //Como el anno bisiesto solo afecta a febrero puse un if para cubrir ese parametro
        if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)){
            resultado=29;
        }
        else
        {
            resultado=28;
        }
        
        break;
    case 3:
        resultado=31;
        break;
    case 4:
        resultado=30;
        break;
    case 5:
        resultado=31;
        break;
    case 6:
        resultado=30;
        break;
    case 7:
        resultado=31;
        break;
    case 8:
        resultado=31;
        break;
    case 9:
        resultado=30;
        break;
    case 10:
        resultado=31;
        break;
    case 11:
        resultado=30;
        break;
    case 12:
        resultado=31;
        break;
    }
    return resultado;
}