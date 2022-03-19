#include <stdio.h>
#define LINHAS 5
#define COLUNAS 2

    int main() {

        int i,j;
        int mat[LINHAS][COLUNAS] = { {10, 20},
                                     {30, 40},
                                     {50, 60},
                                     {70, 80},
                                     {90, 100} };
        
        for (int i = 0; i < LINHAS; i++) {       // linhas
            for (int j = 0; j < COLUNAS; j++) {       // colunas
                printf("%d ",*(*(mat + i) + j) );
            }
            printf("\n");
        }

        return 0;
    }