/*NOMBRE: RICARDO PAREDES SANCHEZ
FECHA: 26/FEBRERO/2025
PROGRAMA: actividad-de-programacion9-matrices
CENTRO UNIVERSITARIO DE LOS ALTOS/UNIVERSIDAD DE GUADALAJARA
INGENIERIA EN COMPUTACION /2DO SEMESTRE
PROFESOR:SERGIO FRANCO CASILLAS
DESCRIPCION: el usuario creara una matriz de minimo 2X2 y maximo 10X10, la matriz se llenará con datos y luego se hara una operacion que decida el usuario entre suma, resta y multiplicacion*/
#include <stdio.h>
#include <stdlib.h>
int main() // Inicio de main
{   
    bool menu = true; //sera usado para ciclar el programa y salir de el cuando sea necesario
    int tamanoi, tamanoj; // Tamaño de i y j
    do
    { // Limitar las matrices
    printf("\n**Bienvenid@, este programa te permitira asignarle valores ya sean propios o aleatorios a dos matrices y luego sumarlas restarlas o multiplicarlas**\n");
    printf("¿De que tamaño quieres que sean las matrices? (minimo 2, maximo 10)\n");
    printf("columnas: ");
    scanf("%d", &tamanoi);
    printf("filas: ");
    scanf("%d", &tamanoj);
    if (tamanoi < 2 or tamanoi > 10 or tamanoj < 2 or tamanoj > 10) // si no se cumple que lo minimo sea 2X2 o lo maximo 10X10
    {
        printf("\n--Tamaño invaliido, intente de nuevo--\n");
    }
    } while (tamanoi < 2 or tamanoi > 10 or tamanoj < 2 or tamanoj > 10); //si se cumplen las condiciones
    int matriz1[tamanoi][tamanoj], matriz2[tamanoi][tamanoj], matriz3[tamanoi][tamanoj]; // Inicializar matrices por si se quieren mostrar sin agregar nada
    for (int i = 0; i < tamanoi; i++) 
    //inicio de for
    {
        for (int j = 0; j < tamanoj; j++)
        //inicio for anidado
        {
            matriz1[i][j] = 0;
            matriz2[i][j] = 0;
        }
        //fin for anidado
    }
    //fin de for
    char opcion;
    while (menu) //el ciclo continua mientras el boleano menu sea igual a true 
    { //inicio while
        printf("\n*Matrices*\n");
        printf("1. Agregar valores\n2. Agregar valores aleatorios\n3. Operar\n4. Editar valores\n5. Vaciar matrices\n6. Mostrar matrices\n7. Salir\nPor favor, selecciona una opcion: ");
        scanf(" %c", &opcion);
        //inicio switch
        switch (opcion)
        {
            case '1': //  Agregar valores
            {
                char matriz;
                printf("\n*Agregar valores*\n");
                printf("En que matriz quiere agregar valores?: ");
                scanf(" %c", &matriz);
                //inicio switch dentro del primer switch
                switch (matriz)
                {
                    case '1': // Matriz 1
                    {
                        for (int i = 0; i < tamanoi; i++)
                        {
                            for (int j = 0; j < tamanoj; j++)
                            {
                                printf("Valor de la matriz %c en el espacio de memoria %d, %d: ", matriz, i, j);
                                scanf("%d", &matriz1[i][j]);
                            }
                        }
                        break;
                    }
                    case '2': // Matriz 2
                    {
                        for (int i = 0; i < tamanoi; i++)
                        {
                            for (int j = 0; j < tamanoj; j++)
                            {
                                printf("Valor de la matriz %c en el espacio de memoria %d, %d: ", matriz, i, j);
                                scanf("%d", &matriz2[i][j]);
                            }
                        }
                        break;
                    }
                    default:
                    //en caso que el usuario elija una opcion diferente de 1 o 2
                    {
                        printf("Matriz no valida\n");
                        break;
                    }
                } //fin de switch secundario  
                break;
            } //fin de caso 1
            case '2': // Agregar valores aleatorios
            //inicio caso 2
            {
                for (int i = 0; i < tamanoi; i++) 
                {
                    for (int j = 0; j < tamanoj; j++)
                    {
                        int numran = (rand() % 200) - 100; // rand() % 200 genera números de 0 a 200, restamos 100 para obtener el rango deseado
                        matriz1[i][j] = numran;
                       numran = 0;
                    }
                }
                for (int i = 0; i < tamanoi; i++) 
                {
                    for (int j = 0; j < tamanoj; j++)
                    {
                        int numran = (rand() % 200) - 100; // rand() % 200 genera números de 0 a 200, restamos 100 para obtener el rango deseado
                        matriz2[i][j] = numran;
                        numran = 0;
                    }
                }
                printf("\n--Se han rellenado las matrices con numeros aleatorios del -100 a 100--\n");
                break;
            } //fin de case 2
            case '3': // Operar
            {
                char operacion;
                printf("\n*Operar*\n");
                printf("¿Que operacion te gustaria realizar?\n");
                printf("1. suma\n2. resta\n3. multiplicacion\nQue oeracion decea realizar entre las matrices?: ");
                scanf(" %c", &operacion);
                switch (operacion)
                //inicio switch secundario
                {
                    case '1': // Suma
                    {                        
                        for (int i = 0; i < tamanoi; i++) 
                        {
                            for (int j = 0; j < tamanoj; j++)
                            {
                                matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
                            }
                        }
                        printf("\n--Se sumo la matriz 1 con la matriz 2--\n");
                        break;
                    }
                    case '2': // Resta
                    {                        
                        for (int i = 0; i < tamanoi; i++) 
                        {
                            for (int j = 0; j < tamanoj; j++)
                            {
                                matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
                            }
                        }
                        printf("\n--Se resto la matriz 1 con la matriz 2--\n");
                        break;
                    } 
                    case '3': // Multiplicacion
                    {
                        for (int i = 0; i < tamanoi; i++) // Cambiar de linea de la primera matriz
                        {
                            for (int j = 0; j < tamanoj; j++) // limite de la segunda matriz, que es la que multiplica cada termino
                            {
                                matriz3[i][j] = 0;
                                for (int k = 0; k < tamanoi; k++) // limite de la primera matriz, que es la que multiplica cada termino
                                {
                                    matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
                                }
                            }
                        }
                        printf("\n--Se multiplico la matriz 1 con la matriz 2--\n");                    
                        break;
                    }
                    default:
                    {
                        printf("\n--Operador no valido--\n");
                        break;
                    }
                } //fin de switch secundario
                printf("\nMatriz 3 (Resultado) = \n{\n");
                for (int i = 0; i < tamanoi; i++)
                {
                    for (int j = 0; j < tamanoj; j++)
                    {
                        printf("%d ", matriz3[i][j]);
                    }
                    printf("\n");
                }
                printf("}\n");
                break;
            }
            case '4': // Editar valores
            //inicio de case 4
            {
                char matriz;
                printf("\n*Editar valores*\n");
                printf("Que matriz quiere editar?: ");
                scanf(" %c", &matriz);
                switch (matriz)
                //inicio switch secundario
                {
                    case '1' :
                    {
                        int i, j;
                        printf("Numero de la columna de la matriz: ");
                        scanf("%d", &i);
                        i--;
                        printf("Numero del renglon de la matriz: ");
                        scanf("%d", &j);
                        j--;
                        if (i >= 0 and i < tamanoi and j >= 0 and j < tamanoj)
                        {
                            printf("Valor anterior: %d\n", matriz1[i][j]);
                            printf("Valor nuevo: ");
                            scanf("%d", &matriz1[i][j]);
                        }
                        else
                        {
                            printf("Espacio de memoria invalido\n");
                        }
                        break;
                    }
                    case '2' :
                    {
                        int i, j;
                        printf("Numero de la columna de la matriz: ");
                        scanf("%d", &i);
                        i--;
                        printf("Numero del reglon de la matriz: ");
                        scanf("%d", &j);
                        j--;
                        if (i >= 0 and i < tamanoi and j > 0 and j < tamanoj)
                        {
                            printf("Valor anterior: %d\n", matriz2[i][j]);
                            printf("Valor nuevo: ");
                            scanf("%d", &matriz2[i][j]);
                        }
                        else
                        {
                            printf("Espacio de memoria invalido\n");
                        }
                        break;
                    }
                    default:
                    {
                        printf("Matriz no valida\n");
                        break;
                    }
                }
                //fin de switch secundario
                break;
            } //fin case 4
            case '5': // Vaciar matrices
            //inicio case 5
            {   
                for (int i = 0; i < tamanoi; i++)
                {
                    for (int j = 0; j < tamanoj; j++)
                    {
                        matriz1[i][j] = 0;
                        matriz2[i][j] = 0;
                    }
                }
                printf("\n--Se han vaciado las matrices--\n");
                break;
            }
            //fin case 5
            case '6': // Mostrar matrices
            {   // Matriz 1
                printf("\nMatriz 1 = \n"); //\n
                for (int i = 0; i < tamanoi; i++)
                {
                    for (int j = 0; j < tamanoj; j++)
                    {
                        printf("%d ", matriz1[i][j]);
                    }
                    printf("\n");
                }
                printf("\n"); //\n
                // Matriz 2
                printf("Matriz 2 = \n \n");
                for (int i = 0; i < tamanoi; i++)
                {
                    for (int j = 0; j < tamanoj; j++)
                    {
                        printf("%d ", matriz2[i][j]);
                    }
                    printf("\n");
                }
                printf("\n"); 

                break;
            } //fin case 6
            case '7': // Salir
            //inicio case 7
            {
                menu = false;  //si el usuario elige salir, menu (que antes era true) se vuelve false y ya no cumple la condicion para seguir ciclandose
                printf("\n--Ha salido--\n");
                break;
            }
            //fin case 7
            default:  //si el usuario ingreso un valor que no es del 1 al 7
            //inicio default
            {
                printf("\n--Opcion no valida intente denuevo--\n");
                break;
            }
            //fin de default
            
        } //fin del switch inical que lo inicio todo
    } //fin del while
    return 0;  //retorna 0
} //fin del main