#include <Adafruit_LiquidCrystal.h>


//                INICIALIZACION DE VARIABLES


unsigned short int size = 0;
//unsigned short int capacidad = 15;
const short int pulsador1 = 2;
const short int pulsador2 = 3;
const short int analogPin = 0;

float val = 0;
float** arreglo = nullptr; // Puntero inicial
float inicio;
float tiempoVal = 0;

Adafruit_LiquidCrystal lcd_1(0);

//               REGISTRO DE ACTIVACION

bool verificarcuadrada(float** arreglo, unsigned short int filas);
bool senialTriangular(float** arreglo, int filas);
int predominante(int cuadra, int triangu, int senoi);

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
    arreglo = new float*[size];
    for (int i = 0; i<size; i++)
    {
        arreglo[i] = new float [2];
    }
}

void loop()
{
    while (digitalRead(pulsador1) == LOW){
        //val = analogRead(analogPin);
        //Serial.println(val/100);
    }
    if (digitalRead(pulsador1)==HIGH){
        inicio = millis();
        bool triangular, cuadra, bandera = true;
        unsigned short int contCuadrada = 0, contTriangular = 0, contSenoidal = 0;
        Serial.println("Adquisicion...\n");
        while (digitalRead(pulsador2) == LOW){
            val = analogRead(analogPin);
            tiempoVal = millis() - inicio;
            val = val/100;

            //Serial.println(val);
            //Serial.println(size);
            //Serial.println(tiempoVal);
            //Serial.println("------");
            //delay(70);

            // Alternativa 1 de reemplazo.
            if (size>50){
                //delay(1);
                // 				IDENTIFICAR CUADRADA

                cuadra = verificarcuadrada(arreglo, size);
                if(cuadra){contCuadrada++;}

                // 				IDENTIFICAR TRIANGULAR

                triangular = senialTriangular(arreglo, size);
                if(triangular){contTriangular++;}
                else{contSenoidal++;}
                size = 0;
            }
            else if (bandera){arreglo[size] = new float[2];}

            arreglo[size][0] = val; 		//Dato en posicion 0
            arreglo[size][1] = tiempoVal; 	  //Tiempo en la posicion 1
            ++size;
        }
        delay(100);

        //              INVOCACION DE AMPLITUD Y FRECUENCIA.
        float periodo = calcularPeriodo(arreglo, size);
        float frecuencia = calcularFrecuencia(periodo);
        float amplitud = calcularAmplitud(arreglo,size);


        // 				IDENTIFICAR CUADRADA

        cuadra = verificarcuadrada(arreglo, size);
        if(cuadra){contCuadrada++;}

        // 				IDENTIFICAR TRIANGULAR

        triangular = senialTriangular(arreglo, size);
        if(triangular){contTriangular++;}
        else{contSenoidal++;}


        Serial.print("Frecuencia: ");
        Serial.println(frecuencia);
        Serial.print("Amplitud:");
        Serial.println(amplitud);

        int predo = predominante(contCuadrada, contTriangular, contSenoidal);

        switch (predo) {
        case 1:
            lcd_1.print("CUA");
            break;
        case 2:
            lcd_1.print("TRI");
            break;
        case 3:
            lcd_1.print("SEN");
            break;
        case 4:
            lcd_1.print("DES");
            break;
        default:
            break;
        }

        // Liberar la memoria al final
        for (int i = 0; i<size; i++){
            delete[] arreglo[i];
        }
        delete[] arreglo;

    }
    //while (1); //frenar la ejecucion pero no terminarla
}


//                  PARA LA IDENTIFICACION DE LA SEÑAL

bool verificarcuadrada(float** arreglo, unsigned short int filas){
    //Recibe el apuntador al arreglo de datos, guarda su primer valor, e itera entre sus posiciones
    //para luego compararlo con el resto, si encuantra 3 valores distintos retorna false(0) y si
    //solo encuentra 2 valores en todos los datos retorna true(1)
    if (filas < 2) {
        return false;
    }
    float primerValor = arreglo[0][0];
    float segundoValor;
    bool encontradoSegundoValor = false;

    for(int i = 1; i < filas-1; i++){
        if (arreglo[i][0] != primerValor) {
            if (!encontradoSegundoValor) {
                segundoValor = arreglo[i][0];
                encontradoSegundoValor = true;
            } else if (arreglo[i][0] != segundoValor) {
                return false;
            }
        }
    };
    return true;
}

