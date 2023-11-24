#include <stdio.h>
#include <math.h>
#include "calculadora.h"

int main(void){

    int opcion;
    
    do{
        printf("\n______________CALCULADORA______________\n");
        printf("Seleccione la operacion que desea realizar\n");
        printf("1. Ecuaciones de segundo grado\n");
        printf("2. Multiplicacion de matrices\n");
        printf("3. Componentes de vectores\n");
        printf("4. Calcular determinante de matrices 2x2 y 3x3\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            float a, b, c, discriminante, resultado1, resultado2;

            printf("____Bienvenido a la calculadora de ecuaciones de segundo grado____\n");
            printf("Escriba los valores de la ecuacion de la forma ax^2 + bx + c\n");
            printf("Nota: Escriba los decimales con punto.\n");

            do{
                printf("\nValor de a: ");
                scanf("%f", &a);
                if(a==0){
                    printf("Para ser una ecuacion cuadratica, el valor de a debe ser diferente de 0.\n");
                    printf("Ingrese nuevamente.\n");
                }
            }while(a==0);

            printf("Valor de b: ");
            scanf("%f", &b);
            printf("Valor de c: ");
            scanf("%f", &c);

            discriminante = calculoDiscriminante(a,b,c);
            printf("\nEl discriminante es: %.2f\n", discriminante);

            if(discriminante < 0){
                printf("\nEl sistema no tiene solucion.\n");

            }else if(discriminante > 0){
                printf("\nEl sistema tiene 2 soluciones.\n");

                resultado1 = calculoResultado1(a,b,c,discriminante);
                resultado2 = calculoResultado2(a,b,c,discriminante);

                printf("\nPrimer resultado\t x1: %.2f\n", resultado1);
                printf("Segundo resultado\t x2: %.2f\n", resultado2);
            }else{
                printf("\nEl sistema tiene una unica solucion\n");

                resultado1 = calculoResultado1(a,b,c,discriminante);
                resultado2 = calculoResultado2(a,b,c,discriminante);

                printf("\nPrimer resultado\t x1: %.2f\n", resultado1);
                printf("Segundo resultado\t x2: %.2f\n", resultado2);
            }
            break;
        case 2:

            float matriz1 [3][3];
            float matriz2 [3][3];
            float resultado [3][3];
            printf("______Multiplicacion de Matrices 3x3______\n");
            printf("Ingrese los elementos de la matriz 1:\n");
            for (int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    printf("Elemento en la posicion [%d][%d]: ", i+1, j+1);
                    scanf("%f", &matriz1[i][j]);
                }
            }  
            printf("Ingrese los elementos de la matriz 2:\n");
            for (int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++){
                    printf("Elemento en la posicion [%d][%d]: ", i+1, j+1);
                    scanf("%f", &matriz2[i][j]);
                }
            }  

            multiplicarMatrices(matriz1, matriz2, resultado);

            printf("\nMatriz 1:\n");
            imprimirMatriz(matriz1);
  
            printf("\nMatriz 2:\n");
            imprimirMatriz(matriz2);
  
            printf("\nMatriz Resultante:\n");
            imprimirMatriz(resultado);
            
            break;
        case 3:
            float vector1[3];
            float vector2[3];
            float vector_diferencia[3];
            float norma1, norma2, distancia, angulo; 
            float producto_interno;
  
            printf("______Componentes de dos vectores______\n");
            printf("Escriba los elementos del Vector 1:\n");
            for(int i = 0; i < 3; i++){
                printf("Elemento en la posicion %d: ", i+1);
                scanf("%f", &vector1[i]);
            }

            printf("Escriba los elementos del Vector 2:\n");
            for(int i = 0; i < 3; i++){
                printf("Elemento en la posicion %d: ", i+1);
                scanf("%f", &vector2[i]);
            }

            norma1 = calcularNorma(vector1);
            norma2 = calcularNorma(vector2);
            distancia = calcularDistancia(vector1, vector2);
            producto_interno = calcularProductoInterno(vector1, vector2);
            angulo = calcularAngulo(producto_interno, norma1, norma2);
  
            printf("La norma del vector 1 es: %.2f\n", norma1);
            printf("La norma del vector 2 es: %.2f\n", norma2);
            printf( "La distancia entre los vectores es: %.2f\n", distancia);
            printf("El producto interno entre los vectores es: %.2f\n", producto_interno);
            printf( "El angulo entre los vectores es: %.2f\n", angulo);
            
            break;
        case 4:
            float matriz33[3][3];
            float matriz22[2][2];
            int op_matriz;
            float determinante;
            do{
                printf("\n______Calculadora de Determinantes______\n");
                printf("Seleccione el tamanio de la matriz: \n");
                printf("1. Matriz 2x2\n");
                printf("2. Matriz 3x3\n");
                printf("3. Salir\n");
                printf("Opcion: ");
                scanf("%d", &op_matriz);
                switch(op_matriz){
                case 1:
                    printf("Ingrese los valores de la matriz 2x2:\n");
                    for(int i = 0; i < 2; i++){
                        for(int j = 0; j < 2; j++){
                            printf("Elemento en la posicion: %d, %d: ", i + 1, j + 1);
                            scanf("%f", &matriz22[i][j]);
                        }
                    }
                    determinante = calcularDeterminante2x2(matriz22);
                    printf("\nDeterminante: %.2f\n", determinante);
                    break;
                case 2:
                    printf("Ingrese los valores de la matriz 3x3:\n");
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            printf("Elemento en la posicion: %d, %d: ", i + 1, j + 1);
                            scanf("%f", &matriz33[i][j]);
                        }
                    }
                    determinante = calcularDeterminante3x3(matriz33);
                    printf("\nMatriz 3x3:\n");
                    imprimirMatriz(matriz33);
                    printf("\nDeterminante: %.2f\n", determinante);
                    break;
                case 3:
                    break;
                default:
                    printf("Opcion invalida.\n");
                    break;      
                }
            }while(op_matriz != 3);
            break;
        case 5:
            printf("Gracias por usar.\n");
            break;
        default:
            printf("Opcion incorrecta. Ingrese nuevamente\n");
            break;
        }
        
    }while(opcion!=5);
    return 0;
}