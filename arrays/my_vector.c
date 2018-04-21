#include <stdlib.h>
#include <stdbool.h>
#include "my_vector.h"

#define STARTING_CAPACITY 16

vector* vector_create() {
    vector* new_vector = (vector*) malloc(sizeof(vector));
    int* data = (int*) malloc(sizeof(int) * STARTING_CAPACITY);
    new_vector->data = data;
    new_vector->size = 0;
    new_vector->capacity = STARTING_CAPACITY;
    return new_vector;
}

int index_in_bounds(vector* v, int i) {
    return i >= 0 && i < v->size;
}

int vector_size(vector* v) {
    return v->size;
}

int vector_capacity(vector* v) {
    return v->capacity;
}

int vector_is_empty(vector* v) {
    return v->size == 0;
}

int vector_at(vector* v, int i) {
    if (index_in_bounds(v, i)) {
        return v->data[i];
    } else {
        return 0; // NOTE: ???
    }
}