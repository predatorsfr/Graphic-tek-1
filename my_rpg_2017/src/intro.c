/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** introduction
*/

#include "../include/my.h"

void wait_five(s_struct *all)
{
	while (all->text.se_first_pnj < 5) {
		all->text.ti_first_pnj = sfClock_getElapsedTime(
			all->text.c_first_pnj);
		all->text.se_first_pnj = all->text.ti_first_pnj.microseconds /
			1000000.0;
	}
	sfClock_restart(all->text.c_first_pnj);
	all->text.se_first_pnj = 0;
}

static void first_pnj_move(s_struct *all)
{
	sfVector2f buf;
	int j = 0;

	while (j != 200) {
		sfRenderWindow_clear(all->render.win, sfBlack);
		sfRenderWindow_drawSprite(
			all->render.win, all->text.s_first_pnj, NULL);
		buf = sfSprite_getPosition(all->text.s_first_pnj);
		if (buf.x >= 350)
			sfSprite_move(
				all->text.s_first_pnj, all->text.m_first_pnj);
		sfRenderWindow_display(all->render.win);
		j++;
	}
}

static void freeze_time(s_struct *all)
{
	int i = 0;
	int j = 0;

	while (i == 0) {
		first_pnj_move(all);
		start_dialog(all);
		i++;
	}
}

void destroy_intro(s_struct *all)
{
	sfTexture_destroy(all->text.t_little);
	sfSprite_destroy(all->text.s_little);
	sfTexture_destroy(all->text.t_dialog);
	sfSprite_destroy(all->text.s_dialog);
	sfClock_destroy(all->text.c_first_pnj);
	sfText_destroy(all->string.diag1);
	sfText_destroy(all->string.space);
	free (all->string.text);
}

int pnj_case_intro(s_struct *all)
{
	if (all->data.x_pos > 29 || all->data.x_pos < 26
	    || all->data.y_pos > 29 || all->data.y_pos < 26) {
		if (all->data.intro != 1) {
			all->text.t_first_pnj = sfTexture_createFromFile
				("textures/first_pnj.png", NULL);
			all->text.c_first_pnj = sfClock_create();
			all->text.s_first_pnj = sfSprite_create();
			all->text.p_first_pnj.x = 900;
			all->text.p_first_pnj.y = 75;
			all->text.m_first_pnj.x = -5;
			all->text.m_first_pnj.y = 0;
			sfSprite_setTexture(
				all->text.s_first_pnj, all->text.t_first_pnj,
				sfTrue);
			sfSprite_setPosition(
				all->text.s_first_pnj, all->text.p_first_pnj);
			freeze_time(all);
			destroy_intro(all);
			all->data.intro = 1;
		}
	}
	return (0);
}
