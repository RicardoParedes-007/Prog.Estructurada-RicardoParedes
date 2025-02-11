/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 11/FEBRERO/2025
PROGRAMA: actividad-de-programacion5
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario escribe un numero, el programa busca todos los multiplos de 3 y de 5 que existen antes del numero dado y luego los suma*/
#include <stdio.h>
int main()
{
    int numero = 0;
    printf("Dame un número del 1 al 1000: \n");
    scanf("%d", &numero);

    if (numero < 1 || numero > 1000) {   //aqui el programa evalua el numero y si no cumple las condiciones imprime error en la pantalla
        printf("Número no válido. Debe ser entre 1 y 1000.\n");
        return 0;  //si el numero no es valido, el codigo se termina de ejecutar
    }

    printf("Múltiplos de 3:\n");
    for (int i = 1; i <= numero; i++) {
        if (i % 3 == 0) {  //el signo % significa "residuo" y lo que hace es dividir el numero entre 3 y checar cuantos valores enteros sobraron
            printf("%d ", i); //si no sobra nada en la division, la division entre 3 es exacta asi que el numero es multipllo de 3 y se imprime en pantalla
        }
    }

    printf("\nMúltiplos de 5:\n");
    for (int i = 1; i <= numero; i++) {
        if (i % 5 == 0) { //repetimos el residuo pero esta vez con el 5 para buscar multiplos de 5
            printf("%d ", i);
        }
    }

    int mult3 = 0; //creamos las variables multiplo de 3 (mult3) y multiplo de 5 (mult5)
    int mult5 = 0;

    for (int i = 1; i <= numero; i++) {
        if (i % 3 == 0) { //si i entre 3 es division exacta
            mult3 += i;  //mult3 se suma a la variable i
        }
        if (i % 5 == 0) { //si i entre 5 es division exacta
            mult5 += i;  //mult5 se suma a la variable i
        }
    }

    printf("\nSuma de múltiplos de 3: %d\n", mult3); //se imprime el valor final de mult3
    printf("Suma de múltiplos de 5: %d\n", mult5);  //se imprime el valor final de mult5

    return 0;
}
