/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "../include/my.h"
#include "../include/lib.h"

s_struct *init_render(s_struct *all)
{
	if ((all->render.win = create_window("RPG", WIDTH, HEIGHT)) == NULL)
		return (NULL);
	all->render.sprite = sfSprite_create();
	all->render.texture = sfTexture_create(WIDTH, HEIGHT);
	sfRenderWindow_setFramerateLimit(all->render.win, 60);
	sfSprite_setTexture(all->render.sprite, all->render.texture, sfTrue);
	return (all);
}

int ini_text(s_struct *all)
{
	int i = 0;
	all->string.text = malloc(sizeof(char *) * 10);

	while (i != 8) {
		all->string.text[i] = malloc(sizeof(char) * 140);
		i++;
	}
	all->string.text[i] = NULL;
}

int init_data(s_struct *all)
{
	all->data.front_speed = 0.1;
	all->data.rot_speed = 0.12;
	all->data.x_dir = -1;
	all->data.y_dir = 0;
	all->data.x_cam = 0;
	all->data.y_cam = 0.66;
	all->data.x_pos = all->map.line / 2;
	all->data.y_pos = all->map.nbchar / 2;
	all->data.intro = 0;
	return (1);
}

s_struct *init_text(s_struct *all)
{
	all->text.t_little = sfTexture_createFromFile("textures/little_pnj.png", NULL);
	all->text.t_hitbox = sfTexture_createFromFile("textures/hitbox.png", NULL);
	all->text.s_hitbox = sfSprite_create();
	all->text.p_hitbox.x = 25;
	all->text.p_hitbox.y = 444;
	all->text.t_skeleton = sfTexture_createFromFile("textures/skeleton.png", NULL);
	all->text.s_skeleton = sfSprite_create();
	all->text.p_skeleton.x = 630;
	all->text.p_skeleton.y = 30;
	all->text.t_fight = sfTexture_createFromFile("textures/fight_bckgrnd.png", NULL);
	all->text.s_fight = sfSprite_create();
	all->string.diag1 = sfText_create();
	all->text.s_little = sfSprite_create();
	all->text.p_little.x = 800;
	all->text.p_little.y = 120;
	all->string.space = sfText_create();
	all->string.p_space.x = 30;
	all->string.p_space.y = 380;
	all->string.p_diag.x = 30;
	all->string.p_diag.y = 455;
	all->text.t_bar = sfTexture_createFromFile("textures/inventory_bar.png", NULL);
	all->text.s_bar = sfSprite_create();
	all->text.p_bar.x = 114;
	all->text.p_bar.y = 180;
	all->text.t_bckgrnd = sfTexture_createFromFile("textures/background_dark.png", NULL);
	all->text.s_bckgrnd = sfSprite_create();
	all->text.p_bckgrnd.x = 112;
	all->text.p_bckgrnd.y = 84;
	all->string.p_skeleton.x = 83;
	all->string.p_skeleton.y = 75;
	all->string.pos.x = 120;
	all->string.pos.y = 180;
	all->string.ext.x = 880;
	all->string.ext.y = 90;
	all->string.val_life.x = 300;
	all->string.val_life.y = 130;
	all->string.val_vig.x = 450;
	all->string.val_vig.y = 130;
	all->string.val_lvl.x = 602;
	all->string.val_lvl.y = 130;
	all->string.val_dmg.x = 750;
	all->string.val_dmg.y = 130;
	all->string.val_name.x = 120;
	all->string.val_name.y = 90;
	all->string.val_stat.x = 400;
	all->string.val_stat.y = 325;
	all->string.skeleton = sfText_create();
	all->string.stat = sfText_create();
	all->string.quit = sfText_create();
	all->string.life = sfText_create();
	all->string.vig = sfText_create();
	all->string.lvl = sfText_create();
	all->string.dmg = sfText_create();
	all->string.name = sfText_create();
	all->string.text1 = sfText_create();
	all->string.text2 = sfText_create();
	all->string.text3 = sfText_create();
	all->string.text4 = sfText_create();
	all->string.text5 = sfText_create();
	all->string.text6 = sfText_create();
	all->string.text7 = sfText_create();
	all->string.text8 = sfText_create();
	all->string.text9 = sfText_create();
	all->string.text10 = sfText_create();
	all->string.text11 = sfText_create();
	all->string.text12 = sfText_create();
	all->string.text13 = sfText_create();
	all->string.font = sfFont_createFromFile("src/arial.ttf");
	sfText_setFont(all->string.skeleton, all->string.font);
	sfText_setFont(all->string.life, all->string.font);
	sfText_setFont(all->string.stat, all->string.font);
	sfText_setFont(all->string.vig, all->string.font);
	sfText_setFont(all->string.lvl, all->string.font);
	sfText_setFont(all->string.dmg, all->string.font);
	sfText_setFont(all->string.name, all->string.font);
	sfText_setFont(all->string.quit, all->string.font);
	sfText_setFont(all->string.text1, all->string.font);
	sfText_setFont(all->string.text2, all->string.font);
	sfText_setFont(all->string.text3, all->string.font);
	sfText_setFont(all->string.text4, all->string.font);
	sfText_setFont(all->string.text5, all->string.font);
	sfText_setFont(all->string.text6, all->string.font);
	sfText_setFont(all->string.text7, all->string.font);
	sfText_setFont(all->string.text8, all->string.font);
	sfText_setFont(all->string.text9, all->string.font);
	sfText_setFont(all->string.text10, all->string.font);
	sfText_setFont(all->string.text11, all->string.font);
	sfText_setFont(all->string.text12, all->string.font);
	sfText_setFont(all->string.text13, all->string.font);
	sfText_setFont(all->string.space, all->string.font);
	sfText_setFont(all->string.diag1, all->string.font);
	sfSprite_setTexture(all->text.s_hitbox, all->text.t_hitbox, sfTrue);
	sfSprite_setPosition(all->text.s_hitbox, all->text.p_hitbox);
	sfSprite_setTexture(all->text.s_skeleton, all->text.t_skeleton, sfTrue);
	sfSprite_setPosition(all->text.s_skeleton, all->text.p_skeleton);
	sfSprite_setTexture(all->text.s_little, all->text.t_little, sfTrue);
	sfSprite_setPosition(all->text.s_little, all->text.p_little);
	sfSprite_setTexture(all->text.s_bar, all->text.t_bar, sfTrue);
	sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
	sfSprite_setTexture(all->text.s_fight, all->text.t_fight, sfTrue);
	sfSprite_setTexture(all->text.s_bckgrnd, all->text.t_bckgrnd, sfTrue);
	sfSprite_setPosition(all->text.s_bckgrnd, all->text.p_bckgrnd);
	return (all);
}

s_struct *fill_ray(s_struct *all, int x)
{
	if ((all->ray.steps = malloc(sizeof(int) * 2)) == NULL ||
	    (all->ray.sides = malloc(sizeof(double) * 2)) == NULL ||
	    (all->ray.pos_i = malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	all->ray.x_win = x;
	all->ray.cam_x = 2 * x / (double)(WIDTH) - 1;
	all->ray.ray_x = all->data.x_pos;
	all->ray.ray_y = all->data.y_pos;
	all->ray.dir_x = all->ray.cam_x * all->data.x_cam + all->data.x_dir;
	all->ray.dir_y = all->ray.cam_x * all->data.y_cam + all->data.y_dir;
	return (all);
}
