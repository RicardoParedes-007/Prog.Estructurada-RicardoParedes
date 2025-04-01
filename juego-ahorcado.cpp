#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrarAhorcado(int intentos) {
    const vector<string> dibujo = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };
    cout << dibujo[intentos] << "\n";
}

bool letraYaJugadas(const vector<char>& letrasJugadas, char letra) {
    //se hace un booleano que usa un vector y la funcion find (incluida en la biblioteca vector) para encontrar letras que ya se usaron
    return find(letrasJugadas.begin(), letrasJugadas.end(), letra) != letrasJugadas.end();
}


//se hace una funcion void que imprime guiones en funcion de que tan larga sea la palabra (para eso se usa length)
void jugarAhorcado(const string& palabra) {
    vector<char> letrasJugadas;
    string palabraOculta(palabra.length(), '_');
    int intentos = 0;

    //inicio while
    while (intentos < 6 && palabraOculta != palabra) {
        cout << "\nPalabra: " << palabraOculta << "\n";
        mostrarAhorcado(intentos);
        cout << "Letras jugadas: ";
        //este for muestra las letras que ya se jugaron
        for (char letra : letrasJugadas) cout << letra << " ";
        cout << "\nIngresa una letra: ";
        
        char letra;
        cin >> letra;

        if (letraYaJugadas(letrasJugadas, letra)) {
            cout << "¡Ya jugaste esa letra! Intenta otra.\n";
            continue;
        }

        letrasJugadas.push_back(letra);

        if (palabra.find(letra) != string::npos) { //busca si la letra jugada esta en la palabra
            for (size_t i = 0; i < palabra.length(); i++) {
                if (palabra[i] == letra) palabraOculta[i] = letra; //si la letra esta en la palabra, la revela
            }
        } else {
            cout << "Letra incorrecta.\n";
            intentos++; //se pierde un intento
        }
    }
    //fin de while

    if (palabraOculta == palabra) {
        cout << "\n¡Felicidades! Adivinaste la palabra: " << palabra << "\n";
    } else {
        mostrarAhorcado(intentos); //llamamos a la funcion
        cout << "\n¡Perdiste! La palabra era: " << palabra << "\n";
    }
}

//inicio de main
int main() {
    //se crea un vector de strings con el banco de palabras
    vector<string> bancoPalabras = {
        "computadora", "programacion", "tecnologia", "inteligencia", "codigo",
        "desarrollo", "software", "hardware", "internet", "algoritmo",
        "ingenieria", "hipopotomonstrosesquipedaliofobia", "matematicas", "ciencia", "electricidad",
        "electronica", "memoria", "artificial", "videojuego", "paralelepipedo"
    };

    cout << "Bienvenido al juego del ahorcado.\n";
    cout << "Elige una opción: \n";
    cout << "1. Jugar contra otra persona\n";
    cout << "2. Jugar contra la computadora\n";
    
    int opcion;
    cin >> opcion;

    string palabra;

    switch (opcion) {
        case 1:{
            cout << "Jugador 1, ingresa la palabra para adivinar: ";
            cin >> palabra;
            cin.ignore();  // Limpiar el buffer de entrada porque si no, se va a ver la palabra
            cout << "\n\n\n\n\n\n\n\n\n";  //hacer muchos saltos de linea para que no se vea la palabra
            break;
        }
        case 2: {
            srand(time(nullptr));
            palabra = bancoPalabras[rand() % bancoPalabras.size()]; //esto lo que hace es ver el tamaño del vector y agarrar un dato al azar
            break;
        }
        default: {
            cout << "Opción inválida.\n";  //para cuando pongan una opcion que truene el programa
            return 1;  //esto hace que el programa se acabe pero marcando un error (creo)
        }
    }

    jugarAhorcado(palabra); //mandamos llamar la funcion de jugar usando la palabra elegida

    return 0;
}
//fin de main