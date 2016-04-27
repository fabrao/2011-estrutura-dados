#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct elemento{
	char dado;
}Elemento;

typedef struct no{
	struct no *ant;
	Elemento e;
	int contador;
}Pilha;

void empilha(Pilha **topo, Elemento e){
    Pilha *P1;
    P1 = (Pilha*)malloc(sizeof(Pilha));
    P1->e=e;
    P1->ant = *topo;
    if(*topo == NULL)
        P1->contador = 1;
    else
        P1->contador = (*topo)->contador + 1;
    *topo = P1;
     printf ("\nO Elemento %c foi empilhado!\n\n", e.dado);
}

Elemento desempilha (Pilha **topo){
         if(*topo == NULL){
            printf ("Pilha vazia!\n");
         }else{
               Elemento e = (*topo)->e;
               struct no *aux = *topo;
               *topo = (*topo) -> ant;
               free(aux);
               printf ("\nO elemento %c foi desempilhado\n\n", e.dado);
               return e;
         }
}


int main(){
       Pilha *P;
       Elemento e;
       char c;
       printf("'+' acompanhado do elemento para empilhar\n");
       printf("'-' para desempilhar o ultimo elemento digitado\n");
       do{
            fflush(stdin);
            scanf("%c", &c);
            if(c=='+'){
                scanf("%c", &e.dado);
                empilha (&P, e);
            }else{
                  desempilha(&P);
            }
       }while (c=='+' || c=='-');
       getch();
       return 0;
}
