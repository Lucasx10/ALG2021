#include <stdio.h>
#include <stdlib.h>

    int pot(int x, int y) {
        if ( y == 0 )  
            return 1;
        return ( x * pot(x, y-1));
    }

    int main () {
        int x, y;
        
        printf("Digite o valor para X e Y: ");
        scanf("%d%d", &x, &y);

        printf("%d elevado a %d e igual a %d\n ",x, y, pot(x,y));

        return 0;
    }