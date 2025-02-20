/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 20/FEBRERO/2025
PROGRAMA: actividad-de-programacion8-suma-de-arreglos
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: ponemos un arreglo de 10 numeros y en cada numero se le pregunta al usuario si desea continuar, si desea continuar, se añade otro numero al array y a la suma, si no desea continuar, se suman los numeros que ya hay en el array*/

#include <iostream>
using namespace std;

int main() {
    // Declarar variables
    float valores[10];   // Array de 10 valores máximos
    int contador = 0;    // Variable para contar cuántos números lleva el array
    char eleccion;       // Para que el usuario decida cuándo dejar de ingresar números

    cout << "**Hola usuario, este programa te permitirá añadir 10 números diferentes y sumarlos**" << endl;

    while (contador < 10) {  // Contador debe ser menor a 10 para evitar desbordar memoria
        cout << "¿Te gustaría continuar? (s/n): ";
        cin >> eleccion;

        switch (eleccion) {
            case 'n':
            case 'N': 
                cout << "Gracias por tu tiempo" << endl;
                contador = 10;  // Salir del bucle
                break;

            case 's': 
            case 'S': { cout << "Dame el valor para la posición " << contador + 1 << ": ";
                cin >> valores[contador];
                contador++;
                break;
                }
                //cout << "Dame el valor para la posición " << contador + 1 << ": ";
                //cin >> valores[contador];
                //contador++;
                //break;

            default:
                cout << "Opción no válida." << endl;
                break;
        }
    }

    // Mostrar lista de valores
    cout << "Lista de valores: ";
    for (int i = 0; i < contador; ++i) {
        cout << valores[++i] << " ";
    }
    cout << endl;

    // Calcular y mostrar la sumatoria de todos los elementos
    float suma = 0;
    for (int i = 0; i < contador; ++i) {
        suma += valores[i];
    }
    cout << "La sumatoria de todos los elementos es: " << suma << endl;

    return 0;
}
