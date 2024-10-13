#include <iostream>

#include "funcionesGenerales.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"

#include <fstream>
#include <string>

//using namespace std;

Estacion(){
    //Constructor que inicializa el arreglo de surtidores
    sizeSurtidores = 1;
    surtidores = new Surtidor*[sizeSurtidores];
}

~Estacion() {
    //Para liberar todo lo dinamico.
    //liberarSurtidores();
}

//Getters
string getnombre(){return nombre;}
string getcodigoEstacion(){return codigoEstacion;}
string getgerente(){return gerente;}
string getregion(){return region;}
string getcoordenadas(){return coordenadas;}
int getsizeSurtidores(){return sizeSurtidores;}

//Setters
string setNombre(string newNombre){
    //Validar formato del parametro
    //nombre = newNombre;
}
string setCodigoEstacion(string newCodigoEstacion){
    //Validar formato del parametro
    //codigoEstacion = newCodigoEstacion;
}
string setGerente(string newGerente){
    //Validar formato del parametro
    //gerente = newGerente;
}
string setRegion(string newRegion){
    //Validar formato del parametro
    //region = newRegion;
}
string setCoordenadas(string newCoordenadas){
    //Validar formato del parametro
    //coordenadas = newCoordenadas;
}
int setSizeSurtidores(string newSizeSurtidores){
    //Validar formato del parametro
    //sizeSurtidores = newSizeSurtidores;
}


//                  METODOS


void expandirSurtidores(Surtidor**& arr, int& size) {
    //Metodo privado para expandir el arreglo de surtidores
    // Función que expande un arreglo dinámico
    // Crear un nuevo arreglo con una posición más
    Surtidor** nuevoArr = new Surtidor*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new Surtidor[4]; // tamaño del segundo arreglo por definir
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

    /*
    int nuevaCapacidad = capacidadSurtidores + 1;
    Surtidor* nuevoArreglo = new Surtidor*[nuevaCapacidad];
    for (int i = 0; i < numSurtidores; i++) {
        nuevoArreglo[i] = surtidores[i];
    }
    delete[] surtidores;
    surtidores = nuevoArreglo;
    capacidadSurtidores = nuevaCapacidad;
    */
}

void agregarSurtidor(const Surtidor& nuevoSurtidor) {
    //Metodo para agregar un surtidor

}

void eliminarSurtidor(const string& codigo) {
    //Metodo para eliminar un surtidor

}

void activarSurtidor(const string& codigoSurtidor){
    //cuestionable, yo creo que se puede hacer solo con el setter
}

void desactivarSurtidor(const string& codigoSurtidor){
    //cuestionable, yo creo que se puede hacer solo con el setter
}

void consultarHistorico(){
    //metodo publico para imprimir por pantalla o en ur archivo de texto plano el historico
    //de transacciones
}

void asignarCapacidadTanque(){
    // Asignar la capacidad del tanque de suministro, con un valor aleatorio entre
    //100 y 200 litros para cada una de las categorías
}

void reportarLitrosVendidos(){
    // Reportar la cantidad de litros vendida según cada categoría de combustible.
}


/*
Estacion::Estacion(int capacidadInicialSurtidores, const string& nombre, const string& codigoEstacion, const string& gerente, const string& region, const string& coordenadas)
    : nombre(nombre), codigoEstacion(codigoEstacion), gerente(gerente), region(region), coordenadas(coordenadas){
    //Constructor que inicializa el arreglo de surtidores
    numSurtidores = 0;
    capacidadSurtidores = capacidadInicialSurtidores;
    surtidores = new Surtidor*[capacidadSurtidores];
}
*/




