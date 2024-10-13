#include <iostream>

#include "funcionesGenerales.h"
#include "class_Estacion.h"

#include <fstream>
#include <string>

//using namespace std;

/*
            //Atributos

Estacion** estaciones; ///arreglo dinamico de estaciones
int numEstaciones; // size de estaciones

void expandirEstaciones();
void liberarEstaciones();
*/

/*
            //Metodos
//Constructor

RedNacional(int capacidadInicialEstaciones = 12);
//Destructor

~RedNacional();
//Getters

int getnumEstaciones()const;
int getcapacidadEstaciones()const;
//Setters

int setnumEstaciones();
int setCapacidadEstaciones();
//Metodos

void agregarEstacion(Estacion* nuevaEstacion);
void eliminarEstacion(const string& codigoEstacion);
void ventasCombustible();
void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra);
bool verificarFugas(const string& codigoEstacion);

*/



RedNacional::RedNacional(){
    //Constructor que inicializa el arreglo de estaciones
    sizeEstaciones = 1;
    estaciones = new Estacion*[sizeEstaciones];
}

RedNacional::~RedNacional(){
    //Destructor para liberar arreglo de estaciones luego de guardarlas
    for(int i = 0; i < sizeEstaciones; i++){
        delete estaciones[i];
    }
    delete[] estaciones;
}

//Getters
int RedNacional::getSizetaciones(){
    return sizeEstaciones;
}

//Setters
int RedNacional::setSizeEstaciones(int newSize){
    // validar el nuevo numero entero.
}

//                      Metodos


void RedNacional::expandirEstasiones(Estacion**& arr, int& size){
    //Metodo privado para expandir el arreglo de estaciones
    // Función que expande un arreglo dinámico
    // Crear un nuevo arreglo con una posición más
    Estacion** nuevoArr = new Estacion*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new string[4]; // tamaño del segundo arreglo por definir
    }

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            nuevoArr[i][j] = arr[i][j];
        }
    }

    // Liberar la memoria del arreglo original
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    // Actualizar el puntero para que apunte al nuevo arreglo
    arr = nuevoArr;

    // Aumentar el tamaño
    size += 1;

    //          Arreglo karen
    /*
    int nuevaCapacidad = capacidadEstaciones + 1;

    Estacion** nuevoArreglo = new Estacion*[nuevaCapacidad];
    for(int i = 0; i < numEstaciones; i++){
        nuevoArreglo[i] = estaciones[i];
    }
    delete[] estaciones;
    estaciones = nuevoArreglo;
    capacidadEstaciones = nuevaCapacidad;
    */
}

void RedNacional::agregarEstacion(){
    //Metodo publico para agregar una estacion
}

void RedNacional::eliminarEstacion(const string& codigoEstacion){
    //Metodo publico para eliminar una estacion (sólo si no posee surtidores activos).
}

void ventasCombustible(){
    //Metodo publico para calcular el monto total de ventas por estacion segun el combustible
}

void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra){
    //Metodo publico para fijar los precios del combustible
}

bool verificarFugas(const string& codigoEstacion){
    //Metodo publico para verificar fugas en las esatciones
}


/*
void expandirArreglo(string**& arr, int& size) {
    // Función que expande un arreglo dinámico
    // Crear un nuevo arreglo con una posición más
    string** nuevoArr = new string*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new string[4];
    }

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            nuevoArr[i][j] = arr[i][j];
        }
    }

    // Liberar la memoria del arreglo original
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    // Actualizar el puntero para que apunte al nuevo arreglo
    arr = nuevoArr;

    // Aumentar el tamaño
    size += 1;
}
*/










