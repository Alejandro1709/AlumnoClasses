#include "pch.h"
#include "Alumno.h"
 
//implementacion de los metods
Alumno::Alumno(string nombre,
    string apellido,
    string seccion,
    double nota_parcial1,
    double nota_parcial2) {
 
 
    //asignar los valores a nuestros atributos
    this->nombre = nombre;
    this->apellido = apellido;
    this->seccion = seccion;
    //asignacion validada de notas
    if (nota_parcial1 >= 0 && nota_parcial1 <= 20) {
        this->nota_parcial1 = nota_parcial1;
    }
    else {
        cout << "Cuidado: Nota " << nota_parcial1 << " no valida, la nota sera configurada a 0";
        this->nota_parcial1 = 0;
    }
    if (nota_parcial2 >= 0 && nota_parcial2 <= 20) {
        this->nota_parcial2 = nota_parcial2;
    }
    else {
        cout << "Cuidado: Nota " << nota_parcial2 << " no valida, la nota sera configurada a 0";
        this->nota_parcial2 = 0;
    }
}
string Alumno::getApellido() {
    return this->apellido;
}
 
string Alumno::getNombre() {
    return this->nombre;
}
 
string Alumno::getSeccion() {
    return this->seccion;
}
 
double Alumno::getNotaParcial1() {
    return this->nota_parcial1;
}
 
double Alumno::getNotaParcial2() {
    return this->nota_parcial2;
}
 
void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}
 
void Alumno::setApellido(string apellido) {
    this->apellido = apellido;
}
 
void Alumno::setSeccion(string seccion) {
    this->seccion = seccion;
}
 
void Alumno::setNotaParcial1(double nota_parcial1) {
    if (nota_parcial1 >= 0 && nota_parcial1 <= 20) {
        this->nota_parcial1 = nota_parcial1;
    }
    else {
        cout << "Cuidado: Nota " << nota_parcial1 << " no valida, la nota no se modificara";
    }
}
 
void Alumno::setNotaParcial2(double nota_parcial2) {
    if (nota_parcial2 >= 0 && nota_parcial2 <= 20) {
        this->nota_parcial2 = nota_parcial2;
    }
    else {
        cout << "Cuidado: Nota " << nota_parcial1 << " no valida, la nota no se modificara";
    }
}
 
// servicios de la clase
double Alumno::calcularPromedio() {
    return (this->nota_parcial1 + this->nota_parcial2) / 2;
}
 
bool Alumno::esAprobado() {
    return (this->calcularPromedio() >= 13.0);
}
/* Este codigo es equivalente al codigo anterior
bool Alumno::esAprobado() {
    if (this->calcularPromedio() >= 13.0)
        return true;
    else
        return false;
}
*/
void Alumno::imprimir() {
    cout << "Datos Alumno:" << endl;
    cout << "\tNombre:\t" <<this->nombre<< endl;
    cout << "\tApellido:\t" << this->apellido << endl;
    cout << "\tSeccion:\t" << this->seccion << endl;
    cout << "\tParcial 1:\t" << this->nota_parcial1 << endl;
    cout << "\tParcial 2:\t" << this->nota_parcial2 << endl;
    cout << "\tPromedio:\t" << this->calcularPromedio() << endl;
    cout << "\tCondicion:\t" << (this->esAprobado() ? "Aprobado":"Desaprobado") << endl;
    /*
    if (this->esAprobado()) {
        cout << "\tCondicion:\t" << "Aprobado"<< endl;
    }
    else {
        cout << "\tCondicion:\t" << "Desaprobado" << endl;
    }
    */
}