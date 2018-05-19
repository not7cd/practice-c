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

void vector_resize (vector* v, int new_cap) {
    int* new_data = (int*) malloc(sizeof(int) * new_cap);
    for (int i = 0; i < v->size; ++i) {
        *(new_data+i) = *(v->data+i);
    }
    free(v->data);
    v->data = new_data;
    v->capacity = new_cap;
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

// push at the end
void vector_push(vector* v, int val) {
    *(v->data+v->size) = val;
    v->size++;
    if (v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    return;
}

// insert at any index in bounds
void vector_insert(vector* v, int i, int val) {

    for (int j = v->size; j > i; --j) {
        *(v->data+j) = *(v->data+j-1);
    }
    *(v->data+i) = val;
    v->size++;

    if (v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    return;
}

// insert at the beginning
void vector_prepend(vector* v, int val) {
    vector_insert(v, 0, val);
    return;
}

// delete last element and return it's value
int vector_pop(vector* v) {
    v->size--;
    int val = *(v->data+v->size);
    return val;
}

// delete element at index
void vector_delete(vector* v, int i) {
    for (int j = i; j < v->size; ++j) {
        *(v->data+j) = *(v->data+j+1);
    }
    v->size--;
    return;
}

// remove first element with matching value
void vector_remove(vector* v, int val) {
    int i = vector_find(v, val);
    vector_delete(v, i);
    return;
}

// return index of first element with value
int vector_find(vector* v, int val) {
    for (int i = 0; i < v->size; i++) {
        if (val == *(v->data+i)) {
            return i;
        }
    }
    return -1;
}