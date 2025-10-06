// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 01/10/2025
// Número de ejercicio: 3
#include <iostream>
#include <vector>
using namespace std;

int sumatoria(vector<int>N, int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+= N[i];
    }
    return sum;
}

int promedio(int sum, int n){
    return sum/n ;
}

void DesvPorValor(vector<int>&d, int n, int prom){
    int desv=0;
    desv=n-prom;
    d.push_back(desv);
    cout<<"la desviacion de: "<<n<<" del promedio es: "<<desv<<endl; //como se pide en el programa se muestra el numero y su varianza al lado
}

int varianzaTotal(vector<int>d, int n){
    int v=0;
    for (int i = 0; i < n; i++)
    {
        v+=d[i]*d[i]; //para no meter una libreria solo para una operacion lo hice de esta manera
    }
    return v/n;
}

int main () {
    vector<int> calificaciones;
    vector<int> desviaciones;
    int n=0, cal=0;
    cout<<"Cuantas calificaciones desea introducir? "<<endl;
    cin>>n;
    for (int i = 0; i < n ; i++)
    {
        cout<<"Ingrese la nota "<<i+1<<": "<<endl;
        cin>>cal;
        calificaciones.push_back(cal);
    }
    cout<<"La sumatoria de las calificaciones es: "<<sumatoria(calificaciones, n)<<endl;
    cout<<"El promedio de las calificaciones es: "<<promedio(sumatoria(calificaciones, n), n)<<endl;
    for (int i = 0; i < n ; i++)
    {
        DesvPorValor(desviaciones,calificaciones[i], promedio(sumatoria(calificaciones, n), n));
    }
    cout<<"La varianza total es de: "<<varianzaTotal(desviaciones, desviaciones.size());
    return 0;
}