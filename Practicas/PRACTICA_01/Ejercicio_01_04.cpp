// Materia: Programación I, Paralelo 4
// Autor: Jhoel Fernando Gallegos Mamani
// Carnet: 10904518 L.P.
// Carrera del estudiante: Ingeniería de Multimedia e Interactividad
// Fecha creación: 22/08/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;

int main() {
    const float pi = 3.14159; //el "cons" es para evitar que la variable de pi se pueda modificar luego, y si se intenta que salga error
    int radio=0;
    cout<<"ingrese el radio de la esfera: "<<endl;
    cin >>radio;
    float volumen=(radio*radio*radio)*4/3*pi; // esta puesto de esta manera para que todo se haga correctamente
    cout<<"El volumen de la esfera es: "<<volumen;
    return 0;
}