// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 9

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

struct Alumno
{
    string nombre;
    float T1, T2, T3, T4, EF;
    float NF;
};

void MostrarAlumno(vector<Alumno> &alumnos, int nro) //menu para no repetir muchas veces el mismo codigo
{
    cout << "\tNombre: " << alumnos[nro].nombre << endl
         << "\tNotas parciales: " << alumnos[nro].T1 << ", " << alumnos[nro].T2 << ", " << alumnos[nro].T3 << ", " << alumnos[nro].T4 << endl
         << "\tExamen Final: " << alumnos[nro].EF << endl
         << "\tNota Final: " << alumnos[nro].NF << endl;
}

int main()
{
    int n;
    float suma = 0, maximo = 0, minimo = 999;
    vector<Alumno> Alumnos;

    cout << "Ingrese la cantidad de alumnos del curso: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cout << "==================================================================" << endl;
        Alumno AlumnoX;
        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        getline(cin, AlumnoX.nombre);
        cout << "Ingrese las notas T1, T2, T3, T4 separadas por espacio: ";
        cin >> AlumnoX.T1 >> AlumnoX.T2 >> AlumnoX.T3 >> AlumnoX.T4;
        cout << "Ingrese la nota del Examen Final (EF): ";
        cin >> AlumnoX.EF;

        float NP = (AlumnoX.T1 + AlumnoX.T2 + AlumnoX.T3 + AlumnoX.T4) / 4;
        AlumnoX.NF = 0.7 * NP + 0.3 * AlumnoX.EF;

        suma += AlumnoX.NF;
        if (AlumnoX.NF > maximo)
            maximo = AlumnoX.NF;
        if (AlumnoX.NF < minimo)
            minimo = AlumnoX.NF;

        cin.ignore();
        Alumnos.push_back(AlumnoX);
        system("cls");
    }

    cout << "===================== LISTA DE ALUMNOS =====================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "------------------------------------------------------------" << endl;
        MostrarAlumno(Alumnos, i);
        cout << "------------------------------------------------------------" << endl;
    }
    cout << "===================== RESULTADOS GENERALES =====================" << endl
    << "\tPromedio general: " << suma / n << endl
    << "\tNota máxima: " << maximo << endl
    << "\tNota mínima: " << minimo << endl
    << "==================================================================" << endl;
    system("pause");
    return 0;
}
