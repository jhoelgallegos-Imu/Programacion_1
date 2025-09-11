// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 7
#include <iostream>
#include <ctime>
using namespace std;

int masde18, masde175;
int edades(int num, int &masde18); //Al enlasar las bariables lo hace facil para contarlos
int alturas(int n, int &masde18);

int main () {
    srand(time(NULL));
    int n;
    cout<<"Ingrese una cantidad de alumnos"<<endl;
    cin>>n;
    cout << "Edad media: " << edades(n, masde18) << ", Mayores de 18: " << masde18 << endl;
    cout << "Estatura media: " << alturas(n, masde175) << ", Mayores de 1.75m: " << masde175 << endl;
    return 0;
}

int edades(int num, int &masde18){
    int resultado=0;
    for (int i = 1; i <= num; i++)
    {
        int edad = (rand() % 35) + 1;
        resultado+=edad;
        if (edad>=18)
        {
            masde18+=1;
        }   
    }
    resultado=resultado/num;
    return resultado;
}

int alturas(int n, int &masde175) {
    int sumatoria=0;
    for (int i = 1; i <= n; i++)
    {
        int altura = (rand() % 81) + 120;
        sumatoria+=altura;
        if (altura>=175)
        {
            masde175+=1;
        }
    }
    sumatoria=sumatoria/n;
    return sumatoria;
}