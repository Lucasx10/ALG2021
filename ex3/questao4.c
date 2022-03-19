#include <stdio.h>
#include <stdlib.h>

int compara(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main() 
{   
    
    int vetor[10] = {12, 2, 3, 1, 40, 7, 8, 6, 22, 0};
    int *ptr = &vetor;
    
    printf("Vetor incial: \n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    qsort(ptr, 10, sizeof(int), compara); //ordenando 

    printf("\n\nVetor ponteiro ordenado: \n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }
        
    return 0;
}