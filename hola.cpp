// funciones: Dividir una tarea en chiquitas para hacerlo mejor :D
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<int> cienannos() {
    vector<int> annos;
    int rango = 2025 - 1990;
    for (int i = 0; i < 100; i++) {
        double aleatorionormalizado = (double)rand() / RAND_MAX;
        int anno = 1990 + int(aleatorionormalizado * (rango + 1));
        annos.push_back(anno);
    }
    return annos;
}


int main() {
    vector<int> listaannos= cienannos();
    for (int i = 0; i <=99; i++)
    {
        cout<<i+1<<" "<<listaannos[i]<<endl;
    }
    
    return 0;
}

