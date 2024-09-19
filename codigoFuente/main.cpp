#include <Adafruit_LiquidCrystal.h>



//                INICIALIZACION DE VARIABLES


signed short int size = -20; // Cantidad de datos entrando
unsigned short int sizeArreglo = 0; // posiciones reales en el arreglo
const signed short int max = 102;
signed short int tramos = 0;
const unsigned short int pulsador1 = 2;
const unsigned short int pulsador2 = 3;
const unsigned short int analogPin = 0;

float val = 0;
float** arreglo = nullptr; // Puntero inicial
float inicio;
float tiempoVal = 0;

Adafruit_LiquidCrystal lcd_1(0);

//               REGISTRO DE ACTIVACION

bool verificarcuadrada(float** arreglo, unsigned short int filas);
bool senialTriangular(float** arreglo, unsigned short int filas);
bool verificarsenoidal(float** arreglo, unsigned short int filas);
unsigned short int predominante(unsigned short int cuadra, unsigned short int triangu,unsigned short int senoi);

float calcularAmplitud(float** arreglo, unsigned short int size);
float calcularPeriodo(float** arreglo, unsigned short int size);
float calcularFrecuencia(float periodo);

void setup()
{
    lcd_1.begin(16, 2);
    Serial.begin(9600);
    pinMode(pulsador1, INPUT);
    pinMode(pulsador2, INPUT);

    //CREANDO MATRIZ DE DATOS
    arreglo = new float*[max];
    for (unsigned short int i = 0; i<max; i++)
    {
        arreglo[i] = new float [2];
    }
}

void loop()
{
    //delay(2000);
    lcd_1.clear();
    while (digitalRead(pulsador1) == LOW){
        //val = analogRead(analogPin);
        //Serial.println(val/100);
    }
    if (digitalRead(pulsador1)==HIGH){
        inicio = millis();
        float periodo, frecuencia, amplitud;
        bool triangular, cuadra, senoi, bandera = false;
        unsigned short int contCuadrada = 0, contTriangular = 0, contSenoidal = 0;
        Serial.println("Iniciando Adquisicion...\n");
        while (digitalRead(pulsador2) == LOW){
            val = analogRead(analogPin);
            tiempoVal = millis() - inicio;
            val = val/100;

            Serial.println(val);
            //Serial.println(size);
            //Serial.println(tiempoVal);
            //Serial.println("------");
            if (size >= max){
                Serial.println("------");
                // 				IDENTIFICAR CUADRADA
                cuadra = verificarcuadrada(arreglo, sizeArreglo);
                if(cuadra){contCuadrada++;}
                else {
                    // 				IDENTIFICAR TRIANGULAR

                    triangular = senialTriangular(arreglo, sizeArreglo);
                    if(triangular){contTriangular++;}
                    else if (senoi = verificarsenoidal(arreglo, sizeArreglo)) {contSenoidal++;}
                }

                bandera = true;
                size = 0;
                sizeArreglo = 0;
            }
            if(bandera){
                arreglo[sizeArreglo][0] = val; 		//Dato en posicion 0
                arreglo[sizeArreglo][1] = tiempoVal; 	  //Tiempo en la posicion 1
                size++;
                sizeArreglo++;
            }
            else if (size>=0){
                arreglo[sizeArreglo][0] = val; 		//Dato en posicion 0
                arreglo[sizeArreglo][1] = tiempoVal; 	  //Tiempo en la posicion 1
                size++;
                sizeArreglo++;
            }
            else{size++;}
        }

        //              INVOCACION DE AMPLITUD Y FRECUENCIA.
        periodo = calcularPeriodo(arreglo, sizeArreglo);
        frecuencia = calcularFrecuencia(periodo);
        amplitud = calcularAmplitud(arreglo, sizeArreglo);

        // 				IDENTIFICAR CUADRADA

        cuadra = verificarcuadrada(arreglo, sizeArreglo);
        if(cuadra){contCuadrada++;}
        else {
            // 				IDENTIFICAR TRIANGULAR

            triangular = senialTriangular(arreglo, sizeArreglo);
            if(triangular){contTriangular++;}
            else if (senoi = verificarsenoidal(arreglo, sizeArreglo)) {contSenoidal++;}
        }

        unsigned short int predo = predominante(contCuadrada, contTriangular, contSenoidal);

        switch (predo) {
        case 1:
            lcd_1.setCursor(0,0);
            lcd_1.print("F=");
            lcd_1.print(frecuencia);
            lcd_1.print("Hz");
            lcd_1.setCursor(9, 0);
            lcd_1.print("A=");
            lcd_1.print(amplitud);
            lcd_1.print("V");
            lcd_1.setCursor(0, 1);
            lcd_1.print(" Cuadrada ");
            break;
        case 2:
            lcd_1.setCursor(0,0);
            lcd_1.print("F=");
            lcd_1.print(frecuencia);
            lcd_1.print("Hz");
            lcd_1.setCursor(9, 0);
            lcd_1.print("A=");
            lcd_1.print(amplitud);
            lcd_1.print("V");
            lcd_1.setCursor(0, 1);
            lcd_1.print(" Triangular ");
            break;
        case 3:
            lcd_1.setCursor(0,0);
            lcd_1.print("F=");
            lcd_1.print(frecuencia);
            lcd_1.print("Hz");
            lcd_1.setCursor(9, 0);
            lcd_1.print("A=");
            lcd_1.print(amplitud);
            lcd_1.print("V");
            lcd_1.setCursor(0, 1);
            lcd_1.print(" Senoidal ");
            break;
        case 4:
            lcd_1.setCursor(0,0);
            lcd_1.print("F=");
            lcd_1.print(frecuencia);
            lcd_1.print("Hz");
            lcd_1.setCursor(9,0);
            lcd_1.print("A=");
            lcd_1.print(amplitud);
            lcd_1.print("V");
            lcd_1.setCursor(0, 1);
            lcd_1.print(" Desconocida ");
            break;
        default:
            break;
        }

        // Liberar la memoria al final
        for (int i = 0; i<max; i++){
            delete[] arreglo[i];
        }
        delete[] arreglo;

    }
    while (1); //frenar la ejecucion pero no terminarla
}


