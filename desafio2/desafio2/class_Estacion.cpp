#include <iostream>

#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

Estacion::Estacion(){}

Estacion::Estacion(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO) {
    //Constructor
    nombre = nombreO;
    codigoEstacion = codigoEstacionO;
    gerente = gerenteO;
    region = regionO;
    coordenadas = coordenadasO;
}

Estacion::~Estacion() {}

//Getters
string Estacion:: getnombre() const { return nombre; }
string Estacion:: getcodigoEstacion()const{return codigoEstacion;}
string Estacion:: getgerente()const{return gerente;}
string Estacion:: getregion()const{return region;}
string Estacion:: getcoordenadas()const{return coordenadas;}
int Estacion:: getsizeSurtidores()const{return sizeSurtidores;}
int Estacion:: getCapacidadSurtidores()const{return capacidadSurtidores;}

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


void Estacion:: expandirSurtidores() {
    //Metodo publico para expandir el arreglo de surtidores
    // Crear un nuevo arreglo con una posición más
    capacidadSurtidores = capacidadSurtidores + 1;
    Surtidor* nuevoArr = new Surtidor[capacidadSurtidores];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeSurtidores; ++i) {
        nuevoArr[i] = surtidores[i];
    }

    // Liberar la memoria del arreglo original
    delete[] surtidores;

    // Actualizar el puntero para que apunte al nuevo arreglo
    surtidores = nuevoArr;
}

void Estacion::agregarSurtidor() {
    //Metodo para agregar un surtidor
    string codigo, modelo;
    cout << "Ingrese el codigo para el nuevo surtidor: " << endl;
    cin >> codigo;
    //verificar codigo no repetido
    for(int i = 0; i < sizeSurtidores; i++ ){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            cout << "El surtidor " << codigo << " ya existe" << endl;
            return;
        }
    }
    //Menu para seleccionar el modelo del surtidor
    int opcion;
    do{
        cout << "Seleccione el modelo del surtidor: " << endl;
        cout << "1. Modelo 1 " << endl;
        cout << "2. Modelo 2 " << endl;
        cout << "3. Modelo 3 " << endl;
        cin >> opcion;
        switch(opcion) {
        case 1:
            modelo = "modelo1";
            break;
        case 2:
            modelo = "modelo2";
            break;
        case 3:
            modelo = "modelo3";
            break;
        default:
            cout << "Opcion no valida. Por favor, intente nuevamente. " << endl;
            break;
        }
    } while((opcion < 1) || (opcion > 3));

    agregarSurtidorLectura(codigo,modelo,true);
    cout << "Surtidor " << codigo << " agregado exitosamente." << endl;
}


void Estacion:: agregarSurtidorLectura(string codigo, string modelo, bool estado) {
    //Metodo para agregar un surtidor
    if(sizeSurtidores == 0){surtidores = new Surtidor[capacidadSurtidores];}
    else{
        if (sizeSurtidores == capacidadSurtidores) {
            expandirSurtidores();
        }
    }
    surtidores[sizeSurtidores] = Surtidor(codigo, modelo, true);
    sizeSurtidores++;
}

void Estacion:: mostrarEstaciones(){cout<<codigoEstacion<<"->\t"<<nombre<<endl;}

string Estacion::obtenerCodigosurtidor(){
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea eliminar: " << endl;
    cin >> codigo;
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            return codigo;
        }
    }
    cout << "El surtidor " << codigo << " no existe." << endl;
    return "";
}


void Estacion:: eliminarSurtidor(string codigo) {
    //Metodo para eliminar un surtidor
    int posicion = -1;
    //Encontrar surtidor en el arreglo
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            posicion = i;
            break;
        }
    }
    if(posicion == -1){
        cout << "Surtidor " << codigo << " no existe." << endl;
        return;
    }

    //Inicializa el arreglo
    Surtidor* nuevoArregloSurtidores = new Surtidor[ sizeSurtidores - 1];
    //Copia los elementos hasta encontrar al surtidor
    for(int i = 0; i < posicion; i++){
        nuevoArregloSurtidores[i] = surtidores[i];
    }
    for(int j = posicion; j < sizeSurtidores - 1; j++){
        nuevoArregloSurtidores[j] = surtidores[j + 1];
    }
    //Elimina el arreglo antiguo
    delete[] surtidores;
    //Actualiza el arreglo
    surtidores = nuevoArregloSurtidores;
    //Actualiza el tamaño del arreglo
    sizeSurtidores--;
    cout << "Surtidor " << codigo << " eliminado con exito." << endl;
}

