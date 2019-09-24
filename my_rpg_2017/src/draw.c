/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "../include/my.h"
#include "../include/lib.h"

void		my_put_pixel(sfUint8 *pixels, int x, int y, sfColor color)
{
	pixels[(WIDTH * y + x) * 4] = color.r;
	pixels[(WIDTH * y + x) * 4 + 1] = color.g;
	pixels[(WIDTH * y + x) * 4 + 2] = color.b;
	pixels[(WIDTH * y + x) * 4 + 3] = color.a;
}

void draw_square(sfUint8 *pixels, int x, int y, sfColor color)
{
	int xx;
	int yy;

	xx = x + 2;
	yy = y + 2;
	while (y < yy) {
		x = xx - 2;
		while (x < xx) {
			my_put_pixel(pixels, x, y, color);
			x++;
		}
		y++;
	}
}

void my_draw_line(sfUint8 *pixels, sfVector2i fr, sfVector2i to, sfColor color)
{
	float t = 0;
	int x = 0;
	int y;
	static int u = 1;
	int m = sqrt(pow(to.x - fr.x, 2) + pow(to.y - fr.y, 2));

	while (t < 1) {
		x = ((1 - t) * fr.x + t * to.x);
		y = ((1 - t) * fr.y + t * to.y);
		draw_square(pixels, x, y, color);
		t += 1 / (double)m;
	}
}


sfUint8 *create_pixel_buffer(int width, int height)
{
	int i = 0;
	sfUint8 *pixels;

	if (!(pixels = malloc(width * height * 4 * sizeof(*pixels))))
		return (NULL);
	while (i < width * height * 4)
		pixels[i++] = 0;
	return (pixels);
}

sfRenderWindow *create_window(char *name, int width, int height)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = width;
	mode.height = height;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
	if (window == NULL)
		return(NULL);
	return (window);
}
