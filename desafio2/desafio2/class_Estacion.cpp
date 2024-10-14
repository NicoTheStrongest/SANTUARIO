#include <iostream>

#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

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
}

void agregarSurtidor() {
    //Metodo para agregar un surtidor
    string codigo, modelo;
    cout << "Ingrese el codigo para el nuevo surtidor: " << endl;
    cin >> codigo;
    //verificar codigo valido y no repetido
    for(int i = 0; i < ){

    }
    cout << "Ingrese el modelo del nuevo surtidor(modelo1, modelo2, modelo3): " << endl;
    cin >> modelo;
    while(modelo != "modelo1" || modelo != "modelo2" || modelo != "modelo3"){
        cout << "Modelo de surtidor no valido, intente nuevamente: " << endl;
        cin >> modelo;
    }
    //Expansion del arreglo
    //Estacion::expandirSurtidores();



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

void eliminarSurtidor() {
    //Metodo para eliminar un surtidor
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea eliminar: " << endl;
    cin >> codigo;
    int posicion = -1;
    //Encontrar surtidor en el arreglo
    for(int i = 0; i < tamanio; i++){
        if(arreglo[i] == codigo){
            posicion = i;
            break;
        }
    }
    if(posicion == -1){
        cout << "Surtidor " << codigo << "no existe." << endl;
    }
    //Inicializa el arreglo
    string* nuevoArreglo = new string[tamanio -1];
    //Copia los elementos hasta encontrar al surtidor
    for(int i = 0; i < posicion; i++){
        nuevoArreglo[i] = arreglo[i];
    }
    for(int j = pos; j < tamanio -1; j++){
        nuevoArreglo = arreglo[j + 1];
    }
    delete arreglo[posicion];
    arreglo = nuevoArreglo;
    /*
    //Desplazar los elementos
    for(int i = posicion; i < tamanio - 1; i++){
        arreglo[i] = arreglo[i + 1];
    }
    tamanio--;
    //inicializo el arreglo
    string* nuevoarreglo = new string[tamanio];
    //copio los elementos
    for(int i = 0; i < tamanio; i++){
        nuevoarreglo[i] = arreglo[i];
    }
    //Liberar la memoria
    delete[] arreglo;
    //apuntar al nuevo arreglo
    arreglo = nuevoarreglo;
*/

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




