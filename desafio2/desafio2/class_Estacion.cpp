#include <iostream>

#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

/*
    //Atributos
    Surtidor* surtidores; // Arreglo dinamico de surtidores de la estacion
    std::string nombre, codigoEstacion, gerente, region, coordenadas; // atributos surtidor
    int sizeSurtidores = 0;
    int naves[6];
*/

Estacion::Estacion(){}

Estacion::Estacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO) {
    //Constructor que inicializa el arreglo de surtidores
    nombre = nombreO;
    codigoEstacion = codigoEstacionO;
    gerente = gerenteO;
    region = regionO;
    coordenadas = coordenadasO;
}

Estacion::~Estacion() {}

string Estacion:: getnombre() const { return nombre; }
string Estacion:: getcodigoEstacion()const{return codigoEstacion;}
string Estacion:: getgerente()const{return gerente;}
string Estacion:: getregion()const{return region;}
string Estacion:: getcoordenadas()const{return coordenadas;}
int Estacion:: getsizeSurtidores()const{return sizeSurtidores;}

//Setters
std::string setNombre(std::string newNombre){
    //Validar formato del parametro
    //nombre = newNombre;
}
std::string setCodigoEstacion(std::string newCodigoEstacion){
    //Validar formato del parametro
    //codigoEstacion = newCodigoEstacion;
}
std::string setGerente(std::string newGerente){
    //Validar formato del parametro
    //gerente = newGerente;
}
std::string setRegion(std::string newRegion){
    //Validar formato del parametro
    //region = newRegion;
}
std::string setCoordenadas(std::string newCoordenadas){
    //Validar formato del parametro
    //coordenadas = newCoordenadas;
}
int setSizeSurtidores(std::string newSizeSurtidores){
    //Validar formato del parametro
    //sizeSurtidores = newSizeSurtidores;
}


//                  METODOS


void Estacion:: expandirSurtidores() {
    //Metodo privado para expandir el arreglo de surtidores
    // Crear un nuevo arreglo con una posición más
    int nuevaCapacidad = capacidadSurtidores + 1;
    Surtidor* nuevoArr = new Surtidor[nuevaCapacidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeSurtidores; ++i) {
        nuevoArr[i] = surtidores[i];
    }

    // Liberar la memoria del arreglo original
    delete[] surtidores;

    // Actualizar el puntero para que apunte al nuevo arreglo
    surtidores = nuevoArr;
    capacidadSurtidores = nuevaCapacidad;
}

void Estacion:: expandirNaves() {
    //Metodo privado para expandir el arreglo de surtidores
    // Crear un nuevo arreglo con una posición más
    int nuevaCapacidad = capacidadNaves + 1;
    string* nuevoArr = new string[nuevaCapacidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < navesActuales; ++i) {
        nuevoArr[i] = naves[i];
    }

    // Liberar la memoria del arreglo original
    delete[] naves;

    // Actualizar el puntero para que apunte al nuevo arreglo
    naves = nuevoArr;
    capacidadNaves = nuevaCapacidad;
}

void Estacion:: agregarSurtidor(string codigo, string modelo, bool estado) {
    //Metodo para agregar un surtidor
    if(sizeSurtidores == 0){surtidores = new Surtidor[capacidadNaves];}
    else{
        if (sizeSurtidores == capacidadSurtidores) {
            expandirSurtidores();  // Si el arreglo está lleno, lo expandimos
        }
    }
    surtidores[sizeSurtidores] = Surtidor(codigo, modelo, estado);
    sizeSurtidores++;
}

void Estacion:: mostrarEstaciones(){
    cout << "Nombre: " << nombre << ", Codigo: " << codigoEstacion << std::endl;
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

void Estacion:: agregarNaveLectura(string codigo){
    //agrega los codios al arreglo de naves
    if(navesActuales == 0){naves = new string[capacidadNaves];}
    else{
        if (navesActuales == capacidadNaves) {
            expandirNaves();  // Si el arreglo está lleno, lo expandimos
        }
    }
    naves[navesActuales] = codigo;
    navesActuales++;
}

void Estacion:: mostrarNaves(){
    //mostar arreglo de naves
    for (int i = 0; i < 6; ++i) {
        cout<<naves[i]<<"aa";
    }
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




