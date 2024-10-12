#include <iostream>
#include <class_Ventas.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Constructor
Ventas::ventas(const string& fechaHora,const string& tipoCombustible,const string& metodoPago,const string& documentoCliente,const string& codigoSurtidor,double cantidadCombustible,double monto){

}
//Getters, Setters
string Ventas::getfechaHora(){
    return fechaHora;
}
string Ventas::getTipoCombustible(){
    return tipoCombustible;
}
string Ventas::getMetodoPago(){
    return metodoPago;
}
string Ventas::getDocumentoCliente(){
    return documentoCliente;
}
double Ventas::getmonto() const{
    return monto;
}
double getCantidadCombustible() const{
    return cantidadCombustible;
}

//metodos
string fechaHora(){
    //funcion que retorna la fecha y hora en el formato deseado
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);
    char fechaHora[20];
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", tiempoLocal);
    return string(fechaHora);




