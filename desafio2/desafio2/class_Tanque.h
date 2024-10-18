#ifndef CLASS_TANQUE_H
#define CLASS_TANQUE_H

#include <iostream>

#include <fstream>
#include <string>

using namespace std;

class Tanque{
private:
    //                  ATRIBUTOS
    int capacidadTotal = 300;
    int combustibleDisponibleTotal = 300;
    int capacidadRegular = 100;
    int capacidadPremium = 100;
    int capacidadEcoextra = 100;
    int disponibleRegular = 100;
    int disponiblePremium = 100;
    int disponibleEcoextra = 100;
public:
    //                  CONSTRUCTOR Y DESTRUCTOR
    Tanque();
    Tanque(int capacidadRegular, int capacidadPremium, int capacidadEcoextra, int disponibleRegular, int disponiblePremium, int disponibleEcoextra);
    ~Tanque();

    //                  GETTERS
    int getCapacidadTotal() const;
    int getCombustibleDisponibleTotal() const;
    int getCapacidadRegular() const;
    int getCapacidadPremium() const;
    int getCapacidadEcoextra() const;
    int getDisponibleRegular() const;
    int getDisponiblePremium() const;
    int getDisponibleEcoexptra() const;

    //                  SETTERS
    void setCapacidadTotal (int newCapacidad);
    void setCombustibleDisponibleTotal (int newCombustibleDisponibleTotal);
    void setCapacidadRegular (int newCapacidadRegular);
    void setCapacidadPremium(int newCapacidadPremium);
    void setCapacidadEcoextra(int newCapacidadEcoextra);
    void setDisponibleRegular(int newDisponibleRegular);
    void setDisponiblePremium(int newDisponiblePremium);
    void setDisponibleEcoextra(int newDisponibleEcoextra);

    //                  METODOS
    void disminuirDisponible(string combustible, int cantidad);
};

#endif // CLASS_TANQUE_H
