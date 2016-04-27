#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define TAMANHO 1000
#define REPETICAO 100

int cont_busca=0;
int cont_insere=0;
int cont_ord=0;

typedef struct node{
        int dado ;
        struct node *prox;
}NODE;

//FUNCAO INICIALIZAR
NODE* inicializa(){
      return NULL;
}

//FUNCAÇO INSERIR
void insere(NODE *list, int valor){
    NODE *p = list;
	NODE *novo;
	NODE *anterior = NULL;
    novo = (NODE*)malloc(sizeof(NODE));
	anterior = (NODE*)malloc(sizeof(NODE));
    novo->dado = valor;
	novo->prox = NULL;
	/*procura posicao para insercao*/

    while(p!= NULL && p->dado > valor){
        cont_insere+=2;
        anterior = p;
		p = p->prox;
	}
    cont_insere+=2;
	/*insere elemeto*/
	cont_ord+=2;
	if(list->prox == NULL){
		list->prox = novo;
        novo->prox = NULL;
        }else{
            anterior->prox = novo;
            novo->prox = p;
	}
}

//FUNCAO BUSCA
void busca(NODE *list, int x){
    NODE *aux=list;
    int max=0;
    while(aux->prox->dado!= x){
       cont_busca++;
       aux=aux->prox;
       max++;
       cont_busca++;
       if(max == TAMANHO){
            break;
       }
    }
    cont_busca++; //PORQUE ENCONTROUO NUMERO
}
//FUNCAO IMPRIMI
void imprime (NODE* list){
   NODE *p;   /* variável auxiliar para percorrer a lista */
   for (p = list->prox; p != NULL; p = p->prox)
      printf("\ninfo = %d", p->dado);
}

main(){
    NODE *lista;
    lista = (NODE*)malloc(sizeof(NODE));
    srand(time(NULL));
    int vetor_busca[REPETICAO];
    int vetor_insere[REPETICAO];
    int vetor_ord[REPETICAO];
    int n_rand=0,i,j;
    int n_busca=0;
    //QUANTAS LISTAS
    for(i=0;i<REPETICAO;i++){
       //QUANDO ZERAMOS A LISTA
       lista->prox=inicializa();
           //ELEMENTOS DE 1 LISTA
           n_busca = rand()%TAMANHO;
           for(j=0;j<TAMANHO;j++){
               n_rand = rand()%TAMANHO;
               insere(lista,n_rand);
           }
    busca(lista,n_busca);
    vetor_busca[i]=cont_busca;
    cont_busca=0;
    vetor_insere[i]=cont_insere;
    cont_insere=0;
    vetor_ord[i]=cont_ord;
    cont_ord=0;
    }
    printf("\n\nVETOR COM O N de COMPARACOES PARA  BUSCA:");
    for(i=0; i<REPETICAO; i++){
        printf("\n%d", vetor_busca[i]);
    }
    printf("\nVETOR COM O N de COMPARACOES PARA INSERCAO:");
    for(i=0; i<REPETICAO; i++){
        printf("\n%d", vetor_insere[i]);
    }

    printf("\nVETOR COM O N de MOVIMENTACOES PARA INSERCAO:");
    for(i=0; i<REPETICAO; i++){
        printf("\n%d", vetor_ord[i]);
    }
}
