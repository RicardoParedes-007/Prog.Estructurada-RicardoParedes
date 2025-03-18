/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 18/MARZO/2025
PROGRAMA: actividad-de-programacion11
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario escribe un numero y el programa imprime una secuencia en base a varias condiciones*/
#include <iostream>
using namespace std;

void secuencia(int n, int &longitud) {
    //se crea la variable secuencia que hace las operaciones que se necesitan
    while (n != 1) {
        cout << n << endl; // Imprime el número actual de la secuencia
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        longitud++; // Incrementa la longitud de la secuencia
    }
    cout << "1" << endl;
    longitud++; // Cuenta el último "1" de la secuencia
}

int main() {
    int n1, n2, longitud1 = 0, longitud2 = 0;
    cout << "*Hola usuario, este programa hará dos secuencias numericas basada en el numero que le des y comparara su tamaño" << endl;
    cout << "Ingresa un numero: ";
    cin >> n1;

    cout << "La secuencia generada por el número que diste es:" << endl;
    secuencia(n1, longitud1);

    cout << "Ingresa otro número: ";
    cin >> n2;

    cout << "La secuencia generada por el numero que diste es:" << endl;
    secuencia(n2, longitud2);

    cout << "La longitud de la primera secuencia fue: " << longitud1 << endl;
    cout << "La longitud de la segunda secuencia fue: " << longitud2 << endl;

    if (longitud1 > longitud2) {
        cout << "La primera secuencia es mayor." << endl;
    } else if (longitud1 < longitud2) {
        cout << "La segunda secuencia es mayor." << endl;
    } else {
        cout << "Ambas secuencias tienen la misma longitud." << endl;
    }
    cout << "gracias por usar el programa :)" ;

    return 0;
}
