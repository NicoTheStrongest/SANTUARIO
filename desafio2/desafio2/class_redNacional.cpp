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
    RedNacional(string nombreRegion){}
    string getRegiones(int posicion){}
    string setRegiones(string nombreRegion){}
    ~RedNacional();
};



