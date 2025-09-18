// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 18/09/2025
// Número de ejercicio: 9

#include <iostream>
#include <cstdlib>  
#include <ctime>
using namespace std;

int main () {
    srand(time(0));
    int n=0, antiguedad=0;
    float comision=0, Precomision=0 ,sueldo=0;
    cout<<"Cuantas vendedoras tiene la tienda de cosmeticos? "<<endl;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        antiguedad=(rand()%3)+1; // la antiguedad como no esta definida la de 1 a 3 annos
        switch (antiguedad)
        {
        case 1:
            sueldo+=2000;
            break;
        case 2:
            sueldo+=2500;
            break;
        case 3:
            sueldo+=3000;
            break;
        
        default:
            break;
        }
        int ProdVend=(rand() % 10)+1;
        for (int j = 1; j < ProdVend; j++)
        {
            float PrecProdc=(rand()%81)+20; //rango de precio de productos vendidos
            Precomision+=PrecProdc;
        }
    }
    comision=Precomision*0.10;
    sueldo+=comision;
    cout<<"Las comisiones en total serian igual a: "<<comision<<endl;
    cout<<"El sueldo total a pagar a "<<n<<" vendedoras/vendedores seria: "<<sueldo<<endl;
    return 0;
}