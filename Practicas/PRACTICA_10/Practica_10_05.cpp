// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 11/11/2025
// Número de ejercicio: 5
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

void LeerArchivo(vector<Producto> &lista, const char nombreArchivo[30]) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }
    Producto temp;
    while (archivo >> temp.nombre >> temp.precio) {
        lista.push_back(temp);
    }
    archivo.close();
}

bool ActualizarPrecio(vector<Producto> &lista, const string &nombreProd, float nuevoPrecio) {
    bool encontrado = false;
    for (auto &prod : lista) {
        if (prod.nombre == nombreProd) {
            prod.precio = nuevoPrecio;
            encontrado = true;
            break;
        }
    }
    return encontrado;
}

void GuardarArchivo(const vector<Producto> &lista, const char nombreArchivo[30]) {
    ofstream archivo(nombreArchivo);
    for (const auto &prod : lista) {
        archivo << prod.nombre << " " << prod.precio << endl;
    }
    archivo.close();
}

int main() {
    vector<Producto> productos;
    char nombreArchivo[30] = "productos.txt";
    string nombreBuscado;
    float nuevoPrecio;
    char opcion;
    LeerArchivo(productos, nombreArchivo);
    if (productos.empty()) {
        cout << "El archivo esta vacio o no se pudo leer correctamente." << endl;
        return 0;
    }
    do {
        system("cls");
        cout << "================== ACTUALIZAR PRECIOS ==================" << endl;
        cout << "Ingrese el nombre del producto a actualizar: ";
        cin >> nombreBuscado;
        cout << "Ingrese el nuevo precio: ";
        cin >> nuevoPrecio;
        bool actualizado = ActualizarPrecio(productos, nombreBuscado, nuevoPrecio);
        if (actualizado) {
            cout << "\nPrecio actualizado correctamente!" << endl;
            GuardarArchivo(productos, nombreArchivo);
        } else {
            cout << "\nEl producto '" << nombreBuscado << "' no existe en el archivo." << endl;
        }
        cout << "\n¿Desea actualizar otro producto? (S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's'); //para repetir la accion hasta que el usuario decida que quiere cerar el programa
    cout << "\nCambios guardados correctamente en '" << nombreArchivo << "'." << endl;
    cout << "========================================================" << endl;
    return 0;
}
