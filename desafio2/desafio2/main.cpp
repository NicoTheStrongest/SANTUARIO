#include <iostream>
#include "class_Estacion.h"
#include "class_Naves.h"
#include "class_RedNacional.h"
#include "class_Surtidor.h"
#include "class_Tanque.h"
#include "class_Ventas.h"
#include "funcionesGenerales.h"

using namespace std;

/*
archivo de usuarios
archivo historico de transacciones por estacion
archivo base de datos general
*/

int main(){
    bool sesionActiva = true;
    while(sesionActiva == true){
        int inicioValido = inicioSesion();
        if (inicioValido == 1){
            //funcionalidad de agregar estacion
        }
        else if (inicioValido == 2){
            //funcionalidad de eliminar estacion
        }
        else if (inicioValido == 3){
            //funcionalidad de mostrar monto total
        }
        else if (inicioValido == 4){
            //funcionalidad de fijar precio de combustible (de ultimas)
        }
        else if (inicioValido == 5){
            string region;
            int numRegion = menuRegion();
            if (numRegion == 1){// Norte
                region = "Norte";
                //metodo de despliegue para las estaciones de norte
                //Elegir estacion de norte
            }
            else if (numRegion == 2){// Centro
                region = "Centro";
                //metodo de despliegue para las estaciones de centro
                //Elegir estacion de centro
            }
            else if (numRegion == 3){// Sur
                region = "Sur";
                //metodo de despliegue para las estaciones de sur
                //Elegir estacion de sur
            }
            else if (numRegion == 0){// Salir
                sesionActiva = false;
            }
            if(sesionActiva){
                // Trabajar sobre la region y la estacion escogida
                //Menu de funcionalidades de estacion
                int numGestionEstacion = menuEstacion();
                if(numGestionEstacion == 1){
                    //funcionalidad de agregar surtidor
                }
                else if(numGestionEstacion == 2){
                    //funcionalidad de eliminar surtidor
                }
                else if(numGestionEstacion == 3){
                    //funcionalidad de consultar hisorico de transacciones
                }
                else if(numGestionEstacion == 4){
                    //Funcionalida de eporte de litros vendidos
                }
                else if(numGestionEstacion == 5){
                    //Funcionalidad de simular venta
                }
                else if(numGestionEstacion == 6){
                    //Funcionalidad de asignar capacidad de tanque (?)
                }
                else if(numGestionEstacion == 7){
                    //Funcionalidad de verificacion de fuga.
                }
                else if(numGestionEstacion == 0){
                    //salir
                    sesionActiva = false;
                }
            }
        }
        else if (inicioValido == 0){// Salir
            sesionActiva = false;
        }
    }
    mensajeSalida();
}
