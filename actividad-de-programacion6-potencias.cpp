/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 11/FEBRERO/2025
PROGRAMA: actividad-de-programacion6-potencias
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario da un valor numerico, el programa eleva todos los numeros hasta llegar al que dio el usuario al cuadrado y luego los suma*/
#include <iostream>
#include <cmath>  //se utiliza la biblioteca cmath para poder usar potencias
using namespace std;

int main() {  //inicio del main
    unsigned int numero = 0;   //se declara la variable como un entero sin signo ya que no debe de haber numeros menores a 0
    char seleccion = 0;
    unsigned int cuadrado = 0;
    cout << "Este programa suma numeros elevados al cuadrado" << endl;
    cout << "Te gustaria continuar (teclea s para si y n para no)" << endl;
    cin >> seleccion;
    switch (seleccion) {
        case 'n':  //si el usuario decide no continuar con el programa, salta el siguiente mensaje
            cout << "Gracias por tu tiempo :)" << endl;
            break;
        case 's': {//si el usuario decide si continuar con el programa
            cout << "Bienvenido, por favor ingresa el numero limite al que puede llegar el programa:" << endl;
            cin >> numero;
            if (numero < 0) {  //si el numero es negativo, salta un mensaje de error
                cout << "Error: numero negativo no permitido" << endl;
                return 1;
            }
            unsigned int i = 0;
            unsigned int suma = 0;
            for (i = 1; i <= numero; i++) { 
                cuadrado = pow(i, 2); // //el pow se usa para elevar numeros a una potencia, en este caso se eleva i a la potencia 2
                cout << "El cuadrado de " << i << " es " << cuadrado << endl;
                suma += cuadrado; 
            }
            cout << "La suma de todos los cuadrados hasta llegar al numero dado es " << suma << endl;
            break;} 
       default:
            cout << "El valor ingresado no es valido" << endl; //si el usuario ingresa algo diferente de s o n salta este mensaje
            break;
    }
    return 0;  //fin del main
}
