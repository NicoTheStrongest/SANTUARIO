#include <iostream>
#include <funcionesGenerales.h>
#include <class_Surtidor.h>
#include <fstream>
#include <string>

using namespace std;

//constructor que inicializa el arreglo de ventas
Surtidor::Surtidor(int capacidadInicialVentas,const string& codigoSurtidor,const string& modelo,bool activo,double precioRegular,double precioPremium,double precioEcoExtra){

    numVentas = 0;
    capacidadVentas = capacidadInicialVentas;
    ventas = new Ventas*[capacidadVentas];
}

//Getters
string Surtidor::getcodigoSurtidor()const{
    return codigoSurtidor;
}
string Surtidor::getmodelo()const{
    return modelo;
}
bool Surtidor::getactivo()const{
    return activo;
}
int Surtidor::getnumVentas()const{
    return numVentas;
}
int Surtidor::getcapacidadVentas()const{
    return capacidadVentas;
}
double Surtidor::getprecioRegular()const{
    return precioRegular;
}
double Surtidor::getprecioPremium()const{
    return precioRegular;
}
double Surtidor::getprecioEcoExtra()const{
    return precioEcoExtra;
}

//Metodo privado para expandir el arreglo de ventas
void Surtidor::expandirVentas(){
    int nuevaCapacidad = capacidadVentas + 1;
    Ventas** nuevoArreglo = new Ventas*[nuevaCapacidad];
    for(int i = 0; i < numVentas; i++){
        nuevoArreglo[i] = ventas[i];
    }
    delete[] ventas;
    ventas = nuevoArreglo;
    capacidadVentas = nuevaCapacidad;
}

//Metodo privado para liberar el arreglo de ventas
void Surtidor::liberarVentas(){
    for(int i = 0; i < numVentas; i++){
        delete ventas[i];
    }
    delete[] ventas;
}

//Destructor
Surtidor::~Surtidor(){
    liberarVentas();
}
