// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani 
// Fecha creación: 04/11/2025
// Número de ejercicio: 7

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

struct Producto
{
    char nombre[30];
    char codigo[9];
    float precio;
    int CantidadInventario;
    string comentarios;
};

void MostrarInventario(vector<Producto> & Prods, int nro){ //menu para poder mostrar los productos y si es necesario el comentario
    cout<<"\t Nombre: "<<Prods[nro].nombre<<" | Codigo: "<<Prods[nro].codigo<<endl
        <<"\t Precio: "<<Prods[nro].precio<<" | Existencias en inventario: "<<Prods[nro].CantidadInventario<<endl;
    if (Prods[nro].CantidadInventario<5)
    {
        cout<<"\t COMENTARIO: "<<Prods[nro].comentarios<<endl;
    }
    
}

int main () {
    int n, PprodMasCaro=0, TotalProductos=0;
    float ProdMasCaro=0.0;
    vector<Producto> Productos;
    cout<<"Ingrese la cantidad de Productos que quiera ingresar: ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n ; i++)
    {
        cout<<"=================================================================="<<endl;
        Producto ProductoX;
        cout<<"Ingrese el nombre del Producto "<<i+1<<": ";
        cin.getline(ProductoX.nombre,30);
        cout<<"Ingrese el codigo del Producto (9 caracteres) "<<i+1<<": ";
        cin.getline(ProductoX.codigo,9);
        cout<<"Ingrese el precio del Producto "<<i+1<<": ";
        cin>>ProductoX.precio;
        cout<<"Ingrese la cantidad del Producto en el inventario "<<i+1<<": ";
        cin>>ProductoX.CantidadInventario;
        TotalProductos+=ProductoX.CantidadInventario;
        if (ProductoX.CantidadInventario < 5)
        {
            ProductoX.comentarios="PRODUCTO CON BAJA CANTIDAD EN INVENTARIO";
        }
        if (ProductoX.precio > ProdMasCaro)
        {
            ProdMasCaro=ProductoX.precio;
            PprodMasCaro=i;
        }
        
        cin.ignore();
        cout<<"=================================================================="<<endl;
        Productos.push_back(ProductoX);
        system("cls");
    }
    cout<<"=================================================================="<<endl
    <<"El producto mas caro es: "<<endl;
    MostrarInventario(Productos, PprodMasCaro);
    cout<<"=================================================================="<<endl
    <<"\t El total del inventario es de: "<<TotalProductos<<endl
    <<"==================================================================";
    return 0;
}