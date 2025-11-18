// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 18-11-2025
// Número de ejercicio: 3
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Pizza
{
    int codigo;
    char nombre[30];
    char tipo[15];     // TRADICIONAL o ESPECIAL
    char tamano[20];   // XS, MEDIANA, GRANDE, FAMILIAR, INTERMINABLE
    float precio;
};

struct Venta
{
    char CI[12];
    int codigoPizza;
    char tamano[20];
    int cantidad;
};

void AdicionarPizza()
{
    Pizza p, temp;
    bool existe = false;
    cout << "Codigo: ";
    cin >> p.codigo;
    cin.ignore();
    ifstream r("PRODUCTO.BIN", ios::binary);
    if (r)
    {
        while (r.read((char *)&temp, sizeof(temp)))
        {
            if (temp.codigo == p.codigo)
            {
                existe = true;
                break;
            }
        }
    }
    r.close();
    if (existe)
    {
        cout << "Ya existe una pizza con ese codigo" << endl;
        return;
    }
    cout << "Nombre: ";
    cin.getline(p.nombre, 30);
    cout << "Tipo (TRADICIONAL/ESPECIAL): ";
    cin.getline(p.tipo, 15);
    cout << "Tamano (XS/MEDIANA/GRANDE/FAMILIAR/INTERMINABLE): ";
    cin.getline(p.tamano, 20);
    cout << "Precio base TRADICIONAL: ";
    cin >> p.precio;
    cin.ignore();
    if (strcmp(p.tipo, "ESPECIAL") == 0)
        p.precio = p.precio * 1.10;
    ofstream w("PRODUCTO.BIN", ios::binary | ios::app);
    w.write((char *)&p, sizeof(p));
    w.close();
    cout << "Pizza registrada exitosamente" << endl;
}

void ListadoPizzas()
{
    Pizza p;
    ifstream r("PRODUCTO.BIN", ios::binary);
    if (!r)
    {
        cout << "No existen pizzas registradas" << endl;
        return;
    }
    cout << "CODIGO | NOMBRE | TIPO | TAMANO | PRECIO | CANT | TOTAL" << endl;
    while (r.read((char *)&p, sizeof(p)))
    {
        Venta v;
        int cantidad = 0;
        ifstream t("VENTAS.TXT");
        while (t >> v.CI >> v.codigoPizza >> v.tamano >> v.cantidad)
        {
            if (v.codigoPizza == p.codigo && strcmp(v.tamano, p.tamano) == 0)
            {
                cantidad += v.cantidad;
            }
        }
        t.close();
        float total = cantidad * p.precio;
        cout << p.codigo << "  " << p.nombre << "  " << p.tipo << "  "
             << p.tamano << "  " << p.precio << "  "
             << cantidad << "  " << total << endl;
    }
    r.close();
}

void ModificarPrecio()
{
    int cod;
    Pizza p;
    bool encontrado = false;
    cout << "Codigo a modificar: ";
    cin >> cod;
    cin.ignore();
    fstream archivo("PRODUCTO.BIN", ios::binary | ios::in | ios::out);
    if (!archivo)
    {
        cout << "No existe archivo" << endl;
        return;
    }
    while (archivo.read((char *)&p, sizeof(p)))
    {
        if (p.codigo == cod)
        {
            encontrado = true;
            cout << "Nuevo precio base TRADICIONAL: ";
            cin >> p.precio;
            cin.ignore();
            if (strcmp(p.tipo, "ESPECIAL") == 0)
                p.precio = p.precio * 1.10;
            int pos = -1 * (int)sizeof(p);
            archivo.seekp(pos, ios::cur);
            archivo.write((char *)&p, sizeof(p));
            cout << "Precio modificado" << endl;
            break;
        }
    }
    if (!encontrado)
        cout << "Pizza no encontrada" << endl;
    archivo.close();
}

void EliminarPizza()
{
    int cod;
    Pizza p;
    cout << "Codigo a eliminar: ";
    cin >> cod;
    cin.ignore();
    ifstream r("PRODUCTO.BIN", ios::binary);
    if (!r)
    {
        cout << "No existe archivo" << endl;
        return;
    }
    ofstream w("TEMP.BIN", ios::binary);
    bool eliminado = false;
    while (r.read((char *)&p, sizeof(p)))
    {
        if (p.codigo == cod)
            eliminado = true;
        else
            w.write((char *)&p, sizeof(p));
    }
    r.close();
    w.close();
    remove("PRODUCTO.BIN");
    rename("TEMP.BIN", "PRODUCTO.BIN");
    if (eliminado)
        cout << "Pizza eliminada exitosamente" << endl;
    else
        cout << "Codigo no encontrado" << endl;
}

void AdicionarVenta()
{
    Venta v;
    Pizza p;
    bool existe = false;
    cout << "CI Cliente: ";
    cin.getline(v.CI, 12);
    cout << "Codigo Pizza: ";
    cin >> v.codigoPizza;
    cin.ignore();
    cout << "Tamano: ";
    cin.getline(v.tamano, 20);
    cout << "Cantidad vendida: ";
    cin >> v.cantidad;
    cin.ignore();
    ifstream r("PRODUCTO.BIN", ios::binary);
    while (r.read((char *)&p, sizeof(p)))
    {
        if (p.codigo == v.codigoPizza)
        {
            existe = true;
            break;
        }
    }
    r.close();
    if (!existe)
    {
        cout << "No existe la pizza" << endl;
        return;
    }
    ofstream w("VENTAS.TXT", ios::app);
    w << v.CI << " " << v.codigoPizza << " " << v.tamano << " " << v.cantidad << endl;
    w.close();
    cout << "Venta registrada" << endl;
}

int main() { 
    int option; 
    do { 
        cout << "====================== PIZZERIA ELIS ======================" << endl 
        <<"1) Adicionar Pizza               2) Listado de Productos "<<endl 
        <<"3) Buscar un producto por codigo 4) Modificar un producto"<<endl 
        <<"5) Adicionar ventas del producto 0)Salir"<<endl; 
        cin>>option; 
        cin.ignore(); 
        switch (option) { 
            case 1: 
                system("cls"); 
                cout << "================= ADICIONAR PIZZA =================" << endl; 
                AdicionarPizza(); 
                system("pause"); 
                break; 
            case 2: system("cls"); 
                cout << "============== LISTA DE PIZZAS ===============" << endl; 
                ListadoPizzas(); system("pause"); 
                break; 
            case 3: 
                system("cls"); 
                cout << "=========== MODIFICAR POR CODIGO =============" << endl; 
                ModificarPrecio(); 
                system("pause"); 
                break; 
            case 4: 
                system("cls"); 
                cout << "=============== ELIMINAR PIZZA ===============" << endl; 
                EliminarPizza(); 
                system("pause"); 
                break; 
            case 5: 
                system("cls"); 
                cout << "==================== ADICIONAR VENTAS ====================" << endl; 
                AdicionarVenta(); 
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