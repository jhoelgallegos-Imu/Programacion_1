#include <iostream>
using namespace std;

int main() {
//cout << "Hola, mundo!" << endl;
//    int edad=0;
/*    int x = 10 ;
    cout << x ;
    int y = 6;
    int sum = x+y ;
    cout <<sum <<endl;
    float deci=10.99;
    cout <<deci <<endl;
    char letra = 'J';
    cout <<letra <<endl;
    bool estudent=true;
    bool on= false ;
    std::string oracion= "Pepitoclavounclavito en la calva de un calvito";
    cout<< "Un dia "<< oracion <<endl;
    // constantes :b
    const double PI=3.14159;
    double rad=10;
    double circ= 2*PI*rad;
    cout <<circ<<"cm. ";
    cout<<"AYUDAAAAAA";*/
/*    do
    {
        cout<<"Ingrese su edad"<<endl;
        cin>>edad;
    } while (edad<0 || edad>=120 );
    cout<<"ingreso la edad correctamente";*/
    int numero=0;
    cout<<"ingrese un numero n: "<<endl;
    cin>>numero;
    for (int i = 1; i <= numero; i++)
    {
        if (i%2 == 0) //si es par
        {
            cout<<i<<" - ";
        }
        
    }
    
    return 0;
}