//                  PARA LA IDENTIFICACION DE LA SEÑAL

bool verificarcuadrada(float** arreglo, unsigned short int filas){
    //Recibe el apuntador al arreglo de datos, guarda su primer valor, e itera entre sus posiciones
    //para luego compararlo con el resto, si encuantra 3 valores distintos retorna false(0) y si
    //solo encuentra 2 valores en todos los datos retorna true(1)
    if (filas < 2) {return false;}
    float primerValor = arreglo[0][0];
    float segundoValor;
    bool encontradoSegundoValor = false;

    for(unsigned short int i = 1; i < filas-2; i++){
        if (arreglo[i][0] != primerValor) {
            if (!encontradoSegundoValor) {
                segundoValor = arreglo[i][0];
                encontradoSegundoValor = true;
            } else if (arreglo[i][0] != segundoValor) {
                return false;
            }
        }
        if (arreglo[i-1][0]<arreglo[i][0] && arreglo[i][0]==arreglo[i+2][0]){return true;}
    };
    return true;
}

bool senialTriangular(float** arreglo, unsigned short int filas){
    //esta funcion verifica si una funcion es triangular o no, retorna true
    //si es triangular, o false si no lo es.
    if (filas < 10){return false;}
    for (unsigned short int i = 5; i < filas-2; i++){
        float deltaTiempo = (arreglo[i][1])-(arreglo[i-1][1]);
        float deltaValor = (arreglo[i][0])-(arreglo[i-1][0]);
        float pendiente1 = (deltaValor)/(deltaTiempo);				// PENDIENTE ANTERIOR

        float deltaTiempo2 = (arreglo[i-1][1])-(arreglo[i-2][1]);
        float deltaValor2 = (arreglo[i-1][0])-(arreglo[i-2][0]);
        float pendiente2 = (deltaValor2)/(deltaTiempo2);			// PENDIENTE ANTERIORx2

        float deltaTiempo3 = (arreglo[i+2][1])-(arreglo[i][1]);
        float deltaValor3 = (arreglo[i+2][0])-(arreglo[i][0]);
        float pendiente3 = (deltaValor3)/(deltaTiempo3);			// PENDIENTE POSTERIOR

        if (arreglo[i][0]==arreglo[i+1][0] || (arreglo[i][0]==arreglo[i-1][0])){
            return false;
        }
        if ((arreglo[i-1][0]<arreglo[i][0]) && (arreglo[i][0]>arreglo[i+1][0]) || (arreglo[i-1][0]>arreglo[i][0]) && (arreglo[i][0]<arreglo[i+1][0])){
            float deltaTiempo4 = (arreglo[i-2][1])-(arreglo[i-3][1]);
            float deltaValor4 = (arreglo[i-2][0])-(arreglo[i-3][0]);
            float pendiente4 = (deltaValor)/(deltaTiempo);

            float deltaTiempo5 = (arreglo[i-3][1])-(arreglo[i-4][1]);
            float deltaValor5 = (arreglo[i-3][0])-(arreglo[i-4][0]);
            float pendiente5 = (deltaValor)/(deltaTiempo);

            float deltaTiempo6 = (arreglo[i-4][1])-(arreglo[i-5][1]);
            float deltaValor6 = (arreglo[i-4][0])-(arreglo[i-5][0]);
            float pendiente6 = (deltaValor)/(deltaTiempo);

            float promPendientes = abs(pendiente1+pendiente2+pendiente3+pendiente4+pendiente5)/5;

            //QUE EL PROMEDIO DE LAS 5 PENDIENTES ANTERIORES SEA APROX A LA PENDIENTE ACTUAL
            if (pendiente1>=promPendientes*0.88 && pendiente1<=promPendientes*1.249){return true;}
            //QUE LA PENDIENTE 2 SEA SEMEJANTE A LA PENDIENTE 1
            if(pendiente2>=pendiente1*0.88 && pendiente2<=pendiente1*1.249){return true;}
            //QUE LA PENDIENTE 3 SEA SEMEJANTE A LA PENDIENTE 1 MULTIPLICADA POR (-1)
            if (pendiente3>=(pendiente1*0.88)*(-1) && pendiente3<=(pendiente1*1.249)*(-1)){return true;}
            //QUE LA PENDIENTE ANTERIOR Y POSTERIOR SEAN 0 APROX (RETORNA CERO)
            if ((pendiente1 >= -0.00218096 && pendiente1 <= 0.00218096) && (pendiente3 >= -0.00218096 && pendiente3 <= 0.00218096)){return false;}
        }
        if(arreglo[i-1][0]<arreglo[i][0] && arreglo[i][0]<arreglo[i+1][0]){
            //QUE LA DIFERENCIA ENTRE DOS PENDIENTES CONSECUTIVAS SEA 0 APROX
            if(pendiente3-pendiente1>-0.000218096 && pendiente3-pendiente1<0.000218096){return true;}
            //QUE LAS PENDIENTES CONSECUTIVAS SEAN IGUALES APROX
            if(pendiente3>=pendiente1*0.99999999999 && pendiente3<=pendiente1*1.000000001){return true;}
        }
    }
    return false;
}

