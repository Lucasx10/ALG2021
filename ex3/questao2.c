#include <stdio.h>

int main() {

    int a = 1, b = 2, c = 3, d = 4;

    int *pa=&a, *pb=&b, *pc=&c, *pd=&d;

    printf("%d %d %d %d\n", a, b, c, d);
   
    scanf("%d", pa);
    scanf("%d", pb);
    scanf("%d", pc);
    scanf("%d", pd);

    //impressao dos valores
    
    printf("Novo valor de A: %d \n", a);
    printf("Novo valor de B: %d \n", b);
    printf("Novo valor de C: %d \n", c);
    printf("Novo valor de D: %d \n", d);

    return 0;
}