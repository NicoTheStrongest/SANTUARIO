#include <iostream>
#include <funcionesGenerales.h>
#include <class_Estacion.h>
#include <fstream>
#include <string>

using namespace std;

//Constructor que inicializa el arreglo de surtidores
Estacion::Estacion(int capacidadInicialSurtidores){
    numSurtidores = 0;
    capacidadSurtidores = capacidadInicialSurtidores;
    surtidores = new Surtidor[capacidadSurtidores];
}

//Metodo privado para expandir el arreglo de surtidores
void Estacion::expandirSurtidores() {
    int nuevaCapacidad = capacidadSurtidores * 2;
    Surtidor* nuevoArreglo = new Surtidor[nuevaCapacidad];
    for (int i = 0; i < numSurtidores; i++) {
        nuevoArreglo[i] = surtidores[i];
    }
    delete[] surtidores;
    surtidores = nuevoArreglo;
    capacidadSurtidores = nuevaCapacidad;
}

//Metodo para liberar la memoria de surtidores
void Estacion::liberarSurtidores() {
    for(int i = 0; i < numSurtidores; i++){
        delete surtidores[i]
    }
    delete[] Surtidores;
}

// Destructor
Estacion::~Estacion() {
    liberarSurtidores();
}

//Metodo para agregar un surtidor
void Estacion::agregarSurtidor(const Surtidor& nuevoSurtidor) {

}

//Metodo para eliminar un surtidor
void Estacion::eliminarSurtidor(const string& codigo) {
}