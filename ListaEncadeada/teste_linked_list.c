#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int main () {

    LinkedList *L = LinkedList_create();
    LinkedList_add_first(L, 10);
    LinkedList_add_first(L, 2);
    LinkedList_add_first(L, 4);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);


    return 0;
}