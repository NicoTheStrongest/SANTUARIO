#include <iostream>

#include "funcionesGenerales.h"
#include "class_RedNacional.h"
#include "class_Estacion.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

//                  Constructor y destructor
RedNacional::RedNacional(): sizeEstaciones(0), capacidadEstaciones(2) {
    estaciones = new Estacion[capacidadEstaciones];

    // Inicializar los precios (Ejemplo)
    precios[0][0] = 1.10;  // Norte, Regular
    precios[0][1] = 1.50;  // Norte, Premium
    precios[0][2] = 1.30;  // Norte, EcoExtra

    precios[1][0] = 1.00;  // Centro, Regular
    precios[1][1] = 1.40;  // Centro, Premium
    precios[1][2] = 1.25;  // Centro, EcoExtra

    precios[2][0] = 1.20;  // Sur, Regular
    precios[2][1] = 1.60;  // Sur, Premium
    precios[2][2] = 1.35;  // Sur, EcoExtra
}

RedNacional::~RedNacional(){

}

//                  Getters - Setters
int RedNacional:: getSizetaciones() const {
    return sizeEstaciones;
}
int RedNacional:: setSizeEstaciones(int newSize){
    // validar el nuevo numero entero.
}
int setCapacidadEstaciones(){}

//                      Metodos


void RedNacional:: expandirEstaciones(){
    //Metodo privado para expandir el arreglo de estaciones
    // Crear un nuevo arreglo con una posición más
    int nuevaCapadidad = capacidadEstaciones + 1;
    Estacion* nuevoArr = new Estacion[nuevaCapadidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeEstaciones; ++i) {
        nuevoArr[i] = estaciones[i];
    }

    // Liberar la memoria del arreglo original
    delete[] estaciones;

    // Actualizar el puntero para que apunte al nuevo arreglo
    estaciones = nuevoArr;
    capacidadEstaciones = nuevaCapadidad;
}

void RedNacional:: agregarEstacionLectura(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO){
    //Metodo publico para agregar una estacion
    if (sizeEstaciones == capacidadEstaciones) {
        expandirEstaciones();  // Si el arreglo está lleno, lo expandimos
    }
    estaciones[sizeEstaciones] = Estacion(nombreO, codigoEstacionO, gerenteO, regionO, coordenadasO);
    sizeEstaciones += 1;
}

void RedNacional:: agregarEstacion(){
    //Pide y valida todos los datos del una estacion para luego agregarla
    string nombre, documento, codigo, region, gps;
    int cod = sizeEstaciones + 1;
    codigo = to_string(cod);

    cout<<"Ingrese nombre de la estacion: ";
    cin.ignore();
    getline(cin, nombre);

    cout<<"Ingrese documento del gerente de la estacion: ";
    getline(cin, documento);
    formatoDocumento(&documento);

    string prints;
    prints = "./../../prints/MenuRegion.txt";
    leerArchivoPorLinea(prints);
    string mensaje1 = "Escoja un opcion: ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";
    const int size = 3;
    string opcionesValidas[size] = {"1", "2", "3"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    if(opcionElegida == 1){region = "Norte";}
    if(opcionElegida == 2){region = "Centro";}
    if(opcionElegida == 3){region = "Sur";}

    cout<<"Ingrese las coordenadas de la estacion: ";
    cin.ignore();
    getline(cin, gps);

    if (sizeEstaciones == capacidadEstaciones) {
        expandirEstaciones();  // Si el arreglo está lleno, lo expandimos
    }
    estaciones[sizeEstaciones] = Estacion(nombre, codigo, documento, region, gps);
    sizeEstaciones += 1;
}

void RedNacional:: eliminarEstacion(bool bandera, string codigoEliminar){
    //Metodo publico para eliminar una estacion (sólo si no posee surtidores activos).
    int posicion = -1;
    //Encontrar surtidor en el arreglo
    for(int i = 0; i < sizeEstaciones; i++){
        if(estaciones[i].getcodigoEstacion() == codigoEliminar){
            posicion = i;
            break;
        }
    }
    if(bandera == false){
        cout << "Estacion " << codigoEliminar << " no se puede eliminar" << endl;
        return;
    }
    else{
        //Inicializa el arreglo
        Estacion* nuevoArr = new Estacion[sizeEstaciones - 1];
        //Copia los elementos hasta encontrar al surtidor
        for(int i = 0; i < posicion; i++){
            nuevoArr[i] = estaciones[i];
        }
        for(int j = posicion; j < sizeEstaciones - 1; j++){
            nuevoArr[j] = estaciones[j + 1];
        }
        //Elimina el arreglo antiguo
        delete[] estaciones;
        //Actualiza el arreglo
        estaciones = nuevoArr;
        //Actualiza el tamaño del arreglo
        sizeEstaciones--;
    }
    system("pause");
}

string RedNacional:: obtenerCodigoEstacion(){
    //Pide un codigo de estacion y lo retorna
    limpiarPantalla();
    mostrarArregloEstaciones();
    string codigoEliminar;
    cout<<"Escoja una opcion: ";
    cin.ignore();
    getline(cin, codigoEliminar);
    return codigoEliminar;
}

/*
void Estacion::eliminarSurtidor(Surtidor*& arr, int* size) {
    //Metodo para eliminar un surtidor
    string codigo;
    cout << "Ingrese el codigo del surtidor que desea eliminar: " << endl;
    cin >> codigo;
    int posicion = -1;
    //Encontrar surtidor en el arreglo
    for(int i = 0; i < (*size); i++){
        if(arr[i].getCodigoSurtidor() == codigo){
            posicion = i;
            break;
        }
    }
    if(posicion == -1){
        cout << "Surtidor " << codigo << " no existe." << endl;
        return;
    }
    //Inicializa el arreglo
    Surtidor* nuevoArr = new Surtidor[(*size) - 1];
    //Copia los elementos hasta encontrar al surtidor
    for(int i = 0; i < posicion; i++){
        nuevoArr[i] = arr[i];
    }
    for(int j = posicion; j < (*size) - 1; j++){
        nuevoArr[j] = arr[j + 1];
    }
    //Elimina el arreglo antiguo
    delete[] arr;
    //Actualiza el arreglo
    arr = nuevoArr;
    //Actualiza el tamaño del arreglo
    (*size)--;
    cout << "Surtidor " << codigo << " eliminado con exito." << endl;

}
*/

void RedNacional:: ventasCombustible(){
    //Metodo publico para calcular el monto total de ventas por estacion segun el combustible
}

void RedNacional:: fijarPrecios(double precioRegular,double precioPremium,double precioEcoExtra){
    //Metodo publico para fijar los precios del combustible
}

bool RedNacional:: verificarFugas(const std::string& codigoEstacion){
    //Metodo publico para verificar fugas en las esatciones
}

void RedNacional:: mostrarArregloEstaciones(){
    //
    for (int i = 0; i < sizeEstaciones; ++i) {
        estaciones[i].mostrarEstaciones();
    }
}

void RedNacional::agregarRegiones(string arreglo[]){
    for (int i = 0; i < sizeRegion ; ++i) {
        regiones[i] = arreglo[i];
    }
}







Estacion* RedNacional:: getEstaciones() const {return estaciones;}

/*
void expandirArreglo(string**& arr, int& size) {
    // Función que expande un arreglo dinámico
    // Crear un nuevo arreglo con una posición más
    string** nuevoArr = new string*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new string[4];
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
}
*/










