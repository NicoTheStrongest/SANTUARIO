#ifndef CLASS_REDNACIONAL_H
#define CLASS_REDNACIONAL_H

#include <iostream>
#include <funcionesGenerales.h>
#include <fstream>
#include <string>

using namespace std;

class RedNacional{
private:
    string regiones[3];
    static int numEstaciones;
public:
    RedNacional(string nombreRegion);
    string getRegiones(int posicion) const;
    string setRegiones(string nombreRegion);
    ~RedNacional();
};


#endif // CLASS_REDNACIONAL_H
