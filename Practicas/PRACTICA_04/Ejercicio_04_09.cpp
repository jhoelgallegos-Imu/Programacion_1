// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 15/09/2025
// Número de ejercicio: 9

#include <iostream>
#include <cstdlib>  
#include <ctime>
using namespace std;

int main () {
    srand(time(0));
    int n=0, antiguedad=0;
    float comision=0;
    cout<<"Cuantas vendedoras tiene la tienda de cosmeticos? "<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        antiguedad=(rand());
        int ProdVend=(rand() % 10);
    }
    
    
    return 0;
}