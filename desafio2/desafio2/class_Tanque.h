#ifndef CLASS_TANQUE_H
#define CLASS_TANQUE_H

#include <iostream>

#include <fstream>
#include <string>

class Tanque{
private:
    int capacidadTotal;
    int combustibleDisponibleTotal;
    int capacidadRegular;
    int capacidadPremium;
    int capacidadEcoextra;
    int disponibleRegular;
    int disponiblePremium;
    int disponibleEcoextra;
public:
    //Constructor
    Tanque();
    Tanque(int capacidad, int combustibleDisponible, int  capacidadRegular, int  capacidadPremium, int  capacidadEcoextra, int  disponibleRegular, int  disponiblePremium, int  disponibleEcoextra);
    //Destructor
    ~Tanque();
    //Getter
    int getCapacidadTotal() const;
    int getCombustibleDisponibleTotal() const;
    int getCapacidadRegular() const;
    int getCapacidadPremium() const;
    int getCapacidadEcoextra() const;
    int getDisponibleRegular() const;
    int getDisponiblePremium() const;
    int getDisponibleEcoexptra() const;
    //Setter
    void setCapacidadTotal (int newCapacidad);
    void setCombustibleDisponibleTotal (int newCombustibleDisponibleTotal);
    void setCapacidadRegular (int newCapacidadRegular);
    void setCapacidadPremium(int newCapacidadPremium);
    void setCapacidadEcoextra(int newCapacidadEcoextra);
    void setDisponibleRegular(int newDisponibleRegular);
    void setDisponiblePremium(int newDisponiblePremium);
    void setDisponibleEcoextra(int newDisponibleEcoextra);
    //Metodos
    void disminuirDisponible(std::string combustible,int cantidad);

};

#endif // CLASS_TANQUE_H
