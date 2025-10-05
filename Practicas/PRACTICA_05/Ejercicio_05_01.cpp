// Materia: Programación I, Paralelo 4
// Autor:Jhoel Fernando Gallegos Mamani
// Carnet: 10904518
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 05/10/2025
// Número de ejercicio: 1
#include <iostream>
#include <cstdlib>  
#include <ctime>
#include <vector>
#include <string>

using namespace std;

void Gvoltages(vector<float>&v){    //a
    float vol=0,limSup=220.0,limInfe=20.0;
    for (int i = 0; i < 100; i++)
    {
        vol=limInfe + static_cast<float>(rand()) / RAND_MAX * (limSup - limInfe);
        vol = ((int)(vol * 100)) / 100.0;
        v.push_back(vol);
    }  
}

void Gtemperaturas(vector<float>&t){    //b
    float tem=0,limSup=100.00,limInfe=0.00;
    for (int i = 0; i < 50; i++)
    {
        tem=limInfe + static_cast<float>(rand()) / RAND_MAX * (limSup - limInfe);
        tem = ((int)(tem * 100)) / 100.0;
        t.push_back(tem);
    }  
}

void Galfanum(vector<string>&alfa) {   //c
    for (int i = 0; i < 30; i++) {
        string caracter = "";
        for (int j = 0; j < 9; j++) {
            int tipo = rand() % 3;
            if (tipo == 0)
                caracter += '0' + rand() % 10;   
            else if (tipo == 1)
                caracter += 'A' + rand() % 26;    
            else
                caracter += 'a' + rand() % 26;   
        }
        alfa.push_back(caracter);
    }
}

void Gannos(vector<int>&a){    //d
    float anno=0,limSup=100.00,limInfe=0.00;
    for (int i = 0; i < 100; i++)
    {
        anno=(rand()%36)+1990;
        a.push_back(anno);
    }  
}

void Gvelocidades(vector<float>&v){  //e
    float vel=0.0,limSup=300.0,limInfe=10.0;
    for (int i = 0; i < 32; i++)
    {
        vel=limInfe + static_cast<float>(rand()) / RAND_MAX * (limSup - limInfe);
        vel = ((int)(vel * 100)) / 100.0;
        v.push_back(vel);
    }  
}

void Gdistancias(vector<float>&d){  //f
    float dis=0,limSup=1000.0,limInfe=1.0;
    for (int i = 0; i < 1000; i++)
    {
        dis = limInfe + static_cast<float>(rand()) / RAND_MAX * (limSup - limInfe);
        dis = ((int)(dis * 100)) / 100.0;
        d.push_back(dis);
    }  
}

int main () {
    srand(time(0));
    int n;
    vector<float> voltajes;
    vector<float> temperaturas;
    vector<string> alfanumericos;
    vector<int> annos;
    vector<float> velocidades;
    vector<float> distancias;
    cout<<"a) Una lista de 100 voltajes: "<<endl;
    Gvoltages(voltajes);
    for (int i = 0; i < voltajes.size(); i++)
    {
        cout<<"El voltaje Nro. "<<i+1<<" es: "<<voltajes[i]<<endl;
    }
    cout<<"b) Una lista de 50 temperaturas: "<<endl;
    Gtemperaturas(temperaturas);
    for (int i = 0; i < temperaturas.size(); i++)
    {
        cout<<"La temperatura Nro. "<<i+1<<" es: "<<temperaturas[i]<<endl;
    }
    cout<<"c) Una lista de 30 caracteres alfanumericos: "<<endl;
    Galfanum(alfanumericos);   
    for (int i = 0; i < alfanumericos.size(); i++)
    {
        cout<<"El caracter alfanumerico Nro. "<<i+1<<" es: "<<alfanumericos[i]<<endl;
    } 
    // para ver mejor el codigo puede activar el cin n para verlo detenidamente, es solo un espaciador
    //cin>>n;
    cout<<"d) Una lista de 100 anios: "<<endl;
    Gannos(annos);
    for (int i = 0; i < annos.size(); i++)
    {
        cout<<"El anio Nro. "<<i+1<<" es: "<<annos[i]<<endl;
    }
    cout<<"e) Una lista de 32 velocidades: "<<endl;
    Gvelocidades(velocidades);
    for (int i = 0; i < velocidades.size(); i++)
    {
        cout<<"La velocidad Nro. "<<i+1<<" es: "<<velocidades[i]<<endl;
    }
    cout<<"f) Una lista de 1000 distancias: "<<endl;
    Gdistancias(distancias);
    for (int i = 0; i < distancias.size(); i++)
    {
        cout<<"La distancia Nro. "<<i+1<<" es: "<<distancias[i]<<endl;
    }
    return 0;
}