#include <stdio.h>
#include <stdlib.h>

    int soma(int n){
        if(n < 3)
            return 0;
        else 
            return n + soma(n-1);
    }
    
    int main () {
        int n = 7;
        printf("%d\n ", soma(n));
        return 0;
    }