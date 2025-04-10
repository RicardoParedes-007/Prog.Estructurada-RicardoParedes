/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 10/ABRIL/2025
PROGRAMA: actividad-de-programacion12-palindromos
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: El usuario ingresa una palabra y el programa detecta si es palindromo, cuantas vocales y cuantas consonantes tiene*/

#include <iostream>
//incluimos la libreria vector para poder usar el .size
#include <vector>
using namespace std;

int numVocales = 0;
int numConsonantes = 0;

int main() {
    //crear una variable tipo string llamada palabra
    string palabra;
    cout << "**Bienvenido usuario, este programa te dira si una palabra que tu escojas es palindromo o no**" << endl;
    cout << "**Ingresa tu palabra:" << endl;
    cin >> palabra;

    // el numero de caracteres es igual al tamaño de la palabra
    int numCaracteres = palabra.size();
    
    for (int i = 0; i < numCaracteres; i++) {
        char letra = palabra[i];
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            numVocales++;
        }
        else {
            numConsonantes++;
        }
    }
    
    // Revisar si es un palindromo con un for
    bool palindromo = true;
    for (int i = 0; i < numCaracteres / 2; i++) {
        if (palabra[i] != palabra[numCaracteres - 1 - i]) {
            palindromo = false;
            break;
        }
    }

    // Imprimir mensajes

      if (palindromo) {
        cout << "La palabra es un palíndromo." << endl;
    } 
      else {
        cout << "La palabra no es un palíndromo." << endl;
    }

    cout << "**Letras que tiene la palabra: " << numCaracteres << endl;
    cout << "**Vocales que tiene la palabra: " << numVocales << endl;
    cout << "**Consonantes que tiene la palabra: " << numConsonantes << endl;

    return 0;
}
