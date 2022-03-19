#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char *strings[5];

    for (int i = 0; i < 5; i++) {
        char str[69];
        char *tmp;

        printf("Digite a string numero %d:", (i + 1));
        fgets(str, 69, stdin);

        tmp = (char*) malloc(strlen(str) + 1);
        strcpy(tmp, str);

        strings[i] = tmp;
    }

    for (int i = 1; i <= 5; i++) {
        printf("string numero %d: %s", i, strings[i - 1]);
    }

    return 0;
}