#include "Clientes.h"
#include "Administracion.h"
#include "Ventas.h"
#include "estructuras.h"
using namespace std;

int main () {
    system("cls");
    int option;
    do
    {
        cout<<"============================================================"<<endl
            <<"\t SISTEMA DE ADMINISTRACION DE MYNINTENDO "<<endl
            <<"============================================================"<<endl
            <<"1) TIENDA 2) VENTAS/STOCK 3) ADMINISTRACION 0) Salir | R: ";
        cin>>option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            IniciarTienda();
            break;
        case 2:
            IniciarInventarioTienda();
            break;
        case 3:
            IniciarClientes();
            break;
        default:
            cout<<"Opcion no valida, por favor seleciones otra ";
            system("pause");
        }
        system("cls");
    } while (option!=0);
    cout<<"Cerando programa";
    return 0;
}