// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>
using namespace std;

struct Atleta
{
    char nombre [60];
    char pais [30];
    int edad ;
    int mejor_tiempo ;
};

void MostrarMejorResultado(vector<Atleta> atletas, int posicion){
    cout<<"\t El mejor tiempo es de: "<<atletas[posicion].nombre<<" | de: "<<atletas[posicion].pais<<endl
    <<"\t con el tiempo de: "<<atletas[posicion].mejor_tiempo<<" (seg.) | con la edad: "<<atletas[posicion].edad;
}

int main () {
    vector<Atleta> atletas;
    int n, ElMejorTiempo=7000, posicion; //puse 2 horas en segundos ya que no estoy del todo seguro cuanto seria un gran tiempo
    cout<<"Ingrese la cantidad de atletas de los que quiera ingresar los datos: ";
    cin>>n;
    cout<<"=================================================================="<<endl;
    cin.ignore();
    for (int i = 0; i < n ; i++)
    {
        Atleta atletaX;
        cout<<"Ingrese el nombre del atleta "<<i+1<<" :";
        cin.getline(atletaX.nombre,60);
        cout<<"Ingrese el pais del atleta "<<i+1<<" :";
        cin.getline(atletaX.pais,30);
        cout<<"Ingrese la edad del atleta "<<i+1<<" :";
        cin>>atletaX.edad;
        cout<<"Ingrese el mejor tiempo del atleta "<<i+1<<" :";
        cin>>atletaX.mejor_tiempo;
        cin.ignore();
        cout<<"=================================================================="<<endl;
        atletas.push_back(atletaX);
        if (atletaX.mejor_tiempo < ElMejorTiempo) //se guarda y se modifica el mejor tiempo
        {
            posicion=i;
            ElMejorTiempo= atletaX.mejor_tiempo ;
        }
        
    }
    MostrarMejorResultado(atletas, posicion);
    return 0;
}