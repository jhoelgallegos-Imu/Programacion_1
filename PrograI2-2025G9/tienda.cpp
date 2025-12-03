#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
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
                <<"\t Tipo:\t|Cantidad: \t|Precio:"<<endl;
            for (int  i = 0; i < n; i++)
            {
            cout<<"| "<<FacturaTemp[i].Tipo_precio<<"\t| "<<FacturaTemp[i].cantidad<<"\t|"<<FacturaTemp[i].Tipo_precio<<endl;
            }
            cout<<"                                 |Total="<<totalfinal*3.12<<endl;
        }
        cout<<"Quiere imprimir esta factura? 1)si 2)no R.-";
        cin>>option;
        cin.ignore();
        if (option==1)
        {
            BarraDeCarga();
        }
    } while (option!=1);
}

void AdministrarPerfiles(){

}

int main () {
    int option;
    do
    {
        system("cls");
        cout<<"------------------------------------------------------------"<<endl
            <<"\t SISTEMA DE ADMINISTRACION DE TIENDA "<<endl
            <<"------------------------------------------------------------"<<endl
            <<"1) Crear Factura 2) Administrar perfil 0) Salir ";
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
            AdministrarPerfiles();
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