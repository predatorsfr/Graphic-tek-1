/*
** EPITECH PROJECT, 2018
** menu.h
** File description:
** menu.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>

typedef struct menu_window {
	sfVideoMode mode;
	sfRenderWindow *window;
	sfSprite *background;
	sfIntRect backgroundrect;
	sfMusic *music;
	sfTexture *texture;
	sfClock *clock1;
	sfEvent event;
}menu_t;

typedef struct button {
	sfVector2f butpos;
	sfSprite *sprite;
	sfTexture *texture;
}button_t;

typedef struct button_list {
	button_t play_game;
	button_t htp;
	button_t quit_game;
	button_t retmenu;
}buttonlist_t;

int create_my_window(void);
