#include "matrix.h"

int main(){
	Matrix m;
    Caminho c;
    int opcao;
	preencherMatriz(&m,&c);
    printf("A Matriz preenchida e:\n");
    printaMatrix(&m);
    andarMatriz(&m,&c);
    printf("O caminho percorrido foi:\n");
    printCaminho(&m);
    printf("Deseja imprimir o caminho na ordem correta ou na ordem reversa?: (0/1)\n");
    scanf("%d",&opcao);
    printaCaminho(&c,opcao);
	return 0;
}
