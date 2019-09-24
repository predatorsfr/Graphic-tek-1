/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "include/my.h"
#include "include/item.h"
#include "include/lib.h"
#include "include/get_next_line.h"
#include "include/menu.h"

sfColor		choose_color(s_struct *all)
{
	sfColor	color;
	int pos;

	pos = all->map.map2[all->ray.pos_i[0]][all->ray.pos_i[1]];
	if (pos == 1)
		color = sfCyan;
	else if (pos == 2)
		color = sfMagenta;
	else if (pos == 3)
		color = sfBlue;
	else if (pos == 4)
		color = sfWhite;
    else if (pos == 5)
      color = sfRed;
	else if (pos == 0)
		color = sfGreen;
	if (all->ray.is_side == 1) {
		color.r /= 1.5;
		color.g /= 1.5;
		color.b /= 1.5;
	}
	return (color);
}

void free_fill_ray(s_struct *all)
{
	free(all->ray.steps);
	free(all->ray.sides);
	free(all->ray.pos_i);
}

int		wolf(s_struct *all, inventory *inventory, stats player)
{
	char *inv = malloc(sizeof(char) * 5);
	item *now = inventory->first_item;
	int position;
	int i = 0;
	int k = 0;
	int j = 0;
	int xleft = 120;
	int xrigth = 380;
	int yup = 180;
	int ydown = 210;
	sfUint8 *pixels;
	sfEvent	event;
	s_struct *(*vent[11])(s_struct *, item *);

	vent[0] = load_text_1;
	vent[1] = load_text_2;
	vent[2] = load_text_3;
	vent[3] = load_text_4;
	vent[4] = load_text_5;
	vent[5] = load_text_6;
	vent[6] = load_text_7;
	vent[7] = load_text_8;
	vent[8] = load_text_9;
	vent[9] = load_text_10;
	vent[10] = load_text_11;
	pixels = create_pixel_buffer(WIDTH, HEIGHT);
	sfRenderWindow_display(all->render.win);
	sfRenderWindow_clear(all->render.win, sfBlack);
	sfRenderWindow_drawSprite(all->render.win, all->render.sprite, NULL);
	all->data.x = 0;
	while ((all = fill_ray(all, all->data.x)) != NULL && all->data.x++ < WIDTH){
		draw_ray(all, pixels);
		free_fill_ray(all);
	}
	free_fill_ray(all);
	sfTexture_updateFromPixels(all->render.texture, pixels, WIDTH, HEIGHT, 0, 0);
	free(pixels);
	/*while (sfRenderWindow_pollEvent(all->render.win, &event)) {
		if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape || event.type == sfEvtClosed)
			while( i == 0) {
			sfRenderWindow_drawSprite(all->render.win, all->text.s_bckgrnd, NULL);
			sfRenderWindow_display(all->render.win);
			if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
				i = 1;
			}

	}
	i = 0;
}*/
	if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
		while( i == 0) {
		sfRenderWindow_drawSprite(all->render.win, all->text.s_bckgrnd, NULL);
		sfRenderWindow_display(all->render.win);
		//if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
		//	i = 1;
		//}
	}		//if (sfKeybo		//if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
		//	i = 1;
		//}ard_isKeyPressed(sfKeyEscape) == sfTrue) {
		//	i = 1;
		//}
}
	if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue) {
		while (i == 0) {
			sfRenderWindow_drawSprite(all->render.win, all->text.s_bckgrnd, NULL);
			sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text1, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text2, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text3, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text4, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text5, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text6, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text7, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text8, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text9, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text10, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text11, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text12, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.text13, NULL);
			sfText_setString(all->string.quit, "X");
			sfText_setString(all->string.stat, "Cost:\t\t\tLvl:\t\t\tDamage:");
			sfText_setString(all->string.name, "Name:\t\t\tLife:\t\tVigeur:\t\tLvl:\t\tStrength:\nPlayer");
			sfText_setString(all->string.vig, player.vigor);
			sfText_setString(all->string.lvl, player.lvl);
			sfText_setString(all->string.life, player.life);
			sfText_setString(all->string.dmg, player.damage);
			sfText_setPosition(all->string.stat, all->string.val_stat);
			sfText_setPosition(all->string.quit, all->string.ext);
			sfText_setPosition(all->string.life, all->string.val_life);
			sfText_setPosition(all->string.vig, all->string.val_vig);
			sfText_setPosition(all->string.lvl, all->string.val_lvl);
			sfText_setPosition(all->string.dmg, all->string.val_dmg);
			sfText_setPosition(all->string.name, all->string.val_name);
			sfRenderWindow_drawText(all->render.win, all->string.stat, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.quit, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.name, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.life, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.vig, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.lvl, NULL);
			sfRenderWindow_drawText(all->render.win, all->string.dmg, NULL);
			sfRenderWindow_display(all->render.win);
			while (now->name_item != NULL || j != 11) {
				all = (*vent[j])(all, now);
				all->string.pos.y = all->string.pos.y + 30;
				j++;
				if (now->name_item != NULL)
					now = now->next;
			}
			while (sfRenderWindow_pollEvent(all->render.win, &event)) {
				yup = 180;
				ydown = 210;
				all->string.mouse = sfMouse_getPositionRenderWindow(all->render.win);
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > 880
				    && all->string.mouse.x < 901
				    && all->string.mouse.y > 99
				    && all->string.mouse.y < 128) {
					i = 1;
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup
				    && all->string.mouse.y < ydown) {
							position = 0;
					all->text.p_bar.y = 180;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+30
				    && all->string.mouse.y < ydown+30) {
							position = 1;
					all->text.p_bar.y = 210;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+60
				    && all->string.mouse.y < ydown+60) {
							position = 2;
					all->text.p_bar.y = 240;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+90
				    && all->string.mouse.y < ydown+90) {
							position = 3;
					all->text.p_bar.y = 270;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+120
				    && all->string.mouse.y < ydown+120) {
							position = 4;
					all->text.p_bar.y = 300;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+150
				    && all->string.mouse.y < ydown+150) {
							position = 5;
					all->text.p_bar.y = 330;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+180
				    && all->string.mouse.y < ydown+180) {
							position = 6;
					all->text.p_bar.y = 360;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+210
				    && all->string.mouse.y < ydown+210) {
							position = 7;
					all->text.p_bar.y = 390;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+240
				    && all->string.mouse.y < ydown+240) {
							position = 8;
					all->text.p_bar.y = 420;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+270
				    && all->string.mouse.y < ydown+270) {
							position = 9;
					all->text.p_bar.y = 450;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
				if (event.type == sfEvtMouseButtonReleased
				    && all->string.mouse.x > xleft
				    && all->string.mouse.x < xrigth
				    && all->string.mouse.y > yup+300
				    && all->string.mouse.y < ydown+300) {
							position = 10;
					all->text.p_bar.y = 474;
					sfSprite_setPosition(all->text.s_bar, all->text.p_bar);
					sfRenderWindow_drawSprite(all->render.win, all->text.s_bar, NULL);
				}
			}
		}
		all->string.pos.y = 180;
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
		rot_cam(all, 1);
	else if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue)
		rot_cam(all, -1);
	else if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
		mov_cam(all, 1);
	else if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
		mov_cam(all, -1);
}

int	start_game(void)
{
	FILE *fd;
	int i = 0;
	static s_struct all;
	static inventory *inventory;
	stats player = init_gamer(player);

	inventory = initialisation_inventory();
	init_inventory(inventory);
	if ((fd = fopen("maps/antitest", "r")) == NULL)
		return (84);
	all.map.map2 = txt_to_char(fd, &all);
	if ((!(init_render(&all)) || !(init_data(&all)) || !(init_text(&all))
	     || !(ini_text(&all))))
		return (84);
	while (sfRenderWindow_isOpen(all.render.win)) {
		if (wolf(&all, inventory, player) == -1)
			return (84);
			if(pnj_case_intro(&all) == 84)
			return (84);
			fight_detection(&all);
	}
	sfRenderWindow_destroy(all.render.win);
	sfTexture_destroy(all.render.texture);
	sfText_destroy(all.string.text1);
	sfSprite_destroy(all.text.s_bckgrnd);
	sfSprite_destroy(all.render.sprite);
	return (0);
}

int main(int ac, char **av)
{
	menu_t menu;
	menu_t title;
	buttonlist_t buttons;

	create_my_window();
}
