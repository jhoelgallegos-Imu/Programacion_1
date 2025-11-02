#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
//estructuras con vectores

struct Estudiante
{
    int edad;
    char nombre[30];
    char apellido[30];
    int nota;
};

int main() {
    srand(time(0));
    Estudiante estudiante1;
    cout<<"Ingrese su nombre: ";
    cin.getline(estudiante1.nombre,30);
    cout<<"Ingrese su apellido: ";
    cin.getline(estudiante1.apellido,30);
    cout<<"Ingrese su edad: ";
    cin>>estudiante1.edad;
    estudiante1.nota= (rand()% 41)+60;
    cout<<" Nombre: "<<estudiante1.nombre
    <<" Apellido: "<<estudiante1.apellido<<endl
    <<" edad: "<<estudiante1.edad<<" Nota: "<<estudiante1.nota;
    return 0;
}

