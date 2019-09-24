/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/menu.h"
#include "../include/my.h"

void how_to_play(menu_t *menu, sfSprite *htp)
{
	int i = 0;
	while (i == 0) {
	sfRenderWindow_drawSprite(menu->window, htp, NULL);
	sfRenderWindow_display(menu->window);
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
		i = 1;
	}
}
}

int button_mouseclicked(buttonlist_t *buttons, menu_t *menu, sfSprite *htp)
{
	sfVector2i click = sfMouse_getPositionRenderWindow(menu->window);

	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		if (click.y >= 300 && click.y <= 350 && click.x >= 500 && click.x <= 745) {
			buttons->play_game.texture = sfTexture_createFromFile("./img/play_clicked.png", NULL);
			return (1);
		}
		if (click.y >= 400 && click.y <= 450 && click.x >= 500 && click.x <= 745) {
			buttons->htp.texture = sfTexture_createFromFile("./img/htp_clicked.png", NULL);
			sfSprite_setTexture(buttons->htp.sprite, buttons->htp.texture, sfTrue);
			how_to_play(menu, htp);
		}
		if (click.y >= 500 && click.y <= 550 && click.x >= 500 && click.x <= 745) {
			buttons->quit_game.texture = sfTexture_createFromFile("./img/quit_clicked.png", NULL);
			sfSprite_setTexture(buttons->quit_game.sprite, buttons->quit_game.texture, sfTrue);
			return (2);
		}
	} else {
		if (click.y >= 300 && click.y <= 350 && click.x >= 500 && click.x <= 745) {
			buttons->play_game.texture = sfTexture_createFromFile("./img/play_mouse.png", NULL);
			sfSprite_setTexture(buttons->play_game.sprite, buttons->play_game.texture, sfTrue);
		}
		if (!(click.y >= 300 && click.y <= 350 && click.x >= 500 && click.x <= 745)) {
		       	sfTexture_destroy(buttons->play_game.texture);
			buttons->play_game.texture = sfTexture_createFromFile("./img/play_off.png", NULL);
			sfSprite_setTexture(buttons->play_game.sprite, buttons->play_game.texture, sfTrue);
		}
		if (click.y >= 400 && click.y <= 450 && click.x >= 500 && click.x <= 745) {
			buttons->htp.texture = sfTexture_createFromFile("./img/htp_mouse.png", NULL);
			sfSprite_setTexture(buttons->htp.sprite, buttons->htp.texture, sfTrue);
		}
		if (!(click.y >= 400 && click.y <= 450 && click.x >= 500 && click.x <= 745)) {
		  	sfTexture_destroy(buttons->htp.texture);
			buttons->htp.texture = sfTexture_createFromFile("./img/htp_off.png", NULL);
			sfSprite_setTexture(buttons->htp.sprite, buttons->htp.texture, sfTrue);
		}
		if (click.y >= 500 && click.y <= 550 && click.x >= 500 && click.x <= 745) {
			buttons->quit_game.texture = sfTexture_createFromFile("./img/quit_mouse.png", NULL);
			sfSprite_setTexture(buttons->quit_game.sprite, buttons->quit_game.texture, sfTrue);
		}
		if (!(click.y >= 500 && click.y <= 550 && click.x >= 500 && click.x <= 745)) {
		       	sfTexture_destroy(buttons->quit_game.texture);
			buttons->quit_game.texture = sfTexture_createFromFile("./img/quit_off.png", NULL);
			sfSprite_setTexture(buttons->quit_game.sprite, buttons->quit_game.texture, sfTrue);
		}
	}
}

int create_title(menu_t *title)
{
	sfVector2f pos = {200, 50};

	title->background = sfSprite_create();
	sfSprite_setTexture(title->background, title->texture, sfTrue);
	sfSprite_setPosition(title->background, pos);
}

int create_background(menu_t *menu)
{
	if (!menu->texture)
		return (84);
	menu->background = sfSprite_create();
	sfSprite_setTexture(menu->background, menu->texture, sfTrue);
	sfSprite_setTextureRect(menu->background, menu->backgroundrect);
	if (sfTime_asMilliseconds(sfClock_getElapsedTime(menu->clock1)) >= 45) {
		menu->backgroundrect.left = menu->backgroundrect.left + 1280;
		if (menu->backgroundrect.left >= 7680) {
			menu->backgroundrect.left = 1280;
			menu->backgroundrect.top = menu->backgroundrect.top + 720;
			if (menu->backgroundrect.top >= 4320)
				menu->backgroundrect.top = 0;
		}
		sfClock_restart(menu->clock1);
	}
	return (0);
}

