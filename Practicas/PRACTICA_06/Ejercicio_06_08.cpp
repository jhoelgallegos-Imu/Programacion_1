// Materia: Programación I, Paralelo 1
// Autor: Jhoel Fernando Gallegos Mamani
// Fecha creación: 9/10/2024
// Número de ejercicio: 8
/* Problema planteado: Escribe un programa que valide si una cadena ingresada cumple con el formato básico
de una dirección de correo electrónico (por ejemplo, contiene exactamente un '@' y al
menos un punto '.' después del '@').
• // Entrada: "usuario@example.com"
• // Salida: "Correo electrónico válido"
• // Entrada: "usuarioexample.com"
• // Salida: "Correo electrónico inválido"  */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ValidarCorreo(string v){
    bool valid = false;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]=='@')//busca un arroba
        {
            for (int j = i; j < v.size() ; j++) //verifica un punto despues del arroba 
            {
                if (v[j]=='.')
                {
                    valid=true; //al verificar ambos se vuelve verdadero
                }
            }
        }
    }
    if (valid)
    {
        cout<<"Su correo es valido :D ";
    }
    else
    {
        cout<<"Su correo no es valido D: ";
    }
    
}

int main () {
    string correo = "";
    cout<<"Ingrese su correo para validarlo: "<<endl;
    getline(cin, correo);
    cout<<"-------------------------------------------------"<<endl;
    ValidarCorreo(correo);
    return 0;
}