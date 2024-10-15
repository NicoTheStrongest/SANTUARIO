#ifndef CLASS_TANQUE_H
#define CLASS_TANQUE_H

#include <iostream>

#include <fstream>
#include <string>

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
    Tanque();
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
    void setCapacidadTotal(int newCapacidad);
    void setCombustibleDisponibleTotal(int newCombustibleDisponibleTotal);
    void setCapacidadRegular(double newCapacidadRegular);
    void setCapacidadPremium(double newCapacidadPremium);
    void setCapacidadEcoextra(double newCapacidadEcoextra);
    void setDisponibleRegular(double newDisponibleRegular);
    void setDisponiblePremium(double newDisponiblePremium);
    void setDisponibleEcoextra(double newDisponibleEcoextra);
};

#endif // CLASS_TANQUE_H
