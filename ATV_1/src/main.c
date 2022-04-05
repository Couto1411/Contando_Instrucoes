#include "matrix.h"

int main(){
	Matrix m;
	preencherMatriz(&m);
    printf("A Matriz preenchida e:\n");
    printaMatrix(&m);
    andarMatriz(&m);
    printf("O caminho percorrido foi:\n");
    printCaminho(&m);
	return 0;
}
