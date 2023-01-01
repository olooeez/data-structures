#ifndef INCLUDE_DYNAMIC_LIST_H
#define INCLUDE_DYNAMIC_LIST_H

#include <stddef.h>

typedef struct node_s *list_t;

list_t *list_dynamic_start(void);

void list_dynamic_end(list_t *li_p);
void list_dynamic_insert_begin(list_t *li, int data);
void list_dynamic_insert_final(list_t *li, int data);
void list_dynamic_remove_begin(list_t *li);
void list_dynamic_remove_final(list_t *li);

void list_dynamic_remove_value(list_t *li, int data);
void list_dynamic_remove_index(list_t *li, size_t index);
void list_dynamic_clear(list_t *li);

size_t list_dynamic_get_index(list_t *li, int data);
size_t list_dynamic_size(list_t *li);

_Bool list_dynamic_empty(list_t *li);

#endif
