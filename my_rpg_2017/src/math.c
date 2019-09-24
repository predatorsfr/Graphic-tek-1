/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "../include/my.h"
#include "../include/lib.h"

double grab_wall_dist(s_struct *all, double dx, double dy, int hit)
{
	while (hit == 0) {
		if (all->ray.sides[0] < all->ray.sides[1]) {
			all->ray.sides[0] += dx;
			all->ray.pos_i[0] += all->ray.steps[0];
			all->ray.is_side = 0;
		} else {
			all->ray.sides[1] += dy;
			all->ray.pos_i[1] += all->ray.steps[1];
			all->ray.is_side = 1;
		}
		if (all->map.map2[all->ray.pos_i[0]][all->ray.pos_i[1]] > 0.0)
			hit = 1;
	}
	dx = all->ray.pos_i[1] - all->ray.ray_y;
	if (all->ray.is_side == 0)
		dx = all->ray.pos_i[0] - all->ray.ray_x;
	if (all->ray.is_side == 0)
		return (fabs((dx + (1 - all->ray.steps[0]) / 2) / all->ray.dir_x));
	else
		return (fabs((dx + (1 - all->ray.steps[1]) / 2) / all->ray.dir_y));
}

double get_wall_dist(s_struct *all, double dx, double dy)
{
	all->ray.pos_i[0] = (int)(all->ray.ray_x);
	all->ray.pos_i[1] = (int)(all->ray.ray_y);
	all->ray.steps[0] = 1;
	all->ray.steps[1] = 1;
	if (all->ray.dir_x < 0)
		all->ray.sides[0] = dx * (all->ray.ray_x - all->ray.pos_i[0]);
	else
		all->ray.sides[0] = dx * (1.0 + all->ray.pos_i[0] - all->ray.ray_x);
	if (all->ray.dir_y < 0)
		all->ray.sides[1] = dy * (all->ray.ray_y - all->ray.pos_i[1]);
	else
		all->ray.sides[1] = dy * (1.0 + all->ray.pos_i[1] - all->ray.ray_y);
	if (all->ray.dir_x < 0)
		all->ray.steps[0] = -1;
	if (all->ray.dir_y < 0)
		all->ray.steps[1] = -1;
	return (grab_wall_dist(all, dx, dy, 0));
}

void draw_ray(s_struct *all, sfUint8* pixels)
{
	sfVector2i from;
	sfVector2i to;
	int tmp;
	double delta_x;
	double delta_y;
	double wall_dist;

	delta_x = sqrt(1 + (all->ray.dir_y * all->ray.dir_y) / (all->ray.dir_x * all->ray.dir_x));
	delta_y = sqrt(1 + (all->ray.dir_x * all->ray.dir_x) / (all->ray.dir_y * all->ray.dir_y));
	wall_dist = get_wall_dist(all, delta_x, delta_y);
	tmp = (int)(HEIGHT / wall_dist);
	from.x = all->ray.x_win;
	to.x = all->ray.x_win;
	from.y = ((tmp * -1) + HEIGHT) / 2;
	to.y = (tmp + HEIGHT) / 2;
	if (from.y < 0)
		from.y = 0;
	if (to.y >= HEIGHT)
		to.y = HEIGHT - 1;
	my_draw_line(pixels, from, to, choose_color(all));
}

void mov_cam(s_struct *all, int dif)
{
	double sp;

	sp = all->data.front_speed;
	if (dif == 1)
	{
		if (all->map.map2[(int)(all->data.x_pos + all->data.x_dir * sp)][(int)(all->data.y_pos)] == 0)
			all->data.x_pos += all->data.x_dir * sp;
		if (all->map.map2[(int)(all->data.x_pos)][(int)(all->data.y_pos + all->data.y_dir * sp)] == 0)
			all->data.y_pos += all->data.y_dir * sp;
	} else {
		if (all->map.map2[(int)(all->data.x_pos - all->data.x_dir * sp)][(int)(all->data.y_pos)] == 0)
			all->data.x_pos -= all->data.x_dir * sp;
		if (all->map.map2[(int)(all->data.x_pos)][(int)(all->data.y_pos - all->data.y_dir * sp)] == 0)
			all->data.y_pos -= all->data.y_dir * sp;
	}
}

void rot_cam(s_struct *all, int div)
{
	double rot;
	double tmpcam;
	double tmpdir;

	rot = all->data.rot_speed * div;
	tmpdir = all->data.x_dir;
	all->data.x_dir = all->data.x_dir * cos(rot) - all->data.y_dir * sin(rot);
	all->data.y_dir = tmpdir * sin(rot) + all->data.y_dir * cos(rot);
	tmpcam = all->data.x_cam;
	all->data.x_cam = all->data.x_cam * cos(rot) - all->data.y_cam * sin(rot);
	all->data.y_cam = tmpcam * sin(rot) + all->data.y_cam * cos(rot);
}
