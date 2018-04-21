#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../minunit.h"
#include "my_vector.h"

vector* mock_vector_3() {
    vector* mock_v;
    mock_v = vector_create();
    mock_v->size = 3;
    mock_v->data[0] = 97;
    mock_v->data[1] = 98;
    mock_v->data[2] = 99;
    return mock_v;
}

MU_TEST(test_vector_create) {
    vector* v;
    v = vector_create();

    mu_check(v->size == 0);
    mu_check(v->capacity == 16);
    mu_check(v->data != NULL);
}

MU_TEST(test_size_getter) {
    vector* v;
    v = vector_create();

    mu_check(vector_size(v) == 0);
}

MU_TEST(test_capacity_getter) {
    vector* v;
    v =  vector_create();

    mu_check(vector_capacity(v) == 16);
}

MU_TEST(test_vector_is_empty) {
    vector* v;
    v =  vector_create();

    mu_check(vector_is_empty(v) == true);
    v->data[0] = 99;
    v->size = 1;
    mu_check(vector_is_empty(v) == false);
}

MU_TEST(test_vector_at) {
    vector* v;
    v = mock_vector_3();

    mu_check(vector_at(v, 0) == 97);
    mu_check(vector_at(v, 1) == 98);
    mu_check(vector_at(v, 2) == 99);
}

MU_TEST(test_vector_push) {
    vector* v;
    v =  vector_create();

    vector_push(v, 97);
    mu_check(v->size == 1);
    mu_check(v->data[0] == 97);
}

MU_TEST(test_vector_push_a_lot) {
    vector* v;
    v =  vector_create();

    for (int i = 0; i < 1000; ++i)
    {
        vector_push(v, i);
    }

    mu_check(v->size == 1000);
    mu_check(v->size <= v->capacity);
    mu_check(v->data[50] == 50);
}

MU_TEST(test_vector_insert) {
    vector* v;
    v = mock_vector_3();

    vector_insert(v, 1, 76);

    mu_check(v->size == 4);
    mu_check(v->data[0] == 97);
    mu_check(v->data[1] == 76);
    mu_check(v->data[2] == 98);
    mu_check(v->data[3] == 99);
}

MU_TEST(test_vector_prepend) {
    vector* v;
    v = mock_vector_3();

    vector_prepend(v, 76);

    mu_check(v->size == 4);
    mu_check(v->data[0] == 76);
    mu_check(v->data[1] == 97);
    mu_check(v->data[2] == 98);
    mu_check(v->data[3] == 99);
}

MU_TEST(test_vector_pop) {
    vector* v;
    v = mock_vector_3();

    mu_check(vector_pop(v) == 99);
    mu_check(v->size == 2);
}

MU_TEST(test_vector_delete) {
    vector* v;
    v = mock_vector_3();

    vector_delete(v, 1);

    mu_check(v->size == 2);
    mu_check(v->data[0] == 97);
    mu_check(v->data[1] == 99);
}

MU_TEST(test_vector_remove) {
    vector* v;
    v =  mock_vector_3();

    vector_remove(v, 98);

    mu_check(v->size == 2);
    mu_check(v->data[0] == 97);
    mu_check(v->data[1] == 99);
}

MU_TEST(test_vector_find) {
    vector* v;
    v =  mock_vector_3();

    mu_check(vector_find(v, 97) == 0);
    mu_check(vector_find(v, 98) == 1);
    mu_check(vector_find(v, 99) == 2);
    mu_check(vector_find(v, 96) == -1);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_vector_create);
    MU_RUN_TEST(test_size_getter);
    MU_RUN_TEST(test_capacity_getter);
    MU_RUN_TEST(test_vector_is_empty);
    MU_RUN_TEST(test_vector_at);
    MU_RUN_TEST(test_vector_push);
    MU_RUN_TEST(test_vector_push_a_lot);
    MU_RUN_TEST(test_vector_insert);
    MU_RUN_TEST(test_vector_prepend);
    MU_RUN_TEST(test_vector_pop);
    MU_RUN_TEST(test_vector_delete);
    MU_RUN_TEST(test_vector_remove);
    MU_RUN_TEST(test_vector_find);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return minunit_status;
}