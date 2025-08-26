// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 24/08/2025
// Número de ejercicio: 11

#include <iostream>
using namespace std;

int main() {
    int mes=0;
    int valid=0;
    do
    {
        cout<<"Ingrese un mes (1-12)"<<endl;
        cin>>mes;
        valid==1;
        if (mes>=1 && mes<=12)
        {
            switch (mes)
            {
            case 1:
            cout<<"usted esta en enero";
            break;
            case 2:
            cout<<"usted esta en febrero";
            break;
            case 3:
            cout<<"usted esta en marzo";
            break;
            case 4:
            cout<<"usted esta en abril";
            break;
            case 5:
            cout<<"usted esta en mayo";
            break;
            case 6:
            cout<<"usted esta en junio";
            break;
            case 7:
            cout<<"usted esta en julio";
            break;
            case 8:
            cout<<"usted esta en agosto";
            break;
            case 9:
            cout<<"usted esta en septiembre";
            break;
            case 10:
            cout<<"usted esta en octubre";
            break;
            case 11:
            cout<<"usted esta en noviembre";
            break;
            case 12:
            cout<<"usted esta en diciembre";
            break; 
            }
        valid+=1;
        }
        else
        {
            cout<<"Ponga un mes valido"<<endl;
            valid==0;
        }
    } while (valid!=1); //Perdon por la forma de validacion pero es la que mejor me a funcionado sin crear un bucle infinito
return 0;
}