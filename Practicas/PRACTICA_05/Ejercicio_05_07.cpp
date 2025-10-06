// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 05/10/2025
// Número de ejercicio: 7
#include <iostream>
#include <vector>
using namespace std;

bool verificar (int n){ //se verifica que el numero sea positivo o negativo para cortar el bucle do while
    if (n>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main () {
    vector<int> vectorde10;
    int n=0, num;
    do
    {
        n+=1;
        cout<<"Ingrese un numero, es "<<n<<"/10 numeros"<<endl;
        cin>>num;
        if (verificar(num)==true)
        {
            vectorde10.push_back(num);
        }
        else
        {
            n=10;
        }
        
    } while (n!=10);
    cout<<"Su vector final es: ";
    for (int i = 0; i < vectorde10.size() ; i++)
    {
        cout<<" "<<vectorde10[i];
    }
    return 0;
}