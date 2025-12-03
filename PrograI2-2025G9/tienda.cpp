#include <iostream>
#include <vector>
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


void CrearFactura(){
    vector <Compra> FacturaTemp;
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