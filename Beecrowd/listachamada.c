#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Autor: Lucas Prado   Matricula: 2020018187
Data: 05/03/2022
Codigo lista chamada
*/

char V[100][100] ;

int main()
{   
    int i, j, N, r, K;
    char aux[100];

    scanf("%d %d", &N, &K) ;

    for(i = 0; i <= N ; i++){
        gets(V[i]);
    }

    for (i = 0; i <= N; i++){
        for (j = i+1; j <= N; j++){
            r = strcmp(V[i],V[j]);
            if(r > 0){
                strcpy(aux, V[i]);
                strcpy(V[i], V[j]);
                strcpy(V[j], aux);
            }
        }
    }
        puts(V[K]);

  return 0 ;
}