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
        printf("3. Norma, distancia y angulo entre vectores\n");
        printf("4. Angulos y lados de un triangulo\n");
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

            int matriz1 [3][3];
            int matriz2 [3][3];
            int resultado [3][3];
            printf("______Multiplicacion de Matrices 3x3______\n");
            printf("Ingrese los elementos de la matriz 1:\n");
            for (int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    printf("Elemento en la posicion [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz1[i][j]);
                }
            }  
            printf("Ingrese los elementos de la matriz 2:\n");
            for (int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++){
                    printf("Elemento en la posicion [%d][%d]: ", i+1, j+1);
                    scanf("%d", &matriz2[i][j]);
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
            break;
        case 4:
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