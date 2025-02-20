/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 19/FEBRERO/2025
PROGRAMA: actividad-de-programacion7-n-de-primos
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario da un valor numerico, el programa busca todos los numeros primos entre el 1 y el numero que puso el usuario y luego los suma*/
#include <iostream>
using namespace std;

//Desarrollo de la variable "primo"
bool primo(int numero) {  //primo es un boleano y los datos que se ingresan en primo, es la variable entera numero
    if (numero <= 1) return false;     //si el numero es negativo, 0 o 1, el boleano regresa "falso"
    for (int i = 2; i <= numero / 2; i++) {  //el bucle continuara mientras que i sea menor o igual a la mitad del numero
        if (numero% i == 0) return false;  // si el numero que da el usuario es divisible entre i, regresa "falso"
    }
    return true;   //si las condiciones del for se cumplen, primo es igual a "verdadero"
}
//inicio de main
int main() {
//se declaran las variables enteras n y suma y se inician en 0
int n, suma = 0;
    //imprimimos los sigueintes mensajes al usuario
    cout << "**Bienvenido usuario, este programa te dira los numeros primos entre el 1 y el numero que quieras**" << endl;
    cout << "**Por favor introduce un número** ";  
    //el valor que ponga el usuario se guarda en la variable n   
    cin >> n;

    for (int i = 2; i <= n; i++) {  //se declara el bucle y decimos que i no puede ser mayor a n
        if (primo(i)) {   //aqui se llama a la funcion, la cual , recibe los datos que tiene i
            suma += i;    //a la variable suma se le aumenta el valor de i
            cout << i << "  ";  //imprimimos el valor de i, solo si es primo
        }
    }

    cout <<endl << "La suma de los números primos hasta " << n << " es: " << suma << endl;
    cout << "~~~Gracias por usar mi programa, que tengas un lindo dia~~~" << endl;
    return 0;
}
