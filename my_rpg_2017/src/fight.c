/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** fight
*/

#include "../include/my.h"

void button_fight(s_struct *all)
{
	sfEvent event;
	
	all->string.mouse = sfMouse_getPositionRenderWindow(all->render.win);
	if (event.type == sfEvtMouseButtonReleased
	    && all->string.mouse.x > 25
	    && all->string.mouse.x < 91
	    && all->string.mouse.y > 444
	    && all->string.mouse.y < 510) {
	}
}
int skeleton_fight(s_struct *all)
{
	int i = 0;

	while (i == 0) {
		sfRenderWindow_clear(all->render.win, sfBlack);
		sfText_setString(all->string.skeleton, "SKELETON\t\t\t\t    1");
		sfText_setPosition(all->string.skeleton, all->string.p_skeleton);
		sfRenderWindow_drawSprite(all->render.win, all->text.s_fight, NULL);
		sfRenderWindow_drawText(all->render.win, all->string.skeleton, NULL);
		sfRenderWindow_drawSprite(all->render.win, all->text.s_skeleton, NULL);
		sfRenderWindow_drawSprite(all->render.win, all->text.s_hitbox, NULL);
		button_fight(all);
		sfRenderWindow_display(all->render.win);
		wait_five(all);
		i++;
	}
}

void fight_detected(s_struct *all, int i)
{
	if (i == 0) {
		skeleton_fight(all);
	}
}

int fight_detection(s_struct *all)
{
	if (all->data.x_pos > 21 && all->data.x_pos < 23) {
			fight_detected(all, 0);
		}
}
