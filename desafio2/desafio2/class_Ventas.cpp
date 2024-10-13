#include <iostream>

#include "funcionesGenerales.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Constructor
Ventas::Ventas(){}
Ventas::Ventas(const string fechaHora, const string tipoCombustible, const string metodoPago, const string documentoCliente, const string codigoSurtidor, double cantidadCombustible, double monto)
    : fechaHora(fechaHora), tipoCombustible(tipoCombustible), metodoPago(metodoPago), documentoCliente(documentoCliente), codigoSurtidor(codigoSurtidor), cantidadCombustible(cantidadCombustible), monto(monto){}

//Destructor
Ventas::~Ventas(){}

//Getters
string Ventas:: getfechaHora() const {return fechaHora;}
string Ventas:: getTipoCombustible() const {return tipoCombustible;}
string Ventas:: getMetodoPago() const {return metodoPago;}
string Ventas:: getDocumentoCliente() const {return documentoCliente;}
double Ventas:: getMonto() const {return monto;}
double Ventas:: getCantidadCombustible() const {return cantidadCombustible;}

//Setters
string setFechaHora(string newFechaHora){
    //validar formato del parametro
    //fechaHora = newFechaHora;
}

string setTipoCombustible(string newTipoCombustible){
    //validar formato del parametro
    //tipoCombustible = newTipoCombustible;
}

string setMetodoPago(string newMetodoPago){
    //validar formato del parametro
    //metodoPago = newMetodoPago;
}

string setDocumentoCliente(string newDocumentoCliente){
    //validar formato del parametro
    //documentoCliente = newDocumentoCliente;
}

double setMonto(double newMonto){
    //validar formato del parametro
    //monto = newMonto;
}
double setCantidadCombustible(double newCantidadCombustible){
    //validar formato del parametro
    //cantidadCombustible = newCantidadCombustible;
}

//              METODOS

string fechaHora(){
    //funcion que retorna la fecha y hora en el formato deseado
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);
    char fechaHora[20];
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    return string(fechaHora);
}




