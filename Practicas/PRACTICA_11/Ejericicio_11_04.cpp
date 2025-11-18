// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 18-11-2025
// Número de ejercicio: 4
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Estudiante {
    char carnet[15];
    char nombres[30];
    char apellidos[30];
    char materia[40];
    int paralelo;
};

struct NotaHab {
    char carnet[15];
    char materia[40];
    int paralelo;
    float nota1;
    float nota2;
    float nota3;
};

void AdicionarEstudiante() {
    Estudiante e, temp;
    bool existe = false;

    cout << "Carnet: ";
    cin.getline(e.carnet, 15);

    ifstream r("ESTUDIANTES4.BIN", ios::binary);
    if (r) {
        while (r.read((char*)&temp, sizeof(temp))) {
            if (strcmp(temp.carnet, e.carnet) == 0) {
                existe = true;
                break;
            }
        }
    }
    r.close();

    if (existe) {
        cout << "Estudiante ya registrado." << endl;
        return;
    }

    cout << "Nombres: ";
    cin.getline(e.nombres, 30);
    cout << "Apellidos: ";
    cin.getline(e.apellidos, 30);
    cout << "Materia: ";
    cin.getline(e.materia, 40);
    cout << "Paralelo: ";
    cin >> e.paralelo;
    cin.ignore();

    ofstream w("ESTUDIANTES4.BIN", ios::binary | ios::app);
    w.write((char*)&e, sizeof(e));
    w.close();

    cout << "Estudiante registrado con exito." << endl;
}

void ListadoHabilitados() {
    Estudiante e;

    ifstream r("ESTUDIANTES4.BIN", ios::binary);
    if (!r) {
        cout << "No existen estudiantes." << endl;
        return;
    }

    cout << "CARNET | NOMBRES | APELLIDOS | MATERIA | PARALELO | NOTA HAB. | ESTADO" << endl;

    float sumaHabilitados = 0;
    int contHabilitados = 0;

    while (r.read((char*)&e, sizeof(e))) {
        NotaHab n;
        float notaFinal = 0;
        bool tieneNotas = false;
        bool habilitado = true;

        ifstream t("NOTAS4.TXT");
        while (t >> n.carnet >> n.materia >> n.paralelo >> n.nota1 >> n.nota2 >> n.nota3) {
            if (strcmp(n.carnet, e.carnet) == 0 &&
                strcmp(n.materia, e.materia) == 0 &&
                n.paralelo == e.paralelo) {

                notaFinal = n.nota1 + n.nota2 + n.nota3;
                tieneNotas = true;

                if (n.nota1 < 60 || n.nota2 < 60 || n.nota3 < 60)
                    habilitado = false;

                break;
            }
        }
        t.close();

        if (tieneNotas) {
            cout << e.carnet << "  " << e.nombres << "  " << e.apellidos << "  "
                 << e.materia << "  " << e.paralelo << "  "
                 << notaFinal << "  ";

            if (habilitado) {
                cout << "HABILITADO" << endl;
                sumaHabilitados += notaFinal;
                contHabilitados++;
            } else {
                cout << "NO HABILITADO, TIENE UNA NOTA < 60" << endl;
            }
        }
    }

    r.close();

    if (contHabilitados > 0) {
        float promedio = sumaHabilitados / contHabilitados;
        cout << "\nPROMEDIO DE NOTAS DE HABILITADOS: " << promedio << endl;
    } else {
        cout << "\nNo hay estudiantes habilitados." << endl;
    }
}

void EliminarEstudiante() {
    char buscar[15];
    Estudiante e;
    bool eliminado = false;

    cout << "Carnet a eliminar: ";
    cin.getline(buscar, 15);

    ifstream r("ESTUDIANTES4.BIN", ios::binary);
    if (!r) {
        cout << "No existe archivo." << endl;
        return;
    }

    ofstream w("TEMP4.BIN", ios::binary);

    while (r.read((char*)&e, sizeof(e))) {
        if (strcmp(e.carnet, buscar) == 0)
            eliminado = true;
        else
            w.write((char*)&e, sizeof(e));
    }

    r.close();
    w.close();

    remove("ESTUDIANTES4.BIN");
    rename("TEMP4.BIN", "ESTUDIANTES4.BIN");

    if (eliminado)
        cout << "Estudiante eliminado." << endl;
    else
        cout << "Carnet no encontrado." << endl;
}

void AdicionarNotas() {
    NotaHab n;

    cout << "Carnet: ";
    cin.getline(n.carnet, 15);
    cout << "Materia: ";
    cin.getline(n.materia, 40);
    cout << "Paralelo: ";
    cin >> n.paralelo;
    cout << "Nota 1: ";
    cin >> n.nota1;
    cout << "Nota 2: ";
    cin >> n.nota2;
    cout << "Nota 3: ";
    cin >> n.nota3;
    cin.ignore();

    ofstream w("NOTAS4.TXT", ios::app);
    w << n.carnet << " " << n.materia << " " << n.paralelo << " "
      << n.nota1 << " " << n.nota2 << " " << n.nota3 << endl;
    w.close();

    cout << "Notas registradas." << endl;
}

int main() {
    int op;

    do {
        cout << "========== MENU NOTAS UCB ==========" << endl;
        cout << "1. Adicionar Estudiante" << endl;
        cout << "2. Listado de Estudiantes Habilitados" << endl;
        cout << "3. Eliminar Estudiante" << endl;
        cout << "4. Adicionar Notas de Habilitacion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        system("cls");

        switch (op) {
        case 1:
            cout << "=== ADICIONAR ESTUDIANTE ===" << endl;
            AdicionarEstudiante();
            system("pause");
            break;
        case 2:
            cout << "=== LISTADO DE ESTUDIANTES HABILITADOS ===" << endl;
            ListadoHabilitados();
            system("pause");
            break;
        case 3:
            cout << "=== ELIMINAR ESTUDIANTE ===" << endl;
            EliminarEstudiante();
            system("pause");
            break;
        case 4:
            cout << "=== ADICIONAR NOTAS ===" << endl;
            AdicionarNotas();
            system("pause");
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            system("pause");
        }

        system("cls");

    } while (op != 0);

    return 0;
}
