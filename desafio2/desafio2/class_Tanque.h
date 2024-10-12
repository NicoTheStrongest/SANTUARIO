#ifndef CLASS_TANQUE_H
#define CLASS_TANQUE_H

#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>

using namespace std;

class Tanque{
private:
    int capacidad,combustibleDisponible;

public:
    //Constructor
    Tanque(int capacidad,int combustibleDisponible);
    //Getter
    int getcapacidad() const;
    //Setter
    void setcombustibleDisponible(int cantidad);
};

#endif // CLASS_TANQUE_H
