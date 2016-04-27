#include<conio.h>
#include<stdio.h>


// 5! = 5x4x3x2x1 = 120;



//NÃO RECURSIVO;
float fat1(int x){
    float fat = 1;

    fot(int i=x; i>1; i++){
        fat = fat*i;
    }
    return fat;
}


//RECURSIVO;
float fat2(int x){
    if(x==2) return 2;
    return x*float2(x-1);
}
