#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "estructuras.h"
using namespace std;

void SaveCliente(const Clientes &c)
{
    ofstream file("NintendoClients.bin", ios::binary | ios::app);
    if (!file)
    {
        cout << "Error al abrir el archivo NintendoClients.bin\n";
        return;
    }
    file.write(reinterpret_cast<const char*>(&c), sizeof(Clientes));
    file.close();
    cout << "\n Cliente guardado en NintendoClients.bin\n";
}

int IniciarClientes () {
    int option;
    do {
        system("cls");
        cout<<"------------------------------------------------------------"<<endl
            <<"       SISTEMA DE ADMINISTRACION DE CLIENTES NINTENDO "<<endl
            <<"------------------------------------------------------------"<<endl
            <<"1) Ver perfiles 2) Ver miembros 3)Modificar perfiles 4) Eliminar perfiles"<<endl
            <<"5) Restaurar perfiles 6) Crear perfil 0)salir";
        cin>>option;
        cin.ignore();
        switch(option) {
        case 1: { 
            ifstream file("NintendoClients.bin", ios::binary);
            if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
            Clientes c;
            int contador = 1;
            cout << "\n=== LISTA DE CLIENTES ===\n";
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                if(c.existe) {  
                    cout << contador++ << ") CI: " << c.CarnetIdentidad
                         << "\t | Nombre: " << c.Nombre
                         << "\t | Apellido: " << c.Apellido
                         << "\t | Membresia: " << (c.membresia ? "Si" : "No")
                         << "\t | Puntos: " << c.PuntosNintendo << endl;
                }
            }
            file.close();
            break;
        }
        case 2: { 
            ifstream file("NintendoClients.bin", ios::binary);
            if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
            Clientes c;
            int contador = 1;
            cout << "\n=== LISTA DE MIEMBROS ===\n";
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                if(c.existe && c.membresia) { 
                    cout << contador++ << ") CI: " << c.CarnetIdentidad<< "\t | Nombre: " << c.Nombre<< "\t | Apellido: " << c.Apellido<< "\t | Puntos: " << c.PuntosNintendo << endl;
                }
            }
            file.close();
            break;
        }
        case 3: { 
            char ci[10];
            cout << "Ingrese CI del cliente a modificar: ";
            cin.getline(ci , 10);
            fstream file("NintendoClients.bin", ios::binary | ios::in | ios::out);
            if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
            Clientes c;
            streampos pos;
            bool encontrado = false;
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                if(c.existe && strcmp(c.CarnetIdentidad, ci) == 0) { // ✅
                    pos = file.tellg();
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado) { cout<<"Cliente no encontrado\n"; file.close(); break; }
            file.seekp(pos - static_cast<streamoff>(sizeof(Clientes)));
            int r;
            cout << "Ingrese nuevo Nombre: ";
            cin.ignore();
            cin.getline(c.Nombre, 31);
            cout << "Ingrese nuevo Apellido: ";
            cin.getline(c.Apellido, 31);
            cout << "Tiene membresia? 1=Si 2=No: "; 
            cin >> r;
            c.membresia = (r == 1);
            cout << "Puntos Nintendo: "; cin >> c.PuntosNintendo;
            file.write(reinterpret_cast<char*>(&c), sizeof(Clientes));
            file.close();
            cout << "Cliente actualizado correctamente!\n";
            break;
        }
        case 4: {
            char ci[10];
            cout << "Ingrese CI del cliente a eliminar: ";
            cin >> ci;
            fstream file("NintendoClients.bin", ios::binary | ios::in | ios::out);
            if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
            Clientes c;
            streampos pos;
            bool encontrado = false;
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                if(c.existe && strcmp(c.CarnetIdentidad, ci) == 0) { 
                    pos = file.tellg();
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado) { cout<<"Cliente no encontrado\n"; file.close(); break; }
            c.existe = false;
            file.seekp(pos - static_cast<streamoff>(sizeof(Clientes)));
            file.write(reinterpret_cast<char*>(&c), sizeof(Clientes));
            file.close();
            cout << "Cliente eliminado correctamente!\n";
            break;
        }
        case 5: { 
            char ci[10];
            cout << "Ingrese CI del cliente a restaurar: ";
            cin >> ci;
            fstream file("NintendoClients.bin", ios::binary | ios::in | ios::out);
            if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
            Clientes c;
            streampos pos;
            bool encontrado = false;
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                if(c.existe == false && strcmp(c.CarnetIdentidad, ci) == 0) { 
                    pos = file.tellg();
                    encontrado = true;
                    break;
                }
            }
            if(!encontrado) { cout<<"Cliente no encontrado o ya esta activo\n"; file.close(); break; }
            c.existe = true;  
            file.seekp(pos - static_cast<streamoff>(sizeof(Clientes)));
            file.write(reinterpret_cast<char*>(&c), sizeof(Clientes));
            file.close();
            cout << "Cliente restaurado correctamente!\n";
            break;
        }
        case 6: { 
            int r;
            Clientes DatosPersonales;
            cout << "Ingrese CI: ";
            cin.getline(DatosPersonales.CarnetIdentidad , 11);
            cout << "Ingrese Nombre: ";
            cin.getline(DatosPersonales.Nombre , 31);
            cout << "Ingrese Apellido: ";
            cin.getline(DatosPersonales.Apellido , 31);
            cout << "Tiene membresia? 1)Si 2)No: ";
            cin >> r;
            DatosPersonales.membresia = (r == 1);
            DatosPersonales.existe = true;
            SaveCliente(DatosPersonales);
            break;
        }
        case 0:
            cout << "Saliendo del menu de perfiles...\n";
            break;
        default:
            cout << "Opcion no valida\n";
        }
        system("pause");
        system("cls");
    } while(option != 0);
    return 0;
}