#include <stdio.h>
#include <stdlib.h>
#define tam 3

struct func {
    char nome[20];
    char sexo[1];
    int dia;
    char mes[8];
    int ano;
    int idade;
    char cpf[11];
    char cargo[30];
    float salario;
};

int main(){
    
    struct func p[tam];
    int i;

    for(i = 0; i < tam; i++){
        printf("\n Funcionario %d: \n ", i+1 );

        printf("Nome: ");
        gets(p[i].nome); 
        fflush(stdin);

        printf("Sexo(m/f): ");
        gets(p[i].sexo);
        fflush(stdin);

        printf("Dia do nascimento: ");
        scanf("%d", &p[i].dia);
        fflush(stdin);

        printf("mes do nascimento(por extenso): ");
        gets(p[i].mes);
        fflush(stdin);

        printf("Ano do nascimento: ");
        scanf("%i", &p[i].ano);
        fflush(stdin);

        printf("Idade: ");
        scanf("%d", &p[i].idade);
        fflush(stdin);

        printf("CPF(somente numeros): ");
        gets(p[i].cpf);
        fflush(stdin);

        printf("Cargo: ");
        gets(p[i].cargo); 
        fflush(stdin);

        printf("Salario: ");
        scanf("%f",p[i].salario);
    } 
        for(i = 0; i < tam; i++){
        printf("Funcionario %d ", i+1);
        printf("\n Nome :%s", p[i].nome);
        printf("\n Sexo :%s", p[i].sexo);
        printf("\n Data de nascimento:%d %s %d",p[i].dia, p[i].mes, p[i].ano);
        printf("\n Idade: %d ", p[i].idade);
        printf("\n Numero do seu CPF :%s", p[i].cpf);
        printf("\n Cargo :%s", p[i].cargo);
        printf("\n Salario %f ", p[i].salario);
    }
}