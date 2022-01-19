#pragma once
#include<string>
#include<iostream>
using namespace std;
 
class Alumno
{
    // definir los atributos de forma privada
private:
    string nombre;
    string apellido;
    string seccion;
    double nota_parcial1;
    double nota_parcial2;
    //definir los metodos de forma publica
public:
    Alumno(string nombre,
        string apellido,
        string seccion,
        double nota_parcial1,
        double nota_parcial2
    );
    string getNombre();
    string getApellido();
    string getSeccion();
    double getNotaParcial1();
    double getNotaParcial2();
 
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setSeccion(string seccion);
    void setNotaParcial1(double nota_parcial1);
    void setNotaParcial2(double nota_parcial2);
 
    double calcularPromedio();
    bool esAprobado();
    void imprimir();
};