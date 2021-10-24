#include <stdio.h>
#include <time.h>

#include "./vect.h"

#define HEIGHT 60
#define WIDTH 60

#define FPS 30

char symb[] = { ' ', '"', 'O', '_'};

int main(void)
{
	vect centr, current, second, speed = {0}, accel = {0};
	int rad = 10;
	centr.y = rad;
	centr.x = HEIGHT/2;
	speed.y = 1;
	accel.y = 1;
	struct timespec timer;
	timer.tv_sec = 0;
	timer.tv_nsec = 1000000000 / FPS;

	for(;;) {
		printf("\033[1;0H");

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
