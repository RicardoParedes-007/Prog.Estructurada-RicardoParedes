/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 05/FEBRERO/2025
PROGRAMA: actividad-de-programacion3
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario escribe un numero, el programa lo analiza y hace las sumas correspondientes*/
#include <stdio.h>

int main() {
    int numerodado = 0;  // Se declara una variable tipo int en la que se guardará el número que escriba el usuario
    int contador = 0;    // Una variable que me ayudará a contar cuántas veces se suma el número

    printf("Dame un número menor a 1000 (cero para terminar el programa): "); // Pedimos un número al usuario
    scanf("%d", &numerodado);  // El scanf guarda el número en la variable numerodado
 if(numerodado==0)
 return 0; 
 if(numerodado >=1000) {
        printf("No se puede calcular el valor");
    }
    if (numerodado < 500) {
        do {
            numerodado = numerodado + 5;
            contador++;
            printf("%d ", numerodado);
        } while (contador < 100);
    } else if (numerodado > 500) {
        do {
            numerodado = numerodado + 10;
            contador++;
            printf("%d ", numerodado);
        } while (contador < 50);
    } 
    printf("\n el numero de veces que se realizó una suma fue \n: %d",contador);
    return 0;
    }

    

