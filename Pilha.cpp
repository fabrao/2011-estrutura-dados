#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAMANHO 1000 //quantidade de elementos que a pilha aloca
#define REPETICAO 100

//VARIAVEIS GLOBAIS!
 // soma geral do numero de comparaçoes para empilhar
int comp_empilha = 0; //contador de comparaçoes na hora de empilhar
int comp_busca =0;


typedef struct pilha{
    int topo;
    int elementos[TAMANHO];
}Pilha;

void iniciaPilha(Pilha *P){
    P->topo = -1;
}

int pilhaCheia(Pilha *P){
    if(P->topo == TAMANHO-1){
        comp_empilha++;
        return 1;
    }else{
        comp_empilha++;
        return 0;
    }
}

void empilha(Pilha *P, int num){
    if(pilhaCheia(P)){
        comp_empilha++;
        printf("A pilha esta cheia!");
    }else{
        P->topo++;
        P->elementos[P->topo] = num;
        comp_empilha++;
    }
}


int busca(Pilha *P, int num){
    for (int i=0; i<TAMANHO; i++){//FOR para do topo até inicio da pilha
        if(num != P->elementos[i]){
            comp_busca++;//se numero randomico for diferente do elemento a ser comparado,
                            //apenas incrementa o numero de comparaçoes
            }else{
                comp_busca++;
                return comp_busca; //se não o numero é igual, e retorna o numero de comparações até o momento
                }
        }
        return TAMANHO; //caso o numero procurado não esteja na pilha, retorna o numero maximo de comparações.

}

int main(){
    int num;
    int vet_busca[100];
    int vet_empilha[100];

        srand(time(NULL));
        for(int j=0; j<REPETICAO; j++){ // FOR para repetir o procedimento 100 vezes
            Pilha pilha;
            iniciaPilha(&pilha);
            for(int i=0; i<TAMANHO; i++){ // FOR para preencher a pilha com 1000 numeros randomicos
                num=rand()%TAMANHO;
                empilha(&pilha, num);
            }
            vet_empilha[j]=comp_empilha;
            comp_empilha=0; //Zerar "comp_empilha" para recomeçar  o procedimento
            num=rand()%TAMANHO;
            vet_busca[j]= busca(&pilha, num);
            comp_busca = 0;
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
}
