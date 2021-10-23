#include <stdio.h>
#include <math.h>
#include <time.h>

#define HEIGHT 60
#define WIDTH 60

#define FPS 30

typedef struct {
	int x, y;
} vect;

char symb[] = { ' ', '"', 'O', '_'};

vect vec_init(int x, int y);
vect vec_sub(vect v1, vect v2);
vect vec_add(vect v1, vect v2);
int vec_len(vect v);

int main(void)
{
	vect centr, current, second, speed = {0}, accel = {0};
	int rad = 10;
	centr.y = rad;
	centr.x = HEIGHT/2;
	speed.y = 1;
	accel.y = 1;
	struct timespec timer;

	for(;;) {
		printf("\033[1;0H");

		timer.tv_sec = 0;
		timer.tv_nsec = 1000000000 / FPS;

		for(int row = 0; row < HEIGHT; row += 2) {
			for(int col = 0; col < WIDTH; ++col) {
				current =  vec_init(col, row);
				second = vec_init(col, row + 1);

				if(vec_len(vec_sub(centr, current)) <= rad && 
					vec_len(vec_sub(centr, second)) <= rad)
					putchar(symb[2]);
				else if(vec_len(vec_sub(centr, current)) <= rad && 
						vec_len(vec_sub(centr, second)) > rad)
					putchar(symb[1]);
				else if(vec_len(vec_sub(centr, current)) > rad && 
						vec_len(vec_sub(centr, second)) <= rad)
					putchar(symb[3]);
				else
					putchar(symb[0]);
			}
			putchar('\n');
		}
		nanosleep(&timer, NULL);

		centr = vec_add(centr, speed);
		speed = vec_add(speed, accel);

		if(centr.y > HEIGHT - rad)
			speed.y = -0.9 * speed.y;
	}
	return 0;
}

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
