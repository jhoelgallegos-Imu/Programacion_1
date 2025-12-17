#ifndef ESTRUCTURAS_H  
#define ESTRUCTURAS_H

struct fecha
{
    int dia = 18;
    int mes = 7;
    int anio = 2006;
};

struct Clientes
{
    char CarnetIdentidad[10] = "00000000" ;
    char Nombre[31] = "---------------" ;
    char Apellido[31] = "---------------";
    bool membresia = false;
    int PuntosNintendo = 0;
    bool existe = true;
};

struct Compra
{
    int Tipo_precio;
    int cantidad;
    bool descuent0 = false;
    Clientes persona;
    fecha diadecompra;
};

struct Objeto
{
    int codigo;
    int cantidad;
    float precio;
    char nombre[51];
    bool existe = true;
};

#endif  

