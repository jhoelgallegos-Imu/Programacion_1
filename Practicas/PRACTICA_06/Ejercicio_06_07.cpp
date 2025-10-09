// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 7
/* Problema planteado: Compresión de datos en una imagen en escala de grises: Dada una imagen en escala
de grises representada por un vector de N valores entre 0 y 255 (estos valores deben ser
generados aleatoriamente), agrupa los valores en segmentos de 10 unidades y muestra
cuántos píxeles hay en cada rango. */ 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int min, int max){ //genera aleatorios
    return rand() % (max - min + 1) + min;
}

void mostrar(vector<int> p,int inicio, int final){ //muestra la cantidad de x-y que se ingrese(0-9, 40-49, etc...)
    int n=0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] >= inicio && p[i] <= final)
        {
            n++;
        }
    }
    cout<<"El total de pizeles de: "<<inicio+1<<" - "<<final+1<<" es: "<<n<<" pixeles.";
}

int main () {
    vector<int> pixeles;
    int n;
    cout<<"Cuantos valores desea que tenga su imagen: "<<endl;
    cin>> n ;
    cout<<"-------------------------------------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        pixeles.push_back(random(0,255));
    }
    for (int i = 0; i <=25; i++)
    {
        if (i==25)
        {
            mostrar(pixeles, 250, 254);
        }
        else
        {
            mostrar(pixeles, i*10, 9+(10*i));
            cout<<endl;
        }
        cout<<"-------------------------------------------"<<endl;
    }
    
    srand(time(0));
    return 0;
}