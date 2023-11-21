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
/*Multiplicacion de Matrices*/
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

void imprimirMatriz(int m[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
/*Componentes de Vectores*/
float calcularNorma(float vector[3]){
    float norma;
    norma = sqrt(pow(vector[0],2) + pow(vector[1],2) + pow(vector[2],2));
    return norma;
}

float calcularDistancia(float v1[3], float v2[3]){
    float vector_diferencia[3];
    float d;
        for(int i = 0; i < 3; i++){
        vector_diferencia[i] = v1[i] - v2[i];
    }
    d = sqrt(pow(vector_diferencia[0],2) + pow(vector_diferencia[1],2) + pow(vector_diferencia[2],2));
    return d;
}

float calcularProductoInterno(float v1[3], float v2[3]){
    float p_interno = 0;
    for(int i = 0; i < 3; i++){
        p_interno += v1[i] * v2[i];
    }
    return p_interno;
}
float calcularAngulo(float prod_int, float n1, float n2){
    float a = acos(prod_int / (n1 * n2)) * (180/3.1415);
    return a;
}

#endif