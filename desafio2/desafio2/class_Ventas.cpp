#include <iostream>

#include "class_Ventas.h"

#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//Constructor
Ventas::Ventas(){}
Ventas::Ventas(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto)
    : codigoVentas(codigoSurtidor), tipoCombustible(tipoCombustible), fechaHora(fechaHora), cantidadCombustible(cantidadCombustible), metodoPago(metodoPago), documentoCliente(documentoCliente), monto(monto){}

//Destructor
Ventas::~Ventas(){}

//Getters
string Ventas:: getCodigoVentas()const{return codigoVentas;}
string Ventas:: getfechaHora() const {return fechaHora;}
string Ventas:: getTipoCombustible() const {return tipoCombustible;}
string Ventas:: getMetodoPago() const {return metodoPago;}
string Ventas:: getDocumentoCliente() const {return documentoCliente;}
double Ventas:: getMonto() const {return monto;}
double Ventas:: getCantidadCombustible() const {return cantidadCombustible;}

//Setters
string Ventas:: setFechaHora(string newFechaHora){
    //validar formato del parametro
    //fechaHora = newFechaHora;
}

string Ventas:: setTipoCombustible(string newTipoCombustible){
    //validar formato del parametro
    //tipoCombustible = newTipoCombustible;
}

string Ventas:: setMetodoPago(string newMetodoPago){
    //validar formato del parametro
    //metodoPago = newMetodoPago;
}

string Ventas:: setDocumentoCliente(string newDocumentoCliente){
    //validar formato del parametro
    //documentoCliente = newDocumentoCliente;
}

double Ventas:: setMonto(double newMonto){
    //validar formato del parametro
    //monto = newMonto;
}

double Ventas:: setCantidadCombustible(double newCantidadCombustible){
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

void Ventas:: mostrarVentas(){
    cout<<codigoVentas<<"//"<<tipoCombustible<<"//"<<fechaHora<<"//"<<metodoPago<<"//"<<documentoCliente<<"//"<<cantidadCombustible<<"//"<<monto;
    cout<<endl;
}



/*
//Atributos
std::string codigoVentas, tipoCombustible, fechaHora, metodoPago, documentoCliente;
int cantidadCombustible, monto;
*/

















