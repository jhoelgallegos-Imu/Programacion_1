// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 18/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int GRandom(int p, int f){
    return rand() % (f - p + 1) + p;
}

void MostrarTranspuesta(vector<vector<int>> m, int f, int c){ //esto solo muestra su transpuesta ya que no se pidio alguna operacion con esta
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < f; i++)
        {
            cout<<"\t"<<m[i][j];
        }
        cout<<endl;
    }
}

int main(){
    srand(time(0));
    int f = GRandom(1,4), c = GRandom(2,4);
    vector<vector<int>> matriz(f,vector<int>(c));
    cout<<"\t Matriz original: \t"<<endl<<" ============================================ "<<endl;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c ; j++)
        {
            matriz[i][j]=GRandom(1,10);
            cout<<"\t"<<matriz[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<"\t Matriz Transpuesta: \t"<<endl<<" ============================================ "<<endl;
    MostrarTranspuesta(matriz, f, c);
    return 0;
}