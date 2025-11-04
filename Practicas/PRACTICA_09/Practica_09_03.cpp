// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Estudiante
{
    int cedula;
    char Nombre[30];
    char apellido[60];
    int edad;
    char profesion[60];
    char lugar_nacimiento[30];
    char direccion[60];
    int celular;
};

void MostrarEstudiantes (vector<Estudiante> & estudiantes, int nro){ //cree una funcion para que el codigo main sea mas corto
    cout<<"=============================================================================================="<<endl;
    cout<<"\t Nombre completo de estudiante "<<nro+1<<": "<<estudiantes[nro].Nombre<<" "<<estudiantes[nro].apellido<<endl
    <<"\t Edad: "<<estudiantes[nro].edad<<" | Cedula de Identidad: "<<estudiantes[nro].cedula<<endl
    <<"\t Profesion: "<<estudiantes[nro].profesion<<" | Nacido/da en: "<<estudiantes[nro].lugar_nacimiento<<endl
    <<"\t Direccion de recinto: "<<estudiantes[nro].direccion<<" | Nro. de Celular: "<<estudiantes[nro].celular<<endl;
    cout<<"=============================================================================================="<<endl;
}

int main () {
    int n;
    vector<Estudiante> ListEstd ;
    cout<<"Ingrese la cantidad de alumnos de Programacion 1: ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout<<"=================================================================="<<endl;
        Estudiante estudianteI ;
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        cin.getline(estudianteI.Nombre,30);
        cout<<"Ingrese el apellido del Estudiante "<<i+1<<": ";
        cin.getline(estudianteI.apellido,60);
        cout<<"Ingrese el profesion del Estudiante "<<i+1<<": ";
        cin.getline(estudianteI.profesion,60);
        cout<<"Ingrese el lugar de nacimiento del Estudiante "<<i+1<<": ";
        cin.getline(estudianteI.lugar_nacimiento,30);
        cout<<"Ingrese la direccion del Estudiante "<<i+1<<": ";
        cin.getline(estudianteI.direccion,60);
        cout<<"Ingrese la edad del estudiante "<<i+1<<": ";
        cin>>estudianteI.edad;
        cout<<"Ingrese el celular del estudiante "<<i+1<<": ";
        cin>>estudianteI.celular;
        cout<<"Ingrese la cedula del estudiante "<<i+1<<": ";
        cin>>estudianteI.cedula;
        cin.ignore();
        cout<<"=================================================================="<<endl;
        ListEstd.push_back(estudianteI);
        system("cls");
    }
    for (int i = 0; i < n ; i++) //con esta opcion se recorren todos
    {
        MostrarEstudiantes(ListEstd, i);
        system("pause");   
        system("cls"); //use cls y pause para que el codigo quede mas refinado, tambien para poder ver a detalle la informacion de cada estudiante
    }
    /*int option;  //con esta opcion se puede seleccionar el estudiante que se desee
    do
    {
        cout<<"Ingrese el numero del estudiante que quiera ver "<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<" Est. "<<i+1<<" |";
        }
        cout<<"o presione 0 para salir "<<endl;
        cin>>option;
        if (option>=1)
        {
            MostrarEstudiantes(ListEstd, option-1);
            system("pause");
        }   
        system("cls");
    } while (option!=0);
    */
    return 0;
}