#include <iostream>

#include "class_Tanque.h"

#include <fstream>
#include <string>

using namespace std;

//Constructor
Tanque::Tanque(){}
Tanque::Tanque(int capacidad, int combustibleDisponible, int capacidadRegular, int capacidadPremium, int capacidadEcoextra, int disponibleRegular, int disponiblePremium, int disponibleEcoextra)
    : capacidadTotal(capacidad),
    combustibleDisponibleTotal(combustibleDisponible),
    capacidadRegular(capacidadRegular),
    capacidadPremium(capacidadPremium),
    capacidadEcoextra(capacidadEcoextra),
    disponibleRegular(disponibleRegular),
    disponiblePremium(disponiblePremium),
    disponibleEcoextra(disponibleEcoextra) {
}

//Destructor
Tanque::~Tanque(){}

//Getter
int Tanque:: getCapacidadTotal() const {return capacidadTotal;}
int Tanque:: getCombustibleDisponibleTotal() const {return combustibleDisponibleTotal;}
int Tanque:: getCapacidadRegular() const {return capacidadRegular;}
int Tanque:: getCapacidadPremium() const {return capacidadPremium;}
int Tanque:: getCapacidadEcoextra() const {return capacidadEcoextra;}
int Tanque:: getDisponibleRegular() const {return disponibleRegular;}
int Tanque:: getDisponiblePremium() const {return disponiblePremium;}
int Tanque:: getDisponibleEcoexptra() const {return disponibleEcoextra;}

//Setter

void Tanque::setCapacidadTotal(int newCapacidad){
    //validar formato del parametro
    if(newCapacidad > 0){
        capacidadTotal = newCapacidad;
    }
    else{
        cout << "newCapacidad debe ser mayor a cero." << endl;
    }
}

void Tanque::setCombustibleDisponibleTotal(int newCombustibleDisponibleTotal){
    //validar formato del parametro
    if(newCombustibleDisponibleTotal > 0){
        combustibleDisponibleTotal = newCombustibleDisponibleTotal;
    }
    else{
        cout << "newCombustibleDisponibleTotal debe ser mayor a cero." << endl;
    }
}

void Tanque::setCapacidadRegular(int newCapacidadRegular){
    //validar formato del parametro
    if(newCapacidadRegular > 0 && (newCapacidadRegular >= 100 || newCapacidadRegular <= 200)){
        capacidadRegular = newCapacidadRegular;
    }
    else{
        cout << "newCapadidadRegular debe estar entre 100 y 200 litros." << endl;
    }
}

void Tanque::setCapacidadPremium(int newCapacidadPremium){
    //validar formato del parametro
    if(newCapacidadPremium > 0 && (newCapacidadPremium >= 100 || newCapacidadPremium <= 200)){
        capacidadPremium = newCapacidadPremium;
    }
    else{
        cout << "newCapacidadPremium debe estar entre 100 y 200 litros." << endl;
    }
}

void Tanque::setCapacidadEcoextra(int newCapacidadEcoextra){
    //validar formato del parametro
    if(newCapacidadEcoextra > 0 && (newCapacidadEcoextra >= 100 || newCapacidadEcoextra <= 200)){
        capacidadEcoextra = newCapacidadEcoextra;
    }
    else{
        cout << "newCapacidadEcoextra debe estar entre 100 y 200 litros." << endl;
    }
}

void Tanque::setDisponibleRegular(int newDisponibleRegular){
    //validar formato del parametro
    if(newDisponibleRegular >= 0){
        disponibleRegular = newDisponibleRegular;
    }
    else{
        cout << "newDisponibleRegular debe ser mayor o igual a cero." << endl;
    }
}

void Tanque::setDisponiblePremium(int newDisponiblePremium){
    //validar formato del parametro
    if(newDisponiblePremium >= 0){
        disponiblePremium = newDisponiblePremium;
    }
    else{
        cout << "newDisponiblePremium debe ser mayor o igual a cero." << endl;
    }
}

void Tanque::setDisponibleEcoextra(int newDisponibleEcoextra){
    //validar formato del parametro
    if(newDisponibleEcoextra >= 0){
        disponibleEcoextra = newDisponibleEcoextra;
    }
    else{
        cout << "newDisponibleEcoextra debe ser mayor o igual a cero." << endl;
    }
}
 //                 METODOS

void Tanque:: disminuirDisponible(string combustible, int cantidad){
    if(combustible == "regular"){disponibleRegular -= cantidad;}
    else if(combustible == "premium"){disponiblePremium -= cantidad;}
    else if (combustible == "ecoextra"){disponibleEcoextra -= cantidad;}
    else{cout << "Combustible no valido." << endl;}
}














