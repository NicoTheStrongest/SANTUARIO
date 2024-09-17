#include <Adafruit_LiquidCrystal.h>


//                INICIALIZACION DE VARIABLES


unsigned short int size = 0;
unsigned short int capacidad = 15;
const short int pulsador1 = 2;
const short int pulsador2 = 3;
const short int analogPin = 0;

float val = 0;
float** arreglo = nullptr; // Puntero inicial
float inicio;
float tiempoVal = 0;

Adafruit_LiquidCrystal lcd_1(0);

//               REGISTRO DE ACTIVACION

bool verificarcuadrada(float** arreglo, int filas);
bool senialTriangular(float** arreglo, int filas);
bool verificarsenoidal(float** arreglo, int filas);

float calcularAmplitud(float** arreglo, int size);
float calcularPeriodo(float** arreglo, int size);
float calcularFrecuencia(float periodo);

void setup()
{
    lcd_1.begin(16, 2);
    Serial.begin(9600);
    pinMode(pulsador1, INPUT);
    pinMode(pulsador2, INPUT);

    //CREANDO MATRIZ DE DATOS
    arreglo = new float*[capacidad];
    for (int i = 0; i<capacidad; i++)
    {
        arreglo[i] = new float [2];
    }
}

void loop()
{
    while (digitalRead(pulsador1) == LOW){
        val = analogRead(analogPin);
        Serial.println(val/100);
    }
    if (digitalRead(pulsador1)==HIGH){
        inicio = millis();
        unsigned short int contCuadrada = 0, contTriangular = 0, contSenoidal = 0;
        Serial.println("Adquisicion:\n");
        while (digitalRead(pulsador2) == LOW){
            val = analogRead(analogPin);
            tiempoVal = millis() - inicio;
            val = val/100;

            //Serial.println(val);
            //Serial.println(size);
            //Serial.println(freeMemory());
            //Serial.println(tiempoVal);
            //Serial.println("------");
            //delay(70);

            // Para copiar los elementos anteriores al nuevo arreglo
            if (size == capacidad)
            {
                // aumentar la capacidad
                capacidad += 15;
                if (capacidad < 60) //capacidad limite
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
                else
                {
                    //analizar primer tramo
                    for(int i = 0; i < 15; i++){
                        // 				IDENTIFICAR CUADRADA

                        //bool cuadra = verificarcuadrada(arreglo, size);
                        //lcd_1.print(cuadra);

                        // 				IDENTIFICAR TRIANGULAR

                        //bool triangular = senialTriangular(arreglo, size);
                        //lcd_1.print(triangular);
                    }
                }
            }
            else{arreglo[size] = new float[2];}

            arreglo[size][0] = val; //tiempo en posicion 0
            arreglo[size][1] = tiempoVal; 	  //Dato en la posicion 1
            ++size;
        }
        delay(100);
        /*
    Serial.println("Elementos en el arreglo:\n");
    for (int i = 0; i < size; ++i) {
      Serial.println(arreglo[i][1]);
      Serial.println(arreglo[i][0]);
      Serial.println("------");
    }
    */

        /*
    //              INVOCACION DE AMPLITUD Y FRECUENCIA.
    float periodo = calcularPeriodo(arreglo, size);
    float frecuencia = calcularFrecuencia(periodo);
    float amplitud = calcularAmplitud(arreglo,size);

    Serial.print("Periodo: ");
    Serial.println(periodo);
    Serial.print("Frecuencia: ");
    Serial.println(frecuencia);
    Serial.print("Amplitud:");
    Serial.println(amplitud);
    */

        // 				IDENTIFICAR CUADRADA

        //bool cuadra = verificarcuadrada(arreglo, size);
        //lcd_1.print(cuadra);

        // 				IDENTIFICAR TRIANGULAR

        //bool triangular = senialTriangular(arreglo, size);
        //lcd_1.print(triangular);




        //(por terminar) IDENTIFICAR SENOIDAL

        //bool senoidal = verificarsenoidal(arreglo, size);
        //lcd_1.print(senoidal);


        // Liberar la memoria al final
        for (int i = 0; i<size; i++){
            delete[] arreglo[i];
        }
        delete[] arreglo;

    }
    while (1); //frenar la ejecucion pero no terminarla
}

bool verificarcuadrada(float** arreglo, int filas){
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

bool senialTriangular(float** arreglo, int filas){
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


//por terminar
bool verificarsenoidal(float** arreglo, int filas){
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


//                    FUNCIONES PARA AMPLITUD Y FRECUENCIA.


float calcularAmplitud(float** arreglo, int size){
    float valorMax = arreglo[0][0];
    float valorMin = arreglo[0][0];
    for (int i = 1; i < size; ++i) {
        if (arreglo[i][1] < valorMin) {
            valorMin = arreglo[i][0];
        }
        if (arreglo[i][1] > valorMax) {
            valorMax = arreglo[i][0];
        }
    }
    float amplitud = (valorMax - valorMin) / 2;
    return amplitud;
}

float calcularPeriodo(float** arreglo, int size){
    if (size < 3){
        return 0;
    }
    float tiempoInicial = 0;
    float tiempoFinal = 0;
    int Cruce = 0;
    for (int i = 0; i < size-1; i++) {
        if ((arreglo[i][1] > 0 && arreglo[i + 1][1] < 0) || (arreglo[i][1] < 0 && arreglo[i + 1][1] > 0)) {
            Cruce++;
            if(Cruce == 1){
                tiempoInicial = arreglo[i][0];
                Serial.println(tiempoInicial);
            }
            else if(Cruce == 3){
                tiempoFinal = arreglo[i][0];
                Serial.println(tiempoFinal);
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


/*//              PARA MOSTRAR HEAP DISPONIBLE


extern unsigned int __heap_start;
extern void *__brkval;

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
