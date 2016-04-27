#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int dado;
    struct node *dir, *esq;
}NODE;

void insert(NODE **apontno, int e){
    if(*apontno == NULL){
        *apontno = (NODE *)malloc(sizeof(NODE));
        (*apontno)->dado = e;
        (*apontno)->esq=NULL;
        (*apontno)->dir=NULL;
    }else{
        if(e > (*apontno)->dado){
            insert(&(*apontno)->dir,e);
        }
        else{
            insert(&(*apontno)->esq,e);
        }
    }
}


//IMPRIME EM ORDE CRESCENTE.
 void emordem(NODE *apontno){
    if(apontno != NULL){
        emordem(apontno->esq); //IMPRIME <8
        printf("%d\t",apontno->dado); //IMPRIME =8
        emordem(apontno->dir); //IMPRIME >8
    }
 }

//IMPRIME O PRIMEIRO NÓS, OS DA ESQUERDA, DEPOIS OS DA DIREITA.
 void preordem(NODE *apontno){
    if(apontno != NULL){
        printf("%d\t",apontno->dado); //IMPRIME =8
        preordem(apontno->esq);  //IMPRIME <8
        preordem(apontno->dir); //IMPRIME >8
    }
 }

//IMPRIME PRIMEIRO OS DA ESQUERDA, DEPOIS OS DA DIREIRA, POR ULTIMO O PRIMEIRO NÓ.
 void posordem(NODE *apontno){
    if(apontno != NULL){
        posordem(apontno->esq); //IMPRIME <8
        posordem(apontno->dir); //IMPRIME >8
        printf("%d\t",apontno->dado); //IMPRIME =8
    }
 }

//FUNÇAO PARA DELETAR NÓS
void remover(NODE **pRaiz, int numero){
    NODE *pAux = NULL;
    if(numero < (*pRaiz)->dado)
        remover(&(*pRaiz)->esq, numero);
    else if (numero > (*pRaiz)->dado)
        remover(&(*pRaiz)->dir, numero);
    else{
        pAux = *pRaiz;
        if((*pRaiz)->esq == NULL)
            *pRaiz = (*pRaiz)->dir;
        else if((*pRaiz)->dir == NULL)
            *pRaiz = (*pRaiz)->esq;
    }
}

 int main(){
    NODE *arvore = NULL;
    insert(&arvore,8);
    insert(&arvore,6);
    insert(&arvore,3);
    insert(&arvore,1);
    insert(&arvore,4);
    insert(&arvore,16);
    insert(&arvore,9);

    emordem(arvore);
    printf("\n");
    preordem(arvore);
    printf("\n");
    posordem(arvore);
    printf("\n");


    printf("\n\n\n");
    remover(&arvore, 16);

    emordem(arvore);
    printf("\n");
    preordem(arvore);
    printf("\n");
    posordem(arvore);
    printf("\n");
 }



