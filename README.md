# **Parcial Arquitectura de Hardware: Nicolás Echeverri y Samuel Corrales**

## Primer Punto: calcular las raíces de un polinomio grado 2

En este programa el usuario puede ingresar tres números que representan los tres valores en una ecuación cuadrática $ax^{2}+bx+c=0$, haciendo uso del teclado matricial, al ingresar un número el usuario debe presionar la tecla '#' a modo de una tecla 'Enter' para poder pasar a ingresar el siguiente número. Al final el programa debería devolver por consola los dos resultados de la ecuación.

### Declaración de todos los caracteres en el teclado

A continuación se muestra cómo se inicializan todas las teclas:

```C++

char keyMap[numRows][numCols] = {{'1', '2', '3', 'A'},
                                  {'4', '5', '6', 'B'},
                                  {'7', '8', '9', 'C'},
                                  {'*', '0', '#', 'D'}};

DigitalOut rowPins[numRows] = {DigitalOut(D2), DigitalOut(D3), DigitalOut(D4), DigitalOut(D5)};
DigitalIn colPins[numCols] = {DigitalIn(D6), DigitalIn(D7), DigitalIn(D8), DigitalIn(D9)};

```

Luego se lee cuál es la fila y la columna dónde está la tecla que oprimió el usuario:

```C++


```


