// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 22/08/2025
// Número de ejercicio: 6

#include <iostream>
using namespace std;

int main() {
    int numero=0;
    cout<<"Ingrese un numero para evaluar: "<<endl;
    cin>>numero;
    if (numero==0)         //la forma mas facil es usar if, elif y else, oeri igual se podrian usar otras formas como un swich
    {
        cout<<"El numero es 0."<<endl;
    }
    else if (numero>0)
    {
        cout<<"El numero es positivo."<<endl;
    }
    else
    {
        cout<<"El numero es negativo"<<endl;
    }
    return 0;
}