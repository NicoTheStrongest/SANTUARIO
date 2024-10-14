#include <iostream>

#include "funcionesGenerales.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"

#include <fstream>
#include <string>
#include <cctype>

using namespace std;

Estacion::Estacion(){}

Estacion::Estacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO) {
    //Constructor que inicializa el arreglo de surtidores
    nombre = nombreO;
    codigoEstacion = codigoEstacionO;
    gerente = gerenteO;
    region = regionO;
    coordenadas = coordenadasO;
    sizeSurtidores += 1;
    expandirSurtidores(surtidores, &sizeSurtidores);
}

Estacion::~Estacion() {}

//Getters
string Estacion:: getnombre() const { return nombre; }
string Estacion:: getcodigoEstacion()const{return codigoEstacion;}
string Estacion:: getgerente()const{return gerente;}
string Estacion:: getregion()const{return region;}
string Estacion:: getcoordenadas()const{return coordenadas;}
int Estacion:: getsizeSurtidores()const{return sizeSurtidores;}

//Setters
void Estacion::setNombre(std::string newNombre){
    //Validar formato del parametro
    if(newNombre.empty()){
        nombre = newNombre;
    }
    else{
        cout << "El nombre no puede estar vacio." << endl;
    }

}
void Estacion::setCodigoEstacion(std::string newCodigoEstacion){
    //Validar formato del parametro
    if(newCodigoEstacion.length() == 1){
        codigoEstacion = newCodigoEstacion;
    }
    else{
        cout << "El codigo de la estacion deber contener un solo caracter." << endl;
    }
}
void Estacion::setGerente(std::string newGerente){
    //Validar formato del parametro
    if (newGerente.length() == 10){
        gerente = newGerente;
    }
    else{
        cout << "El documento del gerente debe tener diez caracteres." << endl;
    }
}
void Estacion::setRegion(std::string newRegion){
    //Validar formato del parametro
    if(newRegion == "norte" || newRegion == "centro" || newRegion == "sur" ){
        region = newRegion;
    }
    else{
        cout << "La region debe ser 'norte', 'centro' o 'sur'." << endl;
    }

}
void Estacion::setCoordenadas(std::string newCoordenadas){
    //Validar formato del parametro
    coordenadas = newCoordenadas;
}
void Estacion::setSizeSurtidores(int newSizeSurtidores){
    //Validar formato del parametro
    if(newSizeSurtidores > 0){
        sizeSurtidores = newSizeSurtidores;
    }
    else{
        cout << "sizeSurtidores debe ser mayor a cero." << endl;
    }
}


//                  METODOS


void Estacion:: expandirSurtidores(Surtidor*& arr, int* size) {
    //Metodo publico para expandir el arreglo de surtidores
    // Función que expande un arreglo dinámico
    // Crear un nuevo arreglo con una posición más
    Surtidor* nuevoArr = new Surtidor[(*size) + 1];

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

void eliminarSurtidor(const std::string& codigo) {
    //Metodo para eliminar un surtidor

}

void activarSurtidor(const std::string& codigoSurtidor){
    //cuestionable, yo creo que se puede hacer solo con el setter
}

void desactivarSurtidor(const std::string& codigoSurtidor){
    //cuestionable, yo creo que se puede hacer solo con el setter
}

void consultarHistorico(){
    //metodo publico para imprimir por pantalla o en un archivo de texto plano el historico
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




