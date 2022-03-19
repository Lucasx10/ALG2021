#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _static_queue {
    int *data;
    long size;
    long capacity;
    long begin;
    long end;
} QueueStatic;

QueueStatic *create(long capacity) {
    QueueStatic *Q = (QueueStatic *)malloc(sizeof(QueueStatic));
    Q->capacity = capacity;
    Q->data = (int *)malloc(capacity * sizeof(int));
    Q->begin = 0;
    Q->end = 0;
    Q->size = 0;
    return Q;
}

void destroy(QueueStatic **Q_ref) {
    QueueStatic *Q = *Q_ref;
    free(Q->data);
    free(Q);
    *Q_ref = NULL;
}

bool isEmpty(QueueStatic *Q) {
    return Q->size == 0;    
}

bool isFull(QueueStatic *Q) {
    return Q->size == Q->capacity;
}

long size(QueueStatic *Q) {
    return Q->size;
}

void enqueue(QueueStatic *Q, int val) {
    if (isFull(Q)) {
        printf("Queu is full!!\n");
        exit(EXIT_FAILURE);
    }    
    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
}

int peek(QueueStatic *Q){
    if(isEmpty(Q)) {
        printf("Queu is empty!!\n");
        exit(EXIT_FAILURE);
    }
    return Q->data[Q->begin];
}

int denqueue(QueueStatic *Q) {
    if(isEmpty(Q)) {
        printf("Queu is empty!!\n");
        exit(EXIT_FAILURE);
    }
    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;
    return val;
}

void printQueue(QueueStatic *Q) {
    printf("capacity: %ld\n", Q->capacity);
    printf("size: %ld\n", Q->size);
    printf("begin: %ld\n", Q->begin);
    printf("end: %ld\n", Q->end);

    long s, i;
    for(s = 0, i = Q->begin; s < Q->size; s++, i = (i + 1) % Q->capacity) {
        printf("%d, ", Q->data[i]);
    }
    puts("");
}

int main () {
    QueueStatic *Q = create(5);
    int val;

    puts("Enqueue: 10, 20, 30\n");
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    printQueue(Q);

    puts("\n Peek");
    val = peek(Q);
    printf("val = %d\n", val);
    printQueue(Q);

    puts("\n Dequeue");
    val = denqueue(Q);
    printf("val = %d\n", val);
    printQueue(Q);

    puts("\nEnqueue: 40, 50");
    enqueue(Q, 40);
    enqueue(Q, 50);
    printQueue(Q);

    puts("\nDequeue");
    val = denqueue(Q);
    printf("val = %d\n", val);
    printQueue(Q);

    puts("\nEnqueue: 100, 200");
    enqueue(Q, 100);
    enqueue(Q, 200);
    printQueue(Q);

    puts("\nEnqueue: 99");
    enqueue(Q, 99);

    return 0;
}