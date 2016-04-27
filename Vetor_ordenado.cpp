#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define TAM 1000
#define REP 100

int cont_cria;
int cont_busca;
int cont_ord;



void ord_cresc(int *p){
    int AUX;
    int trocou;
    int qtd=TAM;
    do{
        qtd--;
        trocou = 0;
        for(int i = 0; i < qtd; i++){
            if(p[i] > p[i+1]){
                cont_ord += 2;
                AUX=p[i+1];
                p[i+1]=p[i];
                p[i]=AUX;
                trocou=1;
            }
        }
   }while(trocou);
}


int busca( int *array, int chave){
    int inf = 0;
    int sup = TAM-1;
    int meio;
    while (inf <= sup){
        meio = inf + (sup-inf)/2;

        cont_busca++;
        if (chave == array[meio]) {
            return meio;
            }else if (chave < array[meio]){
                sup = meio-1;
                cont_busca++;
                }else{
                    cont_busca++;
                    inf = meio+1;
                }
     }
}


main(){
    int vet[TAM];
    int var;
    int chave;
    int i,j;
    int vetor_busca[REP];
    int vetor_cria[REP];
    int vetor_ord[REP];
    srand(time(NULL));

    for(j=0; j<REP; j++){
        for(i=0; i<TAM; i++){ //preenchendo vetor;
            var = rand()%TAM;
            cont_cria++;
            vet[i] = var;
        }
        ord_cresc(vet);
        chave = rand()%TAM; //gera chave randomico;
        busca(vet, chave); //busca;
        vetor_busca[j] = cont_busca;
        vetor_cria[j] = cont_cria;
        vetor_ord[j] = cont_ord;
        cont_busca = 0;
        cont_cria = 0;
        cont_ord = 0;

    }
    printf("N de Op. de INSERCAO:");
    for(i=0; i<REP; i++){
        printf("\n%d", vetor_cria[i]);
    }

    printf("\n\nN de Op. de ORDENACAO:");
    for(i=0; i<REP; i++){
        printf("\n%d", vetor_ord[i]);
    }
    printf("\n\nN de Op. de BUSCA:");
    for(i=0; i<REP; i++){
        printf("\n%d", vetor_busca[i]);
    }
}
