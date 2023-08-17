#include "mbed.h"
#include <iostream>
#define BLINKING_RATE     500ms

int main() {

    PwmOut ledRojo(LED1);
    PwmOut ledVerde(LED2);
    PwmOut ledAzul(LED3);

    float valorR, valorG, valorB;

    cout << "Ingrese el valor para R: ";
    cin << valorR;

    cout << "Ingrese el valor para G: ";
    cin << valorG;

    cout << "Ingrese el valor para B: ";
    cin << valorB;

    ledRojo.write(valorR);
    ledVerde.write(valorG);
    ledAzul.write(valorB);

}
