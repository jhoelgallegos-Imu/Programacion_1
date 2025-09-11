// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;

int Capicua(int num);

int main () {
    int num;
    cout<<"Ingrese un numero"<<endl;
    cin>>num;
    cout<<Capicua(num)<<endl;
    if (Capicua(num)==num)
    {
        cout<<"El numero es capicua";
    }
    else
    {
        cout<<"El numero no es capicua";
    }
    
    return 0;
}

int Capicua(int num) {
    int invertido=0;
    while (num != 0) { //con esta funcion se puede voltear facilmente el numero
        int digito = num % 10;
        invertido = invertido * 10 + digito;
        num /= 10;
    }
    return invertido;
}