bool verificarsenoidal(float** arreglo, unsigned short int filas){
    //
    //
    float suavidad, pendiente, pendientet;
    short int cambiosSuaves = 0, totalCambios = 0;
    bool bandera = true;
    for (unsigned short int i = 1; i < filas-1; i++){
        pendiente=(arreglo[i][0]-arreglo[i-1][0])/arreglo[i][1]-arreglo[i-1][1];
        pendientet+=(arreglo[i+1][0]-arreglo[i][0])/arreglo[i][1]-arreglo[i-1][1];
        if (pendiente<0){
            pendiente=pendiente*(-1);
        }
        if (pendiente>0){
            if(pendientet>0){
                if (pendientet>=pendiente*0.88 && pendientet<=pendiente*1.249){
                    return true;
                }
            }
            else{
                pendientet=pendientet*(-1);
                if (pendientet>=pendiente*0.88 && pendientet<=pendiente*1.249){
                    return true;
                }
            }
        }
        if (arreglo[i][0]==arreglo[i+1][0] || arreglo[i][0]==arreglo[i-1][0]){
            return true;
        }
        float diferencia1 = arreglo[i][0] - arreglo[i-1][0];
        float diferencia2 = arreglo[i+1][0] - arreglo[i][0];
        if (abs(diferencia2 - diferencia1)<5){
            cambiosSuaves++;
        }
        totalCambios++;
    }
    float proporsionSuave = cambiosSuaves/totalCambios;
    if(proporsionSuave>0.5){return false;}
    return false;
}

unsigned short int predominante(unsigned short int cuadra, unsigned short int triangu, unsigned short int senoi){
    //En base a los contadores de señales, calcula el porcentaje de cada uno y retorna
    //su valor en int.
    float total = (cuadra + triangu + senoi);
    float pcuadra = (cuadra)/total, ptriangu = (triangu)/total, psenoi = (senoi)/total;

    if (pcuadra>0.51){
        return 1;
    } else if(ptriangu>0.51){
        return 2;
    } else if(psenoi>0.51){
        return 3;
    } else {return 4;}
}

//                    FUNCIONES PARA AMPLITUD Y FRECUENCIA.


float calcularAmplitud(float** arreglo, unsigned short int size){
    // Calcula el valor maximo y minimo y luego halla su promedio, retorna su valor float.
    float valorMax = arreglo[0][0];
    float valorMin = arreglo[0][0];
    for (unsigned short int i = 1; i < size; ++i) {
        if (arreglo[i][0] < valorMin) {
            valorMin = arreglo[i][0];
        }
        if (arreglo[i][0] > valorMax) {
            valorMax = arreglo[i][0];
        }
    }
    if (valorMax < 0){valorMax = (-1)*valorMax;}
    if (valorMin < 0){valorMin = (-1)*valorMin;}
    return valorMax;
}

float calcularPeriodo(float** arreglo, unsigned short int size){
    if (size < 3) {
        return 0;
    }
    float tiempoInicial = 0;
    float tiempoFinal = 0;
    unsigned short int Picos = 0;
    for (unsigned short int i = 1; i < size - 1; ++i){
        //Maximo
        float valorAnterior = arreglo[i - 1][0];
        float valorActual = arreglo[i][0];
        float valorSiguiente = arreglo[i + 1][0];
        if ((valorActual) >= (valorAnterior) && (valorActual) > (valorSiguiente)){
            Picos++;
            if (Picos == 1) {
                tiempoInicial = arreglo[i][1];
            }
            else if (Picos == 2) {
                tiempoFinal = arreglo[i][1];
                break;
            }
        }
    }
    float periodo = (tiempoFinal - tiempoInicial) / 1000.0;
    return periodo;
}
float calcularFrecuencia(float periodo){
    if (periodo  <= 0){
        return 0;
    }
    return (1.f / periodo);
}
