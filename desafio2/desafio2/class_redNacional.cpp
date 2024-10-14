#include <iostream>

#include "class_RedNacional.h"
#include "class_Estacion.h"

#include <fstream>
#include <string>
#include <cctype>

using namespace std;


RedNacional::RedNacional(){
    //Constructor que inicializa el arreglo de estaciones
    sizeEstaciones = 1;
    expandirEstaciones(estaciones, &sizeEstaciones);
}

RedNacional::~RedNacional(){
    //Destructor para liberar arreglo de estaciones luego de guardarlas
    delete[] estaciones;
}

//Getters
int RedNacional:: getSizetaciones() const {
    return sizeEstaciones;
}

//Setters
void RedNacional:: setSizeEstaciones(int newSize){
    // validar el nuevo numero entero.
    if(newSize > 0){
        sizeEstaciones = newSize;
    }
    else{
        cout << "newSize debe ser mayor a cero." << endl;
    }
}

//                      Metodos


void RedNacional:: expandirEstaciones(Estacion*& arr, int* size){
    //Metodo privado para expandir el arreglo de estaciones
    // Crear un nuevo arreglo con una posición más
    Estacion* nuevoArr = new Estacion[(*size) + 1];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < *size; ++i) {
        nuevoArr[i] = arr[i];
    }

    // Liberar la memoria del arreglo original
    delete[] arr;

    // Actualizar el puntero para que apunte al nuevo arreglo
    arr = nuevoArr;

    // Aumentar el tamaño
    *size += 1;

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

void RedNacional:: agregarEstacion(Estacion* nuevaEstacion){
    //Metodo publico para agregar una estacion
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

bool RedNacional::verificarFugas(const string& codigoEstacion){
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










