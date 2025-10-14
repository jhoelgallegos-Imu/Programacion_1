// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 14/10/2025
// Número de ejercicio: 1

#include <iostream>
#include <vector>
using namespace std;

void Cambiofila(vector<vector<int>>&m,int c, int f){
    cout<<"Su matriz original es: "<<endl;
    for (int i = 0; i < f; i++) {          
        for (int j = 0; j < c; j++) {      
            cout << m[i][j] << "\t";  
        }
        cout << endl;                      
    }
    cout<<"Su matriz cambiada es: "<<endl;
    for (int j = 0; j < c; j++) { //se imprime la ultima fila primero
        cout << m[f - 1][j] << "\t";
    }
    cout << endl;
    for (int i = 0; i < f - 1; i++) { //se imprimen las otras 2 filas
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> matris;
    int n, f, c;
    cout<<"Cuantas filas quiere que tenga su matriz? "<<endl;
    cin>>f;
    cout<<"Cuantas columnas quiere que tenga su matriz? "<<endl;
    cin>>c;
    for (int i = 0; i < f; i++)
    {
        vector<int> fila;
        for (int j = 0; j < c; j++)
        {
            cout<<"Ingrese el elemento "<<i+1<<" x "<<j+1<<endl;
            cin>>n;
            fila.push_back(n);
            system("cls");
        }
        matris.push_back(fila);
    }
    Cambiofila(matris, c, f);
    return 0;
}