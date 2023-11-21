#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <math.h>
/*Ecuaciones de Segundo Grado*/
float calculoDiscriminante(float p, float q, float r){
    float resultado;
    resultado = pow(q,2) - (4*p*r);
    return resultado;
}

float calculoResultado1(float p, float q, float r, float disc){
    float r1;
    r1 = (-q + sqrt(disc))/(2*p);
    return r1;
}

float calculoResultado2(float p, float q, float r, float disc){
    float r2;
    r2 = (-q - sqrt(disc))/(2*p);
    return r2;
}

void multiplicarMatrices(int m1[3][3], int m2[3][3], int r[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            r[i][j] = 0;
            for (int k = 0; k < 3; k++){
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}
/*Multiplicacion de Matrices*/
void imprimirMatriz(int m[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

#endif