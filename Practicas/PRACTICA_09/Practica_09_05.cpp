// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

struct Pelicula
{
    string titulo;
    string director;
    int minutos;
    int anio_estreno;
    string genero;
};

void MostrarPelicula(vector<Pelicula> & pelis, int nro){ //se hace mas facil mostrar las caracteristicas con un menu void
    cout<<"\t Titulo: "<<pelis[nro].titulo<<endl
        <<"\t Director: "<<pelis[nro].director<<" | Genero: "<<pelis[nro].genero<<endl
        <<"\t Duracion: "<<pelis[nro].minutos<<" | Anio de Estreno: "<<pelis[nro].anio_estreno<<endl;
}

int main () {
    int n;
    string BuscaGenero, BuscaDirector;
    vector<Pelicula> Peliculas;
    cout<<"Ingrese la cantidad de Peliculas que quiera ingresar: ";
    cin>>n;
    cin.ignore(); 
    for (int i = 0; i < n ; i++)
    {
        cout<<"=================================================================="<<endl;
        Pelicula PeliculaX;
        cout<<"Ingrese el Titulo de la Pelicula "<<i+1<<": ";
        getline(cin, PeliculaX.titulo);
        cout<<"Ingrese el Director de la Pelicula "<<i+1<<": ";
        getline(cin, PeliculaX.director);
        cout<<"Ingrese el genero de la Pelicula "<<i+1<<": ";
        getline(cin, PeliculaX.genero);
        cout<<"Ingrese el tiempo (en minutos) de la pelicula "<<i+1<<": ";
        cin>>PeliculaX.minutos;
        cout<<"Ingrese el anio de estreno de la pelicula "<<i+1<<": ";
        cin>>PeliculaX.anio_estreno;
        cin.ignore(); 
        cout<<"=================================================================="<<endl;
        Peliculas.push_back(PeliculaX);
        system("cls");
    }
    cout<<"=================================================================="<<endl
        <<"\t   Ingrese el genero de peliculas que quiera buscar: "<<endl
        <<"=================================================================="<<endl;
    getline(cin, BuscaGenero);
    for (int i = 0; i < n ; i++)
    {
        if (BuscaGenero == Peliculas[i].genero)
        {
            cout<<"---------------------------------------------------------"<<endl;
            MostrarPelicula(Peliculas,i);
            cout<<"---------------------------------------------------------"<<endl;
        }
    }
    system("pause");
    system("cls");
    cout<<"=================================================================="<<endl
        <<"    Ingrese el director por el que quiera buscar las peliculas: "<<endl
        <<"=================================================================="<<endl;
    getline(cin, BuscaDirector);
    for (int i = 0; i < n ; i++)
    {
        if (BuscaDirector == Peliculas[i].director)
        {
            cout<<"---------------------------------------------------------"<<endl;
            MostrarPelicula(Peliculas,i);
            cout<<"---------------------------------------------------------"<<endl;
        }
    }
    system("pause");
    system("cls");
    return 0;
}