bool senialTriangular(float** arreglo, unsigned short int filas){
    //esta funcion verifica si una funcion es triangular o no, retorna true
    //si es triangular, o false si no lo es.
    float valorMax = -999999;
    float valorMin = 999999;
    for (int i = 0; i < filas-1; ++i) {
        if (arreglo[i][0] < valorMin) {
            valorMin = arreglo[i][0];
        }
        if (arreglo[i][0] > valorMax) {
            valorMax = arreglo[i][0];
        }
    }

    for (int i = 2; i < filas-1; i++){
        if ((arreglo[i][0]==arreglo[i+1][0]) && (arreglo[i][1]!=arreglo[i+1][1])){
            return false;
        }
        if (arreglo[i][0]>=valorMax*0.92 && (arreglo[i-1][0])<arreglo[i][0] && arreglo[i][0]>arreglo[i+1][0]){
            float deltaTiempo = (arreglo[i][1])-(arreglo[i-1][1]);
            float deltaValor = (arreglo[i][0])-(arreglo[i-1][0]);
            float pendiente1 = (deltaValor)/(deltaTiempo);

            float deltaTiempo2 = (arreglo[i-1][1])-(arreglo[i-2][1]);
            float deltaValor2 = (arreglo[i-1][0])-(arreglo[i-2][0]);
            float pendiente2 = (deltaValor2)/(deltaTiempo2);

            //float deltaTiempo3 = (arreglo[i+2][1])-(arreglo[i][1]);
            //float deltaValor3 = (arreglo[i+2][0])-(arreglo[i][0]);
            //float pendiente3 = (deltaValor3)/(deltaTiempo3);
            if(pendiente2>=pendiente1*0.88 && pendiente2<=pendiente1*1.249){
                return true;
            }
        }
    }
    return false;
}

int predominante(int cuadra, int triangu, int senoi){
    //En base a los contadores de señales, calcula el porcentaje de cada uno y retorna
    //su valor en int.
    int total = cuadra + triangu + senoi;
    float pcuadra = (cuadra/total)*100, ptriangu = (triangu/total)*100, psenoi = (senoi/total)*100;
    if (pcuadra>ptriangu && pcuadra>psenoi){
        return 1;
    } else if(ptriangu>pcuadra && ptriangu>psenoi){
        return 2;
    } else if(psenoi>triangu && psenoi>pcuadra){
        return 3;
    } else {return 4;}

}

//                    FUNCIONES PARA AMPLITUD Y FRECUENCIA.


float calcularAmplitud(float** arreglo, unsigned short int size){
    // Calcula el valor maximo y minimo y luego halla su promedio, retorna su valor float.
    float valorMax = arreglo[0][0];
    float valorMin = arreglo[0][0];
    for (int i = 1; i < size; ++i) {
        if (arreglo[i][0] < valorMin) {
            valorMin = arreglo[i][0];
        }
        if (arreglo[i][0] > valorMax) {
            valorMax = arreglo[i][0];
        }
    }
    float amplitud = (valorMax - valorMin) / 2;
    return amplitud;
}

float calcularPeriodo(float** arreglo, int size){
    //Calcula el periodo del arreglo de datos, encontrando sus cruces por cero, retorna su valor float.
    if (size < 3){
        return 0;
    }
    float tiempoInicial = 0;
    float tiempoFinal = 0;
    unsigned int Cruce = 0;
    for (int i = 0; i < size-1; i++) {
        if ((arreglo[i][0] > 0 && arreglo[i + 1][0] < 0) || (arreglo[i][0] < 0 && arreglo[i + 1][0] > 0)) {
            Cruce++;
            if(Cruce == 1){
                tiempoInicial = arreglo[i][1];
            }
            else if(Cruce == 3){
                tiempoFinal = arreglo[i][1];
                break;
            }
        }
    }
    float periodo = (tiempoFinal - tiempoInicial) / 1000.0;
    return periodo;
}

