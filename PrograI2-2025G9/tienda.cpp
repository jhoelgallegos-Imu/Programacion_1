#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Clientes
{
    char CarnetIdentidad[10] = "00000000" ;
    char Nombre[31] = "---------------" ;
    char Apellido[31] = "---------------";
    bool membresia = false;
    int PuntosNintendo = 0;
    bool existe = true;
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
                cout << "Ingrese CI: ";
                cin.ignore();
                cin >> DatosPersonales.CarnetIdentidad;
                cout << "Ingrese Nombre: ";
                cin.getline(DatosPersonales.Nombre , 31);
                cout << "Ingrese Apellido: ";
                cin.getline(DatosPersonales.Apellido , 31);
                cout << "Tiene membresia? 1)Si 2)No: ";
                cin >> r;
                DatosPersonales.membresia = (r == 1);
                DatosPersonales.existe = true;
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
            system("cls");
            cout<<"==========MYNINTENDOSTORE=========="<<endl
                <<"-----------------------------------"<<endl
                <<"| Tipo:\t\t|Cantidad: \t|Precio:"<<endl;
            for (int  i = 0; i < n; i++)
            {
            cout<<"| "<<FacturaTemp[i].Tipo_precio<<"\t\t| "<<FacturaTemp[i].cantidad<<"\t\t|"<<FacturaTemp[i].Tipo_precio<<endl;
            }
            cout<<"-----------------------------------"<<endl
            <<"|N: "<<FacturaTemp[0].persona.Nombre<<"\t|A: "<<FacturaTemp[0].persona.Apellido<<"\t|CI: "<<FacturaTemp[0].persona.CarnetIdentidad<<" "<<endl
            <<"-----------------------------------"<<endl;
            cout<<"                                   |Total="<<totalfinal*3.12<<endl;
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
    do {
        cout<<"----------------Seleccione la opcion que quiera ejecutar "<<endl
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
            GuardarCliente(DatosPersonales);
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