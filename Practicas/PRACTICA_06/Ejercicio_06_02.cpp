// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 7/10/2024
// Número de ejercicio: 2
/* Problema planteado: Un arreglo constante contiene la producción en toneladas métricas de 6 minerales, y
otro contiene los nombres de estos minerales, para obtener:
• Buscar por nombre de mineral y desplegar la producción
• Ordenar del mayor al menor (producción) y mostrar:
Mineral Produccion ™
SN 998.000
SB 876.500
AU 786.670
PT 636.143
AG 135.567
CU 109.412 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MenuMineral(){
    cout<<"Ingrese que mineral quisiera buscar su produccion: "<<endl;
    cout<<"Las opciones son: SN, SB, AU, PT, AG y CU "<<endl;
}

void OrdenarMayorMenor(vector<string>&n, vector<int>&p){ //se usa el metodo burbuja para ordenar de mayor a menor el sistema
    int tempP;
    string tempN;
    for (int i = 0; i < p.size()-1; i++)
    {
        for (int j = 0; j < p.size()-i-1; j++)
        {
            if (p[j] < p[j+1])
            {
                tempP = p[j];
                p[j] = p[j+1];
                p[j+1] = tempP;

                tempN = n[j];
                n[j] = n[j+1];
                n[j+1] = tempN;
            }
        }
    }
    cout<<"mineral        Produccion "<<endl;
    for (int i = 0; i < n.size(); i++)
    {
        cout<<"   "<<n[i]<<"            "<<p[i]<<endl;
    }
}

void BuscarMineral(vector<string>ns, vector<int>p, string n){
    for (int i = 0; i < ns.size(); i++)
    {
        if (ns[i]==n)
        {
            cout<<"La produccion de "<<ns[i]<<" es igual a: "<<p[i]<<endl;
        }
    }
}

int main () {
    vector<string> minerales={"SN", "SB", "AU", "PT", "AG", "CU"};
    vector<int> produccion={998000, 876500, 786670, 636143, 135567, 109412};
    string mineral="";
    MenuMineral();
    getline(cin, mineral);
    BuscarMineral(minerales,produccion,mineral); 
    OrdenarMayorMenor(minerales,produccion);
    return 0;
}
