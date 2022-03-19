#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *vetor=NULL;
    int num_elementos = 0;
    int num;

    do {
    printf ("\nEntre com o numero inteiro que deseja inserir no vetor: ");
    scanf("%d",&num);

    if(num) {
        num_elementos++;

        vetor = (int *)realloc(vetor,num_elementos * sizeof(int));

        if (!vetor) { 
            printf ("\n** ERRO! Memoria insuficiente **\n"); 
            exit(1); 
        }
        vetor[num_elementos-1]=num;
    }

    } while(num);
    printf("\nOs elementos do vetor sao:");

    for (num = 0; num < num_elementos; num++)
    printf("\nO elemento %d do vetor e %d", num+1, *(vetor+num));
    free(vetor);

    return 0;
}