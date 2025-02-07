/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 06/FEBRERO/2025
PROGRAMA: actividad-de-programacion4
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario escribe un numero y el programa hace la sucecion de Fibonacci hasta llegar a ese numero*/
#include <stdio.h>

// Función que calcula la sucesión de Fibonacci usando un ciclo while
void fibonacci_while(int max) {  //la variable recibe un valor de tipo entero, este valor representa el numero maximo al que puede llegar la sucesion
    int a = 0, b = 1, temp;  //se declaran 3 variables, b es igual a 1 porque se necesita sumar 0+1 para iniciar la sucesion
    printf("Sucesion de Fibonacci usando while: ");
    while (a <= max) {
        printf("%d ", a);
        temp = a;   //le damos el valor de "a" a una variable que lo unico que hace es sumar ese valor mas "b"
        a = b;
        b = temp + b;  //ahora "a" es igual al valor siguiente y b es igual al valor anterior mas el propio b
    }
    printf("\n"); //hacemos salto de linea para que se vea bonito
} //no se pone return ya que la variable es un void, no regresa datos, solo ayuda a hacer las operaciones mas sencillas

// Función que calcula la sucesión de Fibonacci usando un ciclo for
void fibonacci_for(int max) {
    int a = 0, b = 1, temp;
    printf("Sucesion de Fibonacci usando for: ");
    for ( ; a <= max; temp = a, a = b, b = temp + b) {
        printf("%d ", a);
    }
    printf("\n");
} //no se pone return ya que la variable es un void, no regresa datos, solo ayuda a hacer las operaciones mas sencillas

// Función que calcula la sucesión de Fibonacci usando un ciclo do while
void fibonacci_dowhile(int max) {
    int a = 0, b = 1, temp;
    printf("Sucesion de Fibonacci usando do while: ");
    do {  //se realiza este bloque y despues se checa si cumple la condicion
        printf("%d ", a);
        temp = a;
        a = b;
        b = temp + b;
    } while (a <= max);  //si "a" es menor al maximo al que puede llegar la sucesion, el codigo regresa al "do"
    printf("\n");
} //no se pone return ya que la variable es un void, no regresa datos, solo ayuda a hacer las operaciones mas sencillas

int main() {
    int max;  //la variable max mide el maxixmo al que puede llegar la sucesion
    char ciclo; //la variable ciclo es de un solo caracter y se usa para preguntar que ciclo se debe usar

    // Preguntar al usuario el ciclo que desea usar
    printf("Selecciona el ciclo para calcular la sucesion de Fibonacci (w para while, f para for, d para do while): ");
    scanf(" %c", &ciclo); //el usuario escribe una letra que se guarda en la variable ciclo

    // Preguntar al usuario el número máximo al que puede llegar la sucesión
    printf("Introduce el numero maximo al que puede llegar la sucesion de Fibonacci: ");
    scanf("%d", &max); //el usuario pone el limite, el cual es menor o igual a la variable "a"

    // Ejecutar la función correspondiente según el ciclo seleccionado
    switch (ciclo) {  //en lugar dde hacer 3 if se hace un switch para no complicar las cosas
        case 'w': //en caso de que el usuario escriba w se hace el siguinte bloque de codigo
            fibonacci_while(max); //se invoca a la variable para que haga los calculos declarados al inicio y se hace un break
            break;
        case 'f':
            fibonacci_for(max); //si el usuario escribe f se usa el for
            break;
        case 'd':
            fibonacci_dowhile(max); //si el usuario escribe d se hace el do while
            break;
        default: // si el usuario no elige d f ó w se imprime un mensaje diciendo que ese ciclo no es valido
            printf("Ciclo no valido. Usa 'w' para while, 'f' para for, o 'd' para do while.\n");
            break;
    }

    return 0; //fin del codigo
}


