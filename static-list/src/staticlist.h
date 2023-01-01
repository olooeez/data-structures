#ifndef INCLUDE_STATIC_LIST_H
#define INCLUDE_STATIC_LIST_H

#include <stddef.h>

#define MAX 100

typedef struct list_static_s list_static_t;

list_static_t *list_static_start(void);

void list_static_end(list_static_t *li);
void list_static_insert_begin(list_static_t *li, int data);
void list_static_insert_final(list_static_t *li, int data);
void list_static_remove_begin(list_static_t *li);
void list_static_remove_final(list_static_t *li);

void list_static_remove_value(list_static_t *li, int data);
void list_static_remove_index(list_static_t *li, size_t index);
void list_static_clear(list_static_t *li);

size_t list_static_get_index(list_static_t *li, int data);
size_t list_static_size(list_static_t *li);

_Bool list_static_full(list_static_t *li);
_Bool list_static_empty(list_static_t *li);

#endif
