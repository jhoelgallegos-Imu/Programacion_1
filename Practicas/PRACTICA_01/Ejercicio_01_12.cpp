// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 26/08/2025
// Número de ejercicio: 12

#include <iostream>
using namespace std;

int main() {
    int num=0;
    int valid=0;
    do
    {
        cout<<"Ingrese un numero (1-5)"<<endl;
        cin>>num;
        valid==1;
        if (num>=1 && num<=5){
            cout<<"gracias";
            valid+=1;
        }
        else
        {
            cout<<"Ingrese un valor valido"<<endl;
        }
        
    } while (valid!=1);
return 0;
}