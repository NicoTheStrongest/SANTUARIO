#include <iostream>

#include "funcionesGenerales.h"
#include "class_Surtidor.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

Surtidor::Surtidor(){}

Surtidor::Surtidor(string codigoSurtidor, string modelo, bool activo): codigoSurtidor(codigoSurtidor), modelo(modelo){
    //constructor que inicializa el arreglo de ventas
    precioRegular = 0;
    precioPremium = 0;
    precioEcoExtra = 0;
    sizeVentas = 1;
    expandirVentas(ventas, &sizeVentas);
}

Surtidor::~Surtidor(){
    //Destructor, liberar dinamicos
    //liberarVentas();
}

//Getters
string Surtidor:: getCodigoSurtidor() const {return codigoSurtidor;}

string Surtidor:: getModelo() const {return modelo;}

bool Surtidor:: getActivo() const {return activo;}

int Surtidor:: getSizeVentas() const {return sizeVentas;}

double Surtidor:: getPrecioRegular() const {return precioRegular;}

double Surtidor:: getPrecioPremium() const {return precioRegular;}

double Surtidor:: getPrecioEcoExtra() const {return precioEcoExtra;}

void Surtidor:: expandirVentas(Ventas*& arr, int* size){
    //Metodo privado para expandir el arreglo de ventas
    Ventas* nuevoArr = new Ventas[(*size) + 1];

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
}









