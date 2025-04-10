/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 09/ABRIL/2025
PROGRAMA: actividad-juego2
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: Crear el juego "las torres de Hanoi" con minimo 1 y maximo 10 discos*/

#include <iostream>
#include <vector>
#include <array>

using namespace std;

// Función para mostrar que discos estan en que torres
//esta funcion tiene 3 vectores y un valor entero llamado intentos
void mostrarTorres(const vector<int>& torreA, const vector<int>& torreB, const vector<int>& torreC, int intentos) {
    cout << "\nAsi va quedando tu torre crack:\n";
    cout << "Torre A: ";
    for (int disco : torreA) cout << disco << " ";
    cout << "\nTorre B: ";
    for (int disco : torreB) cout << disco << " ";
    cout << "\nTorre C: ";
    for (int disco : torreC) cout << disco << " ";
    //aqui le decimos al usuario cuantos movimientos lleva
    cout << "\n Movimientos realizados: " << intentos << "\n";
}

// Función para mover un disco entre dos torres
//aqui hay 2 vectores, la torre donde esta el disco y la torre a la que va a llegar
bool moverDisco(vector<int>& origen, vector<int>& destino) {
    //en caso de que la torre de origen no tenga discos, imprime un mensaje
    if (origen.empty()) {
        cout << "La torre de origen está vacía, no puedes mover discos si no hay discos .__.\n";
        return false;
    }
    //si destino es diferente de vacio y el disco de hasta arriba es menor que el que se quiere poner:
    if (!destino.empty() && destino.back() < origen.back()) {
        cout << "No se puede colocar un disco grande sobre uno más pequeño .__.\n";
        return false;
    }
    //el valor que se va al vector de destino se va hasta arriba, este valor es el mismo que el que esta al final del vector origen
    destino.push_back(origen.back());
    //el pop_back elimina el ultimo valor del vector origen porque ese valor es el disco que movimos
    origen.pop_back();
    return true;
}

//inicio de main
int main() {
    array<int, 10> discos; // crear un array de 10 digitos para los discos
    int num_discos; //para guardar el numero de discos que quiere el usuario
    vector<int> torreA, torreB, torreC; // Vectores para las torres
    int intentos = 0;  //iniciamos los intentos en 0
    int opcion, origen, destino;

    cout << "Cuantos discos quieres que sean (máximo 10): ";
    cin >> num_discos;

    if (num_discos > 10) {
        cout << "ERROR: DIJE MAXIMO 10 NO TE QUIERAS PASAR DE LANZA." << endl;
        return 1;
    }

    // Inicializar la torre A con los discos
    //el bucle for lo que hace es que va ingresando al final del vector el valor de los discos, que dependen de cuantos eligio el usuario
    for (int i = num_discos; i > 0; --i) {
        torreA.push_back(i);
    }

    cout << "\n¡Bienvenido al juego de las Torres de Hanoi!\n";
    //llamado de la funcion mostrarTorres
    mostrarTorres(torreA, torreB, torreC, intentos);

    while (true) {
        cout << "\nElige una opción:\n";
        cout << "1. Mover disco\n";
        cout << "2. Rendirse\n";
        cout << "¿Que quieres hacer?: ";
        cin >> opcion;

        if (opcion == 2) {
            cout << "Has decidido rendirte. ¡Gracias por jugar!\n";
            break;
        } else if (opcion == 1) {
            cout << "Selecciona la torre de origen (1=A, 2=B, 3=C): ";
            cin >> origen;
            cout << "Selecciona la torre de destino (1 = A, 2 = B, 3 = C): ";
            cin >> destino;

            //hacemos un puntero que apunta a los vectores, osea las torres
            vector<int>* torres[] = {&torreA, &torreB, &torreC};

            if (origen < 1 || origen > 3 || destino < 1 || destino > 3) {
                cout << "Error. Solo hay 3 torres\n";
            } else if (moverDisco(*torres[origen - 1], *torres[destino - 1])) {
                intentos++;
                mostrarTorres(torreA, torreB, torreC, intentos);
                //verificar si la torre C o la torre B tiene todos los discos
                if (torreC.size() == num_discos || torreB.size() == num_discos) {
                    cout << "\n¡Felicidades! Has completado el juego en " << intentos << " intentos.\n";
                    cout << "Gracias por jugar, se te aprecia un monton :3" << endl;
                    break;
                }
            }
        } else {
            cout << "Opción inválida. Inténtalo de nuevo.\n";
        }
    }

    return 0;
}