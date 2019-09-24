/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** all files related to the npc
*/

#include "../include/my.h"

static void init_dialog(s_struct *all)
{
	all->text.t_dialog = sfTexture_createFromFile
		("textures/dialog.png", NULL);
	all->text.s_dialog = sfSprite_create();
	all->text.p_dialog.x = 0;
	all->text.p_dialog.y = 420;
	sfSprite_setTexture(all->text.s_dialog, all->text.t_dialog, sfTrue);
	sfSprite_setPosition(all->text.s_dialog, all->text.p_dialog);
}

void ini_speech(s_struct *all)
{
	char *ava = "4 champions to beat to recover Ava's sympathy.";

	my_strcpy(all->string.text[0], "Hello young adventurer.");
	my_strcpy(all->string.text[1],
		  "You have been chosen to solve the maze of Cyrix.");
	my_strcpy(all->string.text[2], ava);
	my_strcpy(all->string.text[3],
		  "It will allow you to leave this world.");
	my_strcpy(all->string.text[4],
		  "Each of the four paths lead to a champion.");
	my_strcpy(all->string.text[5],
		  "Try to use 'D' or 'Q' to look around you.");
	my_strcpy(all->string.text[6],
		  "But, I must make sure of your will to succeed.");
	my_strcpy(all->string.text[7],
		  "Here, take this sword and FIGHT !");
}

static void draw_my_text(s_struct *all)
{
	int i = 0;
	sfEvent event;
	char *italic = "Use 'space' to continue the conversation.";

	while (i != 8) {
		sfText_setString(all->string.diag1, all->string.text[i]);
		sfText_setString(all->string.space, italic);
		sfRenderWindow_drawSprite(
			all->render.win, all->text.s_little, NULL);
		sfRenderWindow_drawText(
			all->render.win, all->string.space, NULL);
		sfRenderWindow_drawText(
			all->render.win, all->string.diag1, NULL);
		sfRenderWindow_display(all->render.win);
		while (sfRenderWindow_pollEvent(all->render.win, &event)) {
			if (event.type == sfEvtKeyPressed &&
			    event.key.code == sfKeySpace){
				sfRenderWindow_clear(all->render.win, sfBlack);
				sfRenderWindow_drawSprite(
					all->render.win,
					all->text.s_dialog, NULL);
				i++;
			}
		}
	}
}

void dialog(s_struct *all)
{
	int i = 0;
	sfEvent	event;

	sfRenderWindow_drawText(all->render.win, all->string.diag1, NULL);
	sfRenderWindow_drawText(all->render.win, all->string.space, NULL);
	sfText_setPosition(all->string.space, all->string.p_space);
	sfText_setPosition(all->string.diag1, all->string.p_diag);
	sfText_setColor(all->string.diag1, sfBlack);
	sfText_setStyle(all->string.space, sfTextItalic);
	draw_my_text(all);
}

void start_dialog(s_struct *all)
{
	init_dialog(all);
	ini_speech(all);
	sfRenderWindow_clear(all->render.win, sfBlack);
	sfRenderWindow_drawSprite(all->render.win, all->text.s_dialog, NULL);
	sfSprite_destroy(all->text.s_first_pnj);
	sfTexture_destroy(all->text.t_first_pnj);
	dialog(all);
	wait_five(all);
}
