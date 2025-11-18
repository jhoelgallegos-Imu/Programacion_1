// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 18-11-2025
// Número de ejercicio: 1
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct student {
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct structNotas {
    char ci[10];
    char materia[30];
    int nota;
};

void Opcion1() {
    student nuevo;
    student est;
    bool existencia = false;
    cout<<"-----------Ingrese el C.I. : ";
    cin>>nuevo.ci;
    ifstream archivo("Estudiantes.bin", ios::binary); //luego de escribir el CI se abre el archivo y se analiza y compara para ver si hay alguno igual
    if (archivo) {
        while (archivo.read((char*)&est, sizeof(student))) {
            if (strcmp(est.ci, nuevo.ci) == 0) { //strcmp compara 2 cadenas, si son iguales da 0
                existencia = true;
                break; //al ver que si existe esto se rompe
            }
        }
        archivo.close();
    }
    if (existencia) {
        cout << "!!!! Error: Ya existe un estudiante con ese C.I. !!!!"<<endl; //y salta este mensaje
        return;
    }
    cout << "---------Ingrese nombres: ";
    cin.ignore();
    cin.getline(nuevo.nombres, 30);
    cout << "---------Ingrese apellidos: ";
    cin.getline(nuevo.apellidos, 30);
    ofstream out("Estudiantes.bin", ios::binary | ios::app);
    out.write((char*)&nuevo, sizeof(student));
    out.close();
    cout<<"===================== GUARDADO EXITOSAMENTE ===================="<<endl;
}

void Opcion2() {
    structNotas nuevo;
    bool existeEst = false;
    bool existeNotaDuplicada = false;  
    cout<<"-----------Ingrese el C.I. : ";
    cin>>nuevo.ci;
    ifstream estFile("Estudiantes.bin", ios::binary);
    student estTemp;
    if (estFile) {
        while (estFile.read((char*)&estTemp, sizeof(student))) {
            if (strcmp(estTemp.ci, nuevo.ci) == 0) { 
                existeEst = true;
                break;
            }
        }
    }
    estFile.close();
    if (!existeEst) { //lo mismo que antes, solo que esta vez se evalua para ver que SI exista un ci igual
        cout << "!!!! Error: No existe ningun estudiante con ese CI. !!!! " << endl;
        return;
    }
    cin.ignore();
    cout << "Ingrese la materia: ";
    cin.getline(nuevo.materia, 30);
    ifstream notaFile("Notas.bin", ios::binary);
    structNotas notaTemp;
    if (notaFile) {
        while (notaFile.read((char*)&notaTemp, sizeof(structNotas))) {
            if (strcmp(notaTemp.ci, nuevo.ci) == 0 &&
                strcmp(notaTemp.materia, nuevo.materia) == 0) {

                existeNotaDuplicada = true;
                break;
            }
        }
    }
    notaFile.close();
    if (existeNotaDuplicada) {
        cout << "Error: Ya existe una nota registrada para esa materia." << endl;
        return;
    }  
    cout << "Ingrese la nota (0-100): ";
    cin >> nuevo.nota;
    ofstream out("Notas.bin", ios::binary | ios::app);
    out.write((char*)&nuevo, sizeof(structNotas));
    out.close();
    cout<<"===================== GUARDADO EXITOSAMENTE ===================="<<endl;
}

void Opcion3() {
    ifstream estFile("Estudiantes.bin", ios::binary);
    ifstream notaFile("Notas.bin", ios::binary); //se habren ambos archivos, de las notas y estudiantes
    student est;
    structNotas nota;
    if (!estFile) { //por si el archivo esta vacio
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    system("cls");
    cout << "-------- Lista de estudiantes y sus notas --------" << endl;
    while (estFile.read((char*)&est, sizeof(student))) {
        cout << "\nCI: " << est.ci << endl;
        cout << "Nombres: " << est.nombres << endl;
        cout << "Apellidos: " << est.apellidos << endl;
        bool tieneNotas = false;
        notaFile.clear();     //se resetea si ya esta al final
        notaFile.seekg(0);      // regresa al principio del archivo
        while (notaFile.read((char*)&nota, sizeof(structNotas))) {
            if (strcmp(est.ci, nota.ci) == 0) { //compara ambos CI, y si son iguales muestra las notas con las materias
                tieneNotas = true;
                cout << " - " << nota.materia << ": " << nota.nota << endl;
            }
        }
        if (!tieneNotas) { //si no tiene notas registradas se aparece este mensaje
            cout << "   El estudiante no tiene notas registradas." << endl;
        }
        cout << "---------------------------------------------------" << endl;
    }
    estFile.close();
    notaFile.close();
}

int main() {
    int option;
    do
    {
        cout << "\t================= PROGRAMA =================" << endl
        <<"1) Ingreso de datos estudiantes 2)Ingreso de materias y notas"<<endl
        <<"3)Reportes y notas              0)Salir"<<endl;
        cin>>option;
        cin.ignore();
        switch (option)
        {
        case 1:
            system("cls");
            cout << "================= DATOS DE ESTUDIANTES =================" << endl;
            Opcion1(); //Funciones para que el main sea mas cortos, y al no devolver datos se quedan void
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "============== INGRESO DE MATERIAS/NOTAS ===============" << endl;
            Opcion2();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "==================== REPORTES/NOTAS ====================" << endl;
            Opcion3();
            system("pause");
            break;
        case 0:
            cout << "\t================= CERRANDO PROGRAMA =================" << endl
            <<" GRACIAS POR SU PREFERENCIA :D, que tenga un lindo dia "<<endl;
            system("pause");
            break;
        default:
            cout<<"!=!=!=!=!=!=!=!=!=!= OPCION INVALIDA !=!=!=!=!=!=!=!=!=!=!=!="<<endl;
            system("pause");
            break;
        }
        system("cls");
    } while (option != 0);
    return 0;
}