# **Parcial Arquitectura de Hardware: Nicolás Echeverri(cocotheloco) y Samuel Corrales**

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
Aplicación que solicite al usuario el ingreso de una nota N del 0 al 10 y despliegue una nota alfanumérica de la forma mostrada en el codigo.

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
### Seleccionar tecla del teclado matricial

primero recorremos con un ciclo for los renglones verificando la corriente del renglon, despues en otro ciclo verificcamos las columnas
y si cumple la condicion se le asigna a la variable num el numero seleccionado.

```C++

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
```
### Verificacion de nota

Primero verificamos si el usuario esta ingresando un valor y los esta confirmando con #

```C++

int main() {
    string numero = "";
    float grade;
    while (true) {
        char key = getKeyPressed();
        if (key != '\0') {
            if (key == '#') {
                if (numero.empty()) {
                    printf("No grade entered.\n");
                }
```
luego comenzamos a comprobar la nota ingresada con condicionales, los cuales imprimiran la nota dependiente a el valor ingresado por el usuario.

```C++

else {
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
```
Por ultimo verificamos si el nnumero ingresado es invalido, y retornamos 0 para que vuelva a empezar el ciclo.

```C++

printf("Alphanumeric grade: %c\n", alphanumeric_grade);
                    numero = "";
                }
            } else {
                numero += key;
            }
        }
    }
    return 0;
}
```
## Tercer punto: Encender Led RGB con el teclado
Aplicación que permita generar colores en un LED RGB con base en el código de color RGB.

### Definimos las RGB
Definimos el periodo, creamos PwmOut para controlar los led y definimos la funsion set Color para establecer la intecidad de los RGB.

```C++

#define BLINKING_RATE     50ms
UnbufferedSerial serial(USBTX, USBRX, 9600);

PwmOut ledR(LED1);
PwmOut ledG(LED2);
PwmOut ledB(LED3);

void setRGBColor(float red, float green, float blue) {
    ledR = red;
    ledG = green;
    ledB = blue;
}
```
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
### Seleccionar tecla del teclado matricial

primero recorremos con un ciclo for los renglones verificando la corriente del renglon, despues en otro ciclo verificcamos las columnas
y si cumple la condicion se le asigna a la variable num el numero seleccionado.

```C++

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
```
### Verificacion de tecla

Primero verificamos si el usuario esta ingresando un valor y los esta confirmando con #

```C++

int main() {
    while(true) {
        char key = getKeyPressed();
        if (key != '\0') {
            if (key == '#') {
                break;
            }
```

comprueba si key es un número del 0 al 9 o una letra de A a F (en mayúsculas). Esto se hace para asegurarse de que solo se procesen caracteres hexadecimales válidos.
La función sscanf se utiliza para escanear y convertir la cadena input en un valor hexadecimal que se almacena en la variable colorValue. Esto significa que colorValue contendrá el valor numérico correspondiente al carácter hexadecimal ingresado.
Se calculan los componentes de color RGB a partir del valor hexadecimal almacenado en colorValue. El valor hexadecimal se desplaza y se máscara para extraer los componentes de rojo, verde y azul, y luego se divide por 255.0 para obtener valores de componente en el rango de 0 a 1.

```C++
else {
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
}
```
Finalmente, se llama a una función setRGBColor con los valores de componente de color calculados (rojo, verde y azul) para configurar el color RGB deseado.