void draw_buttons(menu_t *menu, buttonlist_t *buttons)
{
	sfRenderWindow_drawSprite(menu->window, buttons->play_game.sprite,
				  NULL);
	sfRenderWindow_drawSprite(menu->window, buttons->htp.sprite, NULL);
	sfRenderWindow_drawSprite(menu->window, buttons->quit_game.sprite,
				  NULL);
}

int make_loop(menu_t *menu, menu_t *title, buttonlist_t *buttons, sfSprite *htp)
{
	int i = 0;

	while (sfRenderWindow_isOpen(menu->window)) {
		while (sfRenderWindow_pollEvent(menu->window, &menu->event))
			if (menu->event.type == sfEvtClosed)
				sfRenderWindow_close(menu->window);
		create_background(menu);
		sfRenderWindow_clear(menu->window, sfBlack);
		create_title(title);
		sfRenderWindow_drawSprite(menu->window, menu->background, NULL);
		sfRenderWindow_drawSprite(menu->window, title->background,
					  NULL);
		draw_buttons(menu, buttons);
		i = button_mouseclicked(buttons, menu, htp);
		if (i == 1 || i == 2) {
					sfSprite_setTexture(buttons->play_game.sprite, buttons->play_game.texture, sfTrue);
					sfRenderWindow_close(menu->window);
					sfMusic_destroy(menu->music);
					sfSprite_destroy(menu->background);
					sfTexture_destroy(menu->texture);
					sfRenderWindow_destroy(menu->window);
					if (i == 1)
						start_game();
					return (0);
		}
		sfRenderWindow_display(menu->window);
	}
	return (0);
}

void init_buttons(menu_t *menu, buttonlist_t *buttons)
{
	buttons->play_game.sprite = sfSprite_create();
	buttons->htp.sprite = sfSprite_create();
	buttons->quit_game.sprite = sfSprite_create();
	buttons->play_game.butpos = (sfVector2f) {500, 300};
	buttons->htp.butpos = (sfVector2f) {500, 400};
	buttons->quit_game.butpos = (sfVector2f) {500, 500};
	sfSprite_setTexture(buttons->play_game.sprite, buttons->play_game.texture, sfTrue);
	sfSprite_setTexture(buttons->htp.sprite, buttons->htp.texture, sfTrue);
	sfSprite_setTexture(buttons->quit_game.sprite, buttons->quit_game.texture, sfTrue);
	sfSprite_setPosition(buttons->play_game.sprite,
			     buttons->play_game.butpos);
	sfSprite_setPosition(buttons->htp.sprite, buttons->htp.butpos);
	sfSprite_setPosition(buttons->quit_game.sprite,
			     buttons->quit_game.butpos);
}

int create_my_window(void)
{
	menu_t menu;
	menu_t title;
	buttonlist_t buttons;
	sfSprite *htp;
	sfTexture *htp_texture;

	menu.mode = (sfVideoMode) {1280, 720, 32};
	menu.window = sfRenderWindow_create(menu.mode, "AntiCoder || Menu",
					     sfResize | sfClose,
					     NULL);
	if (!menu.window)
		return (84);
	menu.texture = sfTexture_createFromFile("./img/menu.png",
						 NULL);
	title.texture = sfTexture_createFromFile("./img/title.png", NULL);
	menu.backgroundrect = (sfIntRect) {0, 0, 1280, 720};
	menu.clock1 = sfClock_create();
	sfMusic_play(menu.music = sfMusic_createFromFile("./img/menusong.ogg"));
	sfRenderWindow_setFramerateLimit(menu.window, 80);
	buttons.play_game.texture = sfTexture_createFromFile("./img/play_off.png",
							      NULL);
	buttons.htp.texture = sfTexture_createFromFile("./img/htp_off.png", NULL);
	buttons.quit_game.texture = sfTexture_createFromFile("./img/quit_off.png",
							      NULL);
	htp = sfSprite_create();
	htp_texture = sfTexture_createFromFile("./img/htp_menu.png", NULL);
	sfSprite_setTexture(htp, htp_texture, sfTrue);
	init_buttons(&menu, &buttons);
	make_loop(&menu, &title, &buttons, htp);
}
