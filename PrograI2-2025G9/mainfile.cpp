#include <iostream>
#include <cstdlib>
using namespace std;

struct Clientes
{
    char CarnetIdentidad[10] ;
    char Nombre[30] ;
    char Apellido[30];
    bool membresia = false;
    int PuntosNintendo = 0;
};

struct Compra
{
    char CarnetIdentidad[10] = "00000000" ;
    int Tipo;
    int cantidad;
    float precio;
};

void AdministrarClientes(){
    int option;
    system("cls");
    do
    {
        cout<<"------------------------------------------------------------"<<endl
            <<"\t SISTEMA DE ADMINISTRACION DE CLIENTES "<<endl
            <<"------------------------------------------------------------"<<endl
            <<"1) Crear Factura 2) Administrar perfil 0) Salir ";
        cin>>option;
        switch (option)
        {
        case 1:
            AdministrarClientes();
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
}

int main () {
    int option;
    do
    {
        cout<<"============================================================"<<endl
            <<"\t SISTEMA DE ADMINISTRACION DE MYNINTENDO "<<endl
            <<"============================================================"<<endl
            <<"1) Administrar clientes 2) Facturar compra 0) Salir ";
        cin>>option;
        switch (option)
        {
        case 1:
            AdministrarClientes();
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
        system("cls");
    } while (option!=0);
    cout<<"Cerando programa";
    return 0;
}