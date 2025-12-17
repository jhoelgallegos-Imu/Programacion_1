#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstring>
#include "estructuras.h"
using namespace std;

struct ProductoVendido {
    int codigo;
    int cantidadVendida;
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

void BuscarenInventario(int code) {
    fstream file("Inventario.bin", ios::in | ios::binary);
    if (!file) {
        cout << "No se pudo abrir Inventario.bin " << endl;
        return;  
    }
    Objeto o;
    bool encontrado = false;
    while (file.read(reinterpret_cast<char*>(&o), sizeof(Objeto))) {
        if (o.codigo == code) { 
            cout << " Producto: " << o.nombre << " Codigo: " << o.codigo << " Precio: " << o.precio ;
            encontrado = true;
            break;  
        }
    }
    if (!encontrado) {
        cout << "Producto con codigo " << code << " no encontrado." << endl;
    }
    file.close();  
}

void Ventas(){
    int option;
    do
    {
        system("cls");
        cout<<" ----------------------------------------------- "<<endl
            <<"                  VENTAS OPCIONES                "<<endl<<
              " ----------------------------------------------- "<<endl
        <<" 1) Productos vendidos 2) Producto Mas vendido 3) Producto menos vendido"<<endl
        <<" 0)Salir | R: ";
        cin>>option;
        cin.ignore();
        switch (option)
        {
        case 0:
            cout<<"cerrando pestania... ";
            break;
        case 1:
            {
                ifstream file("Ventas.bin", ios::binary);
                if (!file) {
                    cout << "No se pudo abrir el archivo de ventas.\n";
                    return;
                }
                Compra c;
                int contador = 1;
                cout << "\n\t\t=== VENTAS ===\n";
                while (file.read(reinterpret_cast<char*>(&c), sizeof(Compra))) {
                    if (c.Tipo_precio <= 0 || c.cantidad <= 0) {
                        cout << "Producto con codigo " << c.Tipo_precio << " tiene un codigo o cantidad invalido.\n";
                        continue; 
                    }
                    int codigos = c.Tipo_precio;
                    cout << "----------------------------------------------------------------------------------------------------" << endl
                        << contador++ << ") "; 
                    BuscarenInventario(codigos); 
                    cout << " Cantidad: " << c.cantidad 
                        << " Fecha: " << c.diadecompra.dia << "/" << c.diadecompra.mes << "/" << c.diadecompra.anio << endl;
                    cout << "Datos Nombre: " << c.persona.Nombre << " " << c.persona.Apellido
                        << " CI: " << c.persona.CarnetIdentidad << " Membresia: " << c.persona.membresia << endl;
                }
                file.close();
                break;
            }
        case 2: {
            fstream file("Ventas.bin", ios::in | ios::binary);
            if (!file) { 
                cout << "No se pudo abrir ventas.bin" << endl; 
                return;
            } 
            vector<ProductoVendido> ventasTotales;
            Compra c;
            while (file.read(reinterpret_cast<char*>(&c), sizeof(Compra))) 
            { 
                bool encontrado = false; 
                for (auto& venta : ventasTotales) 
                { 
                    if (venta.codigo == c.Tipo_precio) 
                    { 
                        venta.cantidadVendida += c.cantidad; 
                        encontrado = true; 
                        break; 
                    } 
                } 
                if (!encontrado) 
                { 
                    ventasTotales.push_back({c.Tipo_precio, c.cantidad});
                 } 
                } 
                file.close();
                int maxVentas = 0; 
                int codigoMasVendido = -1; 
                for (const auto& venta : ventasTotales) { 
                    if (venta.cantidadVendida > maxVentas) { 
                        maxVentas = venta.cantidadVendida; 
                        codigoMasVendido = venta.codigo; 
                    } 
                } 
                if (codigoMasVendido == -1) { 
                    cout << "No se encontraron ventas en el archivo." << endl; 
                    return; 
                } 
                file.open("Inventario.bin", ios::in | ios::binary); 
                if (!file) { 
                    cout << "No se pudo abrir Inventario.bin" << endl; 
                    return; 
                } 
                Objeto o; 
                bool encontrado = false; 
                while (file.read(reinterpret_cast<char*>(&o), sizeof(Objeto))) { 
                    if (o.codigo == codigoMasVendido) { 
                        cout << "El objeto mas vendido es: " << endl; 
                        cout << "Nombre: " << o.nombre << endl; 
                        cout << "Codigo: " << o.codigo << endl; 
                        cout << "Cantidad vendida: " << maxVentas << endl; 
                        cout << "Precio: " << o.precio << endl; 
                        encontrado = true; break; 
                    } 
                } 
                file.close(); 
                if (!encontrado) { 
                    cout << "No se encontro el producto mas vendido en el inventario." << endl; 
                } 
            break;
        }
        case 3: {
            fstream file("Ventas.bin", ios::in | ios::binary);
            if (!file) {
                cout << "No se pudo abrir ventas.bin" << endl;
                return;
            }
            vector<ProductoVendido> ventasTotales;  
            Compra c;
            while (file.read(reinterpret_cast<char*>(&c), sizeof(Compra))) {
                bool encontrado = false;
                for (auto& venta : ventasTotales) {
                    if (venta.codigo == c.Tipo_precio) {
                        venta.cantidadVendida += c.cantidad;  
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    ventasTotales.push_back({c.Tipo_precio, c.cantidad});
                }
            }
            file.close();
            int minVentas = INT_MAX;
            int codigoMenosVendido = -1;
            for (const auto& venta : ventasTotales) {
                if (venta.cantidadVendida < minVentas) {
                    minVentas = venta.cantidadVendida;
                    codigoMenosVendido = venta.codigo;
                }
            }
            if (codigoMenosVendido == -1) {
                cout << "No se encontraron ventas en el archivo." << endl;
                return;
            }
            file.open("Inventario.bin", ios::in | ios::binary);
            if (!file) {
                cout << "No se pudo abrir Inventario.bin" << endl;
                return;
            }
            Objeto o;
            bool encontrado = false;
            while (file.read(reinterpret_cast<char*>(&o), sizeof(Objeto))) {
                if (o.codigo == codigoMenosVendido) {
                    cout << "El objeto menos vendido es: " << endl;
                    cout << "Nombre: " << o.nombre << endl;
                    cout << "Codigo: " << o.codigo << endl;
                    cout << "Cantidad vendida: " << minVentas << endl;
                    cout << "Precio: " << o.precio << endl;
                    encontrado = true;
                    break;
                }
            }
            file.close();
            if (!encontrado) {
                cout << "No se encontro el producto menos vendido en el inventario." << endl;
            }
            break;
        }
        default:
            cout<<"Opcion no valida, vuelva a intentarlo por favor ;-; "<<endl;
            break;
        }
        system("pause");
    } while (option!=0);
}

void productos(){
    int option;
    do
    {
        system("cls");
        cout<<" ---------------------------------------------------------------- "<<endl
            <<"                          PRODUCTOS OPCIONES                "<<endl<<
              " ---------------------------------------------------------------- "<<endl
        <<"1) Ver Inventario 2) Agregar al Inventario 3) Modificar inventario 4) eliminar del inventario"<<endl
        <<"5) Actualizar inventario 0)Salir | R: ";
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
        case 5: {
             { 
            fstream file("Inventario.bin", ios::in | ios::out | ios::binary);
            if (!file) 
            { 
                cout << "No se pudo abrir Inventario.bin\n"; 
                break; 
            }
            Objeto c;
            int contador = 1, r, agregar;
            cout << "\n=== INVENTARIO ===\n";
            while(file.read(reinterpret_cast<char*>(&c), sizeof(Objeto))) {
                if(c.existe) {  
                    cout << contador++ << ") Nombre: " << c.nombre
                         << "    \t | Precio: " << c.precio
                         << "    \t | Cantidad: " << c.cantidad
                         << "    \t | Codigo: " << c.codigo << endl;
                    cout<<"Desea agregar cantidad de existencias? 1) si 2) no / R: ";
                    cin>>r;
                    if (r==1)
                    {
                        cout<<"Cuantas existencias desea agregar al producto? R: ";
                        cin>>agregar;
                        if (agregar > 0) {  
                        c.cantidad += agregar;
                        file.seekp(-static_cast<int>(sizeof(Objeto)), ios::cur); 
                        file.write(reinterpret_cast<char*>(&c), sizeof(Objeto));  
                        cout << "Cantidad de existencias actualizada a: " << c.cantidad << endl;
                        } 
                        else {
                            cout << "Cantidad no valida.\n";
                        }
                    }
                }
            }
            file.close();
            }
        }
        default:
            cout<<"Opcion no valida, vuelva a intentarlo por favor ;-; "<<endl;
            break;
        }
        system("pause");
    } while (option!=0);
}

int IniciarInventarioTienda () {
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
        case 0:
            cout<<"Cerrando programa, volviendo al menu principal :D"<<endl;
            system("pause");
            break;
        case 1:
            Ventas();
            break;
        case 2:
            productos();
            break;
        default:
            cout<<"Opcion no valida, por favor seleciones otra ";
            system("pause");
            break;
        }
    } while (option!=0);
    return 0;
}