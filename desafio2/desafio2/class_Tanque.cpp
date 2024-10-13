#include <iostream>

#include "funcionesGenerales.h"

#include <fstream>
#include <string>

using namespace std;

//Constructor
Tanque::Tanque(int capacidad, int combustibleDisponible, double capacidadRegular, double capacidadPremium, double capacidadEcoextra, double disponibleRegular, double disponiblePremium, double disponibleEcoextra)
    : capacidadTotal(capacidad),
    combustibleDisponibleTotal(combustibleDisponible),
    capacidadRegular(capacidadRegular),
    capacidadPremium(capacidadPremium),
    capacidadEcoextra(capacidadEcoextra),
    disponibleRegular(disponibleRegular),
    disponiblePremium(disponiblePremium),
    disponibleEcoextra(disponibleEcoextra) {
}

//Getter
int getCapacidadTotal(){return capacidadTotal;}
int getCombustibleDisponibleTotal(){return combustibleDisponibleTotal;}
double getCapacidadRegular(){return capacidadRegular;}
double getCapacidadPremium(){return capacidadPremium;}
double getCapacidadEcoextra(){return capacidadEcoextra;}
double getDisponibleRegular(){return disponibleRegular;}
double getDisponiblePremium(){return disponiblePremium;}
double getDisponibleEcoexptra(){return disponibleEcoexptra;}

//Setter

int setCapacidadTotal(int newCapacidad){
    //validar formato del parametro
    //capacidadTotal = newCapacidad;
}

int setCombustibleDisponibleTotal(int newCombustibleDisponibleTotal){
    //validar formato del parametro
    //combustibleDisponibleTotal = newCombustibleDisponibleTotal;
}

double setCapacidadRegular(double newCapadidadRegular){
    //validar formato del parametro
    //capadidadRegular = newCapadidadRegular;
}

double setCapacidadPremium(double newCapadidadPremium){
    //validar formato del parametro
    //capadidadPremium = newCapadidadPremium;
}

double setCapacidadEcoextra(double newCapadidadEcoextra){
    //validar formato del parametro
    //capadidadEcoextra = newCapadidadEcoextra;
}

double setDisponibleRegular(double newDisponibleRegular){
    //validar formato del parametro
    //disponibleRegular = newDisponibleRegular;
}

double setDisponiblePremium(double newDisponiblePremium){
    //validar formato del parametro
    //disponiblePremium = newDisponiblePremium;
}

double setDisponibleEcoextra(double newDisponibleEcoextra){
    //validar formato del parametro
    //disponibleEcoextra = newDisponibleEcoextra;
}















