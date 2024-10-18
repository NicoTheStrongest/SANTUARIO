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

RedNacional::RedNacional() : sizeEstaciones(0), capacidadEstaciones(2){
    estaciones = new Estacion[capacidadEstaciones];

    // Inicializar los precios (Ejemplo)
    precios[0][0] = 10000;  // Norte, Regular
    precios[0][1] = 20000;  // Norte, Premium
    precios[0][2] = 9000;  // Norte, EcoExtra

    precios[1][0] = 9000;  // Centro, Regular
    precios[1][1] = 18000;  // Centro, Premium
    precios[1][2] = 8000;  // Centro, EcoExtra

    precios[2][0] = 15000;  // Sur, Regular
    precios[2][1] = 25000;  // Sur, Premium
    precios[2][2] = 12000;  // Sur, EcoExtra
}

RedNacional::~RedNacional(){
    //Destructor para liberar arreglo de estaciones luego de guardarlas
}

//                  Getters - Setters
int RedNacional:: getSizetaciones() const {return sizeEstaciones;}
Estacion* RedNacional:: getEstaciones() const {return estaciones;}
int RedNacional:: getCapacidadEstaciones() const {return capacidadEstaciones;}

void RedNacional:: setSizeEstaciones(int newSize){
    // validar el nuevo numero entero.
    if(newSize > 0){
        sizeEstaciones = newSize;
    }
    else{
        cout << "newSize debe ser mayor a cero." << endl;
    }
}
int RedNacional::setCapacidadEstaciones(int newCapacidad){
    if (newCapacidad > 0){
        capacidadEstaciones = newCapacidad;
    }
    else{
        cout << "newCapacidad debe ser mayor a cero.";
    }
}

//                      Metodos


void RedNacional:: expandirEstaciones(){
    //Metodo publico para expandir el arreglo de estaciones
    // Crear un nuevo arreglo con una posición más
    capacidadEstaciones = capacidadEstaciones + 1;
    Estacion* nuevoArr = new Estacion[capacidadEstaciones];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeEstaciones; ++i) {
        nuevoArr[i] = estaciones[i];
    }

    // Liberar la memoria del arreglo original
    delete[] estaciones;

    // Actualizar el puntero para que apunte al nuevo arreglo
    estaciones = nuevoArr;
}

void RedNacional:: agregarEstacionLectura(string nombreO, string codigoEstacionO, string gerenteO, string regionO, string coordenadasO){
    //Metodo publico para agregar una estacion
    if(sizeEstaciones == 0){estaciones = new Estacion[capacidadEstaciones];}
    else{
        if (sizeEstaciones == capacidadEstaciones) {
            expandirEstaciones();
        }
    }
    estaciones[sizeEstaciones] = Estacion(nombreO, codigoEstacionO, gerenteO, regionO, coordenadasO);
    sizeEstaciones++;

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
    formatoDocumentoGerente(&documento);

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
    cout<<"\tMENU DE ESTACIONES"<<endl<<endl;
    mostrarArregloEstaciones();
    string codigoEliminar;
    cout<<"Escoja una opcion: ";
    cin.ignore();
    getline(cin, codigoEliminar);
    return codigoEliminar;
}

string RedNacional:: obtenerRegionEstacion(){
    limpiarPantalla();
    cout<<"\tMENU DE ESTACIONES"<<endl<<endl;
    mostrarArregloEstaciones();
    string codigoEliminar;
    string region;
    cout<<"Escoja una opcion: ";
    cin.ignore();
    getline(cin, codigoEliminar);
    for (int i = 0; i < sizeEstaciones; ++i) {
        if(estaciones[i].getcodigoEstacion() == codigoEliminar){region = estaciones[i].getregion();}
        return region;
    }
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

void RedNacional:: fijarPrecios(){
    //Metodo publico para fijar los precios del combustible
    for (int i = 0; i < sizeRegion; ++i) {
        cout<<"Para la region "<<regiones[i]<<": \n";
        cout<<"precio Regular: ";
        cin>>precios[i][0];
        cout<<"precio Premium: ";
        cin>>precios[i][1];
        cout<<"precio Ecoextra: ";
        cin>>precios[i][2];
        cout<<endl;
    }
}



void RedNacional:: mostrarArregloEstaciones(){
    for (int i = 0; i < sizeEstaciones; ++i) {
        estaciones[i].mostrarEstaciones();
    }
}

string RedNacional::elegirEstacion(){
    //Metodo para elegir la estacion
    string estacion;
    cout << "Ingrese el codigo de la estacion en la que esta trabajando: " << endl;
    for (int i = 0; i < sizeEstaciones; ++i) {
       estaciones[i].mostrarEstaciones();
    }
    cin >> estacion;
    return estacion;
}



void RedNacional::agregarRegiones(string arreglo[]){
    for (int i = 0; i < sizeRegion ; ++i) {
        regiones[i] = arreglo[i];
    }
}



void RedNacional:: asignarCapacidadTanque(){
    // Asignar la capacidad del tanque de suministro, con un valor aleatorio entre
    //100 y 200 litros para cada una de las categorías
    string codigo = obtenerCodigoEstacion();
    for (int i = 0; i < sizeEstaciones; ++i) {
        if(estaciones[i].getcodigoEstacion() == codigo){
            limpiarPantalla();
            estaciones[i].asignarTanque();
            cout<<"Las capacidades del Tantque de la estacion "<<codigo<<" son: "<<endl;
            Tanque tanque = estaciones[i].getTanqueAsociado();
            cout<<"Capacidad Regular: "<<tanque.getCapacidadRegular()<<endl;
            cout<<"Capacidad Premium: "<<tanque.getCapacidadPremium()<<endl;
            cout<<"Capacidad Ecoextra: "<<tanque.getCapacidadEcoextra()<<endl<<endl;
            cout<<"Combustible Total Disponible: "<<tanque.getCombustibleDisponibleTotal()<<endl;
            cout<<"Capacidad Total Disponible: "<<tanque.getCapacidadTotal()<<endl;
            system("pause");
            return;
        }
    }
}

int RedNacional:: calcularMontoPago(string tipoCombustible, int litrosVendidos, string region){
    //calcula un monto de pago dependiendo del tipo de combustible y los litros vendidos
    int monto = litrosVendidos;
    for (int i = 0; i < 3; ++i) {
        if(regiones[i] == region){
            if(tipoCombustible == "Regular"){monto = monto*precios[i][0];}
            else if(tipoCombustible == "Premium"){monto = monto*precios[i][1];}
            else if(tipoCombustible == "Ecoextra"){monto = monto*precios[i][3];}
            return monto;
        }
    }
}









