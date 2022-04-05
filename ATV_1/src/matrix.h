#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MATTAM 20

typedef struct Item{
	int val;
    bool passou;
}Item;

typedef struct Matrix{
	Item vet[MATTAM][MATTAM];
    int iAtual;
    int jAtual;
}Matrix;

void preencherMatriz(Matrix *m);
void printaMatrix(Matrix *m);
void printCaminho(Matrix *m);
void andarMatriz(Matrix *m);
int checaParede(int iAtual, int jAtual);
void andaBaixo(Matrix *m);
void andaDireita(Matrix *m);
void andaEsquerda(Matrix *m);

#endif 