void Estacion:: eliminarSurtidoresNavesEstacion(bool eliminar, string codigo){
    //Metodo publico para eliminar una surtidores y naves asociados a una estacion.
    if(eliminar == false){
        cout <<"No se pueden eliminar los surtidores ni las naves de la estacion "<<codigo<<endl;
        system("pause");
        return;
    }
    else{
        //Eliminar surtidores.
        //contar codigos que inician por el codigo
        int menosSize = 0;
        string codigoSurtidor;
        for (int i = 0; i < sizeSurtidores; ++i) {
            codigoSurtidor = (surtidores[i].getCodigoSurtidor())[0];
            if(codigoSurtidor == codigo){menosSize++;}
        }
        Surtidor* nuevoArr = new Surtidor[sizeSurtidores - menosSize];
        //Copia los elementos hasta encontrar al surtidor
        for(int i = 0, j = 0; i < sizeSurtidores; i++){
            codigoSurtidor = (surtidores[i].getCodigoSurtidor())[0];
            if(codigoSurtidor != codigo){nuevoArr[j] = surtidores[i]; j++;}
        }
        //Elimina el arreglo antiguo
        delete[] surtidores;
        //Actualiza el arreglo
        surtidores = nuevoArr;
        //Actualiza el tamaño del arreglo
        sizeSurtidores = sizeSurtidores - menosSize;
        cout << "Estacion " << codigo << " eliminada con exito." << endl;

        //eliminar naves.
        string codNaves;
        for (int i = 0; i < navesActuales; ++i) {
            codNaves = naves[i][0];
            if (codNaves == codigo){naves[i] = "libre";}
        }
    }
}

void Estacion:: activarSurtidor(){
    // Metodo para activar un surtidor
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea activar: " << endl;
    cin >> codigo;
    //Verifica si el codigo existe
    bool surtidorExiste = false;
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            surtidorExiste = true;
            //Verifica si esta desactivado
            if(!surtidores[i].getEstado()){
                surtidores[i].setEstado(true);
                cout << "Surtidor " << codigo << " ha sido activado con exito." << endl;
            }
            else{
                cout << "El surtidor " << codigo << " ya esta activo." << endl;
            }
            break;
        }
    }
    if(!surtidorExiste){
        cout << "Surtidor " << codigo << " no existe." << endl;
    }
}

void Estacion::desactivarSurtidor(){
    //Metodo para desactivar un surtidor
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea activar: " << endl;
    cin >> codigo;
    //Verifica si el codigo existe
    bool surtidorExiste = false;
    for(int i = 0; i < sizeSurtidores; i++){
        if(surtidores[i].getCodigoSurtidor() == codigo){
            surtidorExiste = true;
            //Verifica si esta activo
            if(surtidores[i].getEstado()){
                surtidores[i].setEstado(false);
                cout << "Surtidor " << codigo << " ha sido activado con exito." << endl;
            }
            else{
                cout << "El surtidor " << codigo << " ya esta activo." << endl;
            }
            break;
        }
    }
    if(!surtidorExiste){
        cout << "Surtidor " << codigo << " no existe." << endl;
    }
}
/*
void Estacion::consultarHistorico(){
    //metodo publico para imprimir por pantalla o en un archivo de texto plano el historico
    //de transacciones
    //Obtener nombre de la estacion
    cout << "Historial de ventas de la estacion " << nombre << endl;
    //Recorrer arreglo de surtidores
    for(int i = 0; i < sizeSurtidores; i++){
        string codigoSurtidor = surtidores[i].getCodigoSurtidor();
        cout << "Ventas del surtidor " << codigoSurtidor << endl;
        //Encontrar ventas asociadas al surtidor
        bool ventasSurtidor = false;
        for(int j = 0; j < sizeVentas; j++){
            if(ventas[j].getCodigoVenta() == codigoSurtidor){
                ventas[j].detallesVentas();
                ventasSurtidor = true;
            }
        }
        if(!ventasSurtidor){
            cout << "no hay ventas registradas para este surtidor" << endl;
        }
    }
}
*/

void Estacion:: asignarCapacidadTanque(){
    // Asignar la capacidad del tanque de suministro, con un valor aleatorio entre
    //100 y 200 litros para cada una de las categorías

}

void Estacion:: reportarLitrosVendidos(){
    // Reportar la cantidad de litros vendida según cada categoría de combustible.
}

void Estacion:: simularVenta(){}

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
    for (int i = 0; i < navesActuales; ++i) {
        cout<<naves[i]<<endl;
    }
}

bool Estacion:: surtidoresInactivos(string codigoEstacion){
    //verificar si una estacion tiene surtidores inactivos
    string codSurtidor;
    bool estado;
    for (int i = 0; i < sizeSurtidores; ++i) {
        codSurtidor = (surtidores[i].getCodigoSurtidor())[0];
        if(codSurtidor == codigoEstacion){
            estado = surtidores[i].getEstado();
            if(estado){return false;}
        }
    }
    return true;
}

Surtidor* Estacion:: getSurtidores() const {return surtidores;}

/*
Estacion::Estacion(int capacidadInicialSurtidores, const string& nombre, const string& codigoEstacion, const string& gerente, const string& region, const string& coordenadas)
    : nombre(nombre), codigoEstacion(codigoEstacion), gerente(gerente), region(region), coordenadas(coordenadas){
    //Constructor que inicializa el arreglo de surtidores
    numSurtidores = 0;
    capacidadSurtidores = capacidadInicialSurtidores;
    surtidores = new Surtidor*[capacidadSurtidores];
}
*/




