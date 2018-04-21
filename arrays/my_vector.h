#pragma once

typedef struct vector_implementation {
    int size;
    int capacity;
    int *data;
} vector;

// return pointer to new vector
vector* vector_create();

// returns vector size
int vector_size(vector* v);

// returns capacity
int vector_capacity(vector* v);

//return true if size is 0
int vector_is_empty(vector* v);

// return value form index i
int vector_at(vector* v, int i);

// push at the end
void vector_push(vector* v, int val);

// insert at any index in bounds
void vector_insert(vector* v, int i, int val);

// insert at the beginning
void vector_prepend(vector* v, int val);

// delete last element and return it's value
int vector_pop(vector* v);

// delete element at index
void vector_delete(vector* v, int i);

// remove first element with matching value
void vector_remove(vector* v, int val);

// return index of first element with value
int vector_find(vector* v, int val);
