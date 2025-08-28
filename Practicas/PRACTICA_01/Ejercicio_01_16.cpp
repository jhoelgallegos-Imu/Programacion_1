// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 16 

#include <iostream>
using namespace std;

int main() {
    int num = 0;
    bool primo = true; 
    int i = 2;
    cout << "Ingrese el numero que quiera verificar si es primo: "<<endl;
    cin >> num;

    if (num <= 1) 
    {
        cout << "El numero no es primo D:"; 
        return 0;
    }

    while (i < num) {
        if (num % i == 0)  //Hace que oase por todos los numeros, si alguien entra entinces "primo" pasa a ser falso ya que significa que el numero es divisible por mas de si mismo y uno
        {   
            primo = false;
            break; //hace que si para una vez por aqui esta parte se detenga y salte a la siguiente inmediatamente
        }
        i++;
    }

    if (primo)
        cout << "El numero es primo :D";
    else
        cout << "El numero no es primo D:";

    return 0;
}
