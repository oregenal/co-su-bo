#include <math.h>
#include "./vect.h"

vect vec_init(int x, int y)
{
	vect res;
	res.x = x;
	res.y = y;
	return res;
}

vect vec_sub(vect v1, vect v2)
{
	vect res;
	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return res;
}

vect vec_add(vect v1, vect v2)
{
	vect res;
	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return res;
}

int vec_len(vect v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
