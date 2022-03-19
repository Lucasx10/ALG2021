#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _queue_node{
    int val;
    struct _queue_node *next;
    struct _queue_node *prev;
} Queue_Node, Node;

typedef struct _queue {
    Queue_Node *begin;
    Queue_Node *end;
    size_t size; 
} Queue;

Node *create_node(int val) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Queue *create() {
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->begin = NULL;
    Q->end = NULL;
    Q->size = 0;
    return Q;
}
void destroy(Queue **Q_ref) {
    Queue *Q = *Q_ref;
    Node *p = Q->begin;
    Node *aux = NULL;
    free(Q);
    *Q_ref = NULL;
}

bool isEmpty(Queue *Q) {
    return Q->size == 0;
}

void enqueue(Queue *Q, int val){
    Node *p = create_node(val);
    if(isEmpty(Q)) {
        Q->begin = p;
        Q->end = p;
    } else { 
        Q->end->next = p;
        p->prev = Q->end;
        Q->end = p;
    }
    Q->size++;
}
int peek(Queue *Q){
    if (isEmpty(Q)) {
        fprintf(stderr, "A fila esta vazia\n");
        exit(EXIT_FAILURE);
    }
    return Q->begin->val;
}

int dequeue(Queue *Q) {
    if (isEmpty(Q)) {
        fprintf(stderr, "A fila esta vazia\n");
        exit(EXIT_FAILURE);
    }
    int val = Q->begin->val;
    Node *p = Q->begin;
    if(Q->size == 1) {
        Q->begin = NULL;
        Q->end = NULL;
    }
    else {
        Q->begin = Q->begin->next;
        Q->begin->prev = NULL;
    }

    free(p);
    Q->size--;
    return val;
}

void Queue_print(Queue *Q) {
    Node* p = Q->begin;
    printf("Q-> ");
    while(p != NULL) {
        printf("%d-> ", p->val);
        p = p->next;
    }
    printf("NULL\n");

    Q->end == NULL ? printf("Q->end = NULL\n") : printf("Q->end = %d\n", Q->end->val);
                   
    printf("Size = %lu\n", Q->size);
}

int main () {
    Queue *Q = create();
    int val;

    Queue_print(Q);

    /* puts("\npeek");          //verificando if peek
    val = peek(Q);
    printf("val = %d\n", val);
    Queue_print(Q); */

    puts("\nenqueue: 10, 20, 30");
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    Queue_print(Q);

    puts("\npeek");
    val = peek(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nDequeue");
    val = dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nEnqueue: 40, 50");
    enqueue(Q, 40);
    enqueue(Q, 50);
    Queue_print(Q);

    puts("\ndequeue");
    val = dequeue(Q);
    printf("val = %d\n", val);
    Queue_print(Q);

    puts("\nenqueue: 100, 200");
    enqueue(Q, 100);
    enqueue(Q, 200);
    Queue_print(Q);

    destroy(&Q);

    return 0;
}