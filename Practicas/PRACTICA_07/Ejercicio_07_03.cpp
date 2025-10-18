// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 18/10/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int GRandom(int p, int f){
    return rand() % (f - p + 1) + p;
}

int FilasLibres(vector<vector<char>> m, int f, int c ){ //escanea las filas y si detecta un zombie ya no la cuenta
    int FL=0;
    for (int i = 0; i < f; i++)
    {
        bool confirmacion=true;
        for (int j = 0; j < c; j++)
        {
            if (m[i][j]=='x')
            {
                confirmacion= false;
                break;
            }
        }
        if (confirmacion==true)
        {
            FL++;
        }
    }
    return FL;
}

int ColumnasLibres(vector<vector<char>> m, int f, int c ){ //escanea las columnas y si detecta un zombie ya no la cuenta
    int CL=0;
    for (int j = 0; j < c; j++)
    {
        bool confirmacion = true;
        for (int i = 0; i < f; i++)
        {
            if (m[i][j]=='x')
            {
                confirmacion= false;
                break;
            }
        }
        if (confirmacion==true)
        {
            CL++;
        }
    }
    return CL;
}

void Zombies(vector<vector<char>> m,vector<int>& ci, vector<int>& cj, int& zt, int f, int c){
    for (int i = 0; i < f ; i++)
    {
        for (int j = 0; j < c ; j++)
        {
            if (m[i][j]=='x')
            {
                ci.push_back(i+1);
                cj.push_back(j+1);
                zt++;
            }
            
        }
        
    }
    
}

bool SePuedeEntrar(vector<vector<char>> m, int f, int c){ //escanea la 1 fila en busca de zombies
    int zombies=0;
    for (int i = 0; i < c ; i++)
    {
        if (m[0][i]=='x')
        {
            zombies++;
        }
    }
    if (zombies>=2)
    {
        return false;
    }
    return true;
}

int main(){
    srand(time(0));
    int filas=GRandom(4,8) , columnas= GRandom(4,8), ZombiesTotales=0;
    vector<vector<char>> MapaDePrision(filas);
    vector<int> coordenadasI;
    vector<int> coordenadasJ;
    cout<<"\t a) Mapa de la Prision: \t"<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            int ZoL = GRandom(1, 10);
            if (ZoL >= 5)
                MapaDePrision[i].push_back('o'); 
            else
            {
                MapaDePrision[i].push_back('x');
            }
        }
    }
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << MapaDePrision[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"b) las filas sin zombies son: "<<FilasLibres(MapaDePrision, filas, columnas)
    <<" las columnas sin zombies son: "<<ColumnasLibres(MapaDePrision, filas, columnas)<<endl
    <<"c) Las coordenadas de los muertos vivientes son: "<<endl;
    Zombies(MapaDePrision, coordenadasI, coordenadasJ, ZombiesTotales, filas, columnas);
    for (int i = 0; i < coordenadasI.size(); i++)
    {
        cout<<"zombie "<<i+1<<" esta en ("<<coordenadasI[i]<<","<<coordenadasJ[i]<<")"<<endl;
    }
    cout<<"d) La cantidad total de zombies en toda la matriz es: "<<ZombiesTotales<<endl;
    if (SePuedeEntrar(MapaDePrision, filas, columnas)==false)
    {
        cout<<"e) No es posible entrar en la instalacion :( ";
    }
    else
    {
        cout<<"e) Es posible entrar en la instalacion :D ";
    }
    
    return 0;
}