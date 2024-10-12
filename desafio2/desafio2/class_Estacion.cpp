#include <iostream>
#include <funcionesGenerales.h>
#include <class_Estacion.h>
#include <fstream>
#include <string>

using namespace std;

//Constructor que inicializa el arreglo de surtidores
Estacion::Estacion(int capacidadInicialSurtidores, const string& nombre, const string& codigoEstacion, const string& gerente, const string& region, const string& coordenadas){
    : nombre(nombre), codigoEstacion(codigoEstacion), gerente(gerente), region(region), coordenadas(coordenadas){}
    numSurtidores = 0;
    capacidadSurtidores = capacidadInicialSurtidores;
    surtidores = new Surtidor*[capacidadSurtidores];
}

//Getters
string Estacion::getnombre()const{
    return nombre;
}
string Estacion::getcodigoEstacion()const{
    return codigoEstacion;
}
string Estacion::getgerente()const{
    return gerente;
}
string Estacion::getregion()const{
    return region;
}
string Estacion::getcoordenadas()const{
    return coordenadas;
}
string Estacion::getnumSurtidores()const{
    return numSurtidores;
}
string Estacion::getcapacidadSurtidores()const{
    return capacidadSurtidores;
}

//Metodo privado para expandir el arreglo de surtidores
void Estacion::expandirSurtidores() {
    int nuevaCapacidad = capacidadSurtidores + 1;
    Surtidor* nuevoArreglo = new Surtidor*[nuevaCapacidad];
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
        delete surtidores[i];
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