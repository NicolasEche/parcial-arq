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

### Almacenamiento de cada valor en la ecuación

Luego se enciende la fila que el usuario ingresa:

```C++

int main() {
   int contador = 0;
   float numeros[3];
   string numero;

   while (true) {
     for (int i = 0; i < numRows; i++) {
       rowPins[i] = 0;

       for (int j = 0; j < numCols; j++) {
         if (!colPins[j]) {
           numero += keyMap[i][j];
           ThisThread::sleep_for(500ms);
         }
       }
       rowPins[i] = 1;
      }
    }
}

```

Se itera a través de todas las filas para encederlas una a una. Luego se verifica si alguna tecla ha sido presionada por medio de esta línea de código:

```C++

if (!colPins[j])

```
Luego de leer la tecla oprimida por el usuario, el caracter que corresponde a dicha tecla se concatena a la cadena 'numero' para guardar un número de más de un dígito.

Ahora, para poder almacenar los tres números, mencionamos anteriormente que se debe presionar la tecla '#' para poder pasar a almacenar el siguiente número, dicho proceso se lleva a cabo mediante la siguiente parte del código:

```C++

if (numero.back() == '#') {
     numero.pop_back();
     numeros[contador] = stof(numero);
     contador++;
     numero = "";

     if (contador == 3) {
       break;
     }
}

```

Primero se verifica si el último caracter de la cadena número es el símbolo '#' a continuación se elimina dicho símbolo para poder usarlo luego en el cálculo de los resultados de la ecuación. El sistema detecta que ya se han ingresado los tres números cuando la longitud de el arreglo ``` numeros ``` tiene un valor de 3, es ahí cuando sale del ciclo while infinito.

### Cálculo de los resultados de la ecuación

Finalmente, con los tres valores de la ecuación se pasan a calcular los dos resultadosde la misma con la fórmula cuadrática general:

```C++

float a = numeros[0];
float b = numeros[1];
float c = numeros[2];

float x1, x2;

x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

printf("Las soluciones de la ecuación son: x1 y x2 respectivamente = %f\n", x1, x2);

return 0;

```

## Segundo Punto: calculo de calificación alfanumérica