float calcularFrecuencia(float periodo){
    // Calcula la fecuncia en base al inverso del periodo y retorna su valor float.
    if (periodo  <= 0){
        return 0;
    }
    return (1.f / periodo);
}

//			PARA IMPRIMIR EL ARREGLO
/*
Serial.println("Elementos en el arreglo:\n");
for (int i = 0; i < size; ++i) {
    Serial.println(arreglo[i][1]);
    Serial.println(arreglo[i][0]);
    Serial.println("------");
    }
*/

/*
 lcd.setCursor(0, 0);  // display position
 lcd.print("T=");
 lcd.print(tempC);     // display the temperature
 lcd.print("C");

 lcd.setCursor(8, 0);  // display position
 lcd.print("H=");
 lcd.print(humi);      // display the humidity
 lcd.print("%");

 lcd.setCursor(0, 1);  // display position
 lcd.print("Gas=");
 lcd.print(porcentajeGas);     // display the temperature
 lcd.print("%");
 digitalWrite (Led, LOW);

*/


//              PARA MOSTRAR HEAP DISPONIBLE

/*
int freeMemory() {
  int free_memory;
  if((int)__brkval == 0) {
    free_memory = (int)&free_memory - (int)&__heap_start;
  } else {
    free_memory = (int)&free_memory - (int)__brkval;
  }
  return free_memory;
}
*/

/*
//            FORMA INICIAL DE REEMPLAZO DE MEMORIA

if (size == capacidad) {
// aumentar la capacidad
capacidad += 1;
    if (capacidad < 160) //capacidad limite
    {
        float** nuevoArreglo = new float*[capacidad];

        // Copiar los elementos al nuevo arreglo
        for (int i = 0; i < size; ++i)
        {
            nuevoArreglo[i] = arreglo[i];
        }

        // Liberar el viejo arreglo
        delete[] arreglo;

        // Asignar el nuevo arreglo
        arreglo = nuevoArreglo;

        arreglo[size] = new float[2];
    }
    else {
        //analizar primer tramo
        for(int i = 0; i < 15; i++){
        // 				IDENTIFICAR CUADRADA

        //bool cuadra = verificarcuadrada(arreglo, size);
        //lcd_1.print(cuadra);

        // 				IDENTIFICAR TRIANGULAR

        //bool triangular = senialTriangular(arreglo, size);
        //lcd_1.print(triangular);
        }
        else{arreglo[size] = new float[2];}
*/

/*
bool verificarsenoidal(float** arreglo, unsigned short int filas){
  //
  //
    float suavidad;
    float pendiente;
    float pendientet;
    bool bandera = true;
    for (int i = 1; i < filas-1; i++){
        pendiente=(arreglo[i][0]-arreglo[i-1][0])/0.1;
        pendientet+=(arreglo[i+1][0]-arreglo[i][0])/0.1;
        if (pendiente<0){
          pendiente=pendiente*(-1);
        }
        if (pendiente>0){
          if(pendientet>0){
            if (pendientet>=pendiente*0.9 && pendientet<=pendiente*1.1){
              return false;
            }
          }
          else{
            pendientet=pendientet*(-1);
            if (pendientet>=pendiente*0.9 && pendientet<=pendiente*1.1){
              return false;
            }
          }
        }
        if (arreglo[i][0]==arreglo[i+1][0] || arreglo[i][0]==arreglo[i-1][0]){
            return false;
        }
        if ((arreglo[i][0]>arreglo[i-1][0])&& bandera){
            suavidad=arreglo[i][0]-arreglo[i-1][0];
            bandera=false;
        }
        if((arreglo[i][0]<arreglo[i-1][0])&& bandera){
            suavidad=arreglo[i-1][0]-arreglo[i][0];
            bandera=false;
        }
        if(!((arreglo[i+1][0]-arreglo[i][0])<=(suavidad*1.5) && ((arreglo[i+1][0]-arreglo[i][0])>=(-1*(suavidad*1.5))))){
          return false;
        }
    }
    return true;
}
*/

