#ifndef INCLUDE_DOUBLE_LIST
#define INCLUDE_DOUBLE_LIST

#include <stddef.h>

typedef struct node_double_s *list_double_t;

list_double_t *list_double_start(void);

void list_double_end(list_double_t *li);
void list_double_insert_begin(list_double_t *li, int data);
void list_double_insert_final(list_double_t *li, int data);
void list_double_remove_begin(list_double_t *li);
void list_double_remove_final(list_double_t *li);

void list_double_remove_value(list_double_t *li, int data);
void list_double_remove_index(list_double_t *li, size_t index);
void list_double_clear(list_double_t *li);

size_t list_double_get_index(list_double_t *li, int data);
size_t list_double_size(list_double_t *li);

_Bool list_double_full(list_double_t *li);
_Bool list_double_empty(list_double_t *li);

#endif