#include <iostream>

#include "funcionesGenerales.h"

#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Constructor
Ventas::ventas(const string& fechaHora,const string& tipoCombustible,const string& metodoPago,const string& documentoCliente,const string& codigoSurtidor,double cantidadCombustible,double monto){}

//Getters
string Ventas::getfechaHora() {return fechaHora;}
string Ventas::getTipoCombustible() {return tipoCombustible;}
string Ventas::getMetodoPago() {return metodoPago;}
string Ventas::getDocumentoCliente() {return documentoCliente;}
double Ventas::getmonto() {return monto;}
double getCantidadCombustible() {return cantidadCombustible;}

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




