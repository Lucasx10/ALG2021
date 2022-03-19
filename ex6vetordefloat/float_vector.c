#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

FloatVector* create(int capacity){
    FloatVector *vec = (FloatVector*) malloc(sizeof(FloatVector));
    vec->capacity = capacity;
    vec->size = 0;
    vec->data = malloc (capacity * sizeof(float));
    return vec;
}

void destroy(FloatVector** vec_ref) {
    FloatVector* vec = *vec_ref;
    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

int size(FloatVector* vec) {
    return vec->size;
}

int capacity(FloatVector* vec){
    return vec->capacity;
}

float get(FloatVector* vec, int index) {
    if(index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR in get()\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size-1);
        exit(EXIT_FAILURE);
    }
    return vec->data[index];
}

void append(FloatVector* vec, float val){
    if (vec->size == vec->capacity) {
        fprintf(stderr, "ERROR in append()\n");
        fprintf(stderr, "Vector iss full\n");
        exit(EXIT_FAILURE);
    }
    vec ->data[vec->size] = val;
    vec ->size++;
}

void set(FloatVector* vec, int index, float val) {
    if (vec->size == vec->capacity) {
        fprintf(stderr, "ERROR in set()\n");
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }
    if(index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR in set()\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size-1);
        exit(EXIT_FAILURE);
    }
    append(vec, vec->data[index]);
    vec->data[index] = val;
}

void rrmov(FloatVector* vec, int index){
    if(index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR in remove()\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size-1);
        exit(EXIT_FAILURE);
    }
    int i;
    for(i=index; i < vec->size; i++) {
        vec->data[i] = vec->data[++index];
    }
    (vec->size)--;
}

void erase(FloatVector* vec){
    vec->data = (float*) malloc(vec->capacity * sizeof(float));
    vec->size = 0;
}


void print(FloatVector* vec){
    puts("------------------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
    puts("----------");
    int i;
    for(i=0; i < vec->size; i++){
        printf("[%d] = %.2f\n", i, vec->data[i]);
    }
    puts("\n------------------------------"); 
}

void clone(FloatVector* vec){
    FloatVector *vec2 = create(vec->capacity);
    int i;
    for(i=0; i < vec->size; i++) {
        vec2->data[vec2->size++] = vec->data[i];
    }
    print(vec2);
}
