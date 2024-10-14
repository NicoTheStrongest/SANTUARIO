#include <iostream>

#include "class_Surtidor.h"
#include "class_Ventas.h"

#include <fstream>
#include <string>

using namespace std;

/*
    //Atributos
    std::string codigoSurtidor,modelo;
    bool activo;
    Ventas* ventas;
    int sizeVentas = 0;
    int capacidadVentas = 0;
    std::string codSurtidores[13];
    int numCodigosSurtidores = 0;
    double precioRegular,precioPremium,precioEcoExtra;
*/

Surtidor::Surtidor(){}

Surtidor::Surtidor(string codigoSurtidor, string modelo, bool estado): codigoSurtidor(codigoSurtidor), modelo(modelo){
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

//Setters
void Surtidor::setCodigoSurtidor(std::string newCodigoSurtidor){
    //Validar formato del parametro
    if(newCodigoSurtidor.length() == 6){
        codigoSurtidor = newCodigoSurtidor;
    }
    else{
        cout << "newCodigoSurtidor debe tener seis caracteres." << endl;
    }
}
void Surtidor::setModelo(std::string newModelo){
    if(newModelo == "modelo1" || newModelo == "modelo2" || newModelo == "modelo3"){
        modelo = newModelo;
    }
    else{
        cout << "newModelo debe ser 'modelo1','modelo2' o 'modelo3'" << endl;
    }
}
void Surtidor::setActivo(bool estado){
    activo = estado;
}
void Surtidor::setSizeVentas(int newSizeVentas){
    if(newSizeVentas > 0){
        sizeVentas = newSizeVentas;
    }
    else{
        cout << "newSizeVentas de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioRegular(double newPrecioRegular){
    if(newPrecioRegular > 0){
            precioRegular = newPrecioRegular;
    }
    else{
        cout << "newPrecioRegular de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioPremium(double newPrecioPremium){
    if(newPrecioPremium > 0){
        precioPremium = newPrecioPremium;
    }
    else{
        cout << "newPrecioPremium de ser mayor a cero" << endl;
    }
}
void Surtidor::setPrecioEcoExtra(double newPrecioEcoextra){
    if(newPrecioEcoextra > 0){
        precioEcoExtra = newPrecioEcoextra;
    }
    else{
        cout << "newPrecioEcoextra de ser mayor a cero" << endl;
    }
}

void Surtidor:: expandirVentas(Ventas*& arr, int* size){
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

bool CambiarActivo(){}
void registrarVenta(const Ventas& nuevaVenta){}





