#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
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

struct Objeto
{
    int codigo;
    int cantidad;
    float precio;
    char nombre[51];
    bool existe = true;
};

void GuardarObjeto(const Objeto &c)
{
    ofstream file("Inventario.bin", ios::binary | ios::app);
    if (!file)
    {
        cout << "Error al abrir el archivo Inventario.bin "<<endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(&c), sizeof(Objeto));
    file.close();
    cout << "\n Objeto guardado en Inventario.bin\n";
}

void Ventas(){
    int option;
    do
    {
        cout<<"----------------Facturacion: Annadir Producto? 1) Si 2) No : R.-";
        cin>>option;
        cin.ignore();
        if (option==1)
        {
            cout<<"productoaniadido"<<endl;
        }
    } while (option!=2);
        cout<<"Desea introducir datos? 1)Si 2) No "<<endl<<" R: ";
        cin>>option;
        cin.ignore();
        if (option==1)
        {
            
        }
}

void productos(){
    int option;
    do
    {
        system("cls");
        cout<<" ------------------------------- PRODUCTOS OPCIONES ------------------------------- "<<endl
        <<"1) Ver Inventario 2) Agregar al Inventario 3) Modificar inventario 4) eliminar del inventario 0)Salir | R: ";
        cin>>option;
        cin.ignore();
        switch (option)
        {
        case 0:
            cout<<"cerrando pestania... ";
            break;
        case 1:
            { 
            ifstream file("Inventario.bin", ios::binary);
            if (!file) { cout << "No se pudo abrir Inventario.bin\n"; break; }
            Objeto c;
            int contador = 1;
            cout << "\n=== INVENTARIO ===\n";
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Objeto))) {
                if(c.existe) {  
                    cout << contador++ << ") Nombre: " << c.nombre
                         << "    \t | Precio: " << c.precio
                         << "    \t | Cantidad: " << c.cantidad
                         << "    \t | Codigo: " << c.codigo << endl;
                }
            }
            file.close();
            break;
            }
        case 2:{ 
            int r;
            Objeto NuevoObjeto;
            cout << "Ingrese el nombre: ";
            cin.getline(NuevoObjeto.nombre , 51);
            cout << "Ingrese la codigo: ";
            cin >> NuevoObjeto.codigo;
            cout << "Ingrese el precio $$$: ";
            cin >> NuevoObjeto.precio;
            cout << "Ingrese la cantidad: ";
            cin >> NuevoObjeto.cantidad;
            GuardarObjeto(NuevoObjeto);
            break;
            }
        case 3: {
            int op;
            cout << "Modificar producto por: 1) Codigo 2) Nombre | R: ";
            cin >> op;
            cin.ignore();
            fstream file("Inventario.bin", ios::binary | ios::in | ios::out);
            if (!file) {
                cout << "No se pudo abrir Inventario.bin\n";
                break;
            }
            Objeto o;
            streampos pos;
            bool encontrado = false;
            if (op == 1) { 
                int code;
                cout << "Ingrese el codigo: ";
                cin >> code;
                cin.ignore();
                while (file.read(reinterpret_cast<char*>(&o), sizeof(Objeto))) {
                    if (o.existe && o.codigo == code) {
                        pos = file.tellg();
                        encontrado = true;
                        break;
                    }
                }
            }
            else if (op == 2) { 
                char nombreBuscar[51];
                cout << "Ingrese el nombre: ";
                cin.getline(nombreBuscar, 51);
                while (file.read(reinterpret_cast<char*>(&o), sizeof(Objeto))) {
                    if (o.existe && strcmp(o.nombre, nombreBuscar) == 0) {
                        pos = file.tellg();
                        encontrado = true;
                        break;
                    }
                }
            }
            if (!encontrado) {
                cout << "Producto no encontrado\n";
                file.close();
                break;
            }
            file.seekp(pos - static_cast<streamoff>(sizeof(Objeto)));
            cout << "Nuevo nombre: ";
            cin.getline(o.nombre, 51);
            cout << "Nuevo precio: ";
            cin >> o.precio;
            cout << "Nueva cantidad: ";
            cin >> o.cantidad;
            file.write(reinterpret_cast<char*>(&o), sizeof(Objeto));
            file.close();
            cout << "Producto modificado correctamente "<<endl;
            break;
        }
        case 4: {
            int code;
            cout << "Ingrese el codigo del producto a eliminar: ";
            cin >> code;
            fstream file("Inventario.bin", ios::binary | ios::in | ios::out);
            if (!file) { 
                cout << "No se pudo abrir NintendoObjetos.bin\n"; 
                break; 
            }
            Objeto o;
            streampos pos;
            bool encontrado = false;
            while (file.read(reinterpret_cast<char*>(&o), sizeof(Objeto))) {
                if (o.existe && o.codigo == code) {
                    pos = file.tellg();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Producto no encontrado\n";
                file.close();
                break;
            }
            o.existe = false;
            file.seekp(pos - static_cast<streamoff>(sizeof(Objeto)));
            file.write(reinterpret_cast<char*>(&o), sizeof(Objeto));
            file.close();
            cout << "Producto eliminado correctamente! D:"<<endl;
            break;
        }
        default:
            cout<<"Opcion no valida, vuelva a intentarlo por favor ;-; "<<endl;
            break;
        }
        system("pause");
    } while (option!=0);
}

int main () {
    int option;
    do
    {
        system("cls");
        cout<<"------------------------------------------------------------"<<endl
            <<"       SISTEMA DE ADMINISTRACION DE INVENTARIO/VENTAS "<<endl
            <<"------------------------------------------------------------"<<endl
            <<"1) Ventas 2) Productos 0) Salir | R: ";
        cin>>option;
        switch (option)
        {
        case 1:
            Ventas();
            break;
        case 2:
            productos();
            break;
        default:
            cout<<"Opcion no valida, por favor seleciones otra ";
            break;
        }
        system("pause");
    } while (option!=0);
    return 0;
}