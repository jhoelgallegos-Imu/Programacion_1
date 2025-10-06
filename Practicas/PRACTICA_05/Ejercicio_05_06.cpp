// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 05/10/2025
// Número de ejercicio: 6
#include <iostream>
#include <vector>
using namespace std;

bool calculo( vector<int> v1, vector<int> v2, vector<int> v3){
    int sum=0 , sumde3=0;
    for (int i = 0; i < 5; i++)
    {
        sum+=v1[i] + v2[i]; //se hace una suma de cada valor de v1 y v2 y tambien aparte de todos los de v3
        sumde3+=v3[i];
    }
    if ( sumde3==sum) // se comparan
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main () {
    vector<int> vector1;
    vector<int> vector2;
    vector<int> vector3;
    int n1,n2,n3;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Escribe el "<<i+1<<"/5 de su 1 vector";
        cin>>n1;
        vector1.push_back(n1);
        cout<<"Escribe el "<<i+1<<"/5 de su 2 vector";
        cin>>n2;
        vector2.push_back(n2);
        cout<<"Escribe el "<<i+1<<"/5 de su 3 vector";
        cin>>n3;
        vector3.push_back(n3);
    }
    if (calculo(vector1,vector2,vector3)==true)
    {
        cout<<"La suma del vector 1 y vector 2, es igual al vector 3";
    }
    else
    {
        cout<<"La suma del vector 1 y vector 2, es diferente al vector 3";
    }
    
    return 0;
}