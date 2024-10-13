#include <iostream>

#include "funcionesGenerales.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

//using namespace std;

/*
Surtidor(){
    //constructor que inicializa el arreglo de ventas
    sizeVentas = 1;
    ventas = new Ventas*[sizeVentas];
}

~Surtidor(){
    //Destructor, liberar dinamicos
    //liberarVentas();
}

//Getters
string getcodigoSurtidor(){return codigoSurtidor;}

string getmodelo(){return modelo;}

bool getactivo(){return activo;}

int getnumVentas(){return numVentas;}

int getcapacidadVentas(){return capacidadVentas;}

double getprecioRegular(){return precioRegular;}

double getprecioPremium(){return precioRegular;}

double getprecioEcoExtra(){return precioEcoExtra;}

void expandirVentas(Ventas**& arr, int& size){
    //Metodo privado para expandir el arreglo de ventas
    Ventas** nuevoArr = new Ventas*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new Ventas[4]; // tamaño del segundo arreglo por definir
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

void liberarVentas(){
    //Metodo privado para liberar el arreglo de ventas
    for(int i = 0; i < sizeVentas; i++){
        delete ventas[i];
    }
    delete[] ventas;
}
