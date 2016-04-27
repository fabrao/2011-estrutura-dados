#include<conio.h>
#include<stdio.h>

typedef struct triangulo{
    int base;
    int altura;
    char nome[20];
}TRIANGULO;

typedef struct retangulo{
    int ladoA;
    int ladoB;
}RETANGULO;

typedef struct figuras{
    TRIANGULO Tri;
    RETANGULO Ret;
}FIGURAS;



//REMOÇÃO
while (p->prox->dado != 'S'){
    p=p->prox;
}
p->prox = aux->prox;
free(aux);



//ADICIONAÇÃO
while(p->prox->dado  <= 'E'){
    p= p->prox;
}
aux->prox = p->prox;
p->prox = aux;
