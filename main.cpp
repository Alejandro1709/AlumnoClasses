#include "pch.h"
#include "Alumno.h"
#include<string>
#include<iostream>
 
using namespace System;
using namespace std;
 
void mostrarArreglo(const Alumno** arreglo, const int& N) {
    for (int i = 0; i < N; i++) {
        cout << "Arreglo [" << i << "] = " << arreglo[i] << endl;
    }
}
 
Alumno** agregarAlFinal(Alumno** vector_anterior, int* tamanho, Alumno* alumno) {
    Alumno** Aux = new Alumno*[*tamanho + 1]; // definir arreglo temporal
    for (int i = 0; i < *tamanho; i++) {// copia de los valores anteriores
        Aux[i] = vector_anterior[i];
    }
    if (vector_anterior != NULL)
        delete[] vector_anterior;
    Aux[*tamanho] = alumno;
    *tamanho = *tamanho + 1;
    return Aux;
}
 
Alumno** insertarEnPosicion(Alumno** V, int* N, int pos, Alumno* alumno) {
    if (pos >= 0 && pos <= *N) { //validando que mi posicion esta dentro del arreglo
        Alumno** Aux = new Alumno*[*N + 1];
        for (int i = 0; i < *N + 1; i++) {
            if (i < pos) Aux[i] = V[i];
            if (i == pos) Aux[i] = alumno;
            if (i > pos) Aux[i] = V[i - 1];
        }
        delete[] V;
        *N = *N + 1;
        return Aux;
    }
    else
        return V;
}
 
Alumno** agregarAlInicio(Alumno** V, int* N, Alumno* alumno) {
    return insertarEnPosicion(V, N, 0, alumno);
}
 
void modificarEnPosicion(Alumno** V, int* N, int posicion, Alumno* alumno) {
    if (posicion > 0 && posicion < *N) { //validando que mi posicion esta dentro del arreglo
        V[posicion] = alumno;
    }
}
 
Alumno** eliminarEnPosicion(Alumno** vector_anterior, int* N, int posicion) {
    if (posicion > 0 && posicion < *N) { //validando que mi posicion esta dentro del arreglo
        Alumno** Aux = new Alumno*[*N - 1];
        //copiar los elementos que no queremos eliminar
        for (int i = 0; i < *N - 1; i++) {
            if (i < posicion)
                Aux[i] = vector_anterior[i];
            else
                Aux[i] = vector_anterior[i + 1];
        }
        //liberar la memoria de vector_anterior
        delete[] vector_anterior;
        *N = *N - 1;
        return Aux;
    }
    else {
        cout << "Posicion incorrecta: Debe estar entre 0 y " << (*N - 1);
        return vector_anterior;
    }
}
/*
void ordenarDescendente(int* V, int* N) {
    int v;
    for (int i = 0; i < *N - 1; i++)
        for (int j = i + 1; j < *N; j++)
            if (V[i] < V[j]) {
                v = V[i];
                V[i] = V[j];
                V[j] = v;
            }
}
*/
void menu() {
    cout << ":::::::::::::::MENU:::::::::::::" << endl;
    cout << "1. Agregar Alumno" << endl;
    cout << "2. Eliminar Alumno" << endl;
    cout << "3. Mostrar Aprobados por seccion" << endl;
    cout << "4. Mostrar Desaprobados por seccion" << endl;
    cout << "5. Promedio Aprobados global" << endl;
    cout << "6. Promedio Desaprobados global" << endl;
    cout << "7. Salir" << endl;
}
 
int leerEntero(const int& minimo, const int& maximo) {
    int entero;
    do {
        cout << "Ingrese un entero entre " << minimo << " y " << maximo << ":";
        cin >> entero;
    } while (entero<minimo || entero > maximo);
    return entero;
}
Alumno* leerAlumno() {
    string nombre;
    string apellido;
    string seccion;
    double nota_parcial1;
    double nota_parcial2;
 
    //lectura de alumno
    cout << "Ingrese un nombre:";
    cin >> nombre;
    cout << "Ingrese un apellido:";
    cin >> apellido;
    cout << "Ingrese un seccion:";
    cin >> seccion;
    do {
        cout << "Ingrese la nota parcial 1:";
        cin >> nota_parcial1;
    } while (nota_parcial1 < 0 || nota_parcial1>20);
 
    do {
        cout << "Ingrese la nota parcial 2:";
        cin >> nota_parcial2;
    } while (nota_parcial2 < 0 || nota_parcial2>20);
 
    return new Alumno(nombre, apellido, seccion, nota_parcial1, nota_parcial2);
 
}
void mostrarAprobados(Alumno** vector, int* N) {
    for (int i = 0; i < *N; i++) {
        if (vector[i]->esAprobado())
            vector[i]->imprimir();
    }
}
 
int main()
{
    int opcion;
    //creamos el vector de alumnos
    Alumno** vector = NULL;
    //creamos la variable del numero de elementos
    int* N;
    N = new int;
    *N = 0;
 
    do {
        //mostrar menu
        menu();
        opcion = leerEntero(1, 7);
        switch (opcion){
            case 1: {
                Alumno* alumno = leerAlumno();
                vector = agregarAlFinal(vector, N, alumno);
            }break;
        
            case 3: {
                mostrarAprobados(vector, N);
            }break;
        }
    } while (opcion != 7);
    
    return 0;
}