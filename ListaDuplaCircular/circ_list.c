#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ------------ DEFINIÇÃO DAS ESTRUTURAS ----------------
typedef struct _circ_node {
  int val;
  struct _circ_node *next;
  struct _circ_node *prev;
} CircNode;

typedef struct circ_list {
  CircNode *begin;
  CircNode *end;
  size_t size;
} CircList;

// ------------ CONSTRUTORES E DESTRUTORES DAS ESTRUTURAS -------------
CircNode *create_node(int val) {
    CircNode *cnode = (CircNode *) malloc(sizeof(CircNode));
    cnode->val = val;
    cnode->next = cnode;
    cnode->prev = cnode;
    return cnode;
}

CircList *create_list() {
    CircList *L = (CircList *) malloc(sizeof(CircList));
    L->begin = NULL;
    L->end = NULL;
    L->size = 0;
    return L;
}

void destroy_list(CircList **L_ref) {
    CircList *L = *L_ref;

    CircNode *p = L->begin;
    CircNode *aux = NULL;

    while (p != NULL){
        aux = p;
        p = p->next;
        free(aux);
    }
    free(p);
    free(L);
    *L_ref = NULL;
}

// ------------ FUNÇÔES -------------- 

bool CircList_is_empty(const CircList *L) {
    return L->size == 0;
}

void CircList_add_first(CircList *L, int val) {

    CircNode *p = create_node(val);

    // Caso 1: Lista vazia
    if(CircList_is_empty(L)) {
        L->begin = p;
        L->end = p;
    } else { // Caso 2: Lista não está vazia
        p->next = L->begin;
        L->begin->prev = p;
        L->begin = p;
        //parte circular
        p->prev = L->end;
        L->end->next = p;
    }
    L->size++;
}

void CircList_add_last(CircList *L, int val) {
    CircNode *p = create_node(val);

    if (CircList_is_empty(L)) {
        L->begin = p;
    }
    else {
        L->end->next = p;
        p->prev = L->end;
        L->begin->prev = p;
        p->next = L->begin;
    }

    L->end = p;
    L->size++;
}

void CircList_print(const CircList *L) {
    if (CircList_is_empty(L)) {
        printf("L -> NULL\n");
        printf("L->end -> NULL\n");
    }
    else {
        CircNode *p = L->begin;
        printf("L -> ");

        for (int i = 0; i < L->size; i++) {
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("\nL->end -> %d\n", L->end->val);
    }

    printf("Size: %lu\n\n", L->size);
}

void CircList_remove(CircList *L, int v) {
    if (!CircList_is_empty) {
        puts("List is empty/null!");
    } else {
        CircNode* p = L->begin;
        size_t original_size = L->size;
        for (size_t i = 0; i < original_size; i++) {
            if (p->val == v) {
                if (L->size == 1) {
                    L->begin = NULL;
                    L->end = NULL;
                    L->size--;
                    break;
                } else {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    if (p == L->begin) {
                        L->begin = p->next;
                    } else if (p == L->end) {
                        L->end = p->prev;
                    }
                    L->size--;
                }
            }
            p = p->next;
        }
    }
}

void CircList_removeDuplicate(CircList *L) {
    CircList* new_list = create_list();
        while(L->size > 0) {
            CircList_add_last(new_list, L->begin->val);
            CircList_remove(L, L->begin->val);
        }
        L->begin = new_list->begin;
        L->end = new_list->end;
        L->size = new_list->size;
}

int CircList_inverted(const CircList *L) {
    int result = 0;
    CircNode *p = L->end;
    for (size_t i = L->size; i > 0; i--) {
            result *= 10;
            result += p->val % 10;
            p = p->prev;
    } 
    return result;
}

CircList* SomaList(CircList*L1, CircList*L2) {
    CircList* result_soma = create_list();
    int soma = CircList_inverted(L1) + CircList_inverted(L2);
    while (soma > 1) {
        CircList_add_first(result_soma, soma % 10);
        soma /= 10;
    }
    return result_soma;
}

// ------------ Teste do codigo -----------

int main() {

    CircList *L = create_list();
    CircList *L1 = create_list();
    CircList *L2 = create_list();

    puts("Lista de entrada = ");
    CircList_add_last(L, 3);
    CircList_add_last(L, 4);
    CircList_add_last(L, 1);
    CircList_add_last(L, 3);
    CircList_add_last(L, 1);
    CircList_add_last(L, 5);
    CircList_add_last(L, 9);
    CircList_add_last(L, 4);
    CircList_add_last(L, 3);
    CircList_print(L);

    puts("Lista de saida = ");
    CircList_removeDuplicate(L);
    CircList_print(L);

    puts("Lista de entrada1 = ");
    CircList_add_last(L1, 3);
    CircList_add_last(L1, 1);
    CircList_add_last(L1, 5);
    CircList_print(L1);

    puts("Lista de entrada2 = ");
    CircList_add_last(L2, 5);
    CircList_add_last(L2, 9);
    CircList_add_last(L2, 2);
    CircList_print(L2);

    puts("Lista de saida = ");
    CircList* result_soma = SomaList(L1, L2);
    CircList_print(result_soma);

    return 0;
}