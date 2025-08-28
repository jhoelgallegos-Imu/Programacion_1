// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 28/08/2025
// Número de ejercicio: 24

#include <iostream>
using namespace std;

int main() {
    int menu=0;
    do
    {
        cout<<"Ingrese la opcion que quiera: "<<endl; //no sabia de que hacer el menu de opciones
        cout<<"1.-3 juegos mas vendidos / 2.- 3 peliculas mas taquilleras"<<endl;
        cout<<"3.-3 mejores series segun IMBD / 4.- Salir"<<endl;
        cin>>menu;
        switch (menu)
        {
        case 1:
            cout<<"1. Tetris 2. Minecraft 3.GTA V"<<endl;
            break;
        case 2:
            cout<<"1. Avatar (2009) 2. Avengers: Endgame (2019) 3.Avatar: El camino del agua (2022)"<<endl;
            break;
        case 3:
            cout<<"1. Breaking Bad 2. The Wire 3. Avatar: La leyenda de Aang"<<endl; //https://www.imdb.com/es/chart/toptv
            break;
        default:
        break;
        }
    } while (menu!=4);
    cout<<"Que tenga bonito dia";
return 0;
}