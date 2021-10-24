#ifndef VECT_H
#define VECT_H

typedef struct {
	int x, y;
} vect;

vect vec_init(int x, int y);
vect vec_sub(vect v1, vect v2);
vect vec_add(vect v1, vect v2);
int vec_len(vect v);

#endif
