#include <stdlib.h>

#include "doublelist.h"

#include <stddef.h>

struct node_double_s {
	struct node_double_s *previous;
	struct node_double_s *next;
	int data;
};

typedef struct node_double_s node_double_t;

list_double_t *list_double_start(void) {
	list_double_t *li = (list_double_t *) malloc(sizeof(list_double_t));

	if (li != NULL) *li = NULL;

	return li;
}

void list_double_end(list_double_t *li) {
	if (li != NULL) {
		node_double_t *node;

		while ((*li) != NULL) {
			node = *li;
			*li = (*li)->next;
			free(node);
		}

		free(li);
	}
}

void list_double_insert_begin(list_double_t *li, int data) {
	if (li == NULL) exit(1); // No memory

	node_double_t *node = (node_double_t *) malloc(sizeof(node_double_t));

	if (node == NULL) exit(1); // No memory

	node->data = data;
	node->next = (*li);
	node->previous = NULL;

	if (*li != NULL) (*li)->previous = node;

	*li = node;
}

void list_double_insert_final(list_double_t *li, int data) {
	if (li == NULL) exit(1); // No memory

	node_double_t *node = (node_double_t *) malloc(sizeof(node_double_t));

	if (node == NULL) exit(1); // No memory

	node->data = data;
	node->next = NULL;

	if ((*li) == NULL) {
		node->previous = NULL;
		*li = node;
	} else {
		node_double_t *tmp = *li;

		while (tmp->next != NULL) tmp = tmp->next;

		tmp->next = node;
		node->previous = tmp;
	}
}

void list_double_remove_begin(list_double_t *li) {
	if (li == NULL) exit(1); // No memory

	if ((*li) == NULL) exit(1); // List empty

	node_double_t *node = *li;

	*li = node->next;

	if (node->next != NULL) node->next->previous = NULL;

	free(node);
}

void list_double_remove_final(list_double_t *li) {
	if (li == NULL) exit(1); // No memory

	if ((*li) == NULL) exit(1); // List empty

	node_double_t *node = *li;

	while (node->next != NULL) node = node->next;

	if (node->previous == NULL) *li = node->next;
	else node->previous->next = NULL;

	free(node);
}

void list_double_remove_value(list_double_t *li, int data) {
	if (li == NULL) exit(1); // No memory

	if ((*li) == NULL) exit(1); // List empty

	node_double_t *node = *li;

	while (node != NULL && node->data != data) node = node->next;

	if (node == NULL) exit(1); // Not in the list

	if (node->previous == NULL) *li = node->next;
	else node->previous->next = node->next;

	if (node->next != NULL) node->next->previous = node->previous;

	free(node);
}

void list_double_remove_index(list_double_t *li, size_t index) {
	if (li == NULL) exit(1); // No memory

	if ((*li) == NULL) exit(1); // List empty

	if (list_double_size(li) < index) exit(1); // Out of range

	node_double_t *node = *li;
	size_t count = 0;

	while (node != NULL && count != index) {
		node = node->next;
		count++;
	}

	if (node->previous == NULL) *li = node->next;
	else node->previous->next = node->next;

	if (node->next != NULL) node->next->previous = node->previous;

	free(node);
}

void list_double_clear(list_double_t *li) {
	if (li != NULL) {
		node_double_t *node;

		while ((*li) != NULL) {
			node = *li;
			*li = (*li)->next;
			free(node);
		}

		*li = NULL;
	}
}

size_t list_double_get_index(list_double_t *li, int data) {
	if (li == NULL) exit(1); // No memory

	if ((*li) == NULL) exit(1); // List empty

	node_double_t *node = *li;
	size_t count = 0;

	while (node != NULL && node->data != data) {
		node = node->next;
		count++;
	}

	if (node == NULL) exit(1); // Not in the list

	return count;
}

size_t list_double_size(list_double_t *li) {
	if (li == NULL) exit(1); // No memory

	size_t count = 0;
	node_double_t *node = *li;

	while (node != NULL) {
		node = node->next;
		count++;
	}

	return count;
}

_Bool list_double_empty(list_double_t *li) {
	if (li == NULL) return 1;
	if ((*li) == NULL) return 1;

	return 0;
}