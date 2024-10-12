#include <iostream>
#include <funcionesGenerales.h>
#include <class_RedNacional.h>
#include <fstream>
#include <string>

using namespace std;

//Constructor que inicializa el arreglo de estaciones
RedNacional::RedNacional(int capacidadInicialEstaciones){
    numEstaciones = 0
    capacidadEstaciones = capacidadInicialEstaciones;
    estaciones = new Estacion*[capacidadEstaciones];
}

//Getters
int RedNacional::getnumEstaciones()const{
    return numEstaciones;
}
int RedNacional::getcapacidadEstaciones()const{
    return capacidadEstaciones;
}

//Metodo privado para expandir el arreglo de estaciones
void RedNacional::expandirEstasiones(){
    int nuevaCapacidad = capacidadEstaciones + 1;
    Estacion** nuevoArreglo = new Estacion*[nuevaCapacidad];
    for(int i = 0; i < numEstaciones; i++){
        nuevoArreglo[i] = estaciones[i];
    }
    delete[] estaciones;
    estaciones = nuevoArreglo;
    capacidadEstaciones = nuevaCapacidad;
}
//Metodo privado para liberar el arreglo de estaciones
void RedNacional::liberarEstaciones(){
    for(int i = 0; i < numEstaciones; i++){
        delete estaciones[i];
    }
    delete[] estaciones;
}

//Destructor
RedNacional::~RedNacional(){
    liberarEstaciones();
}

//Metodo publico para agregar una estacion
void RedNacional::agregarEstacion(Estacion* nuevaEstacion){

}

//Metodo publico para eliminar una estacion
void RedNacional::eliminarEstacion(const string& codigoEstacion){

}

//Metodo publico para calcular el monto total de ventas por estacion segun el combustible
void ventasCombustible(){

}

//Metodo publico para fijar los precios del combustible
void fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra){

}

//Metodo publico para verificar fugas en las esatciones
bool verificarFugas(const string& codigoEstacion);



