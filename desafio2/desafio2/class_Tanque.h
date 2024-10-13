#ifndef CLASS_TANQUE_H
#define CLASS_TANQUE_H

#include <iostream>

#include "funcionesGenerales.h"

#include <fstream>
#include <string>

//using namespace std;

class Tanque{
private:
    int capacidadTotal;
    int combustibleDisponibleTotal;
    double capacidadRegular;
    double capacidadPremium;
    double capacidadEcoextra;
    double disponibleRegular;
    double disponiblePremium;
    double disponibleEcoextra;
public:
    //Constructor
    Tanque(int capacidad, int combustibleDisponible, double capacidadRegular, double capacidadPremium, double capacidadEcoextra, double disponibleRegular, double disponiblePremium, double disponibleEcoextra);
    //Destructor
    ~Tanque();
    //Getter
    int getCapacidadTotal() const;
    int getCombustibleDisponibleTotal() const;
    double getCapacidadRegular() const;
    double getCapacidadPremium() const;
    double getCapacidadEcoextra() const;
    double getDisponibleRegular() const;
    double getDisponiblePremium() const;
    double getDisponibleEcoexptra() const;
    //Setter
    int setCapacidadTotal(int newCapacidad);
    int setCombustibleDisponibleTotal(int newCombustibleDisponibleTotal);
    double setCapacidadRegular(double newCapadidadRegular);
    double setCapacidadPremium(double newCapadidadPremium);
    double setCapacidadEcoextra(double newCapadidadEcoextra);
    double setDisponibleRegular(double newDisponibleRegular);
    double setDisponiblePremium(double newDisponiblePremium);
    double setDisponibleEcoextra(double newDisponibleEcoextra);
};

#endif // CLASS_TANQUE_H
