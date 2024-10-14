#include <iostream>

#include "class_RedNacional.h"

#include <fstream>
#include <string>
#include <cctype>

using namespace std;

/*
    //Atributos
    static const int sizeRegion = 3;
    string regiones[sizeRegion];
    Estacion* estaciones; // arreglo dinamico de estaciones
    int sizeEstaciones = 0; // cantidad de estaciones
*/

RedNacional::RedNacional(){
    capacidadEstaciones = 1;
    estaciones = new Estacion[capacidadEstaciones];
}

RedNacional::RedNacional(const string arreglo[], int size){
    //Constructor que inicializa el arreglo de estaciones
    for (int i = 0; i < size; ++i) {
        regiones[i] = arreglo[i];  // Copiamos los elementos
    }
}

RedNacional::~RedNacional(){

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

void RedNacional:: agregarEstacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO){
    //Metodo publico para agregar una estacion
    if(sizeEstaciones == 0){
        sizeEstaciones += 1;
        estaciones = new Estacion[sizeEstaciones];
    }
    else {
        sizeEstaciones += 1;
        expandirEstaciones();
    }
    estaciones[sizeEstaciones-1] = Estacion(nombreO, codigoEstacionO, gerenteO, regionO, coordenadasO);
    estaciones[0].mostrarEstaciones();
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

void RedNacional:: mostrarArreglo(){
    //
    for (int i = 0; i < 4; ++i) {
        estaciones[i].mostrarEstaciones();
    }
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










