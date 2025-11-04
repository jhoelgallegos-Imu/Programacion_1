// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 04/11/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Empleado
{
    char nombre[60];
    int Id;
    float sueldo;
    int anios;
};

int SalarioMayor (vector<Empleado> chambeadores, float sal, int cant){
    int TotalSal=0;
    for (int i = 0; i < cant; i++)
    {
        if (chambeadores[i].sueldo > sal) //se recoren todos los salarios en busca de los que sean mayores
        {
            TotalSal++;
        }
    }
    return TotalSal;
}

float PromedioAntiguedad(vector<Empleado> chamba, int n) {
    int sum=0;
    for (int i = 0; i < n ; i++)
    {
        sum+=chamba[i].anios;
    }
    return sum/n;
}

int main () {
    int n, MasI, MenosI;
    float ValorSal;
    vector<Empleado> Empleados;
    cout<<"Ingrese la cantidad de empleados que quiera ingresar: ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n ; i++)
    {
        cout<<"=================================================================="<<endl;
        Empleado EmpleadoX;
        cout<<"Ingrese el nombre del empleado "<<i+1<<" :";
        cin.getline(EmpleadoX.nombre,60);
        cout<<"Ingrese el I.D. del empleado "<<i+1<<" :";
        cin>>EmpleadoX.Id;
        cout<<"Ingrese el sueldo del empleado "<<i+1<<" :";
        cin>>EmpleadoX.sueldo;
        cout<<"Ingrese la antiguedad (anios) del empleado "<<i+1<<" :";
        cin>>EmpleadoX.anios;
        cin.ignore();
        cout<<"=================================================================="<<endl;
        Empleados.push_back(EmpleadoX);
        system("cls");
    }
    cout<<"=================================================================="<<endl
    <<"Ingrese la cantidad de salario que quiera evaluar: ";
    cin>>ValorSal;
    cout<<"Existen un total de "<<SalarioMayor(Empleados, ValorSal, n)<<endl
    <<"=================================================================="<<endl;
    cout<<"El promedio de la antiguedad de todos los empleados es: "<<PromedioAntiguedad(Empleados, n)<<endl
    <<"==================================================================";
    return 0;
}