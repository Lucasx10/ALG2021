#include <stdio.h>
#include <stdlib.h>

/* Autor: Lucas Prado   Matricula: 2020018187
Data: 05/03/2022
Codigo Pares e Ímpares
*/

int crescente(void const *a, void const *b )
{
    return (*(int*)a - *(int*)b );
}

int decrescente(void const *a, void const *b )
{
    return (*(int*)b - *(int*)a );
}

int main(){
    int N, i, num, par, impar;
    
    scanf("%d", &N);
    par = 0;
    impar = 0;
    int np[N];
    int ni[N];
    
    for(i = 0; i < N; i++){
        scanf("%d", &num);
        if(num % 2 == 0){
            np[par] = num;
            par++;
        }else{
            ni[impar] = num;
            impar++;
        }
    }
	
    qsort(np, par, sizeof(int), crescente);
    qsort(ni, impar, sizeof(int), decrescente);

    for(i = 0; i < par; i++){
        printf("%d\n",np[i]);
    }
    for(i = 0; i < impar; i++){
        printf("%d\n",ni[i]);
    }
    
    return 0;
}