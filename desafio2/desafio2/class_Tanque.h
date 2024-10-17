#ifndef CLASS_TANQUE_H
#define CLASS_TANQUE_H

#include <iostream>

#include <fstream>
#include <string>

class Tanque{
private:
    int capacidadTotal = 0;
    int combustibleDisponibleTotal = 0;
    int capacidadRegular = 0;
    int capacidadPremium = 0;
    int capacidadEcoextra = 0;
    int disponibleRegular = 0;
    int disponiblePremium = 0;
    int disponibleEcoextra = 0;
public:
    //Constructor
    Tanque();
    Tanque(int capacidadRegular, int capacidadPremium, int capacidadEcoextra, int disponibleRegular, int disponiblePremium, int disponibleEcoextra);
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
    void setCapacidadTotal (int newCapacidad);
    void setCombustibleDisponibleTotal (int newCombustibleDisponibleTotal);
    void setCapacidadRegular (double newCapacidadRegular);
    void setCapacidadPremium(double newCapacidadPremium);
    void setCapacidadEcoextra(double newCapacidadEcoextra);
    void setDisponibleRegular(double newDisponibleRegular);
    void setDisponiblePremium(double newDisponiblePremium);
    void setDisponibleEcoextra(double newDisponibleEcoextra);
};

#endif // CLASS_TANQUE_H
