/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 06/FEBRERO/2025
PROGRAMA: CARACTERES DE SALIDA
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION/2DO SEMESTRE
PROFESOR: sERGIO FRANCO CASILLAS
DESCRIPCION: UN PROGRAMA SENCILLO QUE IMPRIME VARIOS EJEMPLOS DE CADENAS DE CONTROL DE SALIDA*/
#include <stdio.h>

int main() {
    // Usamos el carácter de escape '\n' para crear saltos de línea
    printf("Hola, mundo!\n");  // Imprime "Hola, mundo!" y hace un salto de línea
    
    // Usamos el carácter de escape '\t' para insertar tabulaciones
    printf("\tAqui simulamos oprimir el tabulador.\n"); // Imprime con un espacio de tabulación al inicio (como si usaramos el tabulador)
    
    // Usamos '\b' para simular un retroceso de un carácter
    printf("Hola\b\bMundo!\n");  // Borra "la" de "Hola" y muestra "Mundo!"
    
    // Usamos '\\' para imprimir una barra invertida en pantalla
    printf("Este es un ejemplo de barra invertida: \\\n"); // Muestra "\"
    
    // Usamos '\"' para imprimir comillas dobles
    printf("El texto entre comillas dobles es: \"Hola Mundo\"\n"); // Muestra "Hola Mundo"
    
    // Usamos '\r' para retornar al inicio de la línea sin avanzar a la siguiente
    printf("Hola Mundo\rCambio de posición\n"); // "Hola Mundo" será reemplazado por "Cambio de posición"
    
    // Ejemplo con cadenas de control de tipos de salida
    
    // %d para enteros
    int edad = 18;
    printf("Mi edad es: %d años.\n", edad);  // Imprime el valor entero de edad

    // %f para números de punto flotante
    float temperatura = 33.8;
    printf("Un grado celsius es igual a : %.2f°F.\n", temperatura); // Imprime el valor de temperatura con 2 decimales

    // %s para cadenas de caracteres
    char nombre[] = "Ricardo";   //se usa una variable tipo character (char) y un array al que no le damos un limite de memoria a utilizar
    printf("Mi nombre es: %s.\n", nombre);  // Imprime la cadena de texto "Ricardo"
    
    // %c para caracteres individuales
    char inicial = 'R'; //la letra se pone con comillas simples al ser un solo caractér
    printf("Mi inicial es: %c.\n", inicial);  // Imprime el carácter 'R'
    
    // %x para mostrar el valor de un número en hexadecimal
    int numero = 255;
    printf("El número 255 en hexadecimal es: %x.\n", numero);  // Imprime "ff"
    
    // %o para mostrar el valor de un número en octal
    printf("El número 255 en octal es: %o.\n", numero);  // Imprime "377"

    return 0;
}
