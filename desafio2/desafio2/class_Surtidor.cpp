#include <iostream>

#include "class_Surtidor.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

Surtidor::Surtidor(){}

Surtidor::Surtidor(string codigoSurtidor, string modelo, bool estado)
    : codigoSurtidor(codigoSurtidor), modelo(modelo), estado(estado){
    //constructor que inicializa el arreglo de ventas
    precioRegular = 0;
    precioPremium = 0;
    precioEcoExtra = 0;
}

Surtidor::~Surtidor(){
    //Destructor, liberar dinamicos
    //liberarVentas();
}

//Getters
string Surtidor:: getCodigoSurtidor() const {return codigoSurtidor;}

string Surtidor:: getModelo() const {return modelo;}

bool Surtidor:: getEstado() const {return estado;}

int Surtidor:: getSizeVentas() const {return sizeVentas;}

double Surtidor:: getPrecioRegular() const {return precioRegular;}

double Surtidor:: getPrecioPremium() const {return precioRegular;}

double Surtidor:: getPrecioEcoExtra() const {return precioEcoExtra;}

void Surtidor:: expandirVentas(){
    //Metodo privado para expandir el arreglo de ventas
    int nuevaCapacidad = capacidadVentas + 1;
    Ventas* nuevoArr = new Ventas[nuevaCapacidad];

    // Copiar elementos al nuevo arreglo
    for (int i = 0; i < sizeVentas; ++i) {
        nuevoArr[i] = ventas[i];
    }

    // Liberar la memoria del arreglo original
    delete[] ventas;

    // Actualizar el puntero para que apunte al nuevo arreglo
    ventas = nuevoArr;
    capacidadVentas = nuevaCapacidad;
}

void Surtidor:: agregarVentaLectura(string codigoSurtidor, string tipoCombustible, string fechaHora, int cantidadCombustible, string metodoPago, string documentoCliente, int monto){
    //
    if(sizeVentas == 0){ventas = new Ventas[capacidadVentas];}
    else{
        if (sizeVentas == capacidadVentas) {
            expandirVentas();  // Si el arreglo está lleno, lo expandimos
        }
    }
    ventas[sizeVentas] = Ventas(codigoSurtidor, tipoCombustible, fechaHora, cantidadCombustible, metodoPago, documentoCliente, monto);
    sizeVentas++;
}

void Surtidor:: agregarCodSurtidoresLectura(string codigo){
    //Agregar codigos al arreglo de surtidores.
    if(numCodigosSurtidores <= 12){
        codSurtidores[numCodigosSurtidores] = codigo;
        numCodigosSurtidores += 1;
    }
    else{
        cout<<"No se pueden agregar mas sutidores";
    }
}

void Surtidor:: mostrarCodigos(){
    //mostrar los codigos del codSurtidores
    for (int i = 0; i < numCodigosSurtidores; ++i) {
        cout<<codSurtidores[i];
    }
}

void Surtidor:: mostrarAtributos(){
    cout<<codigoSurtidor<<"->\t"<<modelo<<"->\t"<<estado<<endl;
}

Ventas* Surtidor:: getVentas() const {return ventas;}
