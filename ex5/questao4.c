#include <stdio.h>
#include <stdlib.h>

main(void) {

    char* vetor_strings;
    int i;

    do {

    vetor_strings= (char*) malloc (vetor_strings*sizeof(char));
        if (! vetor_strings){
            printf ("\nERRO!\n"); 
            exit (1);
        }

    for (i=0;i<vetor_strings;i++) {

        printf ("Entre com a string[%d]: ",i+1);
        scanf ("%s",vetor_strings);
    }

    }while(vetor_strings="exit");

    printf ("\nStrings contidas no vetor:\n");

    for (i=0;i<vetor_strings;i++)

    printf ("\nString[%d]: %s",i+1,vetor_strings);
}