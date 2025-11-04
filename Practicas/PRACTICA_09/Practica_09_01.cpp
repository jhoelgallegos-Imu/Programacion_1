// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int random(int min, int max){ 
    return rand() % (max - min + 1) + min;
}

struct Libro
{
    char titulo [30];
    char autor [40];
    int anio_publicacion;
    bool disponible;
};

int main () {
    srand(time(0));
    Libro bock1;
    cout<<"Ingrese el nombre del libro (30 caracteres): ";
    cin.getline(bock1.titulo,30);
    cout<<"Ingrese el autor del libro (40 caracteres): ";
    cin.getline(bock1.autor,40);
    cout<<"Ingrese el anio de publicacion: ";
    cin>>bock1.anio_publicacion;
    int temp = random(0,1); 
    temp==1 ? bock1.disponible=true : bock1.disponible=false ; // ya que solo es de una linea se puede usar esta forma para acortar un poco el codigo
    cout<<"======================================================================"<<endl
    <<"\t Titulo: "<< bock1.titulo<<" | Autor: "<<bock1.autor<<endl
    <<"\t Anio de publicacion: "<<bock1.anio_publicacion<<" | ";
    bock1.disponible == true ? cout<<"El libro esta disponible :D " : cout<<"El libro no esta disponible D:" ;
    return 0;
}