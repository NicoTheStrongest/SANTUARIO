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

//                  CONSTRUCTOR Y DESTRUCTOR

RedNacional::RedNacional() : sizeEstaciones(0), capacidadEstaciones(2){
    //estaciones = new Estacion[capacidadEstaciones];

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
    if(sizeEstaciones > 0){delete[] estaciones;}
}

//                  GETTERS

int RedNacional:: getSizetaciones() const {return sizeEstaciones;}
int RedNacional:: getCapacidadEstaciones() const {return capacidadEstaciones;}
Estacion* RedNacional:: getEstaciones() const {return estaciones;}

//                  SETTERS

void RedNacional:: setSizeEstaciones(int newSize){
    // validar el nuevo numero entero.
    if(newSize > 0){
        sizeEstaciones = newSize;
    }
    else{
        cout << "newSize debe ser mayor a cero." << endl;
    }
}
void RedNacional:: setCapacidadEstaciones(int newCapacidad){
    if (newCapacidad > 0){
        capacidadEstaciones = newCapacidad;
    }
    else{
        cout << "newCapacidad debe ser mayor a cero.";
    }
}

//                  METODOS (PRIVADOS)

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

//                  METODOS (PUBLICOS)

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
    limpiarPantalla();
    string nombre, documento, codigo, region, gps;
    int cod = sizeEstaciones + 1;
    codigo = to_string(cod);
    cout<<"************AGREGAR ESTACION************\n\n";
    cout<<"Ingrese nombre de la estacion: ";
    cin.ignore();
    getline(cin, nombre);

    cout<<"\nIngrese documento del gerente de la estacion: ";
    getline(cin, documento);
    formatoDocumentoGerente(&documento);
    cout<<endl;
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

    cout<<"\nIngrese las coordenadas de la estacion: ";
    cin.ignore();
    getline(cin, gps);

    if (sizeEstaciones == capacidadEstaciones) {
        expandirEstaciones();  // Si el arreglo está lleno, lo expandimos
    }
    estaciones[sizeEstaciones] = Estacion(nombre, codigo, documento, region, gps);
    sizeEstaciones += 1;

    cout<<endl;
    prints = "./../../prints/EstacionAgregada.txt";
    leerArchivoPorLinea(prints);
    system("pause");
}

void RedNacional:: eliminarEstacion(bool bandera, string codigoEliminar){
    //Metodo publico para eliminar una estacion (sólo si no posee surtidores activos).
    int posicion = -1;
    //Encontrar estacion  en el arreglo
    for(int i = 0; i < sizeEstaciones; i++){
        if(estaciones[i].getcodigoEstacion() == codigoEliminar){
            posicion = i;
            break;
        }
    }
    if(bandera == false){
        cout << "\nEstacion " << codigoEliminar << " no se puede eliminar o no existe" << endl;
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
    cout<<"**********MENU DE ESTACIONES**********"<<endl<<endl;
    mostrarArregloEstaciones();
    string codigoEliminar;
    cout<<"\nEscoja una opcion: ";
    cin.ignore();
    getline(cin, codigoEliminar);
    return codigoEliminar;
}

string RedNacional:: obtenerRegionEstacion(string* codigoEstacion){
    limpiarPantalla();
    string region;
    cout<<"**********MENU DE ESTACIONES**********"<<endl<<endl;
    mostrarArregloEstaciones();
    cout<<"Escoja una opcion: ";
    cin.ignore();
    getline(cin, *codigoEstacion);
    for (int i = 0; i < sizeEstaciones; ++i) {
        if(estaciones[i].getcodigoEstacion() == *codigoEstacion){region = estaciones[i].getregion();}
        return region;
    }
}

void RedNacional:: fijarPrecios(){
    //Metodo publico para fijar los precios del combustible
    limpiarPantalla();
    cout<<"*********FIJAR PRECIOS*********"<<endl<<endl;
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
    cout<<endl;
    string prints = "./../../prints/FijarPrecios.txt";
    leerArchivoPorLinea(prints);
    system("pause");
}

void RedNacional:: mostrarArregloEstaciones(){
    for (int i = 0; i < sizeEstaciones; ++i) {
        estaciones[i].mostrarEstaciones();
    }
}

string RedNacional:: elegirEstacion(){
    //Metodo para elegir la estacion
    string estacion;
    cout << "Ingrese el codigo de la estacion en la que esta trabajando: " << endl;
    for (int i = 0; i < sizeEstaciones; ++i) {
       estaciones[i].mostrarEstaciones();
    }
    cout<<"\nElija una opcion: ";
    cin >> estacion;
    return estacion;
}

void RedNacional:: agregarRegiones(string arreglo[]){
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
            cout<<"Las capacidades del Tanque de la estacion "<<codigo<<" son: "<<endl<<endl;
            Tanque tanque = estaciones[i].getTanqueAsociado();
            cout<<"Capacidad Regular: "<<tanque.getCapacidadRegular()<<endl;
            cout<<"Capacidad Premium: "<<tanque.getCapacidadPremium()<<endl;
            cout<<"Capacidad Ecoextra: "<<tanque.getCapacidadEcoextra()<<endl<<endl;
            cout<<"Combustible Total Disponible: "<<tanque.getCombustibleDisponibleTotal()<<endl;
            cout<<"Capacidad Total Disponible: "<<tanque.getCapacidadTotal()<<endl<<endl;
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









