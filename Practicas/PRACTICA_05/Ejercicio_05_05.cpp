// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 05/10/2025
// Número de ejercicio: 5
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

void unificacion(vector<int>&u, vector<int> c1, vector<int> c2, int n){
    for (int i = 0; i < n*2; i++)
    {
        u.push_back(c1[i]);
        u.push_back(c2[i]);
    }
    
}

int main () {
    srand(time(0));
    vector<int> cosa1;
    vector<int> cosa2;
    vector<int> uniones;
    int n=0;
    cout<<"Ingrese la dimencion que quiere que tengan sus vectores: "<<endl;
    cin>>n;
    randomizer(cosa1, n);
    randomizer(cosa2, n);
    unificacion(uniones, cosa1, cosa2, n);
    cout<<"El vector 1 es: ";
    for (int i = 0; i < n ; i++)
    {
        cout<<cosa1[i]<<" - ";
    }
    cout<<endl;
    cout<<"El vector 2 es: ";
    for (int i = 0; i < n ; i++)
    {
        cout<<cosa2[i]<<" - ";
    }
    cout<<endl;
    cout<<"El vector unificado es: ";
    for (int i = 0; i < n*2 ; i++) // se multiplica por 2 ya que la lista es el doble de grande
    {
        cout<<uniones[i]<<" - ";
    }
    return 0;
}