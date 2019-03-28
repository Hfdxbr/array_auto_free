#include "auto_free.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
	struct arrayList *al = NULL;
	int *a;
	double *b;
	char *c;
	int **d;
	a = (int *)mlc(&al, 5 * sizeof(*a));
	b = (double *)mlc(&al, 2 * sizeof(*b));
	c = (char *)mlc(&al, 4 * sizeof(*c));
	d = (int **)mlc(&al, 2 * sizeof(*d));

	for (int i = 0; i < 5; i++)
		a[i] = i;

	printf("a: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	printf("\n");

	b[0] = 1.23; b[1] = 0.333;

	printf("b: ");
	for (int i = 0; i < 2; i++)
		printf("%lf ", b[i]);
	printf("\n");

	c[0] = 'H'; c[1] = 'i'; c[2] = '!'; c[3] = '\0';

	printf("c: ");
	printf("%s", c);
	printf("\n");

	for (int i = 0; i < 2; ++i)
		d[i] = (int *)mlc(&al, 3 * sizeof(int));

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			d[i][j] = 3 * i + j;
	}

	_free(&al, a);

	printf("d:\n");
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j)
			printf("%d ", d[i][j]);
		printf("\n");
	}

	_afree(al);

	return 0;
}