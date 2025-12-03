#include <iostream>
#include <cstdlib>
using namespace std;

struct Clientes
{
    char CarnetIdentidad[10] = "00000000" ;
    char Nombre[30] ;
    char Apellido[30];
    bool membresia = false;
    int PuntosNintendo = 0;
};

struct Compra
{
    char CarnetIdentidad[10] = "00000000";
    int Tipo_precio;
    int cantidad;
    bool descuent0 = false;
};


void CrearFactura(){
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
            cout<<"Opcion en desarrollo"<<endl;
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