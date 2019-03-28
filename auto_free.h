#ifndef _AFREE_
#define _AFREE_

struct arrayList {
	void *cur;
	struct arrayList *prev;
};

void *mlc(struct arrayList **x, unsigned int size);

void _afree(struct arrayList *x);

void _free(struct arrayList **x, void *y);

#endif