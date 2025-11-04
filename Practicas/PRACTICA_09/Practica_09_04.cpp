// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 04/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Empleado
{
    char nombre[60];
    char genero[15];
    float salario;
};

void MostrarEmpleado(vector<Empleado> & empleados, int nro){ 
    cout<<"\t Nombre: "<<empleados[nro].nombre<<" | Genero: "<<empleados[nro].genero<<endl
    <<"\t\t Salario: "<<empleados[nro].salario<<endl;
}

int main () {
    int n, MasI, MenosI;
    float SalMasBajo=21474836 , SalMasAlto=0;
    vector<Empleado> Empleados;
    cout<<"Ingrese la cantidad de empleados que quiera ingresar: ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n ; i++)
    {
        cout<<"=================================================================="<<endl;
        Empleado EmpleadoX;
        cout<<"Ingrese el nombre del empleado de la UCB "<<i+1<<" :";
        cin.getline(EmpleadoX.nombre,60);
        cout<<"Ingrese el genero del empleado de la UCB "<<i+1<<" :";
        cin.getline(EmpleadoX.genero,15);
        cout<<"Ingrese la salario del empleado de la UCB "<<i+1<<" :";
        cin>>EmpleadoX.salario;
        if (EmpleadoX.salario > SalMasAlto) //guardo las posiciones y reestablesco los valores del salario mas alto y bajo
        {
            MasI=i;
            SalMasAlto=EmpleadoX.salario;
        }
        else if (EmpleadoX.salario < SalMasBajo)
        {
            MenosI=i;
            SalMasBajo=EmpleadoX.salario;
        }
        cin.ignore();
        cout<<"=================================================================="<<endl;
        Empleados.push_back(EmpleadoX);
        system("cls");
    }
    cout<<"=================================================================="<<endl<<
    "\t El empleado con mayor salario en la UCB: "<<endl
    <<"=================================================================="<<endl;
    MostrarEmpleado(Empleados, MasI);
    cout<<"=================================================================="<<endl<<
    "\t El empleado con menor salario en la UCB: "<<endl
    <<"=================================================================="<<endl;
    MostrarEmpleado(Empleados, MenosI);
    return 0;
}