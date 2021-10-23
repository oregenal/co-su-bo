#include <stdio.h>
#include <math.h>
#include <time.h>

#define HEIGHT 60
#define WIDTH 60

#define FPS 30

typedef struct {
	int x, y;
} vect;

vect vec_sub(vect v1, vect v2);
vect vec_add(vect v1, vect v2);
int vec_len(vect v);

int main(void)
{
	vect centr, current, second, speed = {0}, accel = {0};
	int rad = 10;
	centr.x = rad;
	centr.y = HEIGHT/2;
	speed.x = 1;
	accel.x = 1;
	struct timespec timer;
	for(;;) {
		timer.tv_sec = 0;
		timer.tv_nsec = 1000000000 / FPS;
		for(int row = 0; row < HEIGHT; row += 2) {
			current.x = row;
			second.x = row + 1;
			for(int col = 0; col < WIDTH; ++col) {
				current.y = col;
				second.y = col;
				if(vec_len(vec_sub(centr, current)) <= rad && 
					vec_len(vec_sub(centr, second)) <= rad)
					putchar('0');
				else if(vec_len(vec_sub(centr, current)) <= rad && 
						vec_len(vec_sub(centr, second)) > rad)
					putchar('"');
				else if(vec_len(vec_sub(centr, current)) > rad && 
						vec_len(vec_sub(centr, second)) <= rad)
					putchar('_');
				else
					putchar(' ');
			}
			putchar('\n');
		}
		nanosleep(&timer, NULL);
		//printf("\033[%dA", HEIGHT);
		//printf("\033[%dD", WIDTH);
		printf("\033[1;0H");
		centr = vec_add(centr, speed);
		speed = vec_add(speed, accel);
		if(centr.x > HEIGHT - rad)
			speed.x = -0.9 * speed.x;
	}
	return 0;
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
