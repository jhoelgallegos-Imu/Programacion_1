#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Fecha
{
    int mes = 0;
    int dia = 0;
    int anio = 0;
};

struct Clientes
{
    char CarnetIdentidad[10] = "00000000" ;
    char Nombre[31] ;
    char Apellido[31];
    bool membresia = false;
    int PuntosNintendo = 0;
};

struct Compra
{
    int Tipo_precio;
    int cantidad;
    bool descuent0 = false;
    Clientes persona;
};

void BarraDeCarga() {
    const int total = 30;   
    cout << "\nCargando...\n";
    for (int i = 0; i <= total; i++) {
        cout << "\r[";
        for (int j = 0; j < i; j++)
            cout << "#";
        for (int j = i; j < total; j++)
            cout << " ";
        cout << "] " << (i * 100 / total) << "%";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(80));
    }
    cout << "\n\n";
}

void GuardarCliente(const Clientes &c)
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

void CrearFactura(){
    vector <Compra> FacturaTemp;
    float totalfinal = 0;
    int option , r, n=0;
    do
    {
        cout<<"----------------Facturacion: Annadir Producto? 1) Si 2) No : R.-";
        cin>>option;
        cin.ignore();
        if (option==1)
        {
            Compra temp;
            cout<<"---------------------Ingrese el codigo del producto: ";
            cin>>temp.Tipo_precio;
            cout<<"---------------------Ingrese la cantidad: ";
            cin>>temp.cantidad;
            cout<<"---------------------Tiene descuento?: 1) si 2) no R.-";
            cin>>r;
            if (r==1)
            {
                temp.descuent0=true;
            }
            n++;
            totalfinal+=temp.cantidad;
            FacturaTemp.push_back(temp);
        }
    } while (option!=2);
        if (n>0)
        {
            cout<<"----------------Desea introducir datos? 1)Si 2) No  R: ";
            cin>>option;
            cin.ignore();
            if (option==1)
            {
                Clientes DatosPersonales;
                cout << "---------------------Ingrese CI: ";
                cin >> DatosPersonales.CarnetIdentidad;
                cout << "---------------------Ingrese Nombre: ";
                cin >> DatosPersonales.Nombre;
                cout << "---------------------Ingrese Apellido: ";
                cin >> DatosPersonales.Apellido;
                cout << "---------------------Tiene membresia? 1)Si 2)No R: ";
                cin >> r;
                if (r==1)
                {
                    DatosPersonales.membresia= true;
                }
                GuardarCliente(DatosPersonales);
                for (int i = 0; i < n; i++)
                {
                    FacturaTemp[i].persona = DatosPersonales ;  
                    FacturaTemp[i].persona.PuntosNintendo=n;
                }
            }
        }
    do
    {
        if (option==1)
        {
            system("cls");
            cout<<"==========MYNINTENDOSTORE=========="<<endl
                <<"-----------------------------------"<<endl
                <<"| Tipo:\t\t|Cantidad: \t|Precio:"<<endl;
            for (int  i = 0; i < n; i++)
            {
            cout<<"| "<<FacturaTemp[i].Tipo_precio<<"\t\t| "<<FacturaTemp[i].cantidad<<"\t\t|"<<FacturaTemp[i].Tipo_precio<<endl;
            }
            cout<<"                                     |Total="<<totalfinal*3.12<<endl;
        }
        cout<<"-----------------------------------"<<endl
            <<"Quiere imprimir esta factura? 1)si 2)no R.-";
        cin>>option;
        cin.ignore();
        if (option==1)
        {
            BarraDeCarga();
        }
        else if (option==2)
        {
            break;
        }
        
    } while (option!=1);
}

void Perfiles(){
    int option;
    do
    {
        cout<<"----------------Seleccione la opcion que quiera ejecutar "<<endl
            <<"\t1) Ver perfiles 2) Ver miembros 3)Modificar perfiles 0)salir";
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
                    cout << contador++ << ") CI: " << c.CarnetIdentidad<< "| Nombre: " << c.Nombre<< "\t| Apellido: " << c.Apellido<< "\t| Membresia: " << (c.membresia ? "Si" : "No")<< "\t| Puntos: " << c.PuntosNintendo << endl;
                }
                file.close();
                cout << "=========================\n";
                break;
            }
            case 2: { 
                ifstream file("NintendoClients.bin", ios::binary);
                if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
                Clientes c;
                int contador = 1;
                cout << "\n=== LISTA DE MIEMBROS ===\n";
                while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                    if(c.membresia) {
                        cout << contador++ << 
                        ") CI: " << c.CarnetIdentidad<< "\t| Nombre: " << c.Nombre<< "\t| Apellido: " << c.Apellido << "\t| Puntos: " << c.PuntosNintendo << endl;
                    }
                }
                file.close();
                cout << "=========================\n";
                break;
            }
            case 3: {
                char ci[10];
                cout << "Ingrese CI del cliente a modificar: ";
                cin >> ci;
                fstream file("NintendoClients.bin", ios::binary | ios::in | ios::out);
                if (!file) { cout << "No se pudo abrir NintendoClients.bin\n"; break; }
                Clientes c;
                bool encontrado = false;
                streampos pos;
                while(file.read(reinterpret_cast<char*>(&c), sizeof(Clientes))) {
                    if(strcmp(c.CarnetIdentidad, ci) == 0) {
                        encontrado = true;
                        pos = file.tellg();
                        break;
                    }
                }
                if(!encontrado) { cout << "Cliente no encontrado\n"; file.close(); break; }
                file.seekp(pos - static_cast<streamoff>(sizeof(Clientes)));
                int r;
                cout << "Ingrese nuevo Nombre: "; 
                cin >> c.Nombre;
                cout << "Ingrese nuevo Apellido: "; 
                cin >> c.Apellido;
                cout << "Tiene membresia? 1=Si 2=No: ";  
                cin >> r;
                c.membresia = (r == 1);
                cout << "Puntos Nintendo: "; cin >> c.PuntosNintendo;
                file.write(reinterpret_cast<char*>(&c), sizeof(Clientes));
                cout << "Cliente actualizado correctamente!\n";
                file.close();
                break;
            }
            case 0:
                cout << "Saliendo del menu de perfiles..."<<endl;
                break;
            default:
                cout << "Opcion no valida, intente de nuevo."<<endl;
        }
        system("pause");
        system("cls");
    } while (option!=0);
}

int main () {
    int option;
    do
    {
        system("cls");
        cout<<"------------------------------------------------------------"<<endl
            <<"\t SISTEMA DE ADMINISTRACION DE TIENDA "<<endl
            <<"------------------------------------------------------------"<<endl
            <<"1) Crear Factura 2) Perfiles de Clientes 0) Salir ";
        cin>>option;
        switch (option)
        {
        case 0:
            cout<<"Cerrando programa, volviendo al menu principal :D"<<endl;
            break;
        case 1:
            CrearFactura();
            break;
        case 2:
            Perfiles();
            break;
        case 3:
            cout<<"Opcion en desarrollo"<<endl;
            break;
        default:
            cout<<"Opcion no valida, por favor seleciones otra ";
        }
        system("pause");
    } while (option!=0);
    return 0;
}