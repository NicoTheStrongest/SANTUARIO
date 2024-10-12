#include <iostream>
#include <funcionesGenerales.h>
#include <class_Tanque.h>
#include <fstream>
#include <string>

using namespace std;

//Constructor
Tanque::Tanque(int capacidad, int combustibleDisponible){
    : capacidad(capacidad), combustibleDisponible(combustibleDisponible){}
}

//Getter
int Tanque::getcapacidad()const{
    return capacidad;
}

//Setter
int Tanque::setcombustibleDisponible(int cantidad){

}


