// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 18-11-2025
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Informacion
{
    char codigo[9];
    char nombre[30];
    int cantidad;
    float precio;
};

struct venta
{
    char CI[10];
    char nombre[30];
    char codigo[9];
    int cantidad;
};

void AdicionarProductos(){
    Informacion p, temp;
    bool existe = false;
    cout<<"Ingrese codigo: ";
    cin.getline(p.codigo,9);
    ifstream r("PRODUCTOS.BIN", ios::binary);
    if(r){
        while(r.read((char*)&temp, sizeof(temp))){
            if(strcmp(temp.codigo,p.codigo)==0){
                existe = true;
                break;
            }
        }
    }
    r.close();
    if(existe){
        cout<<"El producto ya existe"<<endl; //compara el producto para ver si ya existe, si lo hace rompe y regresa todo al menu de inicio
        return;
    }
    cout<<"Ingrese nombre: ";
    cin.getline(p.nombre,30);
    cout<<"Ingrese cantidad inicial: ";
    cin>>p.cantidad;
    cout<<"Ingrese precio unitario: ";
    cin>>p.precio;
    cin.ignore();
    ofstream w("PRODUCTOS.BIN", ios::binary|ios::app);
    w.write((char*)&p, sizeof(p));
    w.close();
    cout<<"Producto registrado"<<endl;
}

void ListadoDeProductos(){
    Informacion p;
    ifstream r("PRODUCTOS.BIN", ios::binary); //abre el bin de los productos
    if(!r){
        cout<<"No existen productos"<<endl;
        return;
    }
    cout<<"CODIGO | NOMBRE |  CANT.INI | PRECIO | VENDIDO | TOTAL"<<endl;
    while(r.read((char*)&p, sizeof(p)))
    {
        int vendido = 0;
        venta v;
        ifstream t("VENTAS.txt");
        while(t >> v.CI >> v.nombre >> v.codigo >> v.cantidad){
            if(strcmp(v.codigo,p.codigo)==0){
                vendido += v.cantidad;
            }
        }
        t.close();
        float total = vendido * p.precio;
        cout<<p.codigo<<"  "<<p.nombre<<"  "<<p.cantidad<<"  "<<p.precio<<"  "<<vendido<<"  "<<total<<endl;
    }
    r.close();
}

void BuscarXCodigo(){
    char buscar[9];
    Informacion p;
    bool encontrado = false;
    cout<<"Codigo a buscar: ";
    cin.getline(buscar,9);
    ifstream r("PRODUCTOS.BIN", ios::binary);
    if(!r){
        cout<<"No existe archivo"<<endl;
        return;
    }
    while(r.read((char*)&p, sizeof(p))){
        if(strcmp(p.codigo,buscar)==0){
            encontrado = true;
            cout<<"Codigo: "<<p.codigo<<endl;
            cout<<"Nombre: "<<p.nombre<<endl;
            cout<<"Cantidad Inicial: "<<p.cantidad<<endl;
            cout<<"Precio: "<<p.precio<<endl;
            break;
        }
    }
    if(!encontrado) cout<<"Producto no encontrado"<<endl;
    r.close();
}

void ModificarProducto(){
    char buscar[9];
    Informacion p;
    bool encontrado = false;
    cout<<"Codigo a modificar: ";
    cin.getline(buscar,9);
    fstream archivo("PRODUCTOS.BIN", ios::binary | ios::in | ios::out);
    if(!archivo){
        cout<<"No existe archivo"<<endl;
        return;
    }
    while(archivo.read((char*)&p, sizeof(p))){
        if(strcmp(p.codigo,buscar)==0){
            encontrado = true;
            cout<<"Nuevo nombre: ";
            cin.getline(p.nombre,30);
            cout<<"Nueva cantidad inicial: ";
            cin>>p.cantidad;
            cout<<"Nuevo precio: ";
            cin>>p.precio;
            cin.ignore();
            int pos = -1 * (int)sizeof(p);
            archivo.seekp(pos, ios::cur);
            archivo.write((char*)&p, sizeof(p));
            cout<<"Producto modificado"<<endl;
            break;
        }
    }
    if(!encontrado) cout<<"Producto no encontrado"<<endl;
    archivo.close();
}

void Adicionarventas(){
    venta v;
    cout<<"CI cliente: ";
    cin.getline(v.CI,10);
    cout<<"Nombre cliente: ";
    cin.getline(v.nombre,30);
    cout<<"Codigo producto comprado: ";
    cin.getline(v.codigo,9);
    cout<<"Cantidad comprada: ";
    cin>>v.cantidad;
    cin.ignore();
    Informacion p;
    bool existe = false;
    ifstream r("PRODUCTOS.BIN", ios::binary);
    while(r.read((char*)&p, sizeof(p))){
        if(strcmp(p.codigo,v.codigo)==0){
            existe = true;
            break;
        }
    }
    r.close();
    if(!existe){
        cout<<"No existe el producto"<<endl;
        return;
    }
    ofstream w("VENTAS.txt", ios::app);
    w<<v.CI<<" "<<v.nombre<<" "<<v.codigo<<" "<<v.cantidad<<endl;
    w.close();
    cout<<"Venta registrada"<<endl;
}

int main() { 
    int option; 
    do { 
        cout << "====================== FARMACIAS CHAVES SISTEM ======================" << endl 
        <<"1) Adicionar Producto            2) Listado de Productos "<<endl 
        <<"3) Buscar un producto por codigo 4) Modificar un producto"<<endl 
        <<"5) Adicionar ventas del producto 0)Salir"<<endl; 
        cin>>option; 
        cin.ignore(); 
        switch (option) { 
            case 1: 
                system("cls"); 
                cout << "================= ADICIONAR PRODUCTOS =================" << endl; 
                AdicionarProductos(); 
                system("pause"); 
                break; 
            case 2: system("cls"); 
                cout << "============== LISTA DE PRODUCTOS ===============" << endl; 
                ListadoDeProductos(); system("pause"); 
                break; 
            case 3: 
                system("cls"); 
                cout << "==================== BUSCAR POR CODIGO ====================" << endl; 
                BuscarXCodigo(); 
                system("pause"); 
                break; 
            case 4: 
                system("cls"); 
                cout << "==================== MODIFICAR PRODUCTO ====================" << endl; 
                ModificarProducto(); 
                system("pause"); 
                break; 
            case 5: 
                system("cls"); 
                cout << "==================== ADICIONAR VENTAS ====================" << endl; 
                Adicionarventas(); 
                system("pause"); 
                break; 
            case 0: 
                cout << "\t================= CERRANDO PROGRAMA =================" << endl 
                <<" GRACIAS POR SU PREFERENCIA :D, que tenga un lindo dia "<<endl; 
                system("pause"); 
                break; 
            default: 
                cout<<"!=!=!=!=!=!=!=!=!=!= OPCION INVALIDA !=!=!=!=!=!=!=!=!=!=!=!="<<endl; 
                system("pause"); 
                break; 
        } 
        system("cls"); 
    } while (option != 0); 
    return 0; 
}