// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 02/11/2025
// Número de ejercicio: 8

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Atleta {
    int Deporte;
    char nombre[30];
    int departamento;
    int medallas;
};

int random(int min, int max) { //la clasica funcion para generar numeros randoms
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0));
    vector<string> deportes = {"Tiro con arco", "Atletismo", "Boxeo", "Ciclismo", "Natación", "Esgrima"};
    vector<string> departamentos = {"Beni", "Chuquisaca", "Cochabamba", "La Paz", "Oruro", "Pando", "Potosí", "Santa Cruz", "Tarija"};
    int n;
    vector<Atleta> Atletas;
    cout << "Ingrese la cantidad de atletas registrados: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        Atleta AtletaX;
        cout << "Ingrese el nombre del atleta " << i + 1 << ": ";
        cin.getline(AtletaX.nombre, 30);
        AtletaX.Deporte = random(0, deportes.size() - 1);
        AtletaX.departamento = random(0, departamentos.size() - 1);
        AtletaX.medallas = random(0, 22);
        Atletas.push_back(AtletaX);
        system("cls");
    }
    cout << "================= LISTA DE ATLETAS =================" << endl;
    for (int i = 0; i < Atletas.size(); i++) {
        cout << i + 1 << ". " << Atletas[i].nombre
             << " | Deporte: " << deportes[Atletas[i].Deporte]
             << " | Departamento: " << departamentos[Atletas[i].departamento]
             << " | Medallas: " << Atletas[i].medallas << endl;
    }
    vector<int> medallero(departamentos.size(), 0);
    for (int i = 0; i < Atletas.size(); i++) {
        medallero[Atletas[i].departamento] += Atletas[i].medallas;
    }
    cout << "\n================= MEDALLERO FINAL =================" << endl;
    for (int i = 0; i < departamentos.size(); i++) {
        cout << departamentos[i] << ": " << medallero[i] << " medallas" << endl;
    }
    int maxMedallas = medallero[0];
    int depGanador = 0;
    for (int i = 1; i < medallero.size(); i++) {
        if (medallero[i] > maxMedallas) {
            maxMedallas = medallero[i];
            depGanador = i;
        }
    }

    cout << "\n El departamento ganador es: " 
         << departamentos[depGanador] 
         << " con " << maxMedallas << " medallas." << endl;

    return 0;
}
