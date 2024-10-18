#include <iostream>

#include "class_Ventas.h"

#include <fstream>
#include <string>
#include <ctime>

using namespace std;

//                  CONSTRUCTOR Y DESTRUCTOR
Ventas::Ventas(){}

Ventas::Ventas(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto)
    : codigoVentas(codigoSurtidor), tipoCombustible(tipoCombustible), fechaHora(fechaHora), cantidadCombustible(cantidadCombustible), metodoPago(metodoPago), documentoCliente(documentoCliente), monto(monto){
}

Ventas::~Ventas(){}

//                  GETTERS

string Ventas:: getCodigoVentas()const{return codigoVentas;}
string Ventas:: getfechaHora() const {return fechaHora;}
string Ventas:: getTipoCombustible() const {return tipoCombustible;}
string Ventas:: getMetodoPago() const {return metodoPago;}
string Ventas:: getDocumentoCliente() const {return documentoCliente;}
int Ventas:: getMonto() const {return monto;}
int Ventas:: getCantidadCombustible() const {return cantidadCombustible;}

//                  SETTERS

void Ventas:: setFechaHora(string newFechaHora){
    fechaHora = newFechaHora;
}
void Ventas:: setTipoCombustible(string newTipoCombustible){
    //validar formato del parametro
    if(newTipoCombustible == "regular" || newTipoCombustible == "premium" || newTipoCombustible == "ecoextra"){
        tipoCombustible = newTipoCombustible;
    }
    else{
        cout << "newTipoCombustible de ser 'regular', 'premium' o 'ecoextra'" << endl;
    }
}
void Ventas:: setMetodoPago(string newMetodoPago){
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
void Ventas:: setMonto(int newMonto){
    //validar formato del parametro
    if(newMonto > 0){
        monto = newMonto;
    }
    else{
        cout << "El newMonto debe ser mayor a cero." << endl;
    }
}
void Ventas:: setCantidadCombustible(int newCantidadCombustible){
    //validar formato del parametro
    if(newCantidadCombustible > 0){
        cantidadCombustible = newCantidadCombustible;
    }
    else{
        cout << "newCantidadCombustible dede ser mayor a cero." << endl;
    }
}

//                 METODOS

void Ventas:: mostrarVentas(){
    cout<<codigoVentas<<"//"<<tipoCombustible<<"//"<<fechaHora<<"//"<<metodoPago<<"//"<<documentoCliente<<"//"<<cantidadCombustible<<"//"<<monto;
    cout<<endl;
}

void Ventas:: detallesVentas(){
    //Metodo que muestra los detalles de las ventas
    cout << "Surtidor: \t\t\t" << codigoVentas << endl;
    cout << "Fecha y hora: \t\t\t" << fechaHora << endl;
    cout << "Cantidad de combustible: \t" << cantidadCombustible << " litros" << endl;
    cout << "Categoria de combustible: \t" << tipoCombustible << endl;
    cout << "Metodo de pago: \t\t" << metodoPago << endl;
    cout << "Cliente: \t\t\t" << documentoCliente << endl;
    cout << "Monto: \t\t\t\t$" << monto << endl;
}

void Ventas:: discriminarVentas(int &totalRegular, int &totalPremium, int &totalEcoextra){
    //Metodo para sumar las ventas por combustible
    string combustible = getTipoCombustible();
    if(combustible == "regular"){
        totalRegular += getCantidadCombustible();
    }
    else if(combustible == "premium"){
        totalPremium += getCantidadCombustible();
    }
    else if(combustible == "ecoextra"){
        totalEcoextra += getCantidadCombustible();
    }
}



