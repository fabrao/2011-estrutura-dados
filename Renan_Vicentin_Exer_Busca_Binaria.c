#include<conio.h>
#include<stdio.h>

void preenche_vet(int *vetor, int quant){
        int i=0;
        int soma= 13;
        for(i=0; i<quant; i++){

            vetor[i] = soma;
            soma += 37;
        }
}

void imprime_vet(int *vetor, int quant){
    int i=0;
    for(i=0; i<quant; i++){
        printf("P[%d]: %d \t", i,vetor[i]);
    }
}

int BuscaBinaria (int *vetor, int quant, int elemento){
     int inicial = 0;
     int final = quant-1;
     int meio;
     while (inicial <= final)
     {
          meio = inicial + (final-inicial)/2;
          if (elemento == vetor[meio])
               return meio;
          else if (elemento < vetor[meio])
               final = meio-1;
          else
               inicial = meio+1;
     }
     return -1;   // elemento não encontrado
}



main(){
    int *vet;
    int posicao=0;
    int quant=0;
    int elemento=0;

    printf("\nEntre com a quantia de valores: ");
    scanf("%d", &quant);

    vet = malloc(quant*sizeof(int));

    preenche_vet(vet, quant);
    imprime_vet(vet, quant);

    printf("\nQual numero deseja saber a posicao?:  ");
    scanf("%d", &elemento);

    posicao = BuscaBinaria(vet, quant, elemento);

    if(posicao != -1){
        printf("\n\nEsta na Posicao: %d", posicao);
    }else{
        printf("\nElemento nao encontrado!");
    }
    printf("\n\n");
}
