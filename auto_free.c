#include "auto_free.h"
#include <stdlib.h>
#include <stdio.h>

void *mlc(struct arrayList **x, unsigned int size) {

	if ((*x) == NULL) {
		(*x) = (struct arrayList *)malloc(sizeof(*(*x)));
		(*x)->cur = malloc(size);
		(*x)->prev = NULL;
	} else {
		struct arrayList *tmp = (struct arrayList *)malloc(sizeof(*tmp));
		tmp->cur = malloc(size);
		tmp->prev = (*x);
		(*x) = tmp;
	}

	return (*x)->cur;
}

void _afree(struct arrayList *x) {
	struct arrayList *tmp;

	if (x == NULL) return;

	while (x->prev != NULL) {
		tmp = x;
		x = x->prev;
		free(tmp->cur);
		free(tmp);
	}

	free(x->cur);
	free(x);
}

void _free(struct arrayList **x, void *y) {
	struct arrayList *curNode, *nextNode;

	if ((*x) == NULL) return;

	curNode = (*x)->prev; nextNode = (*x);

	if (nextNode->cur == y) {
		(*x) = curNode;
		free(nextNode->cur);
		free(nextNode);
		return;
	}

	while (curNode != NULL) {
		if (curNode->cur == y) {
			nextNode->prev = curNode->prev;
			free(curNode->cur);
			free(curNode);
			return;
		}

		nextNode = curNode;
		curNode = curNode->prev;
	}
}