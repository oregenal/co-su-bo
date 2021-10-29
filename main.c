#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>

#include "./vect.h"

#define HEIGHT 60
#define WIDTH 60

#define FPS 30

char *symb = " \"0_";

int main(void)
{
	vect centr, current, second, speed = {0}, accel = {0};
	int rad = 10;
	centr.y = rad;
	centr.x = HEIGHT/2;
	speed.y = 1;
	accel.y = 1;

	for(;;) {
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
		usleep(1000 * 1000 / FPS);

		centr = vec_add(centr, speed);
		speed = vec_add(speed, accel);

		if(centr.y > HEIGHT - rad)
			speed.y = -0.9 * speed.y;

		printf("\033[%dA", HEIGHT/2);
		printf("\033[%dD", WIDTH);
	}
	return 0;
}
