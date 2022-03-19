#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i;

    printf("Digite uma string: "); 
    fgets(str, 100, stdin);   //fgets recebe a string e armazenando na variavel 

    printf("A string invertida : "); 

  for(i=strlen(str); i>=0; i--) //strlen é uma função que retorna o tamanho da string digitada 
     {
       printf("%c" ,str[i]);
     } 
return 0;
}