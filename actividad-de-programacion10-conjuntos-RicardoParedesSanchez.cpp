/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 04/MARZO/2025
PROGRAMA: actividad-de-programacion10
CENTRO UNIVERSITARIO DE LOS ALTOS / UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION / SEGUNDO SEMESTRE
PROFESOR: SERGIO FRANCO CASILLAS
DESCRIPCION: se crean dos vectores que seran conjuntos de la logica matematica y se le preguntara al usuario que operacion realizar de la interseccion, union, diferencia o complemento */
#include <iostream>
#include <vector>   //biblioteca necesaria para hacer vectores
#include <algorithm> //biblioteca que permite usar operadores logicos: union, interseccion , diferencia, complemento etc.
using namespace std;
//creamos dos vectores de datos enteros llamados conjuntoA y conjuntoB (no se declaro un limite para los vectores)
vector <int> conjuntoA;  
vector <int> conjuntoB;
bool menu = true;  //para repetir el proceso
char opcion;
int numero = 0;

int main()
//inicio de main
{
    cout << "bienvenid@ usuari@, este programa te permitira ponerle numeros a un par de conjuntos y hacer varias operaciones con ellos" << endl;
    while (menu) 
    //inicio de while menu
    {
    cout << "**¿Que quieres hacer?**" << endl;
    cout << "1-  agregar valores al conjunto A" << endl;
    cout << "2-  agregar valores al conjunto B" << endl;
    cout << "3-  mostrar valores de los conjuntos" << endl;
    cout << "4-  operar" << endl;
    cout << "5-  editar valores del conjunto A" << endl;
    cout << "6-  editar valores del conjunto B" << endl;
    cout << "7-  vaciar ambos conjuntos" << endl;
    cout << "8-  salir del programa" << endl;
    cin >> opcion;
    switch (opcion) 
    {
        case '1': 
        //inicio case 1
        {
         char op;
            cout << "¿quieres ingresar un valor? (1 para si y 0 para no) " << endl;
            cin >> op;
            switch(op) 
            //inicio switch op
            {
             case '1':
             {  
                cout << "ingresa un numero" << endl;
                cin >> numero;
                conjuntoA.push_back(numero);
                
             }
             case '0':
             {
                break;
             }
             default: 
             {
                cout << "OPCION NO VALIDA" <<endl;
             }
            }
            //fin switch op
        
        }
        //fin de case 1

        case '2': 
        //inicio case 2
        {
            char op;
            cout << "¿quieres ingresar un valor? (1 para si y 0 para no) " << endl;
            cin >> op;
            switch(op) 
            //inicio switch op
            {
             case '1':
             {  
                cout << "ingresa un numero" << endl;
                cin >> numero;
                conjuntoB.push_back(numero);
                
             }
             case '0':
             {
                break;
             }
             default: 
             {
                cout << "OPCION NO VALIDA" <<endl;
             }
            }
            //fin switch op
        }
        //fin de case 2
      
         case '3': 
         // Mostrar valores de los conjuntos
         {
             cout << "Valores en conjunto A: ";
             for (int i : conjuntoA) {
                 cout << i << " ";
             }
             cout << endl;
 
             cout << "Valores en conjunto B: ";
             for (int i : conjuntoB) {
                 cout << i << " ";
             }
             cout << endl;
             break;
         }
         case '4': 
         // Operar
         {
             char operacion;
             cout << "¿Qué operación deseas realizar?" << endl;
             cout << "1 - Unión" << endl;
             cout << "2 - Intersección" << endl;
             cout << "3 - Diferencia de A con B" << endl;
             cout << "4 - Diferencia de B con A" << endl;
             cin >> operacion;
 
             switch (operacion) {
                 case '1': 
                 // Unión
                 {   //se crea un nuevo vector al que le damos los mismos valores del conjunto A
                     vector<int> unionConjuntos = conjuntoA;
                     //se usa el .insert para añadir al conjunto union los elemntos del conjunto B
                     unionConjuntos.insert(unionConjuntos.end(), conjuntoB.begin(), conjuntoB.end());
                     //sort se usa para acomodar los elementos de mayor a menor
                     sort(unionConjuntos.begin(), unionConjuntos.end());
                     //erase y unique se usan para eliminar los elementos repetidos ya que no se necesitan
                     unionConjuntos.erase(unique(unionConjuntos.begin(), unionConjuntos.end()), unionConjuntos.end());
 
                     cout << "Unión de A y B: ";
                     for (int i : unionConjuntos) {
                         cout << i << " ";
                     }
                     cout << endl;
                     break;
                 }
                 case '2': 
                 // Intersección
                 {   //se crea un vector llamado interseccion
                     vector<int> interseccion;
                     //se acomodan los elementos de los conjuntos A y B de menor a mayor
                     sort(conjuntoA.begin(), conjuntoA.end());
                     sort(conjuntoB.begin(), conjuntoB.end());
                     //se usa la funcion set_intersection de la libreria algorithm para hacer la interseccion
                     set_intersection(conjuntoA.begin(), conjuntoA.end(), conjuntoB.begin(), conjuntoB.end(),
                     //el valor regresado se almacena en el vector interseccion
                                      back_inserter(interseccion));
 
                     cout << "Intersección de A y B: ";
                     for (int i : interseccion) {
                         cout << i << " ";
                     }
                     cout << endl;
                     break;
                 }
                 case '3': 
                 // Diferencia de A con B
                 {
                     vector<int> diferencia;
                     //se crea un nuevo vector llamado diferencia
                     sort(conjuntoA.begin(), conjuntoA.end());
                     sort(conjuntoB.begin(), conjuntoB.end());
                     //se usa set_difference de la libreria algorithm
                     set_difference(conjuntoA.begin(), conjuntoA.end(), conjuntoB.begin(), conjuntoB.end(),
                                    back_inserter(diferencia));
 
                     cout << "Diferencia de A con B: ";
                     for (int i : diferencia) {
                         cout << i << " ";
                     }
                     cout << endl;
                     break;
                 }
                 case '4': 
                 // Diferencia de B con A
                 {
                     vector<int> diferencia;
                     //lo mismo que el case anterior pero esta vez el set_difference comienza con el conjunto B
                     sort(conjuntoB.begin(), conjuntoB.end());
                     sort(conjuntoA.begin(), conjuntoA.end());
                     set_difference(conjuntoB.begin(), conjuntoB.end(), conjuntoA.begin(), conjuntoA.end(),
                                    back_inserter(diferencia));
 
                     cout << "Diferencia de B con A: ";
                     for (int i : diferencia) {
                         cout << i << " ";
                     }
                     cout << endl;
                     break;
                 }
                 default:
                     cout << "Operación no válida." << endl;
             }
             break;
         }
 
         case '5': 
         // Editar valores del conjunto A
         {
             int index, nuevoValor;
             cout << "¿Que posicion del conjunto A quieres editar?: ";
             cin >> index;
             //si la posicion es mayor a cero y menor al tamaño del conjunto A
             if (index >= 0 && index < conjuntoA.size()) {
                 cout << "Nuevo valor: ";
                 cin >> nuevoValor;
                 conjuntoA[index] = nuevoValor;
                 //la posicion adquiere el valor que pide el usuario
             } else {
                 cout << "Posicion no valida." << endl;
             }
             break;
         }
         case '6': 
         // Editar valores del conjunto B
         {
             int index, nuevoValor;
             cout << "Indice a editar en conjunto B: ";
             cin >> index;
             if (index >= 0 && index < conjuntoB.size()) {
                 cout << "Nuevo valor: ";
                 cin >> nuevoValor;
                 conjuntoB[index] = nuevoValor;
             } else {
                 cout << "Indice no valido." << endl;
             }
             break;
         }
         case '7': 
         // Vaciar ambos conjuntos
         {
             conjuntoA.clear();  //.clear se usa para eliminar todos los elementos del vector
             conjuntoB.clear();
             cout << "Ambos conjuntos han sido vaciados." << endl;
             break;
         }
         case '8': 
         // Salir del programa
         {
             menu = false;
             //menu se vuelve false y ya no cumple la condicion para seguir ciclandose
             cout << "Gracias por usar el programa. Adios!" << endl;
             break;
         }
         default: 
         {   //si el usuario ingresa una opcion que no se puede ejecutar
             cout << "OPCION NO VALIDA" << endl;
         }
 
            
        }
        //fin de switch opcion

    }
     //fin de while menu
     return 0;
    }
    //fin de main
    