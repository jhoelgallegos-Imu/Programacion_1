// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 20/10/2025
// Número de ejercicio: 1

#include <iostream>
using namespace std; 

int SumaDeDigitos(int n){
    if (n<10)
    {
        return n;
    }
    else
    {
        int ultimo = n % 10; //Guarda un digito y el resto se lo deja y para el proceso y se suma una y otra vez
        int resto = n / 10;       
        return ultimo + SumaDeDigitos(resto);
    }
}

int main() {
    int n;
    cout<<"Ingrese un numero positivo: "<<endl;
    cin>>n; 
    cout<<"La sumatoria de sus digitos es: "<<SumaDeDigitos(n);
    return 0;
}