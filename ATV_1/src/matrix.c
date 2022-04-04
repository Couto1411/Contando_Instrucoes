#include "matrix.h"

void preencherMatriz(Matrix *matriz){
    for (int i = 0; i < MATTAM; i++)
    {
        for (int j = 0; j < MATTAM; j++)
        { 
            matriz->vet[i][j].val=rand()%99;
            matriz->vet[i][j].passou=false;
        }
    }
    matriz->vet[0][0].passou=true;
    matriz->iAtual=0;
    matriz->jAtual=0;
}
void printaMatrix(Matrix *m){
    for (int i = 0; i < MATTAM; i++)
    {
        for (int j = 0; j < MATTAM; j++)
            printf("%d ",m->vet[i][j].val);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < MATTAM; i++)
    {
        for (int j = 0; j < MATTAM; j++)
            printf("%d ",m->vet[i][j].passou);
        printf("\n");
    }
    printf("\n");
}
void andarMatriz(Matrix *m){
    int caso;
    int cont=0;
    while ((m->iAtual<(MATTAM-1))||(m->jAtual<(MATTAM-1)))
    {
        caso=checaParede(m->iAtual,m->jAtual);
        switch (caso)
        {
        case 1:
            if ((m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual+1].val)))
            {
                m->iAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            else{
                m->jAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            break;
        case 2:
            if ((m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual+1].val)))
            {
                m->iAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            else{
                m->jAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            break;
        case 3:
            m->jAtual+=1;
            m->vet[m->iAtual][m->jAtual].passou=true;
            break;
        case 4:
            if ((m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual+1].val)))
            {
                m->iAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            else{
                m->jAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            break;
        case 5:
            if ((m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual+1].val))&&(m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual-1].val))&&(m->vet[m->iAtual+1][m->jAtual].passou==false))
            {
                m->iAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            else if((m->vet[m->iAtual][m->jAtual+1].val>(m->vet[m->iAtual+1][m->jAtual].val))&&(m->vet[m->iAtual][m->jAtual+1].val>(m->vet[m->iAtual][m->jAtual-1].val))&&(m->vet[m->iAtual][m->jAtual+1].passou==false)){
                m->jAtual+=1;
                m->vet[m->iAtual][m->jAtual].passou=true;
            }
            else{
                if (((m->vet[m->iAtual][m->jAtual-1].val)>(m->vet[m->iAtual][m->jAtual+1].val))&&((m->vet[m->iAtual][m->jAtual-1].val)>(m->vet[m->iAtual+1][m->jAtual].val))&&(m->vet[m->iAtual][m->jAtual-1].passou==false))
                {
                    m->jAtual-=1;
                    m->vet[m->iAtual][m->jAtual].passou=true;
                }
                else{
                    if ((m->vet[m->iAtual+1][m->jAtual].val>(m->vet[m->iAtual][m->jAtual+1].val)))
                    {
                        m->iAtual+=1;
                        m->vet[m->iAtual][m->jAtual].passou=true;
                    }
                    else{
                        m->jAtual+=1;
                        m->vet[m->iAtual][m->jAtual].passou=true;
                    }
                }
                
            }
            break;
        case 6:
            m->iAtual+=1;
            m->vet[m->iAtual][m->jAtual].passou=true;
            break;
        case 7:
            m->jAtual+=1;
            m->vet[m->iAtual][m->jAtual].passou=true;
            break;
        case 8:
            m->jAtual+=1;
            m->vet[m->iAtual][m->jAtual].passou=true;
            break;
        case 9:
            printf("Sucesso\n");
            break;
        default:
            break;
        }
        printaMatrix(m);
        printaPos(m);
        cont++;
    }
    printf("Para chegar no final da matriz foram necessários %d passos\n",cont);
}
int checaParede(int iAtual, int jAtual){
    if(iAtual==0 && jAtual==0){
        return 1;
    }
    else if(iAtual==0 && (jAtual!=0 && jAtual!=MATTAM-1)){
        return 2;
    }
    else if(iAtual==0 && jAtual==MATTAM-1){
        return 3;
    }
    else if((iAtual!=0 && iAtual!=MATTAM-1)&& jAtual==0){
        return 4;
    }
    else if((iAtual!=0 && iAtual!=MATTAM-1)&& (jAtual!=0 && jAtual!=MATTAM-1)){
        return 5;
    }
    else if((iAtual!=0 && iAtual!=MATTAM-1)&& jAtual==MATTAM-1){
        return 6;
    }
    else if(iAtual==MATTAM-1 && jAtual==0){
        return 7;
    }
    else if(iAtual==MATTAM-1 && (jAtual!=0 && jAtual!=MATTAM-1)){
        return 8;
    }
    else if(iAtual==MATTAM-1 && jAtual==MATTAM-1){
        return 9;
    }
    else{
        return 0;
    }
}
void printaPos(Matrix *m){
    printf("%d, %d, %d\n",m->iAtual,m->jAtual,m->vet[m->iAtual][m->jAtual].val);
}