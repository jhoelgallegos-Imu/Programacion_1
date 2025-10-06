// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 05/10/2025
// Número de ejercicio: 4
#include <iostream>
#include <cstdlib>  
#include <ctime>
#include <vector>
using namespace std;

void randomizer(vector<int>&v, int n){
    int r=0;
    for (int i = 0; i < n; i++)
    {
        r=(rand()%10)+1;
        v.push_back(r);
    }
}

void multiplicaciones(vector<int>&m, vector<int> c1, vector<int> c2, int n){
    int r=0;
    for (int i = 0; i < n; i++)
    {
        r= c1[i]*c2[i];
        m.push_back(r);
    }
    
}

int main () {
    srand(time(0));
    vector<int> cosa1;
    vector<int> cosa2;
    vector<int> multiplicacion;
    int n=0;
    cout<<"Ingrese la dimension que quiera que tenga los vectores: "<<endl;
    cin>>n;
    randomizer(cosa1, n);
    randomizer(cosa2, n);
    multiplicaciones(multiplicacion, cosa1, cosa2, n);
    for (int i = 0; i < n; i++)
    {
        cout<<cosa1[i]<<" x "<<cosa2[i]<< " = "<< multiplicacion[i] <<endl;
    }
    
    return 0;
}