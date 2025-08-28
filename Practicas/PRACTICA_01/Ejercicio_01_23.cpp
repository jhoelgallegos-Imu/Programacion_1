// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 23 

#include <iostream>
using namespace std;

int main() {
    int num=0;
    int inversa=0;
    cout<<"Ingrese un numero para ser volteado"<<endl;
    cin>>num;
    cout<<"El numero invertido es ";
    while (num!=0) // Despues de pensarlo me di cuenta que la mejor manera era imprimiendolo sin el endl ya que asi saldria como un numero entero apesar de que tecnicamente serian una parte
    {
        inversa=num%10;
        cout<<inversa;
        num=num/10;
    }
    
return 0;
}