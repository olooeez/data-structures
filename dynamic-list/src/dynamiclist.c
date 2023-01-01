#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamiclist.h"

struct node_s {
	int data;
	struct node_s *next;
};

typedef struct node_s node_t;

list_t *list_dynamic_start(void) {
	list_t *li = (list_t *) malloc(sizeof(list_t));

	if (li != NULL) *li = NULL;

	return li;
}

void list_dynamic_end(list_t *li) {
	if (li != NULL) {
		node_t *node;

		while ((*li) != NULL) {
			node = *li;
			*li = (*li)->next;
			free(node);
		}

		free(li);
	}

}

void list_dynamic_insert_begin(list_t *li, int data) {
	if (li == NULL) exit(1);

	node_t *node = (node_t *) malloc(sizeof(node_t));

	if (node == NULL) exit(1);

	node->data = data;
	node->next = (*li);

	*li = node;
}

void list_dynamic_insert_final(list_t *li, int data) {
	if (li == NULL) exit(1);

	node_t *node = (node_t *) malloc(sizeof(node_t));

	if (node == NULL) exit(1);

	node->data = data;
	node->next = NULL;

	if ((*li) == NULL) {
		*li = node;
	} else {
		node_t *tmp;
		tmp = *li;

		while (tmp->next != NULL) tmp = tmp->next;

		tmp->next = node;
	}
}

void list_dynamic_remove_begin(list_t *li) {
	if (li == NULL) exit(1);
	if ((*li) == NULL) exit(1);

	node_t *node = *li;

	*li = node->next;

	free(node);
}

void list_dynamic_remove_final(list_t *li) {
	if (li == NULL) exit(1);
	if ((*li) == NULL) exit(1);

	node_t *previous, *node = *li;

	while (node->next != NULL) {
		previous = node;
		node = node->next;
	}

	if (node == (*li)) *li = node->next;
	else previous->next = node->next;
	
	free(node);
}

void list_dynamic_remove_value(list_t *li, int data) {
	if (li == NULL) exit(1);
	if ((*li) == NULL) exit(1);

	node_t *previous, *node = *li;

	while (node != NULL && node->data != data) {
		previous = node;
		node = node->next;
	}

	if (node == NULL) exit(1);

	if (node == *li) *li = node->next;
	else previous->next = node->next;

	free(node);
}

void list_dynamic_remove_index(list_t *li, size_t index) {
	if (li == NULL) exit(1);
	if ((*li) == NULL) exit(1);

	size_t count = 0;
	node_t *previous, *node = *li;

	while (node != NULL && count != index) {
		previous = node;
		node = node->next;
		count++;
	}

	if (node == NULL) exit(1);

	if (node == *li) *li = node->next;
	else previous->next = node->next;

	free(node);

}

void list_dynamic_clear(list_t *li) {
	if (li == NULL) {
		node_t *node;

		while ((*li) != NULL) {
			node = *li;
			*li = (*li)->next;
			free(node);
		}
	}
}

size_t list_dynamic_get_index(list_t *li, int data) {
	if (li == NULL) exit(1);
	if ((*li) == NULL) exit(1);

	size_t count = 0;
	node_t *node = *li;

	while (node != NULL && node->data != data) {
		node = node->next;
		count++;
	}

	if (node == NULL) exit(1);

	return count;
}

size_t list_dynamic_size(list_t *li) {
	if (li == NULL) exit(1);

	size_t count = 0;
	node_t *node = *li;

	while (node != NULL) {
		node = node->next;
		count++;
	}

	return count;
}

_Bool list_dynamic_empty(list_t *li) {
	if (li == NULL) return 1;
	if ((*li) == NULL) return 1;

	return 0;
}
