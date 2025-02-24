// #include "mbed.h"
// #include <string>

// const int numRows = 4;
// const int numCols = 4;

// char keyMap[numRows][numCols] = {{'1', '2', '3', 'A'},
//                                  {'4', '5', '6', 'B'},
//                                  {'7', '8', '9', 'C'},
//                                  {'*', '0', '#', 'D'}};

// DigitalOut rowPins[numRows] = {DigitalOut(D2), DigitalOut(D3), DigitalOut(D4),
//                                DigitalOut(D5)};
// DigitalIn colPins[numCols] = {DigitalIn(D6), DigitalIn(D7), DigitalIn(D8),
//                               DigitalIn(D9)};

// int main() {
//   int contador = 0;
//   float numeros[3];
//   string numero;

//   while (true) {
//     for (int i = 0; i < numRows; i++) {
//       rowPins[i] = 0;

//       for (int j = 0; j < numCols; j++) {
//         if (!colPins[j]) {
//           numero += keyMap[i][j];
//           ThisThread::sleep_for(500ms);
//         }
//       }
//       rowPins[i] = 1;
//     }

//     if (numero.back() == '#') {
//       numero.pop_back();
//       numeros[contador] = stof(numero);
//       contador++;
//       numero = "";

//       if (contador == 3) {
//         break;
//       }
//     }
//   }

//   float a = numeros[0];
//   float b = numeros[1];
//   float c = numeros[2];

//   float x1, x2;

//   x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
//   x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

//   printf("Las soluciones de la ecuación son: x1 y x2 respectivamente = %f\n", x1, x2);

//   return 0;
// }


/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
/*
#include "mbed.h"
#include <iostream>
#include <string>
#include <cmath>

// Blinking rate in milliseconds
#define BLINKING_RATE     200ms

// Objeto para establecer la comunicación serial con el Pc
UnbufferedSerial serial(USBTX, USBRX, 9600);

using namespace std;

const int numRows = 4;
const int numCols = 4;

char keyMap[numRows][numCols] = {{'1', '2', '3', 'A'},
                                 {'4', '5', '6', 'B'},
                                 {'7', '8', '9', 'C'},
                                 {'*', '0', '#', 'D'}};

DigitalOut rowPins[numRows] = {DigitalOut(D2), DigitalOut(D3), DigitalOut(D4),
                               DigitalOut(D5)};
DigitalIn colPins[numCols] = {DigitalIn(D6), DigitalIn(D7), DigitalIn(D8),
                              DigitalIn(D9)};

char getKeyPressed() {
    for (int i = 0; i < numRows; i++) {
        rowPins[i] = 0;
        for (int j = 0; j < numCols; j++) {
            if (!colPins[j]) {
                char num = keyMap[i][j];
                ThisThread::sleep_for(500ms);  // Avoid multiple readings while the key is pressed
                return num;
            }
        }
        rowPins[i] = 1;
    }
    return '\0';
}

int main() {
    string numero = "";
    float grade;
    while (true) {
        char key = getKeyPressed();
        if (key != '\0') {
            if (key == '#') {
                if (numero.empty()) {
                    printf("No grade entered.\n");
                } else {
                    grade = stof(numero);
                    char alphanumeric_grade;
                    if (grade >= 0 && grade <= 3) {
                        alphanumeric_grade = 'A';
                    } else if (grade > 3 && grade <= 4) {
                        alphanumeric_grade = 'B';
                    } else if (grade > 4 && grade <= 5) {
                        alphanumeric_grade = 'C';
                    } else if (grade > 5 && grade <= 7) {
                        alphanumeric_grade = 'D';
                    } else if (grade > 7 && grade < 9) {
                        alphanumeric_grade = 'E';
                    } else if (grade >= 9 && grade <= 10) {
                        alphanumeric_grade = 'F';
                    } else {
                        printf("Invalid grade entered.\n");
                        numero = "";
                        continue;
                    }
                    printf("Alphanumeric grade: %c\n", alphanumeric_grade);
                    numero = "";
                }
            } else {
                numero += key;
            }
        }
    }
    return 0;
}*/
/*
#include "mbed.h"
#include <iostream>
#include <string.h>

//Definimos el período de tiempo en el que se cambiará el color 
//de los LEDs RGB. En este caso, se establece en 50 milisegundos (ms)
#define BLINKING_RATE     50ms

//Creamos un objeto UnbufferedSerial llamado serial para la comunicación
//serial utilizando los pines USBTX y USBRX de la placa
//La velocidad de transmisión se establece en 9600 baudios*
UnbufferedSerial serial(USBTX, USBRX, 9600);

//Creamos objetos PwmOut para controlar los LEDs RGB conectados a los pines
//LED1, LED2 y LED3 de la placa
//con estos objetos podremos controlar la intensidad de los colores rojo,
//verde y azul mediante modulación por ancho de pulso (PWM)*
PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);

//Definimos una función setRGBColor que toma tres valores flotantes del 0 al 1
//para establecer la intensidad de los colores rojo, verde y azul en los LEDs RGB
void setRGBColor(float red, float green, float blue) {
    ledR = red;
    ledG = green;
    ledB = blue;
}

const int numRows = 4;
const int numCols = 4;

char keyMap[numRows][numCols] = {{'1', '2', '3', 'A'},
                                 {'4', '5', '6', 'B'},
                                 {'7', '8', '9', 'C'},
                                 {'*', '0', '#', 'D'}};

DigitalOut rowPins[numRows] = {DigitalOut(D2), DigitalOut(D3), DigitalOut(D4),
                               DigitalOut(D5)};
DigitalIn colPins[numCols] = {DigitalIn(D6), DigitalIn(D7), DigitalIn(D8),
                              DigitalIn(D9)};

char getKeyPressed() {
    for (int i = 0; i < numRows; i++) {
        rowPins[i] = 0;
        for (int j = 0; j < numCols; j++) {
            if (!colPins[j]) {
                char num = keyMap[i][j];
                ThisThread::sleep_for(500ms);  // Avoid multiple readings while the key is pressed
                return num;
            }
        }
        rowPins[i] = 1;
    }
    return '\0';
}

int main() {
    while(true) {
        char key = getKeyPressed();
        if (key != '\0') {
            if (key == '#') {
                break;
            } else {
                if (key >= '0' && key <= '9' || key >= 'A' && key <= 'F') {
                    char input[8];
                    input[0] = '#';
                    input[1] = key;
                    input[2] = '\0';
                    unsigned int colorValue;
                    sscanf(input, "%x", &colorValue);
                    float red = (1-(float)((colorValue >> 16) & 0xFF) / 255.0f);
                    float green = (1-(float)((colorValue >> 8) & 0xFF) / 255.0f);
                    float blue = (1-(float)(colorValue & 0xFF) / 255.0f);
                    setRGBColor(red, green, blue);
                }
            }
        }
    }
    return 0;
}*/
