#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TAMANHO 1000
#define REPETICAO 100

int comp_insere=0;
int comp_busca=0;

typedef struct node{
    int dado;
    struct node *dir, *esq;
}NODE;


void insert(NODE **apontno, int e){
    if(*apontno == NULL){
        comp_insere++;
        *apontno = (NODE *)malloc(sizeof(NODE));
        (*apontno)->dado = e;
        (*apontno)->esq=NULL;
        (*apontno)->dir=NULL;
    }else{
        comp_insere++;
        if(e >= (*apontno)->dado){
            comp_insere++;
            insert(&(*apontno)->dir,e);
        }
        else{
            comp_insere++;
            insert(&(*apontno)->esq,e);
        }
    }
}


 void buscar(NODE *Arvore,int Valor){
        if(Valor == Arvore->dado){
            comp_busca++;
        }else{
            comp_busca++;
            if(Valor < Arvore->dado && Arvore->esq){
                comp_busca+=2;
                 buscar(Arvore->esq, Valor);
            }
            if(Valor > Arvore->dado && Arvore->dir){
                comp_busca+=2;
                 buscar(Arvore->dir, Valor);
            }
        }
}


 int main(){
    int num;
    int vet_busca[REPETICAO];
    int vet_empilha[REPETICAO];

    srand(time(NULL));

    for(int j=0; j<REPETICAO; j++){
        NODE *arvore = NULL;
        for(int i=0; i<TAMANHO; i++){
            num=0;
            num=rand()%TAMANHO;
            insert(&arvore,num);
        }
        vet_empilha[j] = comp_insere;
        comp_insere=0;
        num=rand()%TAMANHO;
        buscar(arvore, num);
        vet_busca[j]= comp_busca;
        comp_busca=0;
    }

    printf("\nVETOR QTDE DE COMPARACOES PARA INSERCAO:");
    for(int y=0; y<REPETICAO; y++){
        printf("\n%d",vet_empilha[y]);
    }

    printf("\n\n\nVETOR QTDE DE COMPARACOES PARA BUSCA:");
    for(int y=0; y<REPETICAO; y++){
        printf("\n%d",vet_busca[y]);
    }
    printf("\n\n");
    //getch();
 }
