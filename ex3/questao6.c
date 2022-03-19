#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
char tam_palavra,palavra[25],letra[25],lacuna[25]="_";
int chances=5,x,i,pontos=0;

printf("\n\nDigite a palavra secreta:\n\n");
gets(palavra);
system("cls");

for(i=0;i<strlen(palavra);i++)
lacuna[i]='-';
tam_palavra=strlen(palavra);

while(chances>0)
{
x=0;
printf("\n %s \n",lacuna);
printf("\n digite uma letra: ");
gets(letra);

for(i=0;i<strlen(palavra);i++)
{
if(letra[0]==palavra[i])
{
lacuna[i]=palavra[i];
pontos++;
x++;
}
}
if(x==0) {
chances=chances-1;

if(chances==0) {
printf("\n\n VOCE FOI ENFORCADO!");
printf("\n A PALAVRA ERA: %s",palavra);
break;
}

else
printf("\n VOCE ERROU! RESTAM %d CHANCES",chances); }

else{
if(pontos==tam_palavra) {
printf("\n\n VOCE GANHOU!");
printf("\n A PALAVRA E: %s",palavra);
break;}

else {
printf("\n VOCE ACERTOU UMA LETRA!");
}
}
} 
printf("\n\n");
system("pause");
return 0; }