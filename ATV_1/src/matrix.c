#include "matrix.h"

void preencherMatriz(Matrix *matriz){
    // Teste do moodle
    //int disp[7][7] = {{6,18,7,8,9,3,1},{27,45,50,6,5,1,2},{21,32,44,35,0,9,22},{15,11,7,45,4,18,7},{4,9,19,10,6,89,11},{23,23,27,1,91,77,6},{33,28,34,18,19,96,1}};
    // for (int i = 0; i < MATTAM; i++)
    // {
    //     for (int j = 0; j < MATTAM; j++)
    //     { 
    //         matriz->vet[i][j].val=disp[i][j];
    //         matriz->vet[i][j].passou=false;
    //     }
    // }
    for (int i = 0; i < MATTAM; i++)
    {
        for (int j = 0; j < MATTAM; j++)
        { 
            matriz->vet[i][j].val=rand()%100;
            matriz->vet[i][j].passou=false;
        }
    }
    
    matriz->vet[0][0].passou=true;
    matriz->iAtual=0;
    matriz->jAtual=0;
}
//Printa matrix definida e o mapa do caminho, sendo 1 onde passou
void printaMatrix(Matrix *m){
    for (int i = 0; i < MATTAM; i++)
    {
        for (int j = 0; j < MATTAM; j++)
            printf("%d\t",m->vet[i][j].val);
        printf("\n");
    }
    printf("\n");
}
void printCaminho(Matrix *m){
    for (int i = 0; i < MATTAM; i++)
    {
        for (int j = 0; j < MATTAM; j++)
            printf("%d ",m->vet[i][j].passou);
        printf("\n");
    }
    printf("\n");
}
void andarMatriz(Matrix *m){
    int soma=0;
    int caso;
    int cont=0;
    while ((m->iAtual<(MATTAM-1))||(m->jAtual<(MATTAM-1)))
    {
        caso=checaParede(m->iAtual,m->jAtual);
        switch (caso)
        {
        case 1:
            if ((m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual+1].val)))
                andaBaixo(m);
            else{
                if (m->vet[m->iAtual][m->jAtual+1].passou==false)
                    andaDireita(m);
                else
                    andaBaixo(m);
            }
            break;
        case 3:
            andaBaixo(m);
            break;
        case 4:
            if ((m->vet[m->iAtual+1][m->jAtual].val>=(m->vet[m->iAtual][m->jAtual-1].val)))
                andaBaixo(m);
            else{
                if (m->vet[m->iAtual][m->jAtual-1].passou==false)
                    andaEsquerda(m);
                else
                    andaBaixo(m);
            }
            break;
        case 5:
            if ((m->vet[m->iAtual+1][m->jAtual].val>=(m->vet[m->iAtual][m->jAtual+1].val))&&(m->vet[m->iAtual+1][m->jAtual].val>=(m->vet[m->iAtual][m->jAtual-1].val)))
                andaBaixo(m);
            else if((m->vet[m->iAtual][m->jAtual+1].val>=(m->vet[m->iAtual+1][m->jAtual].val))&&(m->vet[m->iAtual][m->jAtual+1].val>=(m->vet[m->iAtual][m->jAtual-1].val))){
                if (m->vet[m->iAtual][m->jAtual+1].passou==false)
                    andaDireita(m);
                else{
                    if (m->vet[m->iAtual+1][m->jAtual].val>=m->vet[m->iAtual][m->jAtual-1].val)
                        andaBaixo(m);
                    else
                        andaEsquerda(m);
                }
            }
            else{
                if (m->vet[m->iAtual][m->jAtual-1].passou==false)
                    andaEsquerda(m);
                else{
                    if (m->vet[m->iAtual+1][m->jAtual].val>=m->vet[m->iAtual][m->jAtual+1].val)
                        andaBaixo(m);
                    else
                        andaDireita(m);
                }
            }
            break;
        case 7:
            andaDireita(m);
            break;
        case 9:
            break;
        default:
            break;
        }
        soma+= m->vet[m->iAtual][m->jAtual].val;
        cont++;
    }
    printf("Para chegar no final da matriz foram necessários %d passos\n",cont);
    printf("A soma dos lugares passados e: %d\n",soma+m->vet[0][0].val);
}
int checaParede(int iAtual, int jAtual){
    if((iAtual==0 && jAtual==0)||(iAtual==0 && (jAtual!=0 && jAtual!=MATTAM-1))||((iAtual!=0 && iAtual!=MATTAM-1)&& jAtual==0))
        return 1;
    else if(iAtual==0 && jAtual==MATTAM-1)
        return 3;
    else if((iAtual!=0 && iAtual!=MATTAM-1)&& jAtual==MATTAM-1)
        return 4;
    else if((iAtual!=0 && iAtual!=MATTAM-1)&& (jAtual!=0 && jAtual!=MATTAM-1))
        return 5;
    else if((iAtual==MATTAM-1 && jAtual==0)||(iAtual==MATTAM-1 && (jAtual!=0 && jAtual!=MATTAM-1)))
        return 7;
    else if(iAtual==MATTAM-1 && jAtual==MATTAM-1)
        return 9;
    else
        return 0;
}
void andaBaixo(Matrix *m){
    m->iAtual+=1;
    m->vet[m->iAtual][m->jAtual].passou=true;
}
void andaDireita(Matrix *m){
    m->jAtual+=1;
    m->vet[m->iAtual][m->jAtual].passou=true;
}
void andaEsquerda(Matrix *m){
    m->jAtual-=1;
    m->vet[m->iAtual][m->jAtual].passou=true;
}