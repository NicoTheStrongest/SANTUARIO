#include <iostream>

#include "class_RedNacional.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

/*
Estacion* estaciones; // arreglo dinamico de estaciones
int sizeEstaciones = 0; // cantidad de estaciones
int capacidadEstaciones = 2;

static const int sizeRegion = 3;
string regiones[sizeRegion];
*/

RedNacional::RedNacional(): sizeEstaciones(0), capacidadEstaciones(2) {
    estaciones = new Estacion[capacidadEstaciones];
}

RedNacional::~RedNacional(){

}

//Getters
int RedNacional:: getSizetaciones() const {
    return sizeEstaciones;
}

//Setters
int RedNacional:: setSizeEstaciones(int newSize){
    // validar el nuevo numero entero.
}

//                      Metodos


void RedNacional:: expandirEstaciones(){
    //Metodo privado para expandir el arreglo de estaciones
    // Crear un nuevo arreglo con una posición más
    int nuevaCapadidad = capacidadEstaciones + 1;
    Estacion* nuevoArr = new Estacion[nuevaCapadidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeEstaciones; ++i) {
        nuevoArr[i] = estaciones[i];
    }

    // Liberar la memoria del arreglo original
    delete[] estaciones;

    // Actualizar el puntero para que apunte al nuevo arreglo
    estaciones = nuevoArr;
    capacidadEstaciones = nuevaCapadidad;
}

void RedNacional:: agregarEstacionLectura(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO){
    //Metodo publico para agregar una estacion
    if (sizeEstaciones == capacidadEstaciones) {
        expandirEstaciones();  // Si el arreglo está lleno, lo expandimos
    }
    estaciones[sizeEstaciones] = Estacion(nombreO, codigoEstacionO, gerenteO, regionO, coordenadasO);
    sizeEstaciones += 1;
}

void RedNacional:: eliminarEstacion(const std::string& codigoEstacion){
    //Metodo publico para eliminar una estacion (sólo si no posee surtidores activos).
}

void RedNacional:: ventasCombustible(){
    //Metodo publico para calcular el monto total de ventas por estacion segun el combustible
}

void RedNacional:: fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra){
    //Metodo publico para fijar los precios del combustible
}

bool RedNacional:: verificarFugas(const std::string& codigoEstacion){
    //Metodo publico para verificar fugas en las esatciones
}

void RedNacional:: mostrarArreglo(){
    //
    for (int i = 0; i < sizeEstaciones; ++i) {
        estaciones[i].mostrarEstaciones();
    }
}

void RedNacional::agregarRegiones(string arreglo[]){
    for (int i = 0; i < sizeRegion ; ++i) {
        regiones[i] = arreglo[i];
    }
}







Estacion* RedNacional:: getEstaciones() const {return estaciones;}

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










