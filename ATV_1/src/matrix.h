#ifndef MATRIX_H
#define MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MATTAM 10

typedef struct Item{
	int val;
    bool passou;
}Item;

typedef struct Matrix{
	Item vet[MATTAM][MATTAM];
    int iAtual;
    int jAtual;
}Matrix;

typedef struct Caminho{
	int vet[MATTAM*MATTAM];
}Caminho;

int contador;

void preencherMatriz(Matrix *m,Caminho *c);
void printaMatrix(Matrix *m);
void printCaminho(Matrix *m);
void andarMatriz(Matrix *m,Caminho *c);
int checaParede(int iAtual, int jAtual);
void andaBaixo(Matrix *m);
void andaDireita(Matrix *m);
void andaEsquerda(Matrix *m);
void printaCaminho(Caminho *c,int choice);

#endif 