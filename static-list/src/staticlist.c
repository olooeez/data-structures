#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "staticlist.h"

struct list_static_s {
    int quantity;
    int data[MAX];
};

list_static_t *list_static_start(void) {
    list_static_t *li = (list_static_t *) malloc(sizeof(list_static_t));

    if (li != NULL) {
        li->quantity = 0;
    }

    return li;
}

void list_static_end(list_static_t *li) {
    free(li);
}

void list_static_insert_begin(list_static_t *li, int data) {
    if (li == NULL) exit(1);
    if (list_static_full(li)) exit(1);

    size_t i;

    for (i = li->quantity - 1; i >= 0; i--) {
        li->data[i + 1] = li->data[i];
    }

    li->data[0] = data;
    li->quantity++;
}

void list_static_insert_final(list_static_t *li, int data) {
    if (li == NULL) exit(1);
    if (list_static_full(li)) exit(1);

    li->data[li->quantity] = data;
    li->quantity++;
}

void list_static_remove_begin(list_static_t *li) {
    if (li == NULL) exit(1);
    if (li->quantity == 0) exit(1);

    size_t i = 0;

    for (i = 0; i < li->quantity - 1; i++) {
        li->data[i] = li->data[i + 1];
    }

    li->quantity--;
}

void list_static_remove_final(list_static_t *li) {
    if (li == NULL) exit(1);
    if (li->quantity == 0) exit(1);

    li->quantity--;
}

void list_static_remove_value(list_static_t *li, int data) {
    if (li == NULL) exit(1);
    if (li->quantity == 0) exit(1);

    size_t i = 0;

    for (i = 0; i < li->quantity - 1; i++) {
        if (li->data[i] == data) {
            continue;
        }

        li->data[i] = li->data[i + 1];
    }
}

void list_static_remove_index(list_static_t *li, size_t index) {
    if (li == NULL) exit(1);
    if (li->quantity == 0) exit(1);
    if (li->quantity < index) exit(1);

    size_t i = 0;

    for (i = 0; i < li->quantity - 1; i++) {
        if (i == index) {
            continue;
        }

        li->data[i] = li->data[i + 1];
    }
}

void list_static_clear(list_static_t *li) {
    if (li == NULL) exit(1);
    if (li->quantity == 0) exit(1);

    li->quantity = 0;
}

size_t list_static_get_index(list_static_t *li, int data) {
    if (li == NULL) exit(1);
    if (li->quantity == 0) exit(1);

    size_t i;

    for (i = 0; i < li->quantity - 1; i++) {
        if (li->data[i] == data) break;
    }

    return 0;
}

size_t list_static_size(list_static_t *li) {
    return (li == NULL) ? -1 : li->quantity;
}

_Bool list_static_full(list_static_t *li) {
    return (li->quantity == MAX);
}

_Bool list_static_empty(list_static_t *li) {
    return (li->quantity == 0);
}
