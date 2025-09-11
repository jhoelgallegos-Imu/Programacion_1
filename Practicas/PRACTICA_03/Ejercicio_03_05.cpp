// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/09/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;

float PromPon(float a, float b, float c, float d);

int main () {
    srand(time(NULL));
    float nota1 = (rand() % 100) + 1;  
    float nota2 = (rand() % 100) + 1;
    float nota3 = (rand() % 100) + 1;
    float nota4 = (rand() % 100) + 1;
    cout<<nota1<<"-"<<nota2<<"-"<<nota3<<"-"<<nota4<<endl;
    cout<<"El promedio ponderado de las notas es: "<<PromPon(nota1,nota2,nota3,nota4);
    return 0;
}

float PromPon(float a, float b, float c, float d){
    float p1, p2, p3, p4;
    int sumatoria= a+b+c+d;
    p1= a/sumatoria; //no estuve del todo seguro de como asignarles algun peso a cada nota ;-;
    p2= b/sumatoria;
    p3= c/sumatoria;
    p4= d/sumatoria;
    float resultado=((a+p1)+(b+p2)+(c+p3)+(d+p4))/(p1+p2+p3+p4);
    return resultado;
}
