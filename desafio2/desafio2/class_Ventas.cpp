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
void Ventas::setFechaHora(string newFechaHora){
    fechaHora = newFechaHora;
}

void Ventas::setTipoCombustible(string newTipoCombustible){
    //validar formato del parametro
    if(newTipoCombustible == "regular" || newTipoCombustible == "premium" || newTipoCombustible == "ecoextra"){
        tipoCombustible = newTipoCombustible;
    }
    else{
        cout << "newTipoCombustible de ser 'regular', 'premium' o 'ecoextra'" << endl;
    }
}

void Ventas::setMetodoPago(string newMetodoPago){
    //validar formato del parametro
    if(newMetodoPago == "efectivo" || newMetodoPago == "Tdebito" || newMetodoPago == "Tcredito"){
        metodoPago = newMetodoPago;
    }
    else{
        cout << "newMetodoPago de ser 'efectivo', 'Tdebito' o 'Tcredito'" << endl;
    }
}

void Ventas:: setDocumentoCliente(string newDocumentoCliente){
    //validar formato del parametro
    if(newDocumentoCliente.length() == 10){
        documentoCliente = newDocumentoCliente;
    }
    else{
        cout << "newDocumentoCliente debe tener diez caracteres" << endl;
    }
}

void Ventas::setMonto(double newMonto){
    //validar formato del parametro
    if(newMonto > 0){
        monto = newMonto;
    }
    else{
        cout << "El newMonto debe ser mayor a cero." << endl;
    }
}

void Ventas:: setCantidadCombustible(double newCantidadCombustible){
    //validar formato del parametro
    if(newCantidadCombustible > 0){
        cantidadCombustible = newCantidadCombustible;
    }
    else{
        cout << "newCantidadCombustible dede ser mayor a cero." << endl;
    }
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




