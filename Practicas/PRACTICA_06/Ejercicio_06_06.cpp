// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 6
/* Problema planteado: Rango de calificaciones en un curso: Un maestro tiene N calificaciones de sus
estudiantes en un vector. Las calificaciones deben ser llenadas en forma aleatoria entre 0
y 100. Luego debe calcular el porcentaje de estudiantes en cada rango:
• 0-59 (Reprobado)
• 60-79 (Regular)
• 80-89 (Bueno)
• 90-100 (Excelente)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int min, int max){
    return rand() % (max - min) + min;
}

void MostrarPorcentaje(int r, int rg, int b, int ex, int n){
    cout << "Los reprobados son: " << (r*100.0)/n << "%" << endl;
    cout << "Los regulares estudiantes son: " << (rg*100.0)/n << "%" << endl;
    cout << "Los buenos estudiantes son: " << (b*100.0)/n << "%" << endl;
    cout << "Los excelentes estudiantes son: " << (ex*100.0)/n << "%" << endl;
}

int main () {
    srand(time(0));
    vector<int> notas;
    int n;
    int reprobado=0, regular=0, bueno=0, excelente=0; 
    cout<<"Ingrese la cantidad de notas que quisiera ingresar: "<<endl;
    cin>>n;
    cout<<"----------------------------------------"<<endl<<"Las calificaciones son: ";
    for (int i = 0; i < n; i++)
    {
        notas.push_back(random(0,100));
        cout<<notas[i]<<", ";
        if (notas[i]<=59)
        {
            reprobado++;
        }
        else if (notas[i]>=60 && notas[i]<=79)
        {
            regular++;
        }
        else if (notas[i]>=80 && notas[i]<=89)
        {
            bueno++;
        }
        else
        {
            excelente++;
        }
    }
    cout<<endl<<"--------------------------------------------"<<endl;
    MostrarPorcentaje(reprobado, regular, bueno, excelente, n);
    return 0;
}