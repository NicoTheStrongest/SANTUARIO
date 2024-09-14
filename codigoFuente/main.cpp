// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int size = 0;
int capacidad = 5;
int pulsador1 = 2;
int pulsador2 = 3;
int analogPin = 0;

float val = 0;
float** arreglo = nullptr; // Puntero inicial
float inicio;
float tiempoVal = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
    Serial.begin(9600);
    pinMode(pulsador1, INPUT);
    pinMode(pulsador2, INPUT);

    lcd_1.begin(16, 2);
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
        delay(70);
    }
    if (digitalRead(pulsador1)==HIGH){
        inicio = millis();
        Serial.println("Adquisicion:\n");
        while (digitalRead(pulsador2) == LOW){
            val = analogRead(analogPin);
            val = val/100;
            Serial.println(val);
            tiempoVal = millis() - inicio;
            Serial.println(tiempoVal);
            Serial.println("------");
            delay(70);
            // Copiar los elementos anteriores al nuevo arreglo
            if (size == capacidad) {
                // Duplicar la capacidad
                capacidad *= 2;
                float** nuevoArreglo = new float*[capacidad];

                // Copiar los elementos al nuevo arreglo
                for (int i = 0; i < size; ++i) {
                    nuevoArreglo[i] = arreglo[i];
                }

                // Liberar el viejo arreglo
                delete[] arreglo;

                // Asignar el nuevo arreglo
                arreglo = nuevoArreglo;

            }
            arreglo[size] = new float[2];
            arreglo[size][0] = tiempoVal;
            arreglo[size][1] = val; //agrega el dato
            ++size;
        }
        delay(100);
        Serial.println("Elementos en el arreglo:\n");
        for (int i = 0; i < size; ++i) {
            Serial.println(arreglo[i][1]);
            Serial.println(arreglo[i][0]);
            Serial.println("------");
        }


        // Liberar la memoria al final
        for (int i = 0; i<size; i++){
            delete[] arreglo[i];
        }
        delete[] arreglo;


        //mostrar en lcd
        //deletes
        //Serial.println("hola");
    }
    while (1); //frenar la ejecucion pero no terminarla
}
