#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define TAM 1000
#define REP 100

int cont_busca;
int cont_cria;


int busca(int *array, int chave){
    for(int i=0; i<TAM; i++){
        if(chave == array[i]){
            cont_busca++;
            return 0;
        }else{
            cont_busca++;
        }
    }
}

main(){
    int vet[TAM];
    int vetor_cria[REP];
    int vetor_busca[REP];
    int var;
    int chave;
    int i, j;

    srand(time(NULL));

    for(j=0; j<REP; j++){
        for(i=0; i<TAM; i++){ //preenchendo vetor;
            var = rand()%TAM;
            cont_cria++;
            vet[i] = var;
        }
        chave = rand()%TAM; //gera chave randomico;
        busca(vet, chave); //busca;
        vetor_busca[j] = cont_busca;
        vetor_cria[j] = cont_cria;
        cont_busca = 0;
        cont_cria = 0;
    }

    printf("\nN de Op. de INSERCAO: \n");
    for(i=0; i<REP; i++){
        printf("%d\n", vetor_cria[i]);
    }

    printf("\nN de Op. de BUSCA: \n");
    for(i=0; i<REP; i++){
        printf("%d\n", vetor_busca[i]);
    }
}
